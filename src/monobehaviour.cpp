#include "monobehaviour.h"


bool MonoBehaviour::ParseNode(const YAML::Node& doc) {
	m_file_id = doc.Anchor();
	if (m_file_id.length() == 0)
		return false;
	YAML::Node node = doc["MonoBehaviour"];
	YAML::Node m_script_node = node["m_Script"];
	int file_id = m_script_node["fileId"].as<int>();
	switch (file_id) {
		case -765806418: { // UnityEngine.UI 

		}
		default:
			// @TODO: put data
			break;
	}
}