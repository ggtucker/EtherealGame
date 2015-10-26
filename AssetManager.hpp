#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <string>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "Animation.hpp"
#include "Tile.hpp"

namespace eth
{
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		void loadAll();

		sf::Font& getFont(const std::string& name) const;
		sf::Texture& getTexture(const TileType tileType) const;
		sf::Texture& getTexture(const std::string& name) const;
		sf::Shader& getShader(const std::string& name) const;
		Animation& getAnimation(const std::string& name) const;

	private:
		std::map<const std::string, sf::Font*> namedFonts;
		std::map<const std::string, sf::Texture*> namedTextures;
		std::map<const std::string, sf::Shader*> namedShaders;
		std::map<const std::string, Animation*> namedAnimations;

		sf::Font* loadFont(const std::string& path) const;
		sf::Texture* loadTexture(const std::string& path) const;
		sf::Shader* loadShader(const std::string& path) const;

		void loadFonts();
		void loadTextures();
		void loadShaders();
		void createAnimations();
	};
}

#endif