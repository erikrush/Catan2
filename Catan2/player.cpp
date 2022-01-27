#include "player.h"

int Player::getLongestRoad() {

	return 0;
}

Player::Player() {
	this->numSignature = 10;
	this->settleCoord = {};
	this->cityCoord = {};
	this->color = "";
	this->playerDevCards["knight"] = 0;
	this->playerDevCards["victory point"] = 0;
	this->playerDevCards["road building"] = 0;
	this->playerDevCards["monopoly"] = 0;
	this->playerDevCards["year of plenty"] = 0;
	this->inventory["wheatTile"] = 0;
	this->inventory["stoneTile"] = 0;
	this->inventory["sheepTile"] = 0;
	this->inventory["brickTile"] = 0;
	this->inventory["woodTile"] = 0;
	this->roadCoordAndAngle = {};
}