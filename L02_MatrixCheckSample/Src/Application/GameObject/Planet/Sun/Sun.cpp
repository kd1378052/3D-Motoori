#include "Sun.h"

Sun::Sun()
{
}

Sun::~Sun()
{
	Release();
}

void Sun::Init()
{
	// 親クラスの同処理を呼び出せるよ！
	//上書きされるからここでInit読んでいる
	PlanetBase::Init();

	if (!m_spModel)
	{
		m_spModel = std::make_shared<KdModelData>();
		m_spModel->Load("Asset/Planets/sun.gltf");
	}
}

void Sun::Update()
{
	//*= 自転　回転処理
	//↓Baseクラスが持ってる　メンバー
	m_mRotation *=
		Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(2.0f));
	//スケール行列　入れるほうが良き

	m_mWorld =
		m_mRotation * Math::Matrix::CreateTranslation(0, 0, 8);
}

void Sun::Release()
{
}
