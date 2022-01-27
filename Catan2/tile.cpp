#include "Tile.h";

gameTile::gameTile() {
	this->name = "blank";
	this->robber = false;
	this->coord = { 0,0 };
	this->index = 0;
	this->robber = false;
}

gameTile::gameTile(std::string name, bool robber, int index, sf::Vector2f coord, sf::Texture resource1, sf::Sprite resource, sf::Texture number, sf::Sprite num) {
	this->name = name;
	this->robber = robber;
	this->index = index;
	this->coord = coord;
	this->resource1 = resource1;
	this->resource = resource;
	this->number = number;
	this->num = num;

};