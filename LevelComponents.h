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

	inline virtual void Init() override
	{
	}
	
	template<typename T>
	T* SpawnThing(Vector2D minPos, Vector2D maxPos)
	{
		if (maxPos < minPos)
		{
			throw "Invalid spawn parameters!";
		}


		int x = Level::GenerateRandom(minPos.x, maxPos.x - 1);
		int y = Level::GenerateRandom(minPos.y, maxPos.y - 1);
		
		Vector2D position(x, y);

		std::unique_ptr<T> thing = std::make_unique<T>(position);
		
		std::cout << "Spawned thing at " << x << "," << y << std::endl;

		return thing.get();
	}
};
