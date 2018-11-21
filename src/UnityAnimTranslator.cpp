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
	//YAML::Node yaml_node;
	
	std::vector<YAML::Node> yaml_documents;
	try{
		yaml_documents = YAML::LoadAllFromFile(file.resolvedFullName().asChar());
		//yaml_node = YAML::LoadFile(file.resolvedFullName().asChar());
	}
	catch(YAML::ParserException& e){
		MGlobal::displayError(e.what());
		return MS::kFailure;
	}
	/*switch (yaml_node.Type()) {
		case YAML::NodeType::Null:
			MGlobal::displayInfo("null");
		case YAML::NodeType::Scalar:
			MGlobal::displayInfo("scalar");
		case YAML::NodeType::Sequence:
			MGlobal::displayInfo("sequence");
		case YAML::NodeType::Map:
			MGlobal::displayInfo("map");
		case YAML::NodeType::Undefined:
			MGlobal::displayInfo("undefined");
	}*/
	/*MGlobal::displayInfo(MString("pre_it ") + yaml_node.as<std::string>().c_str());
	MGlobal::displayInfo(MString("pre_it size") + yaml_node.size());
	MGlobal::displayInfo(MString("pre_it [1] ") + yaml_node[1].as<std::string>().c_str());

	for (YAML::const_iterator it = yaml_node.begin(); it != yaml_node.end(); it++) {
		MGlobal::displayInfo(MString("type ") + it->Type());
		MGlobal::displayInfo(MString("normal ") + it->as<std::string>().c_str());
		MGlobal::displayInfo(MString("first ") + it->first.as<std::string>().c_str());
		MGlobal::displayInfo(MString("second ") + it->second.as<std::string>().c_str());

	}*/
	MGlobal::displayInfo(MString("number of documents in yaml: ") + yaml_documents.size());
	MGlobal::displayInfo(MString("type: ") + yaml_documents[0].Type());

	for (const auto& kv : yaml_documents[0]) {
		const YAML::Node& fval = kv.first;
		const YAML::Node& value = kv.second;
		MGlobal::displayInfo(MString("kv first value type: ") + fval.Type());
		MGlobal::displayInfo(MString("kv first value: ") + fval.as<std::string>().c_str());

		MGlobal::displayInfo(MString("kv second value type: ") + value.Type());
		MGlobal::displayInfo(MString("kv second value: ") + value.as<std::string>().c_str());
		
	}
	return MS::kSuccess;
}

