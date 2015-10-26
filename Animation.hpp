#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <SFML/Graphics.hpp>

namespace eth
{
	class Animation
	{
	public:
		Animation();
		void create(float timePeriod, const sf::Texture& spriteSheet);

		void update(float deltaTime);
		void addFrame(sf::IntRect frame);
		void setTimePeriod(float timePeriod);
		void setSpriteSheet(const sf::Texture& spriteSheet);

		sf::IntRect getCurrentFrame() const;
		const sf::Sprite& getSprite() const;
		sf::Sprite& getSprite();

	private:
		sf::Sprite sprite;
		std::vector<sf::IntRect> frames;
		unsigned index;

		float timePeriod;
		float timeElapsed;
	};
}

#endif