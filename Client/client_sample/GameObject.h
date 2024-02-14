#pragma once

class GameObject
{
public:
	GameObject() {
		m_showing = false;
	}

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Delete() = 0;

public:
	void show()
	{
		m_showing = true;
	}
	void hide()
	{
		m_showing = false;
	}
	void move(int x, int y) {
		m_x = x;
		m_y = y;
	}
	bool isShow()
	{
		return m_showing;
	}
	

	

protected:
	int id;
	int m_x, m_y;
	
	bool m_showing;
	sf::Sprite m_sprite;
	
	sf::Text ui_m_name;
	sf::Text pos;
};

