#include "UnityAnimTranslator.h"

UnityAnimTranslator::UnityAnimTranslator() {

}

UnityAnimTranslator::~UnityAnimTranslator() {

}

void* UnityAnimTranslator::creator() {

	return new UnityAnimTranslator;
}


MStatus UnityAnimTranslator::writer(const MFileObject&, const MString&, MPxFileTranslator::FileAccessMode) {

	return MS::kSuccess;
}
