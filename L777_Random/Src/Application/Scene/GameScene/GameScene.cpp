#include "GameScene.h"
#include"../SceneManager.h"

#include "../../GameObject/Stage/Stage01/Stage01.h"
#include "../../GameObject/Character/Player/Player.h"
#include "../../GameObject/Stage/Stage01/Water/Water.h"

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

	//水
	std::shared_ptr<Water> _water = std::make_shared<Water>();
	_water->Init();
	AddObject(_water);

	//===================================================================
	// キャラクター初期化
	//===================================================================
	std::shared_ptr<Player> _player = std::make_shared<Player>();
	_player->Init();
	_player->RegistHitObject(_stage01);
	AddObject(_player);

	
	//===================================================================
	// カメラ初期化
	//===================================================================
	m_Camera = std::make_unique<TPSCamera>();
	m_Camera->Init();
	m_Camera->SetTarget(_player);
	AddObject(m_Camera);

	// プレイヤーにカメラ情報をセット
	_player->SetCamera(m_Camera);

	//===================================================================
	// ランダム授業
	//===================================================================
	int randRes[10] = {};

	//抽選処理
	
	//以下にrand()が偏るか
	/*
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100000000;i++)
	{
		int _tmp = rand() % 10000;
		int _idx = _tmp / 1000;

		randRes[_idx]++;
	}

	// 結果を出力
	OutputDebugStringA("------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		std::stringstream ss;
		ss << "取得した値が" << i * 1000 << "～" << (i + 1) * 1000 <<
			"の件数 : \t" << randRes[i] << " \n";
		std::string str = ss.str();
		OutputDebugStringA(str.c_str());
	}
	OutputDebugStringA("------------------------------\n");
	*/

	//メルセンヌツイスタ
	/*
	for (int i = 0; i < 100000000; i++)
	{
		int _tmp =	KdRandom::GetInt(0,9999);
		int _idx = _tmp / 1000;

		randRes[_idx]++;
	}

	// 結果を出力
	OutputDebugStringA("------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		std::stringstream ss;
		ss << "取得した値が" << i * 1000 << "～" << (i + 1) * 1000 <<
			"の件数 : \t" << randRes[i] << " \n";
		std::string str = ss.str();
		OutputDebugStringA(str.c_str());
	}
	OutputDebugStringA("------------------------------\n");
	*/

	//レッスンその1*******************************
	//cカードとrカードをそれぞれ50％の確率で抽選し、表示せよ
	// レッスンその１：CカードとRカードをそれぞれ50%の確率で抽選し、表示せよ！
	//int _ThusenNum = 100000000;
	//int _TosenNum[2] = {};

	//for (int i = 0; i < _ThusenNum; i++)
	//{
	//	int _tmp = KdRandom::GetInt(0, 1);

	//	_TosenNum[_tmp]++;
	//}

	//OutputDebugStringA("----------------------------------------------------\n");
	//float _prob = 0; //パーセント
	//for (int i = 0; i < 2; i++)
	//{
	//	std::stringstream ss;
	//	_prob = ((float)_TosenNum[i] / (float)_ThusenNum) * 100;
	//	switch (i)
	//	{
	//	case 0:
	//		ss << "Cカード当選回数 = " << _TosenNum[0] << " " <<
	//			"当選確率 = " << _prob << "%" << "\n";
	//		break;
	//	case 1:
	//		ss << "Rカード当選回数 = " << _TosenNum[1] << " " <<
	//			"当選確率 = " << _prob << "%" << "\n";
	//		break;
	//	}
	//	std::string str = ss.str();
	//	OutputDebugStringA(str.c_str());
	//}
	//OutputDebugStringA("----------------------------------------------------\n");
	//*******************************

	// レッスンその２：CカードとRカードをそれぞれ99.5%(Cカード) 0.5%(Rカード)の確率で抽選し、表示せよ！
	//int _ThusenNum = 100000000;//試行回数

	//int _bunbo = 1000;//袋に入っている球弾の数
	//int _randNum[2] = { 995,5 };//袋に入っているそれぞれの球の個数
	//int _TosenNum[2] = {};

	//for (int i = 0; i < _ThusenNum; i++)
	//{
	//	int _tmp = KdRandom::GetInt(0, _bunbo-1);
	//	if (_tmp <= 995)_TosenNum[0]++;
	//	if (_tmp >= 995)_TosenNum[1]++;
	//}

	////float _comonParsent = 99.5f;

	////for (int a = 0; a < _ThusenNum; a++)
	////{
	////	int randomnum = KdRandom::GetInt(1, 100);
	////	if (randomnum < (float)_comonParsent)
	////	{
	////		_TosenNum[0]++;
	////	}
	////	else if (randomnum < (float)_comonParsent)
	////	{
	////		_TosenNum[1]++;

	////	}
	////}

	//OutputDebugStringA("----------------------------------------------------\n");
	//float _prob = 0; //パーセント
	//for (int i = 0; i < 2; i++)
	//{
	//	std::stringstream ss;
	//	_prob = ((float)_TosenNum[i] / (float)_ThusenNum) * 100;
	//	switch (i)
	//	{
	//	case 0:
	//		ss << "Cカード当選回数 = " << _TosenNum[0] << " " <<
	//			"当選確率 = " << _prob << "%" << "\n";
	//		break;
	//	case 1:
	//		ss << "Rカード当選回数 = " << _TosenNum[1] << " " <<
	//			"当選確率 = " << _prob << "%" << "\n";
	//		break;
	//	}
	//	std::string str = ss.str();
	//	OutputDebugStringA(str.c_str());
	//}
	//OutputDebugStringA("----------------------------------------------------\n");


