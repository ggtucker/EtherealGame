#ifndef TILE_HPP
#define TILE_HPP

#include <random>

namespace eth
{
	enum TileType
	{
		Grass = 0,
		Dirt
	};

	class Tile
	{
	public:
		Tile();
		Tile(TileType type);

		TileType getType();

	private:
		TileType type;
	};
}

#endif