#include "UnityAnimTranslator.h"


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

	MGlobal::displayInfo(file.resolvedFullName());
	
	std::vector<YAML::Node> yaml_documents;

	try{
		yaml_documents = YAML::LoadAllFromFile(file.resolvedFullName().asChar());
	}
	catch(YAML::ParserException& e){
		MGlobal::displayError(e.what());
		return MS::kFailure;
	}

	DEBUG_OUT("Number of documents: ", yaml_documents.size());

	PrefabData prefab_data;

	for (const auto doc : yaml_documents) {
		int tag = ParseDocumentTag(doc.Tag());
		if (tag == -1) {
			ERROR_OUT("Unable to parse document tag: ", doc.Tag());
			return MS::kFailure;
		}

		switch (tag) {
		case 1: { // GameObject
			DEBUG_OUT("[Document]: GameObject");
			GameObject go;
			if (!go.ParseNode(doc["GameObject"])) {
				ERROR_OUT("Unable to process document GameObject: ", YAML::Dump(doc["GameObject"]));
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
			/*Transform trns = ParseTransfrom(doc["Transform"]);
			std::map<std::string, GameObject>::iterator it = prefab_data.game_objects.find(trns.GetFather());
			if (it == prefab_data.game_objects.end()) {
				DEBUG_OUT("[Error]: unable to find gameobject that coorisponds with transform");
			}
			else {
				it->second.SetTransform(trns);
			}*/
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
	return MS::kSuccess;
}


int UnityAnimTranslator::ParseDocumentTag(const std::string& tag_string) {
	size_t pos = tag_string.find_last_of('!');
	if (pos == std::string::npos) {
		return -1;
	}
	return std::stoi(tag_string.substr(pos + 1));
}
