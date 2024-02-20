#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player() {}

	Player(int x, int y, int x2, int y2, int tx, int ty, int tx2, int ty2
		, int ux, int uy, int ux2, int uy2, int ex, int ey, int ex2, int ey2) {
		m_showing = false;
		//m_sprite.setTexture(*pieces);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		//m_UIHP.setTexture(*UI_HP);
		m_UIHP.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		//m_PlayerUI.setTexture(*PlayerUI);
		m_PlayerUI.setTextureRect(sf::IntRect(ux, uy, ux2, uy2));
		//m_PlayerEmptyHP.setTexture(*UI_HP_empty);
		m_PlayerEmptyHP.setTextureRect(sf::IntRect(ex, ey, ex2, ey2));
		set_name("NONAME", false);
		SetLevelFont(0);
	}
	// 플레이어 본인 생성자
	Player(sf::Texture& t, int x, int y, int x2, int y2, sf::Texture& hpbar, int tx, int ty, int tx2, int ty2
		, sf::Texture& playerUI, int ux, int uy, int ux2, int uy2, sf::Texture& playerUI_empty, int ex, int ey, int ex2, int ey2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		m_UIHP.setTexture(hpbar);
		m_UIHP.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		m_PlayerUI.setTexture(playerUI);
		m_PlayerUI.setTextureRect(sf::IntRect(ux, uy, ux2, uy2));
		m_PlayerEmptyHP.setTexture(playerUI_empty);
		m_PlayerEmptyHP.setTextureRect(sf::IntRect(ex, ey, ex2, ey2));
		set_name("NONAME", false);
		SetLevelFont(0);
	}

	// 플레이어 제외 다른 플레이어 생성자
	Player(sf::Texture& t, int x, int y, int x2, int y2, sf::Texture& hpbar, int tx, int ty, int tx2, int ty2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		m_HPBar.setTexture(hpbar);
		m_HPBar.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		set_name("NONAME", false);
		SetLevelFont(0);
	}

public:
	// GameObject을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;

public:
	void set_info(int _id, int _x, int _y, int _hp, int _hpmax, int _level, int exp, int _sector, char* name);
	void set_name(const char str[], bool _ui);
	void SetLevelFont(const char level[]);
	void SetPlayerEmptyHP(int left, int top, int width, int height);
	void SetPlayerCurHP(int left, int top, int width, int height);
	void SetLevel(int _lev) { level = _lev; }
	void setHP(int _hp) { hp = _hp; }
	void setHPmax(int _hpmax) { hpmax = _hpmax; }

public:
	void draw_hp(bool isParty);
	void draw_ui();
	void draw() {		// what?
		if (false == m_showing) return;
		float rx = (m_x - g_left_x) * 65.0f + 8;
		float ry = (m_y - g_top_y) * 65.0f + 8;
		m_sprite.setPosition(rx, ry);
		g_window->draw(m_sprite);

		m_name.setPosition(rx, ry - 40);
		g_window->draw(m_name);

		m_level.setPosition(rx - 40, ry - 40);
		g_window->draw(m_level);
	}
	void set_pos(int x, int y, int sector) {	// UI로 빼야할듯?
		pos.setFont(g_font);
		//string str = x + ", " + y;
		//str += " : SECTOR " + sector;
		string str;
		str += to_string(x);
		str += ", ";
		str += to_string(y);
		str += " / SECTOR : ";
		str += to_string(sector);
		pos.setString(str);
		pos.setFillColor(sf::Color(255, 255, 0));
		pos.setStyle(sf::Text::Bold);
	}

public:
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getSector() { return sector; }
	int getLevel() { return level; }
	int getID() { return id; }
	int getHP() { return hp; }
	int getHPmax() { return hpmax; }
	char* getName() { return my_name; }

public:
	vector<int> party_list;
private:
	char my_name[NAME_SIZE];
	int level;
	int exp, maxexp;
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

	sf::Texture* pieces;
	sf::Texture* PlayerUI;
	sf::Texture* UI_HP;
	sf::Texture* UI_HP_empty;
	sf::Texture* HPBar;
};

