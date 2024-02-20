#include "stdafx.h"
#include "Player.h"
#include <string>
void Player::Init()
{
	pieces = new sf::Texture;
	PlayerUI = new sf::Texture;
	UI_HP = new sf::Texture;
	UI_HP_empty = new sf::Texture;
	HPBar = new sf::Texture;

	pieces->loadFromFile("Texture/User/player.png");
	PlayerUI->loadFromFile("Texture/Single/StatusBar/2.png");
	UI_HP->loadFromFile("Texture/Single/StatusBar/0.png");
	UI_HP_empty->loadFromFile("Texture/Single/StatusBar/emptyhp.png");
	HPBar->loadFromFile("Texture/User/hpbar.bmp");

	m_sprite.setTexture(*pieces);
	m_UIHP.setTexture(*UI_HP);
	m_PlayerUI.setTexture(*PlayerUI);
	m_PlayerEmptyHP.setTexture(*UI_HP_empty);
}

void Player::Update()
{
}

void Player::Delete()
{
	delete pieces;
	delete PlayerUI;
	delete UI_HP;
	delete UI_HP_empty;
	delete HPBar;
}

void Player::set_info(int _id, int _x, int _y, int _hp, int _hpmax, int _level, int _exp,  int _sector, char* _name)
{
	id = _id;
	m_x = _x;
	m_y = _y;
	hp = _hp;
	hpmax = _hpmax;
	level = _level;
	exp = _exp;
	sector = _sector;
	strcpy_s(my_name, _name);
}

void Player::draw_hp(bool isParty)
{
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

void Player::draw_ui()
{
	if (false == m_showing) return;
	float rx = (m_x - g_left_x) * 65.0f + 8;
	float ry = (m_y - g_top_y) * 65.0f + 8;
	m_sprite.setPosition(rx, ry);
	//g_window->draw(m_sprite);

	m_PlayerUI.setPosition(100, 900);
	//g_window->draw(m_PlayerUI);

	m_UIHP.setPosition(130, 910);
	//g_window->draw(m_UIHP);

	m_PlayerEmptyHP.setPosition(133, 910);
	//g_window->draw(m_PlayerEmptyHP);

	m_name.setPosition(rx, ry - 40);
	//g_window->draw(m_name);

	m_level.setPosition(rx - 40, ry - 40);
	//g_window->draw(m_level);

	pos.setPosition(20, 20);
	//g_window->draw(pos);
}

void Player::set_name(const char str[], bool _ui)
{
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

void Player::SetLevelFont(const char level[])
{
	m_level.setFont(g_font);
	m_level.setString(level);
	m_level.setFillColor(sf::Color(255, 255, 0));
	m_level.setStyle(sf::Text::Bold);
}

void Player::SetPlayerEmptyHP(int left, int top, int width, int height)
{
	m_PlayerEmptyHP.setTextureRect(sf::IntRect(left, top, width, height));
}

void Player::SetPlayerCurHP(int left, int top, int width, int height)
{
	m_UIHP.setTextureRect(sf::IntRect(left, top, width, height));
}
