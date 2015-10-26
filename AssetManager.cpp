#include "AssetManager.hpp"
#include <iostream>
namespace eth
{
	AssetManager::AssetManager()
	{
	}

	AssetManager::~AssetManager()
	{
		// Delete fonts
		for(std::pair<const std::string, sf::Font*> entry : namedFonts)
		{
			delete entry.second;
		}
		// Delete textures
		for(std::pair<const std::string, sf::Texture*> entry : namedTextures)
		{
			delete entry.second;
		}
		// Delete shaders
		for(std::pair<const std::string, sf::Shader*> entry : namedShaders)
		{
			delete entry.second;
		}
		// Delete animations
		for(std::pair<const std::string, Animation*> entry : namedAnimations)
		{
			delete entry.second;
		}
	}

	void AssetManager::loadAll()
	{
		loadFonts();
		loadTextures();
		loadShaders();
		createAnimations();
	}

	sf::Font& AssetManager::getFont(const std::string& name) const
	{
		return *namedFonts.at(name);
	}

	sf::Texture& AssetManager::getTexture(const std::string& name) const
	{
		return *namedTextures.at(name);
	}

	Animation& AssetManager::getAnimation(const std::string& name) const
	{
		return *namedAnimations.at(name);
	}

	sf::Shader& AssetManager::getShader(const std::string& name) const
	{
		return *namedShaders.at(name);
	}

	sf::Texture& AssetManager::getTexture(const TileType tileType) const
	{
		switch(tileType)
		{
		case TileType::Grass:
			return *namedTextures.at("grass");
		case TileType::Dirt:
			return *namedTextures.at("dirt");
		}
		return *namedTextures.at("null");
	}

	sf::Font* AssetManager::loadFont(const std::string& path) const
	{
		sf::Font* font = new sf::Font;
		font->loadFromFile(path);
		return font;
	}

	sf::Texture* AssetManager::loadTexture(const std::string& path) const
	{
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(path);
		return texture;
	}

	sf::Shader* AssetManager::loadShader(const std::string& path) const
	{
		sf::Shader* shader = new sf::Shader;
		shader->loadFromFile(path, sf::Shader::Fragment);
		return shader;
	}

	void AssetManager::loadFonts()
	{
		namedFonts["arial"] = loadFont("fonts/arial.ttf");
	}

	void AssetManager::loadTextures()
	{
		namedTextures["character_sprite_sheet"] = loadTexture("images/character.png");
		namedTextures["example_background"]     = loadTexture("images/example_background.jpg");
		namedTextures["grass"]                  = loadTexture("images/grass.png");
		namedTextures["dirt"]                   = loadTexture("images/dirt.png");
	}

	void AssetManager::loadShaders()
	{
		if(sf::Shader::isAvailable())
		{
			namedShaders["pause_menu"] = loadShader("pause_menu.frag");
		}
	}

	void AssetManager::createAnimations()
	{
		unsigned fs = 64; // frame size

		Animation* animation = new Animation;
		animation->create(0, getTexture("character_sprite_sheet"));
		animation->addFrame(sf::IntRect(2 * fs, 3 * fs, fs, fs));
		namedAnimations["standing"] = animation;

		animation = new Animation;
		animation->create(0.05f, getTexture("character_sprite_sheet"));
		animation->addFrame(sf::IntRect(2 * fs, 3 * fs, fs, fs));
		animation->addFrame(sf::IntRect(0 * fs, 0 * fs, fs, fs));
		animation->addFrame(sf::IntRect(1 * fs, 0 * fs, fs, fs));
		animation->addFrame(sf::IntRect(2 * fs, 0 * fs, fs, fs));
		animation->addFrame(sf::IntRect(3 * fs, 0 * fs, fs, fs));
		animation->addFrame(sf::IntRect(0 * fs, 1 * fs, fs, fs));
		animation->addFrame(sf::IntRect(1 * fs, 1 * fs, fs, fs));
		animation->addFrame(sf::IntRect(2 * fs, 1 * fs, fs, fs));
		animation->addFrame(sf::IntRect(2 * fs, 3 * fs, fs, fs));
		animation->addFrame(sf::IntRect(3 * fs, 1 * fs, fs, fs));
		animation->addFrame(sf::IntRect(0 * fs, 2 * fs, fs, fs));
		animation->addFrame(sf::IntRect(1 * fs, 2 * fs, fs, fs));
		animation->addFrame(sf::IntRect(2 * fs, 2 * fs, fs, fs));
		animation->addFrame(sf::IntRect(3 * fs, 2 * fs, fs, fs));
		animation->addFrame(sf::IntRect(0 * fs, 3 * fs, fs, fs));
		animation->addFrame(sf::IntRect(1 * fs, 3 * fs, fs, fs));
		namedAnimations["walking"] = animation;
	}
}