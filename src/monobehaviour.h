#ifndef _MONOBEHAVIOUR_H
#define _MONOBEHAVIOUR_H

#include "unityobject.h"

class MonoBehaviour : public UnityObject {
public:
	virtual bool ParseNode(const YAML::Node&);

private:
	int is_enabled;

};




#endif // !_MONOBEHAVIOUR_H
