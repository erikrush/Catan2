#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class gameTile {
public:
	std::string name;
	bool robber;
	int tileNum;
	int index;
	sf::Vector2f coord;
	sf::Texture resource1;
	sf::Sprite resource;
	sf::Texture number;
	sf::Sprite num;
	gameTile();
	gameTile(std::string name, bool robber, int index, sf::Vector2f coord, sf::Texture resource1, sf::Sprite resource, sf::Texture number, sf::Sprite num);
};
#endif

