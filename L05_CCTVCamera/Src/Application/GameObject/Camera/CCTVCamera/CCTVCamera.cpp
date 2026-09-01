#include "CCTVCamera.h"

void CCTVCamera::Init()
{
	// 親クラスの初期化呼び出し
	CameraBase::Init();

	// 注視点
	m_mLocalPos = Math::Matrix::CreateTranslation(0, 6.0f, -10.0f);
}

void CCTVCamera::PostUpdate()
{
	// ハムスターを「常に」捕らえ続けるカメラ挙動を実装せよ！
	Math::Matrix _targetMat = Math::Matrix::Identity;
	std::shared_ptr<KdGameObject> _spTarget = m_wpTarget.lock();
	if (_spTarget)
	{
		_targetMat = _spTarget->GetMatrix();
	}

	UpdateLookAtRotate(_targetMat.Translation());
}

void CCTVCamera::UpdateLookAtRotate(const Math::Vector3& targetPos)
{
	// 実装方法①　自力ですごい頑張る処理
// 自分の向いている「前」方向ベクトル
// 正しいのはForwardだけどシステム上Backwardが正しい
	//Math::Vector3 _nowDir = GetMatrix().Backward();

	//// ターゲット（ハムスター）への方向ベクトル
	//Math::Vector3 _targetDir = targetPos - GetPos();

	//// XM平面上での方向ベクトルとする
	//_nowDir.y = 0;
	//_nowDir.Normalize();
	//_targetDir.y = 0;
	//_targetDir.Normalize();

	//// ①今向いている方向の「ワールド角度」を求める
	//float _nowAng = atan2(_nowDir.x, _nowDir.z);
	//_nowAng = DirectX::XMConvertToDegrees(_nowAng);

	//// ②ターゲットへ向く「ワールド角度」を求める
	//float _targetAng = atan2(_targetDir.x, _targetDir.z);
	//_targetAng = DirectX::XMConvertToDegrees(_targetAng);

	//// ①と②の間の角度を求める
	//float _betweenAng = _targetAng - _nowAng;

	//// 180どの位置で角度の数値の切れ目
	//if (_betweenAng > 180)
	//{
	//	_betweenAng -= 360;
	//}
	//else if (_betweenAng < -180)
	//{
	//	_betweenAng += 360;
	//}

	//// 1フレームで最大何度傾くか
	//float _rotateAng = std::clamp(_betweenAng, -1.0f, 1.0f);

	//// カメラの角度の更新
	//Math::Matrix _tmpRotation = Math::Matrix::Identity;
	//m_DegAng.y += _rotateAng;
	//_tmpRotation = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_DegAng.y));

	//Math::Matrix _tmpWorld = _tmpRotation * Math::Matrix::CreateTranslation(GetPos());
	//_tmpWorld = _tmpWorld.Invert();

	//Math::Vector3 _targetLocalPos;
	//_targetLocalPos = Math::Vector3::Transform(targetPos, _tmpWorld);

	//_targetLocalPos.x = 0;
	//float _nowAngY = asin(_targetLocalPos.y / _targetLocalPos.Length());

	//// 最終的な回転行列を生成する
	//m_mRotation = Math::Matrix::CreateRotationX(-_nowAngY) * _tmpRotation;
	//m_mWorld = m_mRotation * m_mLocalPos;
	/*
	Math::Vector3 _targetVec = Math::Vector3::Zero;
	_targetVec = targetPos - GetPos();
	
	// YAW角
	float _yaw = DirectX::XMConvertToDegrees(atan2(_targetVec.x, _targetVec.z));
	// PITCH角
	float _pitch = DirectX::XMConvertToDegrees(
	atan2(_targetVec.y, sqrt(pow(_targetVec.x, 2) + pow(_targetVec.z, 2))));

	//// ②-①(ローカルで回転行列を作って合成するパターン)
	//Math::Matrix _RotationX = Math::Matrix::
	//	CreateRotationX(DirectX::XMConvertToRadians(-_pitch));
	//Math::Matrix _RotationY = Math::Matrix::
	//	CreateRotationY(DirectX::XMConvertToRadians(_yaw));
	//m_mWorld = _RotationX * _RotationY * m_mLocalPos;

	//2_2
	m_DegAng = Math::Vector3::Zero;
	m_DegAng.x = -_pitch;
	m_DegAng.y = _yaw;
	//行列が返ってくる
	m_mWorld = GetRotationMatrix() * m_mLocalPos;
	*/
	// 実装方法③　今までの努力が無に帰す処理
	Math::Vector3 _tmpPos = m_mLocalPos.Translation();
	Math::Matrix _shadowVP =
	//　ルックアット　↓中心する物体を見る
		DirectX::XMMatrixLookAtLH(_tmpPos, targetPos, Math::Vector3::Up);

	m_mWorld = _shadowVP.Invert();


}