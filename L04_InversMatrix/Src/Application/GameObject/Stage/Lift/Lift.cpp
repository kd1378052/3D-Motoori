#include "Lift.h"

void Lift::Init()
{
	if (!m_spModel)
	{
		m_spModel = std::make_shared<KdModelWork>();
		m_spModel->SetModelData("Asset/Data/LessonData/Stage/Lift/Lift.gltf");

		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("Lift", m_spModel, KdCollider::TypeGround);
	}

	//SetPos({ -12.0f, 1.0f, 1.0f });

	//開始地点と執着地点
	//ここをいじるだけでリフトの移動が変わる　便利ー
	m_StartPos = { -12.0f, 1.0f , 1.0f };
	m_EndPos = { -6.0f, 1.0f , 1.0f };

	m_Speed = 1.0f / (60.0f * 2);

	//m_pos = { -12.0f, 2.0f, 1.0f };
	////座標行列
	//Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	//// 行列合成 (S * R * T)
	//m_mWorld = transMat;
}

void Lift::Update()
{
	//自分流　上下移動
	//// //移動処理
	//Math::Vector3 prevPos = m_pos;
	//// 移動
	//m_pos.y -= m_speed * m_dir;
	//m_goal += m_speed;

	//if (m_goal >= 1.0f)
	//{
	//	m_dir *= -1;
	//	m_goal = 0;
	//}
	//// 移動量を保存
	//m_move = m_pos - prevPos;

	////座標行列
	//Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	//// 行列合成 (S * R * T)
	//m_mWorld = transMat;
	
	//進捗度の制御
	m_Progress += m_Speed * (m_IsReverse * -2 + 1);
	if (m_Progress >= 1.2f)
	{
		m_IsReverse = true;
	}
	else if(m_Progress < -0.2f)
	{
		m_IsReverse = false;
	}
	float _progress = std::clamp(m_Progress, 0.0f, 1.0f);
	Math::Vector3 towrarEndVec = m_EndPos - m_StartPos;

	//進捗度を用いて座標を確定する
	Math::Matrix _trams =
		Math::Matrix::CreateTranslation(m_StartPos + towrarEndVec * EaseInOutSine(_progress));

	m_mWorld = _trams;
}

void Lift::DrawLit()
{
	if (!m_spModel) return;

	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spModel, m_mWorld);
}