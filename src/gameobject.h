#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <memory>
#include "unityobject.h"
#include "transform.h"
#include <maya/MObject.h>
#include "dbgmsg.h"

class GameObject : public UnityObject {
public:
	virtual bool ParseNode(const YAML::Node&);
	void SetTransform(const Transform&);
	const Transform& GetTransform() const { return m_transform; }
	void SetMObject(MObject mo) { m_maya_object = mo; }
	MObject& GetMObject() { return m_maya_object; }//DEBUG_OUT("GETMOBJ", m_maya_object->apiTypeStr()); return *m_maya_object; }
	int GetIsActive() { return m_is_active; }
	std::string GetName() { return m_name; }
private:
	Transform m_transform;
	int m_is_active;
	std::string m_name;
	std::string m_tag_string;
	MObject m_maya_object;
	// std::shared_ptr<MObject> m_maya_object;
};

#endif