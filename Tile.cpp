#include "Tile.hpp"

namespace eth
{
	Tile::Tile()
	{
		type = static_cast<TileType>(rand() % 2);
	}

	Tile::Tile(TileType type)
		: type(type)
	{
	}

	TileType Tile::getType()
	{
		return type;
	}
}