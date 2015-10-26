#include "Chunk.hpp"
#include <iostream>

namespace eth
{
	Chunk::Chunk(int x, int y)
		: loaded(false), x(x), y(y)
	{
	}

	Chunk::~Chunk()
	{
		unload();
	}

	int Chunk::getX()
	{
		return x;
	}

	int Chunk::getY()
	{
		return y;
	}

	bool Chunk::isLoaded()
	{
		return loaded;
	}

	void Chunk::load()
	{
		tiles = new Tile*[GData::chunk_size];
		for(int i = 0; i < GData::chunk_size; i++)
		{
			tiles[i] = new Tile[GData::chunk_size];
		}
		loaded = true;
	}

	void Chunk::unload()
	{
		for(int i = 0; i < GData::chunk_size; i++)
		{
			delete[] tiles[i];
		}
		delete[] tiles;
		loaded = false;
	}

	void Chunk::render(sf::RenderWindow& window)
	{
		sf::Sprite sprite;
		for(int i = 0; i < GData::chunk_size; i++)
		{
			for(int j = 0; j < GData::chunk_size; j++)
			{
				sprite.setTexture(GData::assets.getTexture(tiles[i][j].getType()));
				sprite.setPosition((x * GData::chunk_size + i) * GData::t_size,
								   (y * GData::chunk_size + j) * GData::t_size);
				window.draw(sprite);
			}
		}
	}
}