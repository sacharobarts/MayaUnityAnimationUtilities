#ifndef UNITYANIMTRANSLATOR_H
#define UNITYANIMTRANSLATOR_H

#include <maya/MPxFileTranslator.h>

class UnityAnimTranslator : public MPxFileTranslator
{
public:
	UnityAnimTranslator();
	virtual ~UnityAnimTranslator();
	static void* creator();
	virtual MStatus writer(const MFileObject&, const MString&, MPxFileTranslator::FileAccessMode);
	bool haveReadMethod() const { return false; }
	bool haveWriteMethod() const { return true; }
	MString defaultExtension() const { return MString(".anim"); }

	

};



#endif // !UNITYANIMTRANSLATOR_H

