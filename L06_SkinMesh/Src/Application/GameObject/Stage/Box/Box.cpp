#include "Box.h"

void Box::Init()
{
	if (!m_spModel)
	{
		m_spModel = std::make_shared<KdModelWork>();
		m_spModel->SetModelData("Asset/Data/LessonData/Box/TreasureBox.gltf");

		//アニメーターの準備
		m_spAnimator = std::make_shared< KdAnimator>();
		m_spAnimator->SetAnimation(m_spModel->GetAnimation("Open"));
	}
	SetPos({ 0.0f,0.0f,0.0f });
}

void Box::Update()
{
	if (!m_spAnimator)return;
	if (!m_spModel)return;

	m_spAnimator->AdvanceTime(m_spModel->WorkNodes());
	//変更された頂点の更新
	m_spModel->CalcNodeMatrices();
}

void Box::DrawLit()
{
	if (!m_spModel) return;

	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spModel);
}
