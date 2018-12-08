#include "transform.h"

#include <iostream>

bool Transform::ParseNode(const YAML::Node& doc) {

	m_file_id = doc.Anchor();
	if (m_file_id.length() == 0)
		return false;

	YAML::Node node = doc["Transform"];
	YAML::Node tl = node["m_LocalPosition"];
	trans_x = tl["x"].as<double>();
	trans_y = tl["y"].as<double>();
	trans_z = tl["z"].as<double>();

	YAML::Node rot = node["m_LocalRotation"];
	rot_x = rot["x"].as<double>();
	rot_y = rot["y"].as<double>();
	rot_z = rot["z"].as<double>();

	YAML::Node scale = node["m_LocalScale"];
	scale_x = scale["x"].as<double>();
	scale_y = scale["y"].as<double>();
	scale_z = scale["z"].as<double>();

	YAML::Node goid = node["m_GameObject"];
	m_gameobject = goid["fileID"].as<std::string>();

	YAML::Node fthr = node["m_Father"];
	m_father = fthr["fileID"].as<std::string>();


	return true;
}

std::string Transform::GetFather() {
	if (m_father.size() == 0)
		return "0";
	return m_father;
}