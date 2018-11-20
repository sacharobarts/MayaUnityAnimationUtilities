#ifndef UNITYTRANSFORMNODE_H
#define UNITYTRANSFORMNODE_H

#include <maya/MPxTransform.h>


class UnityTransformNode : public MPxTransform {
public:
	UnityTransformNode();
	UnityTransformNode(MPxTransformationMatrix *);
	virtual ~UnityTransformNode();
	virtual MPxTransformationMatrix *createTransformationMatrix();


	virtual void postConstructor();
	static void* creator();
	// virtual void resetTransformation(MPxTransformationMatrix*);
	// virtual void resetTransformation(const MMatrix&);
	// virtual MMatrix getMatrix();
	/*
	virtual MStatus validateAndSetValue(
		const MPlug& plug,
		const MDataHandle& handle,
		const MDGContext& context
	);
*/
	static MStatus initialize();
	static MTypeId id;

protected:
	static MObject components;
};

#endif // !UNITYTRANSFORMNODE_H
