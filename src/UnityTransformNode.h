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

	//@TODO: NEED TO CHANGE OBJECTHIDE, CORRESPODNING, AND   INTERNAL TO INCLUDE _GAMEOBJECT_
	static MObject unity_object_hide_flags;
	static MObject unity_corresponding_source_object;
	static MObject unity_prefab_internal;
	static MObject unity_serialized_version;
	static MObject unity_layer;
	static MObject unity_tag_string;
	static MObject unity_navmesh_layer;
	static MObject unity_static_editor_flags;

	static MObject unity_transform_object_hide_flags;
	static MObject unity_transform_corresponding_source_object;
	static MObject unity_transfrom_prefab_internal;
	static MObject unity_transfrom_root_order;
	static MObject unity_transform_local_euler_angles_hint;

	static MObject image_components;
	static MObject image_component_order;
	static MObject unknown_script_components;
	static MObject unknown_script_component_order;
	static MObject script_data;
};

#endif // !UNITYTRANSFORMNODE_H
