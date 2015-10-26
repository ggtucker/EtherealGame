#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "UIManager.hpp"
#include "GameWorld.hpp"
#include "GData.hpp"

namespace eth
{
	class Game
	{
	public:
		Game();

		// Returns whether game is running
		bool running() const;

		// Begins the game loop
		void run();

		// Runs when game loop begins
		void start();

		// Game loop methods
		void handleEvents();
		void update();
		void draw();

		// Runs when the game loop ends
		void shutdown();

	private:
		sf::RenderWindow window;
		sf::Clock timer;
		UIManager uiManager;
		GameWorld gameWorld;

		void initGameData();
		void updateGameData();
	};
}

#endif