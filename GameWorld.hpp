#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include <SFML/Graphics.hpp>
#include "ChunkManager.hpp"
#include "PhysicsWorld.hpp"
#include "Entity.hpp"
#include "Character.hpp"

namespace eth
{
	class GameWorld
	{
	public:
		GameWorld(sf::RenderWindow& window);
		~GameWorld();

		void update(float deltaTime);
		void draw();

		void addEntity(Entity* entity);
		void removeEntity(Entity* entity);

		sf::RenderWindow& getWindow() { return window; }
		float getWidth()              { return width;  }
		float getHeight()             { return height; }

	private:
		ChunkManager chunkManager;
		PhysicsWorld physicsWorld;
		std::vector<Entity*> entities;
		sf::RenderWindow& window;

		float width;
		float height;
	};
}

#endif