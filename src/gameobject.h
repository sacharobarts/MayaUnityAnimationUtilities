#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <memory>
#include "unityobject.h"
#include "transform.h"
#include "dbgmsg.h"
#include "errmsg.h"
#include <maya/MObject.h>
#include <maya/MFnTransform.h>
#include <maya/MPlug.h>

class GameObject : public UnityObject {
public:
	virtual bool ParseNode(const YAML::Node&);
	bool SetMayaProperties();
	void SetTransform(const Transform&);
	const Transform& GetTransform() const { return m_transform; }
	void SetMObject(MObject mo) { m_maya_object = mo; }
	MObject& GetMObject() { return m_maya_object; }
	int GetIsActive() { return m_is_active; }
	std::string GetName() { return m_name; }
private:
	Transform m_transform;
	int m_is_active;
	std::string m_name;
	std::string m_tag_string;
	MObject m_maya_object;
	template<typename T> bool SetAttributeValue(MFnTransform&,const char*,T);
};

#endif