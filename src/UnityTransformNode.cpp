#include "UnityTransformNode.h"

MTypeId UnityTransformNode::id(0x0000321);
MObject UnityTransformNode::components;

UnityTransformNode::UnityTransformNode(): MPxTransform() {

	 // MPxTransform::MPxTransform();
}

UnityTransformNode::UnityTransformNode(MPxTransformationMatrix *tm) : MPxTransform(tm) {

	// MPxTransform::MPxTransform(tm);
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