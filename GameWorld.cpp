#include "GameWorld.hpp"

namespace eth
{
	GameWorld::GameWorld(sf::RenderWindow& window)
		: window(window),
		  width(GData::chunk_cols * GData::chunk_size * GData::t_size),
		  height(GData::chunk_rows * GData::chunk_size * GData::t_size)
	{
		chunkManager.initChunks(window.getView().getCenter());
		physicsWorld.createBorderBody(width, height);
		entities.push_back(new Character(physicsWorld));
	}

	GameWorld::~GameWorld()
	{
		for(unsigned i = 0; i < entities.size(); i++)
		{
			delete entities[i];
			entities[i] = nullptr;
		}
	}

	void GameWorld::update(float deltaTime)
	{
		physicsWorld.step(deltaTime);
		chunkManager.update(deltaTime, window.getView().getCenter());

		for(unsigned i = 0; i < entities.size(); i++)
		{
			entities[i]->update(this, deltaTime);
		}
	}

	void GameWorld::draw()
	{
		chunkManager.render(window);
		for(unsigned i = 0; i < entities.size(); i++)
		{
			entities[i]->draw(window);
		}
	}

	void addEntity(Entity* entity)
	{
	}

	void removeEntity(Entity* entity)
	{
	}
}