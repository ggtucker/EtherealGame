#include <Box2D/Box2D.h>
#include "Game.hpp"

int main(int argc, const char* argv[])
{
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);

	// Load Game Data
	eth::GData::assets.loadAll();

	// Run the Game
    eth::Game game;
	game.run();

    return 0;
}