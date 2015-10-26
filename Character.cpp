#include "Character.hpp"

namespace eth
{
	Character::Character(PhysicsWorld& physicsWorld)
		: Entity(physicsWorld.createCircleBody(GData::r_width/2, GData::r_height/2, GData::t_size/2)),
		  walkingSpeed(4.0f),
		  runningSpeed(8.0f)
	{
		setAnimation(GData::assets.getAnimation("standing"));
	}

	void Character::updateEntity(GameWorld* gameWorld, float deltaTime)
	{
		move(deltaTime);
		rotate();
	}

	void Character::drawEntity(sf::RenderWindow& window)
	{
		sf::Vector2f position = sprite->getPosition();
		sf::View view = window.getView();

		if(position.x > GData::min_view_x && position.x < GData::max_view_x)
		{
			view.setCenter(sf::Vector2f(position.x, view.getCenter().y));
		}

		if(position.y > GData::min_view_y && position.y < GData::max_view_y)
		{
			view.setCenter(sf::Vector2f(view.getCenter().x, position.y));
		}

		window.setView(view);
	}

	void Character::move(float deltaTime)
	{
		float speed = walkingSpeed;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			speed = runningSpeed;
		}

		// W & A -> Move Up Left
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			body->SetLinearVelocity(b2Vec2(-cos(GData::PI/4) * speed, -sin(GData::PI/4) * speed));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// W & D -> Move Up Right
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			body->SetLinearVelocity(b2Vec2(cos(GData::PI/4) * speed, -sin(GData::PI/4) * speed));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// S & A -> Move Down Left
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			body->SetLinearVelocity(b2Vec2(-cos(GData::PI/4) * speed, sin(GData::PI/4) * speed));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// S & D -> Move Down Right
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			body->SetLinearVelocity(b2Vec2(cos(GData::PI/4) * speed, sin(GData::PI/4) * speed));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// W -> Move Up
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			body->SetLinearVelocity(b2Vec2(0.0f, -speed));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// S -> Move Down
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			body->SetLinearVelocity(b2Vec2(0.0f, speed));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// A -> Move Left
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			body->SetLinearVelocity(b2Vec2(-speed, 0.0f));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// D -> Move Right
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			body->SetLinearVelocity(b2Vec2(speed, 0.0f));
			setAnimation(GData::assets.getAnimation("walking"));
		}
		// Not moving
		else
		{
			body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
			setAnimation(GData::assets.getAnimation("standing"));
		}
	}

	void Character::rotate()
	{
		float angle = Util::mouseAngle(sprite->getPosition()) - GData::PI/2;
		Util::rotate(sprite, body, angle);
	}
}