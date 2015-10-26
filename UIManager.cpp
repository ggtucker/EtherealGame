#include "UIManager.hpp"
#include <iostream>
namespace eth
{
	UIManager::UIManager()
	{
	}

	UIManager::~UIManager()
	{
	}

	void UIManager::draw(sf::RenderWindow& window)
	{
		if(sf::Shader::isAvailable())
		{
			for(sf::Shader* shader : currentShaders)
			{
				sf::Texture texture;
				texture.create(GData::d_width, GData::d_height);
				texture.update(window);

				sf::Sprite sprite(texture);
				sprite.setOrigin(GData::d_width/2, GData::d_height/2);
				sprite.setPosition(window.getView().getCenter());

				window.draw(sprite, shader);
			}
		}

		if(GData::paused)
		{
			sf::Text text;
			text.setFont(GData::assets.getFont("arial"));
			text.setString("GAME PAUSED");
			text.setCharacterSize(64);
			text.setColor(sf::Color::Cyan);
			text.setStyle(sf::Text::Bold);

			text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
			text.setPosition(window.getView().getCenter());
			window.draw(text);
		}
	}

	void UIManager::handleInput(sf::RenderWindow& window, sf::Keyboard::Key key)
	{
		if(key == sf::Keyboard::Key::Escape)
		{
			GData::paused = !GData::paused;

			if(GData::paused)
			{
				currentShaders.emplace(&GData::assets.getShader("pause_menu"));
			}
			else
			{
				currentShaders.erase(&GData::assets.getShader("pause_menu"));
			}
		}
		else if(key == sf::Keyboard::Key::Space)
		{
			if(GData::paused)
			{
				window.close();
			}
		}
	}
}