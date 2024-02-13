#pragma once

class GameObject
{
public:
	GameObject(sf::Texture& t, int x, int y, int x2, int y2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		set_name("NONAME", false);
		set_level(0);
	}
	GameObject(sf::Texture& t, int x, int y, int x2, int y2, sf::Texture& hpbar, int tx, int ty, int tx2, int ty2
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
		set_level(0);
	}
	GameObject(sf::Texture& t, int x, int y, int x2, int y2, sf::Texture& hpbar, int tx, int ty, int tx2, int ty2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
		m_HPBar.setTexture(hpbar);
		m_HPBar.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		//ui_m_HPBar.setTexture(hpbar);
		//ui_m_HPBar.setTextureRect(sf::IntRect(tx, ty, tx2, ty2));
		set_name("NONAME", false);
		set_level(0);
	}
	GameObject() {
		m_showing = false;
	}

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Delete() = 0;

public:
	void set_info(int _id, int _level, int _hp, int _hpmax, int _x, int _y, int _sector)
	{
		id = _id;
		level = _level;
		hp = _hp;
		hpmax = _hpmax;
		m_x = _x;
		m_y = _y;
		sector = _sector;
	}
	void show()
	{
		m_showing = true;
	}
	void hide()
	{
		m_showing = false;
	}

	void a_move(int x, int y) {
		m_sprite.setPosition((float)x, (float)y);

	}

	void a_draw() {
		g_window->draw(m_sprite);
	}

	void move(int x, int y) {
		m_x = x;
		m_y = y;
	}

	void draw() {
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
	void draw_block() {
		if (false == m_showing) return;
		float rx = (m_x - g_left_x) * 65.0f + 8;
		float ry = (m_y - g_top_y) * 65.0f + 8;
		m_sprite.setPosition(rx, ry);
		g_window->draw(m_sprite);
	}
	void draw_hp(bool isParty) {
		if (false == m_showing) return;
		float rx = (m_x - g_left_x) * 65.0f + 8;
		float ry = (m_y - g_top_y) * 65.0f + 8;
		m_sprite.setPosition(rx, ry);
		g_window->draw(m_sprite);

		if (isParty)
			m_HPBar.setColor(sf::Color(0, 0, 255));
		else
			m_HPBar.setColor(sf::Color(255, 0, 0));
		m_HPBar.setPosition(rx, ry);
		g_window->draw(m_HPBar);

		m_name.setPosition(rx, ry - 40);
		g_window->draw(m_name);

		m_level.setPosition(rx - 40, ry - 40);
		g_window->draw(m_level);
	}
	void draw_ui()
	{
		if (false == m_showing) return;
		float rx = (m_x - g_left_x) * 65.0f + 8;
		float ry = (m_y - g_top_y) * 65.0f + 8;
		m_sprite.setPosition(rx, ry);
		g_window->draw(m_sprite);

		m_PlayerUI.setPosition(100, 900);
		g_window->draw(m_PlayerUI);

		m_UIHP.setPosition(130, 910);
		g_window->draw(m_UIHP);

		m_PlayerEmptyHP.setPosition(133, 910);
		g_window->draw(m_PlayerEmptyHP);

		m_name.setPosition(rx, ry - 40);
		g_window->draw(m_name);

		m_level.setPosition(rx - 40, ry - 40);
		g_window->draw(m_level);

		pos.setPosition(20, 20);
		g_window->draw(pos);
	}
	void idraw()
	{
		if (false == m_showing) return;
		float rx = (m_x - g_left_x) * 65.0f + 8;
		float ry = (m_y - g_top_y) * 65.0f + 8;
		m_sprite.setPosition(rx, ry);
		g_window->draw(m_sprite);
	}
	bool isShow()
	{
		return m_showing;
	}

	void set_pos(int x, int y, int sector) {
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

	void set_name(const char str[], bool _ui) {
		m_name.setFont(g_font);
		m_name.setString(str);
		m_name.setFillColor(sf::Color(255, 255, 0));
		m_name.setStyle(sf::Text::Bold);

		if (_ui) {
			//ui_m_name.setFont(g_font);
			ui_m_name.setString(str);
			ui_m_name.setFillColor(sf::Color(255, 255, 0));
			ui_m_name.setStyle(sf::Text::Bold);
		}
	}

	void set_level(const char level[]) {
		m_level.setFont(g_font);
		m_level.setString(level);
		m_level.setFillColor(sf::Color(255, 255, 0));
		m_level.setStyle(sf::Text::Bold);
	}

	void set_nameColor(NameColor _color)
	{
		switch (_color)
		{
		case COLOR_GREEN:
			m_name.setFillColor(sf::Color(0, 255, 0));
			m_level.setFillColor(sf::Color(0, 255, 0));
			break;
		case COLOR_YELLO:
			m_name.setFillColor(sf::Color(255, 255, 0));
			m_level.setFillColor(sf::Color(255, 255, 0));
			break;
		case COLOR_RED:
			m_name.setFillColor(sf::Color(255, 0, 0));
			m_level.setFillColor(sf::Color(255, 0, 0));
			break;
		default:
			break;
		}
	}
public:
	int id;
	int m_x, m_y;
	

protected:
	bool m_showing;
	sf::Sprite m_sprite;
	sf::Text m_name;
	sf::Text m_level;
	sf::Text ui_m_name;
	sf::Text pos;
};

