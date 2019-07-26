#pragma once

#include "Level.h"
#include "GObject.h"
#include <iostream>

class Component
{
public:

	virtual void Init() = 0;

	class Level* level;
};

class SpawnerComponent : public Component
{
public:

	virtual void Init() override;
	
	template<typename T>
	T* SpawnThing(const Vector2D& maxPos, const Vector2D& minPos = {0, 0})
	{

		int x = Level::GenerateRandom(minPos.x, maxPos.x - 1);
		int y = Level::GenerateRandom(minPos.y, maxPos.y - 1);
		
		Vector2D position = { x, y };

		std::unique_ptr<T> thing = std::make_unique<T>(position);

		return thing;
	}
};
