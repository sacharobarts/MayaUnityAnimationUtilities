#include "gameobject.h"

// MObject GameObject::m_maya_object;

bool GameObject::ParseNode(const YAML::Node& doc) {

	// parse anchor to file id (.prefabs are setup this way)
	m_file_id = doc.Anchor();
	if (m_file_id.length() == 0)
		return false;

	YAML::Node node = doc["GameObject"];

	m_is_active = node["m_IsActive"].as<int>();
	m_name = node["m_Name"].as<std::string>();
	m_tag_string = node["m_TagString"].as<std::string>();
	

	return true;
}

void GameObject::SetTransform(const Transform& trns) {
	m_transform = trns;
}

// @TODO: DONT ACTUALLY NEED TO PASS THE MOBJECT IN...
bool GameObject::SetMayaProperties() {

	MStatus status;
	// @TODO actually set this...
	MFnTransform fntrans(m_maya_object, &status);
	if (status != MS::kSuccess) {
		ERROR_OUT("Unable to create MFnTransform on MObject m_maya_object MObject:", m_maya_object.apiTypeStr());
		return false;
	}
	
	if (!SetAttributeValue(fntrans, "unityGameObjectGUID", m_file_id.c_str()))
		return false;
	if (!SetAttributeValue(fntrans, "unityTransformGUID", m_transform.GetFileID().c_str()))
		return false;
	if (!SetAttributeValue(fntrans, "unityGameObjectGUID", m_file_id))
		return false;


	return true;
}

template <typename T> bool GameObject::SetAttributeValue(MFnTransform& fntrans,const char* attr_name, T value) {

	MStatus status;
	MPlug guid_attr = fntrans.findPlug(attr_name, status);
	if (status != MS::kSuccess) {
		ERROR_OUT("Unable to find", attr_name, "attribute on", fntrans.fullPathName());
		return false;
	}
	status = guid_attr.setValue(value);
	if (status != MS::kSuccess) {
		ERROR_OUT("Unable to set", attr_name, "attribute on", fntrans.fullPathName());
		return false;
	}

	return true;
}