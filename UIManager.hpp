#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <unordered_set>
#include <SFML/Graphics.hpp>
#include "GData.hpp"
#include "Util.hpp"

namespace eth
{
	class UIManager
	{
	public:
		UIManager();
		~UIManager();

		void draw(sf::RenderWindow& window);

		void handleInput(sf::RenderWindow& window, sf::Keyboard::Key key);

	private:
		std::unordered_set<sf::Shader*> currentShaders;
	};
}

#endif