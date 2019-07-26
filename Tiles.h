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

	inline virtual const char& GetChr() const							{ return this->chr; }
	inline virtual void SetChr(char chr)								{ this->chr = chr; }

	inline virtual bool IsObjectOnTile() const							{ return this->objectOnTile != nullptr; }
	inline virtual class GObject* GetObjectOnTile() const				{ return this->objectOnTile; }
	inline virtual void SetObjectOnTile(class GObject* object)			{ this->objectOnTile = object; }


protected:

	// Character that represents this tile on screen
	char chr;

	class GObject* objectOnTile = nullptr;
};

class Wall : public Tile
{
public:

	Wall(const char chr) : Tile(chr) {}

};
