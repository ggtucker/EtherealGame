#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <Box2D/Box2D.h>
#include "GData.hpp"

namespace eth
{
	class GameWorld;

	class Entity
	{

	public:
		Entity(b2Body* body);
		virtual ~Entity();

		void update(GameWorld* gameWorld, float deltaTime);
		void draw(sf::RenderWindow& window);

	protected:
		b2Body*           body;
		Animation*        animation;
		sf::Sprite*       sprite; // Pointer to sprite from animation

		virtual void updateEntity(GameWorld* gameWorld, float deltaTime) = 0;
		virtual void drawEntity(sf::RenderWindow& window) = 0;

		void setAnimation(Animation& a);

	private:
		void syncPosition();

		// Disable copy constructor and assignment operator
		Entity(const Entity& entity);
		Entity& operator=(const Entity& entity);
	};
}

#endif