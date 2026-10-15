#include "Enemy.h"
#include "../../Camera/CameraBase.h"

void Enemy::Init()
{
	if (m_spModelList.empty())
	{
		std::shared_ptr<KdModelWork> _spModel0;
		_spModel0 = std::make_shared<KdModelWork>();
		_spModel0->SetModelData("Asset/Data/LessonData/Character/Robot/woodRobot01.gltf");
		m_spModelList.push_back(_spModel0);

		std::shared_ptr<KdModelWork> _spModel1;
		_spModel1 = std::make_shared<KdModelWork>();
		_spModel1->SetModelData("Asset/Data/LessonData/Character/Robot/woodRobot02.gltf");
		m_spModelList.push_back(_spModel1);


		m_spAnimator = std::make_shared<KdAnimator>();
		m_spAnimator->SetAnimation(_spModel0->GetAnimation("Walk"));

	}
	SetPos({ 0.0f, 0.0f, 0.0f });
	
}

void Enemy::Update()
{
	// カメラの距離によってm_LodIdxの0と1を切り替えろ！ 
	const std::shared_ptr<CameraBase> _spCamera = GetCamera().lock();
	if (_spCamera)
	{
		// ↓カメラと自身の距離を算出
		CalcDistSqrFromCamera(_spCamera->GetPos());
		//float _dist = GetDistSqrFromCamera();
		//if (_dist < 100)
		//{
		//	m_LodIdx = 0;
		//}
		//else
		//{
		//	m_LodIdx = 1;
		//}
		//↓
		m_LodIdx = (GetDistSqrFromCamera() < 100) ? 0 : 1;

	}
}

void Enemy::DrawLit()
{
		if (m_spModelList.empty())return;

		//m_LodIdx = 0 <- 詳細モデルバージョン
		//m_LodIdx = 1 <- 簡易モデルバージョン

		KdShaderManager::Instance().
			m_StandardShader.DrawModel(*m_spModelList[m_LodIdx], m_mWorld);
}
