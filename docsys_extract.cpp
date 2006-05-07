/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#include "NIF_Blocks.h"

typedef IBlock * (*blk_factory_func)();
extern map<string, blk_factory_func> global_block_map;

//--Block Class Constructors--//

AControllable::AControllable() {
	//AddAttr( attr_string, "Name", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Extra Data", 0, 67240448 );
	//AddAttr( attr_linkgroup, "Extra Data List", 167772416, 0xFFFFFFFF );
	//AddAttr( attr_link, "Controller", 0, 0xFFFFFFFF );
	Init();
}

AController::AController() {
	//AddAttr( attr_link, "Next Controller", 0, 0xFFFFFFFF );
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frequency", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Phase", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Start Time", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Stop Time", 0, 0xFFFFFFFF );
	//AddAttr( attr_controllertarget, "Target", 0, 0xFFFFFFFF );
	Init();
}

ADynamicEffect::ADynamicEffect() {
	//AddAttr( attr_condint, "Affected Node List?", 0, 67108866 );
	//AddAttr( attr_bool, "Switch State", 167903232, 0xFFFFFFFF );
	//AddAttr( attr_linkgroup, "Affected Nodes", 167837696, 0xFFFFFFFF );
	Init();
}

AFx::AFx() {
	//AddAttr( attr_byte, "Unknown1", 0, 0xFFFFFFFF );
	//AddAttr( attr_unk292bytes, "Unknown2", 0, 0xFFFFFFFF );
	Init();
}

AInterpolator::AInterpolator() {
	Init();
}

ALight::ALight() {
	//AddAttr( attr_float, "Dimmer", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Ambient Color", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Diffuse Color", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Specular Color", 0, 0xFFFFFFFF );
	Init();
}

ANode::ANode() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Translation", 0, 0xFFFFFFFF );
	//AddAttr( attr_matrix33, "Rotation", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Scale", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Velocity", 0, 67240448 );
	//AddAttr( attr_linkgroup, "Properties", 0, 0xFFFFFFFF );
	//AddAttr( attr_bbox, "Bounding Box", 0, 67240448 );
	//AddAttr( attr_link, "Collision Data", 167772416, 0xFFFFFFFF );
	Init();
}

AParentNode::AParentNode() {
	//AddAttr( attr_linkgroup, "Children", 0, 0xFFFFFFFF );
	//AddAttr( attr_linkgroup, "Effects", 0, 0xFFFFFFFF );
	Init();
}

AParticleModifier::AParticleModifier() {
	//AddAttr( attr_link, "Next Modifier", 0, 0xFFFFFFFF );
	//AddAttr( attr_parent, "Previous Modifier", 0, 0xFFFFFFFF );
	Init();
}

AParticleNode::AParticleNode() {
	Init();
}

AParticleSystemController::AParticleSystemController() {
	///*AddAttr( attr_float, "Speed", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Speed Random", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Vertical Direction", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Vertical Angle", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Horizontal Direction", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Horizontal Angle", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 11", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Size", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Emit Start Time", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Emit Stop Time", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Emit Rate", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Lifetime", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Lifetime Random", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Start Random", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Emitter", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short 2?", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 13?", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 1?", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 2?", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short 3?", 0, 0xFFFFFFFF );
	//AddAttr( attr_particlegroup, "Particles", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Particle Extra", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Trailer", 0, 0xFFFFFFFF );*/
	Init();
}

APointLight::APointLight() {
	/*AddAttr( attr_float, "Constant Attenuation", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Linear Attenuation", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Quadratic Attenuation", 0, 0xFFFFFFFF );*/
	Init();
}

AProperty::AProperty() {
	Init();
}

APSysEmitter::APSysEmitter() {
	/*AddAttr( attr_float, "Speed", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Speed Variation", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Declination", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Declination Variation", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Planar Angle", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Planar Angle Variation", 0, 0xFFFFFFFF );
	AddAttr( attr_color4, "Initial Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Initial Radius", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Radius Variation", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Life Span", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Life Span Variation", 0, 0xFFFFFFFF );*/
	Init();
}

APSysModifier::APSysModifier() {
	/*AddAttr( attr_string, "Name", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Order", 0, 0xFFFFFFFF );
	AddAttr( attr_controllertarget, "Target", 0, 0xFFFFFFFF );
	AddAttr( attr_bool, "Active", 0, 0xFFFFFFFF );*/
	Init();
}

APSysVolumeEmitter::APSysVolumeEmitter() {
	/*AddAttr( attr_emitterobject, "Emitter Object", 335544324, 0xFFFFFFFF );*/
	Init();
}

AShape::AShape() {
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Skin Instance", 0, 0xFFFFFFFF );
	//AddAttr( attr_shader, "Shader", 167772416, 0xFFFFFFFF );
	Init();
}

AvoidNode::AvoidNode() {
	Init();
}

FxButton::FxButton() {
	Init();
}

FxRadioButton::FxRadioButton() {
	//AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int  2", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 3", 0, 0xFFFFFFFF );
	//AddAttr( attr_linkgroup, "Unknown Links", 0, 0xFFFFFFFF );
	Init();
}

FxWidget::FxWidget() {
	Init();
}

NiAlphaController::NiAlphaController() {
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiAlphaProperty::NiAlphaProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Threshold", 0, 0xFFFFFFFF );
	Init();
}

NiAmbientLight::NiAmbientLight() {
	Init();
}

NiAutoNormalParticles::NiAutoNormalParticles() {
	Init();
}

