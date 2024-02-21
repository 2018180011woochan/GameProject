#include "stdafx.h"
#include "Monster.h"

void Monster::Init()
{
	// npc수만큼 루프 돌면서 불러오기 하는게 말이 안됨. 이거는 client에서 한번 불러오는걸로 해야하나?>
	// 아니면 clinet init 할때 한번 불러오고 저장만 딱 해줄까
	// 고민중..
	skeleton = new sf::Texture;
	wraith = new sf::Texture;
	devil = new sf::Texture;
	diablo = new sf::Texture;

	skeleton->loadFromFile("Texture/Monster/Skeleton.png");
	wraith->loadFromFile("Texture/Monster/wraith4.png");
	devil->loadFromFile("Texture/Monster/Devil2.png");
	diablo->loadFromFile("Texture/Monster/Diablo.png");
}

void Monster::Update()
{
}

void Monster::Delete()
{
	delete skeleton;
	delete wraith;
	delete devil;
	delete diablo;
}

void Monster::set_info(int _id, int _level, int _hp, int _hpmax, int _x, int _y, int _sector)
{
	id = _id;
	level = _level;
	hp = _hp;
	hpmax = _hpmax;
	m_x = _x;
	m_y = _y;
	sector = _sector;
}

void Monster::draw_hp(bool isParty)
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

void Monster::set_name(const char str[], bool _ui)
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

void Monster::SetLevelFont(const char level[])
{
	m_level.setFont(g_font);
	m_level.setString(level);
	m_level.setFillColor(sf::Color(255, 255, 0));
	m_level.setStyle(sf::Text::Bold);
}

void Monster::set_nameColor(NameColor _color)
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

void Monster::setHPBarRect(int left, int top, int width, int height)
{
	m_HPBar.setTextureRect(sf::IntRect(left, top, width, height));
}
