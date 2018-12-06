#ifndef _UNITYOBJECT_H
#define _UNITYOBJECT_H

#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"

class UnityObject {
public:
	virtual bool CreateNode(); // for maya -> unity ?
	virtual bool ParseNode(const YAML::Node&) = 0; // for unity -> maya
	bool DumpNode(const YAML::Node&); // for writing .prefab?
	std::string ReadDataDump(); // unity -> maya dump unkown script data into a node?
	std::string GetFileID() { return m_file_id; }
protected:
	std::string m_file_id;
private:
	std::string m_data;
};

#endif
