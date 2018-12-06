#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "unityobject.h"
#include "transform.h"
#include <maya/MObject.h>

class GameObject : public UnityObject {
public:
	virtual bool ParseNode(const YAML::Node&);
	void SetTransform(const Transform&);
private:
	Transform m_transform;
	int m_is_active;
	std::string m_name;
	std::string m_tag_string;
	MObject m_maya_object;
};

#endif