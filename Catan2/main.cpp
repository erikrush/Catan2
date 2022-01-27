#include "board.h"

using namespace std;

int main() {

	gameBoard game;
	game.initialize(game);
	game.setUp(game);
	game.gameLoop();
	
	return 0;
}