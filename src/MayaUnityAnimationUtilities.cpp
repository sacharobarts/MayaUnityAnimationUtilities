#include <maya/MFnPlugin.h>
#include "UnityTransformNode.h"
#include "UnityAnimTranslator.h"

MStatus initializePlugin(MObject obj) {
	MFnPlugin plugin(obj, "Sacha Roberts", "0.0", "any");

    MStatus status = plugin.registerTransform("UnityTransform",
		UnityTransformNode::id,
		UnityTransformNode::creator,
		UnityTransformNode::initialize,
		MPxTransformationMatrix::creator,
		MPxTransformationMatrix::baseTransformationMatrixId
		);

	CHECK_MSTATUS_AND_RETURN_IT(status);
	status = plugin.registerFileTranslator("Unity Prefab",
		"none",
		UnityAnimTranslator::creator,
		"ExportOptions",
		"DefaultOptions");
	return MS::kSuccess;
}


MStatus uninitializePlugin(MObject obj) {

	MFnPlugin plugin(obj);
	MStatus status = plugin.deregisterNode(UnityTransformNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}