NiBillboardNode::NiBillboardNode() {
	//AddAttr( attr_short, "Billboard Mode", 167837696, 0xFFFFFFFF );
	Init();
}

NiBoolInterpolator::NiBoolInterpolator() {
	//AddAttr( attr_bool, "Bool Value", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiBSAnimationNode::NiBSAnimationNode() {
	Init();
}

NiBSPArrayController::NiBSPArrayController() {
	Init();
}

NiBSParticleNode::NiBSParticleNode() {
	Init();
}

NiBSplineCompFloatInterpolator::NiBSplineCompFloatInterpolator() {
	//AddAttr( attr_float, "Unknown Floats[0]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[1]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[2]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[3]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[4]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[5]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[6]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[7]", 0, 0xFFFFFFFF );
	Init();
}

NiBSplineCompPoint3Interpolator::NiBSplineCompPoint3Interpolator() {
	//AddAttr( attr_int, "Unknown 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[0]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[1]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[2]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[3]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[4]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Floats[5]", 0, 0xFFFFFFFF );
	Init();
}

NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator() {
	//AddAttr( attr_float, "Unknown1[0]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown1[1]", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Basis Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[0]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[1]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[2]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[3]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[4]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[5]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[6]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[7]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[8]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[9]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[10]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[11]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[12]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[13]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[14]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[15]", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown4[16]", 0, 0xFFFFFFFF );
	Init();
}

NiCamera::NiCamera() {
	//AddAttr( attr_short, "Unknown Short", 167837696, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frustum Left", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frustum Right", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frustum Top", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frustum Bottom", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frustum Near", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Frustum Far", 0, 0xFFFFFFFF );
	//AddAttr( attr_bool, "Use Orthographic Projection", 167837696, 0xFFFFFFFF );
	//AddAttr( attr_float, "Viewport Left", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Viewport Right", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Viewport Top", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Viewport Bottom", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "LOD Adjust", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link?", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 2", 67240192, 0xFFFFFFFF );
	Init();
}

NiDirectionalLight::NiDirectionalLight() {
	Init();
}

NiDitherProperty::NiDitherProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiFlipController::NiFlipController() {
	//AddAttr( attr_int, "Texture Slot", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 2", 0, 0x0A010000 );
	//AddAttr( attr_float, "Delta", 0, 0x0A010000 );
	//AddAttr( attr_linkgroup, "Sources", 0, 0xFFFFFFFF );
	Init();
}

NiFloatExtraDataController::NiFloatExtraDataController() {
	//AddAttr( attr_link, "Unknown Link", 335544324, 0xFFFFFFFF );
	//AddAttr( attr_string, "Unknown String", 335544324, 0xFFFFFFFF );
	Init();
}

NiFloatInterpolator::NiFloatInterpolator() {
	//AddAttr( attr_float, "Float Value", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiFogProperty::NiFogProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Fog Depth", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Fog Color", 0, 0xFFFFFFFF );
	Init();
}

NiGeomMorpherController::NiGeomMorpherController() {
	//AddAttr( attr_short, "Unknown", 167837696, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	Init();
}

NiGravity::NiGravity() {
	//AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Force", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Type", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Position", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Direction", 0, 0xFFFFFFFF );
	Init();
}

