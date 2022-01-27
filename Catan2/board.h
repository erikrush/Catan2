#ifndef BOARD_HPP
#define BOARD_HPP
#include <stack>
#include <set>
#include "Tile.h"
#include "player.h"
#include <map>
#include <iostream>
#include <chrono>
#include <thread>
class gameState;

class gameBoard {
public:
	sf::RenderWindow window;
	int turn;
	int playerNum;
	int setUpHouse;
	bool housePlaced;
	bool roadPlaced;
	sf::Vector2i currHouseCoord;

	std::vector<Player*> players;
	std::vector<int> setUpTurns;
	
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Shape*> shapes;
	std::vector<gameTile*> tiles;
	std::vector<sf::Vector2f> vertices;
	std::vector<std::pair<sf::Vector2f, int >> edges;
	std::vector<sf::Texture*> textureList;
	std::vector<sf::Texture*> diceTexts;
	std::vector<sf::Sprite> diceSprites;
	sf::Font font;
	std::vector<sf::Text> sideMenuRight;
	std::vector<sf::Text> sideMenuLeft;
	std::stack<std::string> devCards;
	
	void setUp(gameBoard& board);
	void playerTurn(gameBoard& board, int roll);
	void botTurn(gameBoard& board, int roll);
	void gameLoop();
	void drawer(gameBoard& board);
	void initialize(gameBoard& empty);
	int nearVertex(sf::Vector2i coord, bool house);
	int nearEdge(sf::Vector2f coord);

	gameBoard();
	~gameBoard();
};

#endif