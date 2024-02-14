#include "stdafx.h"
#include "Tile.h"

void Tile::Init()
{
}

void Tile::Update()
{
}

void Tile::Delete()
{
}

void Tile::draw_block()
{
	if (false == m_showing) return;
	float rx = (m_x - g_left_x) * 65.0f + 8;
	float ry = (m_y - g_top_y) * 65.0f + 8;
	m_sprite.setPosition(rx, ry);
	g_window->draw(m_sprite);
}