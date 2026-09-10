#include "Water.h"

void Water::Init()
{
	if (!m_spModel)
	{
		m_spModel = std::make_shared<KdModelData>();
		m_spModel->Load("Asset/Data/LessonData/Stage/Water/Water.gltf");


	}

	SetPos({ 0, 0.5f, 0 });

}

void Water::Update()
{
	m_UVOffset.x += 0.001f;
	m_UVOffset.y += 0.001f;
}

void Water::DrawTranceParent()
{
	if (!m_spModel) return;

	KdShaderManager::Instance().m_StandardShader.SetUVOffset(m_UVOffset);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spModel,m_mWorld);
}

