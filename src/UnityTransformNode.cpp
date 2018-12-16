#include "UnityTransformNode.h"

MTypeId UnityTransformNode::id(0x0000321);
MObject UnityTransformNode::image_component_order;
MObject UnityTransformNode::image_components;
MObject UnityTransformNode::unknown_script_components;
MObject UnityTransformNode::unknown_script_component_order;
MObject UnityTransformNode::script_data;
MObject UnityTransformNode::unity_gameobject_guid;
MObject UnityTransformNode::unity_transform_guid;
MObject UnityTransformNode::unity_object_hide_flags;
MObject UnityTransformNode::unity_corresponding_source_object;
MObject UnityTransformNode::unity_prefab_internal;
MObject UnityTransformNode::unity_serialized_version;
MObject UnityTransformNode::unity_layer;
MObject UnityTransformNode::unity_tag_string;
MObject UnityTransformNode::unity_navmesh_layer;
MObject UnityTransformNode::unity_static_editor_flags;

UnityTransformNode::UnityTransformNode(): MPxTransform() {

}

UnityTransformNode::UnityTransformNode(MPxTransformationMatrix *tm) : MPxTransform(tm) {

}

UnityTransformNode::~UnityTransformNode() {

}

void UnityTransformNode::postConstructor() {
	MPxTransform::postConstructor();
}

void* UnityTransformNode::creator() {
	return new UnityTransformNode();
}

MPxTransformationMatrix *UnityTransformNode::createTransformationMatrix() {
	return new MPxTransformationMatrix();
}

MStatus UnityTransformNode::initialize() {
	
	MStatus status;
	MStatus status2;

	MFnTypedAttribute fnAttr;
	MFnNumericAttribute fnNumAttr;
	MFnCompoundAttribute fnCmpAttr;

	MFnStringData fnStringData;

	unity_gameobject_guid = fnAttr.create("unityGameObjectGUID", "ugg", MFnData::kString,fnStringData.create(&status2),&status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_transform_guid = fnAttr.create("unityTransformGUID", "utg", MFnData::kString,fnStringData.create(&status2), &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_object_hide_flags  = fnNumAttr.create("unityObjectHideFlags", "uhf", MFnNumericData::Type::kInt, 0, &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_corresponding_source_object = fnAttr.create("unityCorrespondingSourceObject", "ucs", MFnData::kString,fnStringData.create(&status2),&status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_prefab_internal = fnAttr.create("unityPrefabInternal", "upi", MFnData::kString,fnStringData.create(&status2),&status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_serialized_version = fnNumAttr.create("unitySerializedVersion", "usv", MFnNumericData::Type::kInt,0,&status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_layer = fnNumAttr.create("unityLayer", "ulr", MFnNumericData::Type::kInt, 0, &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_tag_string = fnAttr.create("unityTagString", "uts", MFnData::kString,fnStringData.create(&status2), &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_navmesh_layer = fnNumAttr.create("unityNavmeshLayer", "unl", MFnNumericData::Type::kInt, 0, &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	unity_static_editor_flags = fnAttr.create("unityStaticEditorFlags", "usf", MFnData::kString,fnStringData.create(&status2), &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);

	script_data = fnAttr.create("scriptData", "scd", MFnData::kString,fnStringData.create(&status2), &status);
	fnAttr.setStorable(true);
	fnAttr.setKeyable(false);
	fnAttr.setHidden(false);
	fnAttr.setReadable(true);
	fnAttr.setWritable(true);


	unknown_script_component_order = fnNumAttr.create("scriptComponentOrder", "co", MFnNumericData::kInt,0,&status);
	fnNumAttr.setKeyable(true);
	//fnNumAttr.setKeyable(false);
	//fnNumAttr.setHidden(false);
	//fnNumAttr.setReadable(true);
	//fnNumAttr.setWritable(false);
	//fnNumAttr.setStorable(true);

	addAttribute(unknown_script_component_order);
	addAttribute(script_data);

	// Add attributes for unknown script data
	unknown_script_components = fnCmpAttr.create("unnknownScriptComponents", "usp");
	fnCmpAttr.setStorable(true);
	fnCmpAttr.setArray(true);
	fnCmpAttr.addChild(script_data);
	fnCmpAttr.addChild(unknown_script_component_order);

	// Add attributes for image components
	image_components = fnCmpAttr.create("imageComponents", "icp");
	fnCmpAttr.setArray(true);
	
	addAttribute(unknown_script_components);
	addAttribute(image_components);
	addAttribute(unity_gameobject_guid);
	addAttribute(unity_transform_guid);

	return MS::kSuccess;
}
/*
void UnityTransformNode::resetTransformation(const MMatrix& matrix) {
	MPxTransform::resetTransformation(matrix);
}
void UnityTransformNode::resetTransformation(MPxTransformationMatrix *resetMatrix) {
	MPxTransform::resetTransformation(resetMatrix);
}
*/
/*
MMatrix UnityTransformNode::getMatrix() {

	matrix = MMatrix();
	return matrix;
}
*/

/*
MStatus UnityTransformNode::validateAndSetValue(
	const MPlug& plug,
	const MDataHandle& handle,
	const MDGContext& context
) {

	//return MPxTransform::validateAndSetValue(plug, handle, context);
	return MS::kSuccess;
}

*/