#pragma once
#include "GameObject.h"
class PlayerAttack : public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;
};

