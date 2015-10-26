#include "Game.hpp"

namespace eth
{
	Game::Game()
		: gameWorld(window)
	{
	}

	bool Game::running() const
	{
		return window.isOpen();
	}

	void Game::run()
	{
		start();

		while(running())
		{
			update();
			draw();
			handleEvents();
		}

		shutdown();
	}

	void Game::start()
	{
		window.create(sf::VideoMode::getDesktopMode(), "Ethereal Game");
		window.setFramerateLimit(60);
		window.setView(sf::View(sf::FloatRect(0, 0, GData::r_width, GData::r_height)));

		initGameData();

		timer.restart();
	}

	void Game::handleEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			sf::Event::EventType etype = event.type;
			if(etype == sf::Event::Closed)
			{
				window.close();
			}
			else if(etype == sf::Event::Resized)
			{
				GData::w_width = std::min(event.size.width, GData::d_width);
				GData::w_height = std::min(event.size.height, GData::d_height);
				window.setSize(sf::Vector2u(GData::w_width, GData::w_height));
			}
			else if(etype == sf::Event::KeyReleased)
			{
				uiManager.handleInput(window, event.key.code);
			}
		}
	}

	void Game::update()
	{
		updateGameData();

		if(!GData::paused)
		{
			sf::Time deltaTime = timer.restart();
			gameWorld.update(deltaTime.asSeconds());
		}
	}

	void Game::draw()
	{
		window.clear(sf::Color::Magenta);
		gameWorld.draw();
		uiManager.draw(window);
		window.display();
	}

	void Game::shutdown()
	{

	}

	void Game::updateGameData()
	{
		sf::Vector2i winPos = window.getPosition();
		GData::w_x = winPos.x;
		GData::w_y = winPos.y;

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		GData::mouse_x = mousePos.x;
		GData::mouse_y = mousePos.y;

		sf::Vector2f viewPos = window.getView().getCenter();
		GData::view_x = viewPos.x;
		GData::view_y = viewPos.y;

		sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		GData::d_width = desktop.width;
		GData::d_height = desktop.height;
	}

	void Game::initGameData()
	{
		sf::Vector2u winSize = window.getSize();
		GData::w_width = winSize.x;
		GData::w_height = winSize.y;

		GData::min_view_x = GData::r_width/2;
		GData::min_view_y = GData::r_height/2;
		GData::max_view_x = gameWorld.getWidth() - GData::r_width/2;
		GData::max_view_y = gameWorld.getHeight() - GData::r_height/2;
	}
}