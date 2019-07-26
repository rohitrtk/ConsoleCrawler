#pragma once

namespace Direction
{
	constexpr char UP		= 'w';
	constexpr char DOWN		= 's';
	constexpr char RIGHT	= 'd';
	constexpr char LEFT		= 'a';
}

class Vector2D
{
public:
	int x;
	int y;

	Vector2D()				: x(0), y(0) {}
	Vector2D(int x, int y)	: x(x), y(y) {}

	bool operator < (Vector2D& other)
	{
		return x < other.x && y < other.y;
	}

	bool operator > (Vector2D& other)
	{
		return x > other.x && y > other.y;
	}

	bool operator <= (Vector2D& other)
	{
		return x <= other.x && y <= other.y;
	}

	bool operator >= (Vector2D& other)
	{
		return x >= other.x && y >= other.y;
	}

	bool operator == (Vector2D& other)
	{
		return x == other.x && y == other.y;
	}

	bool lto(Vector2D& other)
	{
		return x < other.x || y < other.y;
	}

	bool gto(Vector2D& other)
	{
		return x > other.x || y > other.y;
	}
};

class GObject
{
public:

	GObject()							: position(Vector2D(0, 0)) {}
	GObject(int xPos, int yPos)			: position(Vector2D(xPos, yPos)) {} 
	GObject(Vector2D position)			: position(position) {}

	inline virtual Vector2D& GetPosition() const { return this->position; }

private:

	mutable Vector2D position;
};

class GObjective : public GObject
{
public:
	GObjective()						: GObject(Vector2D(0, 0)) {}
	GObjective(int xPos, int yPos)		: GObject(xPos, yPos) {}
	GObjective(Vector2D position)		: GObject(position) {}
};
