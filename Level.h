#pragma once

#include "Tiles.h"
#include "LevelComponents.h"
#include <vector>
#include <memory>

using TileArray = std::vector<std::vector<Tile>>;

template <typename T>
std::size_t GetComponentID()
{
	static std::size_t id = 0;
	return id++;
}

class Level
{
public:
	
	Level(const char* levelPath);

	inline const TileArray& GetTiles() { return this->tiles; }

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... vArgs)
	{
		std::unique_ptr<T> component = 
			std::make_unique<T>(std::forward<TArgs>(vArgs)...);
		component->level = this;

		components.emplace_back(std::move(component.get())); 

		component->Init();

		return *component;
	}

	template <typename T>
	T& GetComponent() const
	{
		Component* component(components.at(GetComponentID<T>()));
		return *static_cast<T*>(component);
	}

	static int GenerateRandom(int low = 0, int high = 9);

	const int GetXSize() const { return this->xSize; }
	const int GetYSize() const { return this->ySize; }

private:

	mutable TileArray tiles;

	int xSize;
	int ySize;

	std::vector<std::string> ReadTextFromFile(const char* levelPath);

	std::vector<class Component*> components;
};

