#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "PhysicsWorld.hpp"
#include "Entity.hpp"
#include "Util.hpp"

namespace eth
{
	class GameWorld;

	class Character : public Entity
	{
	public:
		Character(PhysicsWorld& physicsWorld);

	protected:
		virtual void updateEntity(GameWorld* gameWorld, float deltaTime);
		virtual void drawEntity(sf::RenderWindow& window);

	private:
		float walkingSpeed;
		float runningSpeed;

		void move(float deltaTime);
		void rotate();
	};
}

#endif