#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;

private:
	int level;
	int hp, hpmax;
	short sector;

private:
	sf::Sprite m_HPBar;
	sf::Sprite m_UIHP;
	sf::Sprite m_PlayerUI;
	sf::Sprite m_PlayerEmptyHP;

private:
	sf::Text m_name;
	sf::Text m_level;
};

