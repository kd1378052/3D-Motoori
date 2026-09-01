#include "Player.h"

void Player::Init()
{
	if (!m_spPoly)
	{
		m_spPoly = std::make_shared<KdSquarePolygon>();
		m_spPoly->SetMaterial("Asset/Data/LessonData/Character/Hamu.png");
		m_spPoly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	}

	SetPos({ -12.0f,2.5f, 1.5f });
}

void Player::Update()
{
	//乗り物に乗ているときにPlayerの位置をリフトにしている
	std::shared_ptr<KdGameObject> _spGameObj = m_wpRiddenObject.lock();
	if (_spGameObj)
	{
		//キャラクターの座標をリフトの座標にする
		//　　　　　↓リフトの座標　
		m_mWorld = m_mLocalFromRideObject * _spGameObj->GetMatrix();
	}

	//Characterには重力がかかる
	//これをこのまま書くのは✖
	m_Gravity += 0.01f;
	m_mWorld._42 -= m_Gravity;

	//移動処理

	// 移動処理復活
	float			_moveSpd = 0.05f;
	Math::Vector3	_nowPos = GetPos();

	Math::Vector3	_moveVec = Math::Vector3::Zero;
	if (GetAsyncKeyState('D')) { _moveVec.x = 1.0f; }
	if (GetAsyncKeyState('A')) { _moveVec.x = -1.0f; }
	if (GetAsyncKeyState('W')) { _moveVec.z = 1.0f; }
	if (GetAsyncKeyState('S')) { _moveVec.z = -1.0f; }

	_moveVec.Normalize();
	_moveVec *= _moveSpd;
	_nowPos += _moveVec;

	// キャラクターのワールド行列を創る処理
	m_mWorld = Math::Matrix::CreateTranslation(_nowPos);
	
	//自分流
	//if (GetAsyncKeyState('D')) { m_mWorld._41 += 0.1f; }
	//if (GetAsyncKeyState('A')) { m_mWorld._41 -= 0.1f; }
	//if (GetAsyncKeyState('W')) { m_mWorld._43 += 0.1f; }
	//if (GetAsyncKeyState('S')) { m_mWorld._43 -= 0.1f; }

	if (GetAsyncKeyState(VK_SPACE)) { m_Gravity -= 0.1;}
}
