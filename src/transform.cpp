#include "transform.h"

#include <iostream>

Transform::Transform(const Transform& other) : tx(trans_x), ty(trans_y), tz(trans_z), rx(rot_x), ry(rot_y), rz(rot_z), rw(rot_w), sx(scale_x), sy(scale_y), sz(scale_z){

	m_gameobject = other.m_gameobject;
	m_children = other.m_children;
	m_father = other.m_father;
	m_file_id = other.m_file_id;
	m_data = other.m_data;

	trans_x = other.trans_x;
	trans_y = other.trans_y;
	trans_z = other.trans_z;
	
	rot_x = other.rot_x;
	rot_y = other.rot_y;
	rot_z = other.rot_z;
	rot_w = other.rot_w; 

	scale_x = other.scale_x;
	scale_y = other.scale_y;
	scale_z = other.scale_z;
}

Transform& Transform::operator= (const Transform& other) {

	m_gameobject = other.m_gameobject;
	m_children = other.m_children;
	m_father = other.m_father;
	m_file_id = other.m_file_id;
	m_data = other.m_data;

	trans_x = other.trans_x;
	trans_y = other.trans_y;
	trans_z = other.trans_z;
	
	rot_x = other.rot_x;
	rot_y = other.rot_y;
	rot_z = other.rot_z;
	rot_w = other.rot_w; 

	scale_x = other.scale_x;
	scale_y = other.scale_y;
	scale_z = other.scale_z;
	return *this; 
}

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
	rot_w = rot["w"].as<double>();
	
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

