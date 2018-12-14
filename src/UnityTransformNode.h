#ifndef UNITYTRANSFORMNODE_H
#define UNITYTRANSFORMNODE_H

#include <maya/MPxTransform.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnData.h>
#include <maya/MFnCompoundAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnStringData.h>

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
	static MObject unity_gameobject_guid;
	static MObject unity_transform_guid;
	static MObject image_components;
	static MObject image_component_order;
	static MObject unknown_script_components;
	static MObject unknown_script_component_order;
	static MObject script_data;
};

#endif // !UNITYTRANSFORMNODE_H
