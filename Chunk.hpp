#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include "GData.hpp"

namespace eth
{
	class Chunk
	{
	public:
		Chunk(int x, int y);
		~Chunk();

		int getX();
		int getY();

		bool isLoaded();
		void load();
		void unload();

		void render(sf::RenderWindow& window);

	private:
		Tile** tiles;
		bool loaded;
		int x;
		int y;
	};
}

#endif