#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <map>
#include "SFML/Graphics.hpp"
class Player {
public:
	int numSignature;
	std::string color;
	std::map<std::string, int> inventory;
	std::map<std::string, int> playerDevCards;
	std::vector<sf::Vector2f> settleCoord;
	std::vector<sf::Vector2f> cityCoord;
	std::vector<std::pair<sf::Vector2f, int>> roadCoordAndAngle;

	int getLongestRoad();

	Player();
};

#endif // !PLAYER_HPP

