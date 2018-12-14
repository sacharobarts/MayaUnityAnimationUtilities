#include "UnityAnimTranslator.h"

PrefabData UnityAnimTranslator::prefab_data;


UnityAnimTranslator::UnityAnimTranslator() {

}

UnityAnimTranslator::~UnityAnimTranslator() {

}

void* UnityAnimTranslator::creator() {

	return new UnityAnimTranslator;
}


MStatus UnityAnimTranslator::writer(const MFileObject& file, const MString& export_options, MPxFileTranslator::FileAccessMode file_access_mode) {

	return MS::kSuccess;
}

MStatus UnityAnimTranslator::reader(const MFileObject& file, const MString& import_options, MPxFileTranslator::FileAccessMode file_access_mode) {

	DEBUG_OUT("Reading from:", file.resolvedFullName());
	
	std::vector<YAML::Node> yaml_documents;

	try{
		yaml_documents = YAML::LoadAllFromFile(file.resolvedFullName().asChar());
	}
	catch(YAML::ParserException& e){
		MGlobal::displayError(e.what());
		return MS::kFailure;
	}

	DEBUG_OUT("Number of documents: ", yaml_documents.size());

	// PrefabData prefab_data;

	for (const auto doc : yaml_documents) {

		int tag = ParseDocumentTag(doc.Tag());
		if (tag == -1) {
			ERROR_OUT("Unable to parse document tag: ", doc.Tag());
			return MS::kFailure;
		}

		if (doc.Anchor().length() == 0) {
			ERROR_OUT("Document has no ID anchor: ", YAML::Dump(doc));
			return MS::kFailure;
		}

		switch (tag) {
		case 1: { // GameObject
			DEBUG_OUT("[Document]: GameObject");
			GameObject go;
			if (!go.ParseNode(doc)) {
				ERROR_OUT("Unable to process document GameObject: ", YAML::Dump(doc));
				return MS::kFailure;
			}
			prefab_data.AddGameObject(go);
			break;
		}
		case 2:
			DEBUG_OUT("[Document]: Component");
			// @TODO: gameobject lookup and attchment
			break;
		case 4: { // Transform
			DEBUG_OUT("[Document]: Transform");
			Transform trns;
			if (!trns.ParseNode(doc)) {
				ERROR_OUT("Unable to process document Transform: ", YAML::Dump(doc));
				return MS::kFailure;
			}
			std::map<std::string, GameObject>::iterator it = prefab_data.game_objects.find(trns.GetGameObject());
			if (it == prefab_data.game_objects.end()) {
				ERROR_OUT("[Transform]: Unable to find Transform's owning GameObject: ",trns.GetGameObject());
				return MS::kFailure;
			} else {
				DEBUG_OUT("[Transform]: Found Transform's father!")
				it->second.SetTransform(trns);
			}
			break;
		}
		case 43:
			DEBUG_OUT("[Document]: Mesh");
			// @TODO: make/attch mesh?
			break;
		case 99:
			DEBUG_OUT("[Document]: Image");
			// @TODO: do image stuff
			break;
		default:
			DEBUG_OUT("[Document]: Unsupported type");
			// @TODO: Do default attachment stuff;
			break;
		}

	}

	// @TODO: iterate over transforms and gameobjects and construct maya objects
	CreateMayaHierarchy();

	return MS::kSuccess;
}


int UnityAnimTranslator::ParseDocumentTag(const std::string& tag_string) {
	size_t pos = tag_string.find_last_of('!');
	if (pos == std::string::npos) {
		return -1;
	}
	return std::stoi(tag_string.substr(pos + 1));
}


