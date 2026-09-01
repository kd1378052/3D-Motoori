#pragma once

#include "../CharacterBase.h"
class CCTVCamera;
class Player : public CharacterBase
{
public:
	Player()						{}
	~Player()			override	{}

	void Init()			override;
	void Update()		override;

	void SetCamera(std::shared_ptr<CCTVCamera> camera)
	{
		m_wpCamera = camera;
	}

private:

	//座標返還に必要なカメラ情報
	std::weak_ptr<CCTVCamera> m_wpCamera;

};