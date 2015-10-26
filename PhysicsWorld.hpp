#ifndef PHYSICS_WORLD
#define PHYSICS_WORLD

#include <Box2D/Box2D.h>
#include "GData.hpp"

namespace eth
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		~PhysicsWorld();

		void step(float32 timeStep);

		void createBorderBody(float32 width, float32 height);
		b2Body* createCircleBody(float32 x, float32 y, float32 radius);
		b2Body* createRectBody(float32 x, float32 y, float32 width, float32 height);

	private:
		b2World* world;
		b2Body* borderBody;
	};
}

#endif