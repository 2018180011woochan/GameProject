#pragma once
#include "GameObject.h"

class ChatUI : public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Delete() override;

public:
	void a_move(int x, int y) {
		m_sprite.setPosition((float)x, (float)y);
	}

	void a_draw() {
		g_window->draw(m_sprite);
	}
};

