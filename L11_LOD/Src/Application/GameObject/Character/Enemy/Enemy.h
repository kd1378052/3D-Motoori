#pragma once

#include "../CharacterBase.h"

class Enemy : public CharacterBase
{
public:
	Enemy() {}
	~Enemy()			override {}

	void Init()			override;
	void Update()		override;
	void DrawLit()		override;

protected:


};