NiKeyframeController::NiKeyframeController() {
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiLightColorController::NiLightColorController() {
	//AddAttr( attr_short, "Unknown Short", 167837696, 167837696 );
	//AddAttr( attr_link, "Data", 0, 167837696 );
	//AddAttr( attr_link, "Interpolator", 167903232, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short", 167903232, 0xFFFFFFFF );
	Init();
}

NiLightDimmerController::NiLightDimmerController() {
	//AddAttr( attr_link, "Unknown Link", 0, 0xFFFFFFFF );
	Init();
}

NiLODNode::NiLODNode() {
	//AddAttr( attr_lodinfo, "LOD Info", 0, 0xFFFFFFFF );
	Init();
}

NiLookAtController::NiLookAtController() {
	//AddAttr( attr_short, "Unknown1", 167837696, 0xFFFFFFFF );
	//AddAttr( attr_link, "Look At Node", 0, 0xFFFFFFFF );
	Init();
}

NiLookAtInterpolator::NiLookAtInterpolator() {
	//AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Look At", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Translation", 0, 0xFFFFFFFF );
	//AddAttr( attr_quaternion, "Rotation", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Scale", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link 3", 0, 0xFFFFFFFF );
	Init();
}

NiMaterialColorController::NiMaterialColorController() {
	//AddAttr( attr_short, "Unknown", 167837696, 167837696 );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short", 167903232, 0xFFFFFFFF );
	Init();
}

NiMaterialProperty::NiMaterialProperty() {
	//AddAttr( attr_flags, "Flags", 0, 167772416 );
	//AddAttr( attr_color3, "Ambient Color", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Diffuse Color", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Specular Color", 0, 0xFFFFFFFF );
	//AddAttr( attr_color3, "Emissive Color", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Glossiness", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Alpha", 0, 0xFFFFFFFF );
	Init();
}

NiMeshParticleSystem::NiMeshParticleSystem() {
	//AddAttr( attr_modifiergroup, "Modifiers", 167837696, 0xFFFFFFFF );
	Init();
}

NiMultiTargetTransformController::NiMultiTargetTransformController() {
	//AddAttr( attr_targetgroup, "Targets", 0, 0xFFFFFFFF );
	Init();
}

NiNode::NiNode() {
	Init();
}

NiParticleBomb::NiParticleBomb() {
	//AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	Init();
}

NiParticleColorModifier::NiParticleColorModifier() {
	//AddAttr( attr_link, "Color Data", 0, 0xFFFFFFFF );
	Init();
}

NiParticleGrowFade::NiParticleGrowFade() {
	//AddAttr( attr_float, "Grow", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Fade", 0, 0xFFFFFFFF );
	Init();
}

NiParticleMeshes::NiParticleMeshes() {
	Init();
}

NiParticleMeshModifier::NiParticleMeshModifier() {
	//AddAttr( attr_linkgroup, "Particle Meshes", 0, 0xFFFFFFFF );
	Init();
}

NiParticleRotation::NiParticleRotation() {
	//AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	Init();
}

NiParticles::NiParticles() {
	Init();
}

NiParticleSystem::NiParticleSystem() {
	//AddAttr( attr_modifiergroup, "Modifiers", 167837696, 0xFFFFFFFF );
	Init();
}

NiParticleSystemController::NiParticleSystemController() {
	Init();
}

NiPathController::NiPathController() {
	//AddAttr( attr_short, "Unknown Short 2", 167837696, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown Int 3", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Pos Data", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Float Data", 0, 0xFFFFFFFF );
	Init();
}

NiPlanarCollider::NiPlanarCollider() {
	//AddAttr( attr_short, "Unknown Short", 167772416, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short 2", 67240448, 67240448 );
	//AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 11", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 12", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 13", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 14", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 15", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 16", 0, 0xFFFFFFFF );
	Init();
}

NiPoint3Interpolator::NiPoint3Interpolator() {
	//AddAttr( attr_vector3, "Point 3 Value", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiPointLight::NiPointLight() {
	Init();
}

NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() {
	//AddAttr( attr_bool, "Spawn on Death", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Spawn Modifier", 0, 0xFFFFFFFF );
	Init();
}

NiPSysBoundUpdateModifier::NiPSysBoundUpdateModifier() {
	//AddAttr( attr_short, "Update Skip", 0, 0xFFFFFFFF );
	Init();
}

NiPSysBoxEmitter::NiPSysBoxEmitter() {
	//AddAttr( attr_float, "Width", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Height", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Depth", 0, 0xFFFFFFFF );
	Init();
}

NiPSysColliderManager::NiPSysColliderManager() {
	//AddAttr( attr_link, "Collider", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Bounce", 0, 0xFFFFFFFF );
	//AddAttr( attr_bool, "Spawn on Collide", 0, 0xFFFFFFFF );
	//AddAttr( attr_bool, "Die on Collide", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Spawn Modifier", 0, 0xFFFFFFFF );
	//AddAttr( attr_selflink, "Manager", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Unknown Link?", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Collider Object", 0, 0xFFFFFFFF );
	Init();
}

NiPSysColorModifier::NiPSysColorModifier() {
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiPSysCylinderEmitter::NiPSysCylinderEmitter() {
	//AddAttr( attr_float, "Radius", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Height", 0, 0xFFFFFFFF );
	Init();
}

NiPSysEmitterCtlr::NiPSysEmitterCtlr() {
	//AddAttr( attr_link, "Interpolator", 167903232, 0xFFFFFFFF );
	//AddAttr( attr_string, "Unknown String", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiPSysEmitterDeclinationVarCtlr::NiPSysEmitterDeclinationVarCtlr() {
	//AddAttr( attr_link, "Interpolator", 0, 0xFFFFFFFF );
	//AddAttr( attr_string, "Unknown String", 0, 0xFFFFFFFF );
	Init();
}

NiPSysEmitterInitialRadiusCtlr::NiPSysEmitterInitialRadiusCtlr() {
	//AddAttr( attr_link, "Interpolator", 0, 0xFFFFFFFF );
	//AddAttr( attr_string, "Unknown String", 0, 0xFFFFFFFF );
	Init();
}

NiPSysGravityModifier::NiPSysGravityModifier() {
	//AddAttr( attr_crossref, "Gravity Object", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Gravity Axis", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Decay", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Strength", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Turbulence", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Turbulence Scale", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Force Type", 0, 0xFFFFFFFF );
	Init();
}

NiPSysGrowFadeModifier::NiPSysGrowFadeModifier() {
	//AddAttr( attr_float, "Grow Time", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Grow Generation", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Fade Time", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Fade Generation", 0, 0xFFFFFFFF );
	Init();
}

NiPSysMeshUpdateModifier::NiPSysMeshUpdateModifier() {
	//AddAttr( attr_linkgroup, "Meshes", 0, 0xFFFFFFFF );
	Init();
}

NiPSysPlanarCollider::NiPSysPlanarCollider() {
	//AddAttr( attr_float, "Width", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Height", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "X Axis", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Y Axis", 0, 0xFFFFFFFF );
	Init();
}

NiPSysPositionModifier::NiPSysPositionModifier() {
	Init();
}

NiPSysResetOnLoopCtlr::NiPSysResetOnLoopCtlr() {
	Init();
}

NiPSysRotationModifier::NiPSysRotationModifier() {
	//AddAttr( attr_float, "Initial Rotation Speed", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Initial Rotation Speed Variation", 335544324, 0xFFFFFFFF );
	//AddAttr( attr_float, "Initial Rotation Angle", 335544324, 0xFFFFFFFF );
	//AddAttr( attr_float, "Initial Rotation Angle Variation", 335544324, 0xFFFFFFFF );
	//AddAttr( attr_bool, "Random Rot Speed Sign", 335544324, 0xFFFFFFFF );
	//AddAttr( attr_bool, "Random Initial Axis", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Initial Axis", 0, 0xFFFFFFFF );
	Init();
}

NiPSysSpawnModifier::NiPSysSpawnModifier() {
	//AddAttr( attr_short, "Num Spawn Generations", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Percentage Spawned", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Min Num to Spawn", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Max Num to Spawn", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Spawn Speed Chaos", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Spawn Dir Chaos", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Life Span", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Life Span Variation", 0, 0xFFFFFFFF );
	Init();
}

NiPSysSphereEmitter::NiPSysSphereEmitter() {
	//AddAttr( attr_float, "Radius", 0, 0xFFFFFFFF );
	Init();
}

NiPSysUpdateCtlr::NiPSysUpdateCtlr() {
	Init();
}

NiRotatingParticles::NiRotatingParticles() {
	Init();
}

NiSequenceStreamHelper::NiSequenceStreamHelper() {
	Init();
}

NiShadeProperty::NiShadeProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiSourceTexture::NiSourceTexture() {
	//AddAttr( attr_texsource, "Texture Source", 0, 0xFFFFFFFF );
	//AddAttr( attr_pixellayout, "Pixel Layout", 0, 0xFFFFFFFF );
	//AddAttr( attr_mipmapformat, "Use Mipmaps", 0, 0xFFFFFFFF );
	//AddAttr( attr_alphaformat, "Alpha Format", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Unknown Byte 2", 167903232, 0xFFFFFFFF );
	Init();
}

NiSpecularProperty::NiSpecularProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiSphericalCollider::NiSphericalCollider() {
	//AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	Init();
}

NiSpotLight::NiSpotLight() {
	//AddAttr( attr_float, "Cutoff Angle", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Exponent", 0, 0xFFFFFFFF );
	Init();
}

NiStencilProperty::NiStencilProperty() {
	//AddAttr( attr_flags, "Flags", 0, 167772416 );
	//AddAttr( attr_bool, "Stencil Enabled", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Stencil Function", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Stencil Ref", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Stencil Mask", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Fail Action", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Z Fail Action", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Pass Action", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Draw Mode", 0, 0xFFFFFFFF );
	Init();
}

NiTextureEffect::NiTextureEffect() {
	//AddAttr( attr_matrix33, "Model Projection Matrix", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Model Projection Transform", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Texture Filtering", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Texture Clamping", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Texture Type", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Coordinate Generation Type", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Source Texture", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Clipping Plane", 0, 0xFFFFFFFF );
	//AddAttr( attr_vector3, "Unknown Vector", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Unknown Float", 0, 0xFFFFFFFF );
	//AddAttr( attr_short, "PS2 L", 0, 167903232 );
	//AddAttr( attr_short, "PS2 K", 0, 167903232 );
	//AddAttr( attr_short, "Unknown Short", 0, 67174412 );
	Init();
}

NiTextureTransformController::NiTextureTransformController() {
	//AddAttr( attr_int, "Unknown1", 0, 0xFFFFFFFF );
	//AddAttr( attr_byte, "Unknown2", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown3", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Unknown4", 0, 0xFFFFFFFF );
	Init();
}

NiTransformController::NiTransformController() {
	//AddAttr( attr_link, "Interpolator", 0, 0xFFFFFFFF );
	Init();
}

NiTransformInterpolator::NiTransformInterpolator() {
	//AddAttr( attr_vector3, "Translation", 0, 0xFFFFFFFF );
	//AddAttr( attr_quaternion, "Rotation", 0, 0xFFFFFFFF );
	//AddAttr( attr_float, "Scale", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiTriShape::NiTriShape() {
	Init();
}

NiTriStrips::NiTriStrips() {
	Init();
}

NiUVController::NiUVController() {
	//AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiVertexColorProperty::NiVertexColorProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	//AddAttr( attr_vertmode, "Vertex Mode", 0, 0xFFFFFFFF );
	//AddAttr( attr_lightmode, "Lighting Mode", 0, 0xFFFFFFFF );
	Init();
}

NiVisController::NiVisController() {
	//AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiWireframeProperty::NiWireframeProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiZBufferProperty::NiZBufferProperty() {
	//AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	//AddAttr( attr_int, "Function", 67174412, 0xFFFFFFFF );
	Init();
}

RootCollisionNode::RootCollisionNode() {
	Init();
}

//--Factory Functions--//

IBlock * CreateAvoidNode() {
	return new AvoidNode;
}

IBlock * CreateFxButton() {
	return new FxButton;
}

IBlock * CreateFxRadioButton() {
	return new FxRadioButton;
}

IBlock * CreateFxWidget() {
	return new FxWidget;
}

IBlock * CreateNiAlphaController() {
	return new NiAlphaController;
}

IBlock * CreateNiAlphaProperty() {
	return new NiAlphaProperty;
}

IBlock * CreateNiAmbientLight() {
	return new NiAmbientLight;
}

IBlock * CreateNiAutoNormalParticles() {
	return new NiAutoNormalParticles;
}

IBlock * CreateNiAutoNormalParticlesData() {
	return new NiAutoNormalParticlesData;
}

IBlock * CreateNiBillboardNode() {
	return new NiBillboardNode;
}

IBlock * CreateNiBinaryExtraData() {
	return new NiBinaryExtraData;
}

IBlock * CreateNiBoneLODController() {
	return new NiBoneLODController;
}

IBlock * CreateNiBoolData() {
	return new NiBoolData;
}

IBlock * CreateNiBooleanExtraData() {
	return new NiBooleanExtraData;
}

IBlock * CreateNiBoolInterpolator() {
	return new NiBoolInterpolator;
}

IBlock * CreateNiBSAnimationNode() {
	return new NiBSAnimationNode;
}

IBlock * CreateNiBSPArrayController() {
	return new NiBSPArrayController;
}

IBlock * CreateNiBSParticleNode() {
	return new NiBSParticleNode;
}

IBlock * CreateNiBSplineBasisData() {
	return new NiBSplineBasisData;
}

IBlock * CreateNiBSplineCompFloatInterpolator() {
	return new NiBSplineCompFloatInterpolator;
}

IBlock * CreateNiBSplineCompPoint3Interpolator() {
	return new NiBSplineCompPoint3Interpolator;
}

IBlock * CreateNiBSplineCompTransformInterpolator() {
	return new NiBSplineCompTransformInterpolator;
}

IBlock * CreateNiBSplineData() {
	return new NiBSplineData;
}

IBlock * CreateNiCamera() {
	return new NiCamera;
}

IBlock * CreateNiCollisionData() {
	return new NiCollisionData;
}

IBlock * CreateNiColorData() {
	return new NiColorData;
}

IBlock * CreateNiColorExtraData() {
	return new NiColorExtraData;
}

IBlock * CreateNiControllerSequence() {
	return new NiControllerSequence;
}

IBlock * CreateNiDirectionalLight() {
	return new NiDirectionalLight;
}

IBlock * CreateNiDitherProperty() {
	return new NiDitherProperty;
}

IBlock * CreateNiFlipController() {
	return new NiFlipController;
}

IBlock * CreateNiFloatData() {
	return new NiFloatData;
}

IBlock * CreateNiFloatExtraData() {
	return new NiFloatExtraData;
}

IBlock * CreateNiFloatExtraDataController() {
	return new NiFloatExtraDataController;
}

IBlock * CreateNiFloatInterpolator() {
	return new NiFloatInterpolator;
}

IBlock * CreateNiFloatsExtraData() {
	return new NiFloatsExtraData;
}

IBlock * CreateNiFogProperty() {
	return new NiFogProperty;
}

IBlock * CreateNiGeomMorpherController() {
	return new NiGeomMorpherController;
}

IBlock * CreateNiGravity() {
	return new NiGravity;
}

IBlock * CreateNiIntegerExtraData() {
	return new NiIntegerExtraData;
}

IBlock * CreateNiIntegersExtraData() {
	return new NiIntegersExtraData;
}

IBlock * CreateNiKeyframeController() {
	return new NiKeyframeController;
}

IBlock * CreateNiKeyframeData() {
	return new NiKeyframeData;
}

IBlock * CreateNiLightColorController() {
	return new NiLightColorController;
}

IBlock * CreateNiLightDimmerController() {
	return new NiLightDimmerController;
}

IBlock * CreateNiLODNode() {
	return new NiLODNode;
}

IBlock * CreateNiLookAtController() {
	return new NiLookAtController;
}

IBlock * CreateNiLookAtInterpolator() {
	return new NiLookAtInterpolator;
}

IBlock * CreateNiMaterialColorController() {
	return new NiMaterialColorController;
}

IBlock * CreateNiMaterialProperty() {
	return new NiMaterialProperty;
}

IBlock * CreateNiMeshParticleSystem() {
	return new NiMeshParticleSystem;
}

IBlock * CreateNiMeshPSysData() {
	return new NiMeshPSysData;
}

IBlock * CreateNiMorphData() {
	return new NiMorphData;
}

IBlock * CreateNiMultiTargetTransformController() {
	return new NiMultiTargetTransformController;
}

IBlock * CreateNiNode() {
	return new NiNode;
}

IBlock * CreateNiPalette() {
	return new NiPalette;
}

IBlock * CreateNiParticleBomb() {
	return new NiParticleBomb;
}

IBlock * CreateNiParticleColorModifier() {
	return new NiParticleColorModifier;
}

IBlock * CreateNiParticleGrowFade() {
	return new NiParticleGrowFade;
}

IBlock * CreateNiParticleMeshes() {
	return new NiParticleMeshes;
}

IBlock * CreateNiParticleMeshesData() {
	return new NiParticleMeshesData;
}

IBlock * CreateNiParticleMeshModifier() {
	return new NiParticleMeshModifier;
}

IBlock * CreateNiParticleRotation() {
	return new NiParticleRotation;
}

IBlock * CreateNiParticles() {
	return new NiParticles;
}

IBlock * CreateNiParticlesData() {
	return new NiParticlesData;
}

IBlock * CreateNiParticleSystem() {
	return new NiParticleSystem;
}

IBlock * CreateNiParticleSystemController() {
	return new NiParticleSystemController;
}

IBlock * CreateNiPathController() {
	return new NiPathController;
}

IBlock * CreateNiPixelData() {
	return new NiPixelData;
}

IBlock * CreateNiPlanarCollider() {
	return new NiPlanarCollider;
}

IBlock * CreateNiPoint3Interpolator() {
	return new NiPoint3Interpolator;
}

IBlock * CreateNiPointLight() {
	return new NiPointLight;
}

IBlock * CreateNiPosData() {
	return new NiPosData;
}

IBlock * CreateNiPSysAgeDeathModifier() {
	return new NiPSysAgeDeathModifier;
}

IBlock * CreateNiPSysBoundUpdateModifier() {
	return new NiPSysBoundUpdateModifier;
}

IBlock * CreateNiPSysBoxEmitter() {
	return new NiPSysBoxEmitter;
}

IBlock * CreateNiPSysColliderManager() {
	return new NiPSysColliderManager;
}

IBlock * CreateNiPSysColorModifier() {
	return new NiPSysColorModifier;
}

IBlock * CreateNiPSysCylinderEmitter() {
	return new NiPSysCylinderEmitter;
}

IBlock * CreateNiPSysData() {
	return new NiPSysData;
}

IBlock * CreateNiPSysEmitterCtlr() {
	return new NiPSysEmitterCtlr;
}

IBlock * CreateNiPSysEmitterCtlrData() {
	return new NiPSysEmitterCtlrData;
}

IBlock * CreateNiPSysEmitterDeclinationVarCtlr() {
	return new NiPSysEmitterDeclinationVarCtlr;
}

IBlock * CreateNiPSysEmitterInitialRadiusCtlr() {
	return new NiPSysEmitterInitialRadiusCtlr;
}

IBlock * CreateNiPSysGravityModifier() {
	return new NiPSysGravityModifier;
}

IBlock * CreateNiPSysGrowFadeModifier() {
	return new NiPSysGrowFadeModifier;
}

IBlock * CreateNiPSysMeshUpdateModifier() {
	return new NiPSysMeshUpdateModifier;
}

IBlock * CreateNiPSysPlanarCollider() {
	return new NiPSysPlanarCollider;
}

IBlock * CreateNiPSysPositionModifier() {
	return new NiPSysPositionModifier;
}

IBlock * CreateNiPSysResetOnLoopCtlr() {
	return new NiPSysResetOnLoopCtlr;
}

IBlock * CreateNiPSysRotationModifier() {
	return new NiPSysRotationModifier;
}

IBlock * CreateNiPSysSpawnModifier() {
	return new NiPSysSpawnModifier;
}

IBlock * CreateNiPSysSphereEmitter() {
	return new NiPSysSphereEmitter;
}

IBlock * CreateNiPSysUpdateCtlr() {
	return new NiPSysUpdateCtlr;
}

IBlock * CreateNiRangeLODData() {
	return new NiRangeLODData;
}

IBlock * CreateNiRotatingParticles() {
	return new NiRotatingParticles;
}

IBlock * CreateNiRotatingParticlesData() {
	return new NiRotatingParticlesData;
}

IBlock * CreateNiScreenLODData() {
	return new NiScreenLODData;
}

IBlock * CreateNiSequenceStreamHelper() {
	return new NiSequenceStreamHelper;
}

IBlock * CreateNiShadeProperty() {
	return new NiShadeProperty;
}

IBlock * CreateNiSkinData() {
	return new NiSkinData;
}

IBlock * CreateNiSkinInstance() {
	return new NiSkinInstance;
}

IBlock * CreateNiSkinPartition() {
	return new NiSkinPartition;
}

IBlock * CreateNiSourceTexture() {
	return new NiSourceTexture;
}

IBlock * CreateNiSpecularProperty() {
	return new NiSpecularProperty;
}

IBlock * CreateNiSphericalCollider() {
	return new NiSphericalCollider;
}

IBlock * CreateNiSpotLight() {
	return new NiSpotLight;
}

IBlock * CreateNiStencilProperty() {
	return new NiStencilProperty;
}

IBlock * CreateNiStringExtraData() {
	return new NiStringExtraData;
}

IBlock * CreateNiStringPalette() {
	return new NiStringPalette;
}

IBlock * CreateNiStringsExtraData() {
	return new NiStringsExtraData;
}

IBlock * CreateNiTextKeyExtraData() {
	return new NiTextKeyExtraData;
}

IBlock * CreateNiTextureEffect() {
	return new NiTextureEffect;
}

IBlock * CreateNiTextureTransformController() {
	return new NiTextureTransformController;
}

IBlock * CreateNiTexturingProperty() {
	return new NiTexturingProperty;
}

IBlock * CreateNiTransformController() {
	return new NiTransformController;
}

IBlock * CreateNiTransformData() {
	return new NiTransformData;
}

IBlock * CreateNiTransformInterpolator() {
	return new NiTransformInterpolator;
}

IBlock * CreateNiTriShape() {
	return new NiTriShape;
}

IBlock * CreateNiTriShapeData() {
	return new NiTriShapeData;
}

IBlock * CreateNiTriStrips() {
	return new NiTriStrips;
}

IBlock * CreateNiTriStripsData() {
	return new NiTriStripsData;
}

IBlock * CreateNiUVController() {
	return new NiUVController;
}

IBlock * CreateNiUVData() {
	return new NiUVData;
}

IBlock * CreateNiVectorExtraData() {
	return new NiVectorExtraData;
}

IBlock * CreateNiVertexColorProperty() {
	return new NiVertexColorProperty;
}

IBlock * CreateNiVertWeightsExtraData() {
	return new NiVertWeightsExtraData;
}

IBlock * CreateNiVisController() {
	return new NiVisController;
}

IBlock * CreateNiVisData() {
	return new NiVisData;
}

IBlock * CreateNiWireframeProperty() {
	return new NiWireframeProperty;
}

IBlock * CreateNiZBufferProperty() {
	return new NiZBufferProperty;
}

IBlock * CreateRootCollisionNode() {
	return new RootCollisionNode;
}

//This function registers the factory functions with global_block_map which is used by CreateBlock
void RegisterBlockFactories () {
	global_block_map["AvoidNode"] = CreateAvoidNode;
	global_block_map["FxButton"] = CreateFxButton;
	global_block_map["FxRadioButton"] = CreateFxRadioButton;
	global_block_map["FxWidget"] = CreateFxWidget;
	global_block_map["NiAlphaController"] = CreateNiAlphaController;
	global_block_map["NiAlphaProperty"] = CreateNiAlphaProperty;
	global_block_map["NiAmbientLight"] = CreateNiAmbientLight;
	global_block_map["NiAutoNormalParticles"] = CreateNiAutoNormalParticles;
	global_block_map["NiAutoNormalParticlesData"] = CreateNiAutoNormalParticlesData;
	global_block_map["NiBillboardNode"] = CreateNiBillboardNode;
	global_block_map["NiBinaryExtraData"] = CreateNiBinaryExtraData;
	global_block_map["NiBoneLODController"] = CreateNiBoneLODController;
	global_block_map["NiBoolData"] = CreateNiBoolData;
	global_block_map["NiBooleanExtraData"] = CreateNiBooleanExtraData;
	global_block_map["NiBoolInterpolator"] = CreateNiBoolInterpolator;
	global_block_map["NiBSAnimationNode"] = CreateNiBSAnimationNode;
	global_block_map["NiBSPArrayController"] = CreateNiBSPArrayController;
	global_block_map["NiBSParticleNode"] = CreateNiBSParticleNode;
	global_block_map["NiBSplineBasisData"] = CreateNiBSplineBasisData;
	global_block_map["NiBSplineCompFloatInterpolator"] = CreateNiBSplineCompFloatInterpolator;
	global_block_map["NiBSplineCompPoint3Interpolator"] = CreateNiBSplineCompPoint3Interpolator;
	global_block_map["NiBSplineCompTransformInterpolator"] = CreateNiBSplineCompTransformInterpolator;
	global_block_map["NiBSplineData"] = CreateNiBSplineData;
	global_block_map["NiCamera"] = CreateNiCamera;
	global_block_map["NiCollisionData"] = CreateNiCollisionData;
	global_block_map["NiColorData"] = CreateNiColorData;
	global_block_map["NiColorExtraData"] = CreateNiColorExtraData;
	global_block_map["NiControllerSequence"] = CreateNiControllerSequence;
	global_block_map["NiDirectionalLight"] = CreateNiDirectionalLight;
	global_block_map["NiDitherProperty"] = CreateNiDitherProperty;
	global_block_map["NiFlipController"] = CreateNiFlipController;
	global_block_map["NiFloatData"] = CreateNiFloatData;
	global_block_map["NiFloatExtraData"] = CreateNiFloatExtraData;
	global_block_map["NiFloatExtraDataController"] = CreateNiFloatExtraDataController;
	global_block_map["NiFloatInterpolator"] = CreateNiFloatInterpolator;
	global_block_map["NiFloatsExtraData"] = CreateNiFloatsExtraData;
	global_block_map["NiFogProperty"] = CreateNiFogProperty;
	global_block_map["NiGeomMorpherController"] = CreateNiGeomMorpherController;
	global_block_map["NiGravity"] = CreateNiGravity;
	global_block_map["NiIntegerExtraData"] = CreateNiIntegerExtraData;
	global_block_map["NiIntegersExtraData"] = CreateNiIntegersExtraData;
	global_block_map["NiKeyframeController"] = CreateNiKeyframeController;
	global_block_map["NiKeyframeData"] = CreateNiKeyframeData;
	global_block_map["NiLightColorController"] = CreateNiLightColorController;
	global_block_map["NiLightDimmerController"] = CreateNiLightDimmerController;
	global_block_map["NiLODNode"] = CreateNiLODNode;
	global_block_map["NiLookAtController"] = CreateNiLookAtController;
	global_block_map["NiLookAtInterpolator"] = CreateNiLookAtInterpolator;
	global_block_map["NiMaterialColorController"] = CreateNiMaterialColorController;
	global_block_map["NiMaterialProperty"] = CreateNiMaterialProperty;
	global_block_map["NiMeshParticleSystem"] = CreateNiMeshParticleSystem;
	global_block_map["NiMeshPSysData"] = CreateNiMeshPSysData;
	global_block_map["NiMorphData"] = CreateNiMorphData;
	global_block_map["NiMultiTargetTransformController"] = CreateNiMultiTargetTransformController;
	global_block_map["NiNode"] = CreateNiNode;
	global_block_map["NiPalette"] = CreateNiPalette;
	global_block_map["NiParticleBomb"] = CreateNiParticleBomb;
	global_block_map["NiParticleColorModifier"] = CreateNiParticleColorModifier;
	global_block_map["NiParticleGrowFade"] = CreateNiParticleGrowFade;
	global_block_map["NiParticleMeshes"] = CreateNiParticleMeshes;
	global_block_map["NiParticleMeshesData"] = CreateNiParticleMeshesData;
	global_block_map["NiParticleMeshModifier"] = CreateNiParticleMeshModifier;
	global_block_map["NiParticleRotation"] = CreateNiParticleRotation;
	global_block_map["NiParticles"] = CreateNiParticles;
	global_block_map["NiParticlesData"] = CreateNiParticlesData;
	global_block_map["NiParticleSystem"] = CreateNiParticleSystem;
	global_block_map["NiParticleSystemController"] = CreateNiParticleSystemController;
	global_block_map["NiPathController"] = CreateNiPathController;
	global_block_map["NiPixelData"] = CreateNiPixelData;
	global_block_map["NiPlanarCollider"] = CreateNiPlanarCollider;
	global_block_map["NiPoint3Interpolator"] = CreateNiPoint3Interpolator;
	global_block_map["NiPointLight"] = CreateNiPointLight;
	global_block_map["NiPosData"] = CreateNiPosData;
	global_block_map["NiPSysAgeDeathModifier"] = CreateNiPSysAgeDeathModifier;
	global_block_map["NiPSysBoundUpdateModifier"] = CreateNiPSysBoundUpdateModifier;
	global_block_map["NiPSysBoxEmitter"] = CreateNiPSysBoxEmitter;
	global_block_map["NiPSysColliderManager"] = CreateNiPSysColliderManager;
	global_block_map["NiPSysColorModifier"] = CreateNiPSysColorModifier;
	global_block_map["NiPSysCylinderEmitter"] = CreateNiPSysCylinderEmitter;
	global_block_map["NiPSysData"] = CreateNiPSysData;
	global_block_map["NiPSysEmitterCtlr"] = CreateNiPSysEmitterCtlr;
	global_block_map["NiPSysEmitterCtlrData"] = CreateNiPSysEmitterCtlrData;
	global_block_map["NiPSysEmitterDeclinationVarCtlr"] = CreateNiPSysEmitterDeclinationVarCtlr;
	global_block_map["NiPSysEmitterInitialRadiusCtlr"] = CreateNiPSysEmitterInitialRadiusCtlr;
	global_block_map["NiPSysGravityModifier"] = CreateNiPSysGravityModifier;
	global_block_map["NiPSysGrowFadeModifier"] = CreateNiPSysGrowFadeModifier;
	global_block_map["NiPSysMeshUpdateModifier"] = CreateNiPSysMeshUpdateModifier;
	global_block_map["NiPSysPlanarCollider"] = CreateNiPSysPlanarCollider;
	global_block_map["NiPSysPositionModifier"] = CreateNiPSysPositionModifier;
	global_block_map["NiPSysResetOnLoopCtlr"] = CreateNiPSysResetOnLoopCtlr;
	global_block_map["NiPSysRotationModifier"] = CreateNiPSysRotationModifier;
	global_block_map["NiPSysSpawnModifier"] = CreateNiPSysSpawnModifier;
	global_block_map["NiPSysSphereEmitter"] = CreateNiPSysSphereEmitter;
	global_block_map["NiPSysUpdateCtlr"] = CreateNiPSysUpdateCtlr;
	global_block_map["NiRangeLODData"] = CreateNiRangeLODData;
	global_block_map["NiRotatingParticles"] = CreateNiRotatingParticles;
	global_block_map["NiRotatingParticlesData"] = CreateNiRotatingParticlesData;
	global_block_map["NiScreenLODData"] = CreateNiScreenLODData;
	global_block_map["NiSequenceStreamHelper"] = CreateNiSequenceStreamHelper;
	global_block_map["NiShadeProperty"] = CreateNiShadeProperty;
	global_block_map["NiSkinData"] = CreateNiSkinData;
	global_block_map["NiSkinInstance"] = CreateNiSkinInstance;
	global_block_map["NiSkinPartition"] = CreateNiSkinPartition;
	global_block_map["NiSourceTexture"] = CreateNiSourceTexture;
	global_block_map["NiSpecularProperty"] = CreateNiSpecularProperty;
	global_block_map["NiSphericalCollider"] = CreateNiSphericalCollider;
	global_block_map["NiSpotLight"] = CreateNiSpotLight;
	global_block_map["NiStencilProperty"] = CreateNiStencilProperty;
	global_block_map["NiStringExtraData"] = CreateNiStringExtraData;
	global_block_map["NiStringPalette"] = CreateNiStringPalette;
	global_block_map["NiStringsExtraData"] = CreateNiStringsExtraData;
	global_block_map["NiTextKeyExtraData"] = CreateNiTextKeyExtraData;
	global_block_map["NiTextureEffect"] = CreateNiTextureEffect;
	global_block_map["NiTextureTransformController"] = CreateNiTextureTransformController;
	global_block_map["NiTexturingProperty"] = CreateNiTexturingProperty;
	global_block_map["NiTransformController"] = CreateNiTransformController;
	global_block_map["NiTransformData"] = CreateNiTransformData;
	global_block_map["NiTransformInterpolator"] = CreateNiTransformInterpolator;
	global_block_map["NiTriShape"] = CreateNiTriShape;
	global_block_map["NiTriShapeData"] = CreateNiTriShapeData;
	global_block_map["NiTriStrips"] = CreateNiTriStrips;
	global_block_map["NiTriStripsData"] = CreateNiTriStripsData;
	global_block_map["NiUVController"] = CreateNiUVController;
	global_block_map["NiUVData"] = CreateNiUVData;
	global_block_map["NiVectorExtraData"] = CreateNiVectorExtraData;
	global_block_map["NiVertexColorProperty"] = CreateNiVertexColorProperty;
	global_block_map["NiVertWeightsExtraData"] = CreateNiVertWeightsExtraData;
	global_block_map["NiVisController"] = CreateNiVisController;
	global_block_map["NiVisData"] = CreateNiVisData;
	global_block_map["NiWireframeProperty"] = CreateNiWireframeProperty;
	global_block_map["NiZBufferProperty"] = CreateNiZBufferProperty;
	global_block_map["RootCollisionNode"] = CreateRootCollisionNode;
}