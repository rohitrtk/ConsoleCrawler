#include "pch.h"
#include "Level.h"
#include <string>
#include <fstream>
#include <iostream>
#include <random>

Level::Level(const char* levelPath)
{
	std::vector<std::string> ys = ReadTextFromFile(levelPath);

	using namespace TileConstants;
	for (const auto& y : ys)
	{
		std::vector<Tile> xs;
		for (const auto& x : y)
		{
			char t;
			switch (x)
			{
			case TILE_WALLH:
			case TILE_WALLV:
				t = (x == TILE_WALLH) ? TILE_WALLH : TILE_WALLV;

				xs.push_back(Wall(t));
				break;
			case TILE_GROUND:
				xs.push_back(Tile(TILE_GROUND));
				break;
			case TILE_TRAP:
				xs.push_back(Tile(TILE_TRAP));
				break;
			}
		}

		tiles.push_back(xs);
	}

	this->ySize = static_cast<int>(tiles.size());
	this->xSize = static_cast<int>(tiles.at(0).size()); // All x's are the same
}

std::vector<std::string> Level::ReadTextFromFile(const char* levelPath)
{
	std::vector<std::string> lines;

	std::ifstream file;

	file.open("Maps/Level1.txt");

	if (!file.is_open())
	{
		std::cerr << "Unable to open map" << std::endl;
		return lines;
	}

	std::string line;
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}

	file.close();

	return lines;
}

int Level::GenerateRandom(int low, int high)
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(low, high);

	return distribution(generator);
}
