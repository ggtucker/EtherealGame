#include "Animation.hpp"

namespace eth
{
	Animation::Animation()
		: index(0), timePeriod(0.25), timeElapsed(0)
	{
	}

	void Animation::create(float timePeriod, const sf::Texture& spriteSheet)
	{
		this->timePeriod = timePeriod;
		sprite.setTexture(spriteSheet);
	}

	void Animation::update(float deltaTime)
	{
		sf::IntRect frame = getCurrentFrame();
		sprite.setTextureRect(frame);
		sprite.setOrigin(frame.width/2, frame.height/2);

		if(timePeriod == 0)
			return;

		timeElapsed += deltaTime;

		if(timeElapsed >= timePeriod)
		{
			timeElapsed -= timePeriod;

			if(index + 1 < frames.size())
			{
				index++;
			}
			else
			{
				index = 0;
			}
		}
	}

	void Animation::addFrame(sf::IntRect frame)
	{
		frames.push_back(frame);
	}

	void Animation::setTimePeriod(float timePeriod)
	{
		this->timePeriod = timePeriod;
	}

	void Animation::setSpriteSheet(const sf::Texture& spriteSheet)
	{
		sprite.setTexture(spriteSheet);
	}

	sf::IntRect Animation::getCurrentFrame() const
	{
		if(frames.size() == 0)
			return sf::IntRect();

		return frames[index];
	}

	const sf::Sprite& Animation::getSprite() const
	{
		return sprite;
	}

	sf::Sprite& Animation::getSprite()
	{
		return sprite;
	}
}