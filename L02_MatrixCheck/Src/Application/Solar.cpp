#include "Solar.h"

void Solar::Init()
{
	m_solar = std::make_shared<KdModelData>();
	m_solar->Load("Asset/Planets/sun.gltf");

	Math::Matrix scalMat = Math::Matrix::CreateScale(5, 1, 1);

	//m_mWorld = scalMat;

}


void Solar::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_solar);

}

void Solar::Release()
{
}
