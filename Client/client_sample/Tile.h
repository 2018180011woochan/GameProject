#pragma once
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile(sf::Texture& t, int x, int y, int x2, int y2) {
		m_showing = false;
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(x, y, x2, y2));
	}
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;

public:
	void draw_block();

private:
	sf::Texture* board;
	sf::Texture* Block;
};

