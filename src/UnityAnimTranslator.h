#ifndef UNITYANIMTRANSLATOR_H
#define UNITYANIMTRANSLATOR_H

// #define YAML_CPP_DLL

#include <maya/MPxFileTranslator.h>
#include <maya/MGlobal.h>
#include <maya/MString.h>
#include <vector>
#include <string>
#include <fstream>
#include "yaml-cpp/yaml.h"
#include "prefabdata.h"
#include "dbgmsg.h"
#include "errmsg.h"

class UnityAnimTranslator : public MPxFileTranslator
{
public:
	UnityAnimTranslator();
	virtual ~UnityAnimTranslator();
	static void* creator();
	virtual MStatus writer(const MFileObject&, const MString&, MPxFileTranslator::FileAccessMode);
	virtual MStatus reader(const MFileObject&, const MString&, MPxFileTranslator::FileAccessMode);
	bool haveReadMethod() const { return true; }
	bool haveWriteMethod() const { return true; }
	MString defaultExtension() const { return MString("prefab"); }
private:
	int ParseDocumentTag(const std::string&);
	

};



#endif // !UNITYANIMTRANSLATOR_H

