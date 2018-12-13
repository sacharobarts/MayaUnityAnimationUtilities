#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "unityobject.h"
#include "dbgmsg.h"

class Transform : public UnityObject {
private:
	double trans_x, trans_y, trans_z;
	double rot_x, rot_y, rot_z, rot_w;
	double scale_x, scale_y, scale_z;
	std::string m_gameobject;
	std::vector<std::string> m_children;
	std::string m_father;
public:
	const double& tx;
	const double& ty;
	const double& tz;
	const double& rx;
	const double& ry;
	const double& rz;
	const double& rw;
	const double& sx;
	const double& sy;
	const double& sz;
	Transform() : tx(trans_x), ty(trans_y), tz(trans_z), rx(rot_x), ry(rot_y), rz(rot_z), rw(rot_w), sx(scale_x), sy(scale_y), sz(scale_z) { };
	Transform(const Transform&);
	Transform& operator= (const Transform&);
	virtual bool ParseNode(const YAML::Node&);
	const std::string& GetFather() const { return m_father; };
	std::string GetGameObject() { return m_gameobject; }
};

#endif