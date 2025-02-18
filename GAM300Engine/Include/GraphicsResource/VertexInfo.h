#pragma once
#include "GraphicsResourceDefines.h"
namespace TDS
{

	struct VertexData
	{
		Vec3 m_Pos;
		Vec2 m_UV;
		Vec4 m_fNormal;
		Vec3 m_fTanget;
		Vec3 m_fBitangent;
		iColor m_Tangent;
		iColor m_Bitangent;
		iColor m_Normal;
		iColor m_Color;
	};



}