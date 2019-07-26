#pragma once

#include "GObject.h"

class Player : public GObject
{
public:

	Player()					: GObject() {}
	Player(int xPos, int yPos)	: GObject(xPos, yPos) {}
	Player(Vector2D position)	: GObject(position) {}

	void Move(const char input)
	{
		switch (input)
		{
		case Direction::UP:
			this->GetPosition().y--;
			break;
		case Direction::DOWN:
			this->GetPosition().y++;
			break;
		case Direction::RIGHT:
			this->GetPosition().x++;
			break;
		case Direction::LEFT:
			this->GetPosition().x--;
			break;
		}
	}
};
