#include "GameScene.h"
#include"../SceneManager.h"

#include "../../GameObject/Stage/Stage01/Stage01.h"
#include "../../GameObject/Character/Player/Player.h"
#include "../../GameObject/Stage/Stage01/Water/Water.h"
#include "../../GameObject/Character/Weapon/Tanto/Tanto.h"
#include "../../GameObject/Character/Enemy/Enemy.h"

#include "../../GameObject/Camera/TPSCamera/TPSCamera.h"

void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}
}

void GameScene::Init()
{
	//===================================================================
	// ステージ初期化
	//===================================================================
	std::shared_ptr<Stage01> _stage01 = std::make_shared<Stage01>();
	_stage01->Init();
	AddObject(_stage01);

	////水
	//std::shared_ptr<Water> _water = std::make_shared<Water>();
	//_water->Init();
	//AddObject(_water);
	
	//===================================================================
	// キャラクター初期化
	//===================================================================
	std::shared_ptr<Player> _player = std::make_shared<Player>();
	_player->Init();
	_player->RegistHitObject(_stage01);
	AddObject(_player);

	////敵
	//std::shared_ptr<Enemy> _enemy;
	//for (int i = 0; i < 300; i++)
	//{
	//	_enemy = std::make_shared<Enemy>();
	//	_enemy->Init();
	//	int _x = 5 - (i % 10);
	//	int _z = (i / 10) * 2.0f;
	//	_enemy->SetPos({ (float)_x , (float)0 , (float)_z });
	//	AddObject(_enemy);
	//}

	//短刀
	std::shared_ptr<Tanto> _tanto = std::make_shared<Tanto>();
	_tanto->Init();
	//あなたが私の持ち主です　宣言
	_tanto->SetOwner(_player);
	AddObject(_tanto);

	//===================================================================
	// カメラ初期化
	//===================================================================
	m_Camera = std::make_unique<TPSCamera>();
	m_Camera->Init();
	m_Camera->SetTarget(_player);
	AddObject(m_Camera);

	//敵
	for (int i = 0; i < 300; i++)
	{
		std::shared_ptr<Enemy> _enemy = std::make_shared<Enemy>();
		_enemy->Init();
		int _x = 5 - (i % 10);
		int _z = (i / 10) * 2.0f;
		_enemy->SetPos({ (float)_x , (float)0 , (float)_z });
		_enemy->SetCamera(m_Camera);
		AddObject(_enemy);
	}

	// プレイヤーにカメラ情報をセット
	_player->SetCamera(m_Camera);
	//_enemy->SetCamera(m_Camera);

}
