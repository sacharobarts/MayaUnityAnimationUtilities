#include "UnityTransformNode.h"

MTypeId UnityTransformNode::id(0x0000321);
MObject UnityTransformNode::image_component_order;
MObject UnityTransformNode::image_components;
MObject UnityTransformNode::unknown_script_components;
MObject UnityTransformNode::unknown_script_component_order;
MObject UnityTransformNode::script_data;

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
	
	MFnTypedAttribute fnAttr;
	MFnNumericAttribute fnNumAttr;
	MFnCompoundAttribute fnCmpAttr;

	script_data = fnAttr.create("scriptData", "scd", MFnData::kString);
	fnNumAttr.setKeyable(true);
	// fnAttr.setWritable(false);

	unknown_script_component_order = fnNumAttr.create("scriptComponentOrder", "co", MFnNumericData::kInt);
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