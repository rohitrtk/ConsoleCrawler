#pragma once

namespace Direction
{
	constexpr char UP = 'w';
	constexpr char DOWN = 's';
	constexpr char RIGHT = 'd';
	constexpr char LEFT = 'a';
}

struct Vector2D
{
	int x;
	int y;

	bool operator == (const Vector2D& other)
	{
		return x == other.x && y == other.y;
	}
};

class GObject
{
public:

	GObject() : position({0, 0}) {}
	GObject(int xPos, int yPos) : position({xPos, yPos}) {} 
	GObject(Vector2D position) : position(position) {}

	inline Vector2D& GetPosition() const { return this->position; }

private:

	mutable Vector2D position;
};
