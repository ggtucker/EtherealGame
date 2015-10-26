#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "GData.hpp"

namespace eth
{
	namespace Util
	{
		sf::Vector2i mapPositionToChunk(sf::Vector2f position);
		sf::Vector2f mapPositionToWindow(sf::Vector2f position);
		float mouseAngle(sf::Vector2f position);
		void rotate(sf::Sprite* sprite, b2Body* body, float angle);
		float dist(sf::Vector2i pos1, sf::Vector2i pos2);
	}
}

#endif