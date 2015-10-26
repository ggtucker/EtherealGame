#include "Entity.hpp"

namespace eth
{
	Entity::Entity(b2Body* body)
	: body(body),
	  animation(nullptr),
	  sprite(nullptr)
	{
		body->SetUserData(this);
	}

	Entity::~Entity()
	{
		body->GetWorld()->DestroyBody(body);
	}

	void Entity::update(GameWorld* gameWorld, float deltaTime)
	{
		if(sprite == nullptr)
			return;

		updateEntity(gameWorld, deltaTime);
		animation->update(deltaTime);
		syncPosition();
	}

	void Entity::draw(sf::RenderWindow& window)
	{
		if(sprite == nullptr)
			return;

		drawEntity(window);
		window.draw(*sprite);
	}

	void Entity::setAnimation(Animation& a)
	{
		animation = &a;
		sprite = &animation->getSprite();
	}

	void Entity::syncPosition()
	{
		sprite->setPosition(body->GetPosition().x * GData::ppm,
							body->GetPosition().y * GData::ppm);
	}
}