bool UnityAnimTranslator::CreateMayaHierarchy() {

	DEBUG_OUT("Creating Maya Hierarchy...");



	MStatus status;
	MDagModifier dagmod;

	for (auto it = prefab_data.game_objects.begin(); it != prefab_data.game_objects.end(); it++) {
		MObject mobj = dagmod.createNode(MString("UnityTransform"), MObject::kNullObj, &status);
		if (status != MS::kSuccess) {
			ERROR_OUT("Failed to create UnityTransform node");
			return false;
		}
		DEBUG_OUT("Renaming node to: ", it->second.GetName());
		status = dagmod.renameNode(mobj, MString(it->second.GetName().c_str()));
		it->second.SetMObject(&mobj);
	}
	
	for (auto it = prefab_data.game_objects.begin(); it != prefab_data.game_objects.end(); it++) {
		GameObject uobj = it->second;
		Transform trns_data = uobj.GetTransform();
		std::string father = trns_data.GetFather();

		// Get father MObject and reparent
		if (father.length() != 0) {
			// @TODO: needs a way to error check this in case father cannot be found...
			for (auto sit = prefab_data.game_objects.begin(); sit != prefab_data.game_objects.end(); sit++) {
				Transform tr = sit->second.GetTransform();
				if (father == tr.GetFileID()){
					DEBUG_OUT("Reparenting");
					DEBUG_OUT(father, tr.GetFileID());
					prefab_data.game_objects.find("123");
					// DEBUG_OUT("CHECKING VALID:", it->second.GetMObject().apiTypeStr(), sit->second.GetMObject().apiTypeStr());
					// status = dagmod.reparentNode(uobj.GetMObject(), sit->second.GetMObject());
					CHECK_MSTATUS_AND_RETURN_IT(status);
					break;
				}
			}
			CHECK_MSTATUS_AND_RETURN_IT(status);
		}

		// Set local transform, rotation 
		//MFnTransform fntrans(it->second.GetMObject(), &status);
		//fntrans.setTranslation(MVector(trns_data.tx, trns_data.ty, trns_data.tz), MSpace::kTransform);
		//fntrans.setRotation(MQuaternion(trns_data.rx, trns_data.ry, trns_data.rz, trns_data.rw));
		//double scale_vals[]{ trns_data.sx,trns_data.sy,trns_data.sz };
		//fntrans.setScale(scale_vals);

	}


	//for (auto uobj : prefab_data.game_objects) {
	//	MObject mobj = dagmod.createNode(MString("UnityTransform"), MObject::kNullObj, &status);

	//	if (status != MS::kSuccess) {
	//		ERROR_OUT("Failed to create UnityTransform node");
	//		return false;
	//	}
	//	DEBUG_OUT("Renaming node to: ", uobj.second.GetName());
	//	status = dagmod.renameNode(mobj, MString(uobj.second.GetName().c_str()));

	//	status = mobjs.append(mobj);
	//	if (status == MS::kFailure) {
	//		ERROR_OUT("Failed to append MObject to MObjectArray: mobjs");
	//		return false;
	//	}
	//	uobj.second.SetMObject(&mobjs[0]);
	//}

	//DEBUG_OUT("Starting reparenting and setting transform values...")
	//// @TODO: Look for a way to optimize this into 1 step instead of a "create" then "parent" step
	//for (auto uobjpair : prefab_data.game_objects) {
	//	GameObject uobj = uobjpair.second;
	//	Transform trns_data = uobj.GetTransform();
	//	std::string father = trns_data.GetFather();

	//	// Get father MObject and reparent
	//	if (father.length() != 0) {
	//		//@TODO: needs a way to error check this in case father cannot be found...
	//		for (auto obs : prefab_data.game_objects) {
	//			Transform tr = obs.second.GetTransform();
	//			if (father == tr.GetFileID()){
	//				DEBUG_OUT("Reparenting");
	//				DEBUG_OUT(father, tr.GetFileID());
	//				uobj.GetMObject();
	//				// obs.second.GetMObject();
	//				//DEBUG_OUT(uobj.GetMObject().apiTypeStr());
	//				// DEBUG_OUT(obs.second.GetMObject().apiTypeStr());
	//				// status = dagmod.reparentNode(uobj.GetMObject(), obs.second.GetMObject());
	//				CHECK_MSTATUS_AND_RETURN_IT(status);
	//				break;
	//			}
	//		}
	//		CHECK_MSTATUS_AND_RETURN_IT(status);
	//	}

		// Set local transform, rotation 
		//MFnTransform fntrans(uobj.GetMObject(), &status);
		//fntrans.setTranslation(MVector(trns_data.tx, trns_data.ty, trns_data.tz), MSpace::kTransform);
		//fntrans.setRotation(MQuaternion(trns_data.rx, trns_data.ry, trns_data.rz, trns_data.rw));
		//double scale_vals[]{ trns_data.sx,trns_data.sy,trns_data.sz };
		//fntrans.setScale(scale_vals);
	// }

	DEBUG_OUT("Calling doIt");
	dagmod.doIt();
	return true;
}

