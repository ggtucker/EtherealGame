#include "PhysicsWorld.hpp"

namespace eth
{
	PhysicsWorld::PhysicsWorld()
	{
		b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
		world = new b2World(gravity);
	}

	PhysicsWorld::~PhysicsWorld()
	{
		delete world;
		world = nullptr;
	}

	void PhysicsWorld::step(float32 timeStep)
	{
		world->Step(timeStep, 10, 10);
	}

		b2Body* PhysicsWorld::createCircleBody(float32 x, float32 y, float32 radius)
		{
			b2BodyDef circleBodyDef;
			circleBodyDef.type = b2_dynamicBody;
			circleBodyDef.position.Set(x/GData::ppm, y/GData::ppm);
			b2Body* circleBody = world->CreateBody(&circleBodyDef);

			b2CircleShape circleShape;
			circleShape.m_radius = radius/GData::ppm;

			b2FixtureDef circleShapeDef;
			circleShapeDef.shape = &circleShape;
			circleShapeDef.density = 10.0f;
			circleShapeDef.friction = 0.4f;
			circleShapeDef.restitution = 0.1f;
			b2Fixture* rectFixture = circleBody->CreateFixture(&circleShapeDef);

			return circleBody;
		}

		b2Body* PhysicsWorld::createRectBody(float32 x, float32 y, float32 width, float32 height)
		{
			b2BodyDef rectBodyDef;
			rectBodyDef.type = b2_dynamicBody;
			rectBodyDef.position.Set(x/GData::ppm, y/GData::ppm);
			b2Body* rectBody = world->CreateBody(&rectBodyDef);

			b2PolygonShape rectShape;
			rectShape.SetAsBox(width/GData::ppm/2, height/GData::ppm/2);

			b2FixtureDef rectShapeDef;
			rectShapeDef.shape = &rectShape;
			rectShapeDef.density = 10.0f;
			rectShapeDef.friction = 0.4f;
			rectShapeDef.restitution = 0.1f;
			b2Fixture* rectFixture = rectBody->CreateFixture(&rectShapeDef);

			return rectBody;
		}

	void PhysicsWorld::createBorderBody(float32 width, float32 height)
	{
		// Define and create 'border' body
		b2BodyDef borderBodyDef;
		borderBodyDef.position.Set(0,0);
		borderBody = world->CreateBody(&borderBodyDef);

		// Create border box and its definition
		b2EdgeShape borderBox;
		b2FixtureDef borderBoxDef;
		borderBoxDef.shape = &borderBox;

		float32 borderWidth = width/GData::ppm;
		float32 borderHeight = height/GData::ppm;

		// Create the edges and add them to the border body
		borderBox.Set(b2Vec2(0,0), b2Vec2(borderWidth, 0));
		borderBody->CreateFixture(&borderBoxDef);

		borderBox.Set(b2Vec2(0,0), b2Vec2(0, borderHeight));
		borderBody->CreateFixture(&borderBoxDef);

		borderBox.Set(b2Vec2(0, borderHeight), b2Vec2(borderWidth, borderHeight));
		borderBody->CreateFixture(&borderBoxDef);

		borderBox.Set(b2Vec2(borderWidth, borderHeight), b2Vec2(borderWidth, 0));
		borderBody->CreateFixture(&borderBoxDef);
	}
}