#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "unityobject.h"

class Transform : public UnityObject {
public:
	virtual bool ParseNode(const YAML::Node&);
	std::string GetFather();
	std::string GetGameObject() { return m_gameobject; }
private:
	double trans_x, trans_y, trans_z;
	double rot_x, rot_y, rot_z;
	double scale_x, scale_y, scale_z;
	std::string m_gameobject;
	std::vector<std::string> m_children;
	std::string m_father;
};

#endif