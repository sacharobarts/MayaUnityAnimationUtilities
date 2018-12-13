#include "unityobject.h"


bool UnityObject::CreateNode() {
	return true;
}

bool UnityObject::DumpNode(const YAML::Node&) {

	return true;
}

std::string UnityObject::ReadDataDump() {
	return std::string("hi");
}