// レッスンその３：CカードとRカードとSRカードをそれぞれ34%(Cカード) 33%(Rカード) 33%(SRカード)の確率で抽選し、表示せよ！
//int _ThusenNum = 100000000;//試行回数
//
//int _bunbo = 100;//袋に入っている球弾の数
//int _randNum[3] = { 34,33,33 };//袋に入っているそれぞれの球の個数
//int _TosenNum[3] = {};
//
////自分流
////for (int i = 0; i < _ThusenNum; i++)
////{
////	int _tmp = KdRandom::GetInt(0, _bunbo - 1);
////	if (_tmp <= 34)_TosenNum[0]++;
////	if (_tmp >= 34)
////	{
////		int _tmp = KdRandom::GetInt(1, 2);
////		_TosenNum[_tmp]++;
////	}
////}
//
//for (int i = 0; i < _ThusenNum; i++)
//{
//	//ここ大事　すごく便利
//	//抽選処理の極意
//	int _rnd = KdRandom::GetInt(0, _bunbo - 1);
//	for (int j = 0;j < std::size(_randNum) ; j++)
//	{
//		_rnd -= _randNum[j];
//		if (_rnd < 0)
//		{
//			_TosenNum[j]++;
//			break;
//		}
//	}
//}
//
//OutputDebugStringA("----------------------------------------------------\n");
//float _prob = 0; //パーセント
//for (int i = 0; i < 3; i++)
//{
//	std::stringstream ss;
//	_prob = ((float)_TosenNum[i] / (float)_ThusenNum) * 100;
//	switch (i)
//	{
//	case 0:
//		ss << "Cカード当選回数 = " << _TosenNum[0] << " " <<
//			"当選確率 = " << _prob << "%" << "\n";
//		break;
//	case 1:
//		ss << "Rカード当選回数 = " << _TosenNum[1] << " " <<
//			"当選確率 = " << _prob << "%" << "\n";
//		break;
//	case 2:
//		ss << "SRカード当選回数 = " << _TosenNum[2] << " " <<
//			"当選確率 = " << _prob << "%" << "\n";
//		break;
//	}
//	std::string str = ss.str();
//	OutputDebugStringA(str.c_str());
//}
//OutputDebugStringA("----------------------------------------------------\n");


// レッスンその4：CカードとRカードとSRカードをそれぞれ34%(Cカード) 33%(Rカード) 33%(SRカード)の確率で抽選し、表示せよ！
int _ThusenNum = 100000000;//試行回数

int _bunbo = 1000;//袋に入っている球弾の数
int _randNum[3] = { 500,495,5 };//袋に入っているそれぞれの球の個数
int _TosenNum[3] = {};

for (int i = 0; i < _ThusenNum; i++)
{
	//ここ大事　すごく便利
	//抽選処理の極意
	int _rnd = KdRandom::GetInt(0, _bunbo - 1);
	for (int j = 0; j < std::size(_randNum); j++)
	{
		_rnd -= _randNum[j];
		if (_rnd < 0)
		{
			_TosenNum[j]++;
			break;
		}
	}
}

OutputDebugStringA("----------------------------------------------------\n");
float _prob = 0; //パーセント
for (int i = 0; i < 3; i++)
{
	std::stringstream ss;
	_prob = ((float)_TosenNum[i] / (float)_ThusenNum) * 100;
	switch (i)
	{
	case 0:
		ss << "Cカード当選回数 = " << _TosenNum[0] << " " <<
			"当選確率 = " << _prob << "%" << "\n";
		break;
	case 1:
		ss << "Rカード当選回数 = " << _TosenNum[1] << " " <<
			"当選確率 = " << _prob << "%" << "\n";
		break;
	case 2:
		ss << "SRカード当選回数 = " << _TosenNum[2] << " " <<
			"当選確率 = " << _prob << "%" << "\n";
		break;
	}
	std::string str = ss.str();
	OutputDebugStringA(str.c_str());
}
OutputDebugStringA("----------------------------------------------------\n");


}
