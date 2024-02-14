#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
public:
	Monster(sf::Texture& t, int x, int y, int x2, int y2, sf::Texture& hpbar, int tx, int ty, int tx2, int ty2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		m_HPBar.setTexture(hpbar);
		m_HPBar.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		set_name("NONAME", false);
		set_level(0);
	}

public:
	// GameObject을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;

public:
	void set_info(int _id, int _level, int _hp, int _hpmax, int _x, int _y, int _sector);
	void draw_hp(bool isParty);

	void set_name(const char str[], bool _ui);

	void set_level(const char level[]);
	void set_nameColor(NameColor _color);
	
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

