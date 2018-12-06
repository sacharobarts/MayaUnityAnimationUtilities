#include "gameobject.h"

bool GameObject::ParseNode(const YAML::Node& node) {
	m_is_active = node["m_IsActive"].as<int>();
	m_name = node["m_Name"].as<std::string>();
	m_tag_string = node["m_TagString"].as<std::string>();
	
	// @TODO: Parse tag and file id

	return true;
}

void GameObject::SetTransform(const Transform& trns) {
	m_transform = trns;
}