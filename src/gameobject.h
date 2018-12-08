#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <memory>
#include "unityobject.h"
#include "transform.h"
#include <maya/MObject.h>

class GameObject : public UnityObject {
public:
	virtual bool ParseNode(const YAML::Node&);
	void SetTransform(const Transform&);

	void SetGameObject(MObject& mo) { m_maya_object = std::make_shared<MObject>(mo); }
	int GetIsActive() { return m_is_active; }
	std::string GetName() { return m_name; }

private:
	Transform m_transform;
	int m_is_active;
	std::string m_name;
	std::string m_tag_string;
	std::shared_ptr<MObject> m_maya_object;
};

#endif