#pragma once

class ChatUI : public GameObject
{
public:
	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Delete() override;
};

