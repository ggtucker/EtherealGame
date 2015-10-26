#include "Util.hpp"

namespace eth
{
	namespace Util
	{
		sf::Vector2i mapPositionToChunk(sf::Vector2f position)
		{
			sf::Vector2i chunkCoords;
			chunkCoords.x = position.x / GData::t_size / GData::chunk_size;
			chunkCoords.y = position.y / GData::t_size / GData::chunk_size;
			return chunkCoords;
		}

		sf::Vector2f mapPositionToWindow(sf::Vector2f position)
		{
			sf::Vector2f coords;
			coords.x = (position.x - GData::view_x + GData::r_width/2) * GData::w_width / GData::r_width;
			coords.y = (position.y - GData::view_y + GData::r_height/2) * GData::w_height / GData::r_height;
			return coords;
		}

		float mouseAngle(sf::Vector2f position)
		{
			position = mapPositionToWindow(position);
			return std::atan2(position.y - GData::mouse_y, position.x - GData::mouse_x);
		}

		void rotate(sf::Sprite* sprite, b2Body* body, float angle)
		{
			float degreeAngle = angle * 180 / GData::PI;
			sprite->setRotation(degreeAngle);
			body->SetTransform(body->GetPosition(), angle);
		}

		float dist(sf::Vector2i pos1, sf::Vector2i pos2)
		{
			return sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));
		}
	}
}