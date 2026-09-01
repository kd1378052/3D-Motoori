#pragma once

#include "../CharacterBase.h"
#include"../../Camera/CameraBase.h"

class Player : public CharacterBase
{
public:
	Player()						{}
	~Player()			override	{}

	void Init()			override;
	void Update()		override;

private:
	std::weak_ptr<CameraBase> m_wpCamera;

};