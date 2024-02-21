#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
public:
	Monster() {}
	Monster(sf::Texture& t, int x, int y, int x2, int y2, sf::Texture& hpbar, int tx, int ty, int tx2, int ty2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		m_HPBar.setTexture(hpbar);
		m_HPBar.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		set_name("NONAME", false);
		SetLevelFont(0);
	}
	// after
	Monster(RACE race, int x, int y, int x2, int y2, /*sf::Texture& hpbar,*/ int tx, int ty, int tx2, int ty2) {
		m_showing = false;

		switch (race) {
		case RACE_SKELETON:
			m_sprite.setTexture(*skeleton);
			break;
		case RACE_DEVIL:
			m_sprite.setTexture(*devil);
			break;
		case RACE_DIABLO:
			m_sprite.setTexture(*diablo);
			break;
		}

		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		// hpbar 나중에 하기
		//m_HPBar.setTexture(hpbar);
		//m_HPBar.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		set_name("NONAME", false);
		SetLevelFont(0);
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

	void SetLevelFont(const char level[]);
	void set_nameColor(NameColor _color);
	void setHPBarRect(int left, int top, int width, int height);

	void setHP(int _hp) { hp = _hp; }
	void setHPmax(int _hpmax) { hpmax = _hpmax; }
	void setLevel(int _lev) { level = _lev; }

public:
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getSector() { return sector; }
	int getLevel() { return level; }
	int getID() { return id; }
	int getHP() { return hp; }
	int getHPmax() { return hpmax; }

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

	
	sf::Texture* skeleton;
	sf::Texture* wraith;
	sf::Texture* devil;
	sf::Texture* diablo;
};

