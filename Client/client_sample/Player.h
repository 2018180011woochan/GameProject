#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;

private:
	vector<int> party_list;
	char my_name[NAME_SIZE];

};

