#pragma once
#include "GameObject.h"
class PlayerAttack : public GameObject
{
public:
	// GameObject을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;
};

