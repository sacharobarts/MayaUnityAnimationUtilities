#ifndef _PREFABDATA_H
#define _PREFABDATA_H

#include <map>
#include <string>
#include "gameobject.h"
#include "transform.h"
#include <utility>
#include "yaml-cpp/yaml.h"

class PrefabData {
public:
	// bool ParseGameObject(const YAML::Node&);
	void AddGameObject(GameObject& go) {game_objects.insert(std::pair<std::string, GameObject>(go.GetFileID(), go));}
	std::map<std::string, GameObject> game_objects;
};


#endif
