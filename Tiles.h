#pragma once

namespace TileConstants 
{
	constexpr char TILE_WALLV		= '|';
	constexpr char TILE_WALLH		= '-';
	constexpr char TILE_GROUND		= '#';
	constexpr char TILE_OBJ			= '@';
	constexpr char TILE_TRAP		= '^';
	constexpr char TILE_PLAYER		= 'U';
}

class Tile
{
public:

	Tile(const char chr) : chr(chr) {}

	inline virtual const char& GetChr() const { return this->chr; }
	inline virtual void SetChr(char chr) { this->chr = chr; }

	inline virtual bool IsPlayerOnTile() const { return this->playerOnTile; }
	inline virtual void SetIsPlayerOnTile(bool playerOnTile) { this->playerOnTile = playerOnTile; }


protected:

	// Character that represents this tile on screen
	char chr;

	bool playerOnTile;
};

class Wall : public Tile
{
public:

	Wall(const char chr) : Tile(chr) {}

};
