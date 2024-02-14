#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
}

void Player::Update()
{
}

void Player::Delete()
{
}

void Player::set_info(int _id, int _level, int _hp, int _hpmax, int _x, int _y, int _sector)
{
	id = _id;
	level = _level;
	hp = _hp;
	hpmax = _hpmax;
	m_x = _x;
	m_y = _y;
	sector = _sector;
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

void Player::set_level(const char level[])
{
	m_level.setFont(g_font);
	m_level.setString(level);
	m_level.setFillColor(sf::Color(255, 255, 0));
	m_level.setStyle(sf::Text::Bold);
}