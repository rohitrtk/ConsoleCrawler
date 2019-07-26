#include "pch.h"
#include "Level.h"
#include "Tiles.h"
#include "Player.h"
#include "GObject.h"
#include "LevelComponents.h"
#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>

const char* PATH_LEVEL_1 = "Maps/Level1.txt";

std::unique_ptr<Player>		player;
std::unique_ptr<Level>		level;
std::shared_ptr<GObjective> objective;

void PrintLevel()
{
	const TileArray& levelTiles = level->GetTiles();

	for (std::size_t y = 0; y < levelTiles.size(); ++y)
	{
		for (std::size_t x = 0; x < levelTiles.at(y).size(); ++x)
		{
			Tile t = levelTiles[y][x];
			Vector2D currentIndex( static_cast<int>(x), static_cast<int>(y) );

			if (player && player->GetPosition() == currentIndex)
			{
				t.SetObjectOnTile(player.get());
			}
			//else if (objective && objective->GetPosition() == currentIndex)
			//{
			//	t.SetObjectOnTile(objective);
			//}
			else
			{
				t.SetObjectOnTile(nullptr);
			}

			GObject* obj = t.GetObjectOnTile();
			if (obj)
			{
				if (obj = dynamic_cast<Player*>(obj))
				{
					std::cout << TileConstants::TILE_PLAYER;
				}
				else if (obj = dynamic_cast<GObjective*>(obj))
				{
					std::cout << TileConstants::TILE_OBJ;
				}
			}
			else
			{
				std::cout << t.GetChr();
			}
		}

		std::cout << std::endl;
	}
}

const std::string GetInput()
{
	std::string input;
	std::getline(std::cin, input);

	return input;
}

int main()
{
	level = std::make_unique<Level>(PATH_LEVEL_1);
	player = std::make_unique<Player>();
	objective = std::make_unique<GObjective>();

	SpawnerComponent sc = level->AddComponent<SpawnerComponent>();
	objective.reset(sc.SpawnThing<GObjective>(Vector2D(0,0), Vector2D(10,10))); // NTF

	bool isRunning = true;

	while (isRunning)
	{
		PrintLevel();
		std::string input = GetInput();

		system("CLS");

		if (input == "exit")
		{
			std::cout << "Ending game!" << std::endl;
			isRunning = false;
			break;
		}
		else if (input[0] == 'w' || input[0] == 's' 
			  || input[0] == 'd' || input[0] == 'a')
		{
			player->Move(input[0]);
		}

		
	}

	return 0;
}
