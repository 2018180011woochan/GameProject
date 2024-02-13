#pragma once
#include "GameObject.h"
class Player : public GameObject
{
private:
	vector<int> party_list;
	char my_name[NAME_SIZE];
};

