#include "pch.h"
#include "Level.h"
#include "Tiles.h"
#include "Player.h"
#include "LevelComponents.h"
#include <iostream>
#include <string>
#include <stdlib.h>

const char* PATH_LEVEL_1 = "Maps/Level1.txt";

void PrintLevel(const TileArray& level, Player& player)
{
	for (int y = 0; y < level.size(); ++y)
	{
		for (int x = 0; x < level.at(y).size(); ++x)
		{
			Tile t = level[y][x];
			Vector2D currentIndex = { x, y };

			if (player.GetPosition() == currentIndex)
			{
				t.SetIsPlayerOnTile(true);
			}
			else 
			{
				t.SetIsPlayerOnTile(false);
			}

			if (t.IsPlayerOnTile())
			{
				std::cout << TileConstants::TILE_PLAYER;
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
	Level level(PATH_LEVEL_1);
	Player player;

	level.AddComponent<SpawnerComponent>();

	bool isRunning = true;

	SpawnerComponent s = level.GetComponent<SpawnerComponent>();
	s.SpawnThing<Player>(Vector2D(0,0) , Vector2D(10, 10));

	while (isRunning)
	{
		PrintLevel(level.GetTiles(), player);
		std::string input = GetInput();

		system("CLS");

		if (input == "exit")
		{
			std::cout << "Ending game!" << std::endl;
			isRunning = false;
			break;
		}
		else if (input[0] == 'w' || input[0] == 's' || input[0] == 'd' || input[0] == 'a')
		{
			player.Move(input[0]);
		}

		
	}

	return 0;
}
