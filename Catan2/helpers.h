#pragma once
#include "Board.h"
bool validSetUpHouse(sf::Vector2f coord, gameBoard& board) {
	for (int i = 0; i < board.players.size(); i++) {
		for (int j = 0; j < board.players.at(i)->settleCoord.size(); j++) {
			if (coord == board.players.at(i)->settleCoord.at(j)) {
				return false;
			}
		}
	}
	for (int i = 0; i < board.players.size(); i++) {
		for (int j = 0; j < board.players.at(i)->settleCoord.size(); j++) {
			if (std::abs(coord.x - board.players.at(i)->settleCoord.at(j).x) < 60 && std::abs(coord.y - board.players.at(i)->settleCoord.at(j).y) < 60) {
				return false;
			}
		}
	}
	return true;
}
bool validHouse(sf::Vector2f coord, gameBoard& board) {
	for (int i = 0; i < board.players.size(); i++) {
		for (int j = 0; j < board.players.at(i)->settleCoord.size(); j++) {
			if (coord == board.players.at(i)->settleCoord.at(j)) {
				return false;
			}
		}
	}
	for (int i = 0; i < board.players.size(); i++) {
		for (int j = 0; j < board.players.at(i)->settleCoord.size(); j++) {
			if (std::abs(coord.x - board.players.at(i)->settleCoord.at(j).x) < 60 && std::abs(coord.y - board.players.at(i)->settleCoord.at(j).y) < 60) {
				return false;
			}
		}
	}
	for (int i = 0; i < board.players.at(board.turn % 4)->roadCoordAndAngle.size(); i++) {
		if (std::abs(coord.x - board.players.at(board.turn % 4)->roadCoordAndAngle.at(i).first.x) < 30 && std::abs(coord.y - board.players.at(board.turn % 4)->roadCoordAndAngle.at(i).first.y) < 30) {
			return true;
		}
	}

	return false;
}

bool validRoad(sf::Vector2f coord, gameBoard& board, int turn) {
	for (int j = 0; j < board.players.size(); j++) {
		for (int i = 0; i < board.players.at(j)->roadCoordAndAngle.size(); i++) {
			if (coord == board.players.at(j)->roadCoordAndAngle.at(i).first) {
				return false;
			}
		}
	}

	if (board.turn >= 0) {
		for (int j = 0; j < board.players.at(turn)->roadCoordAndAngle.size(); j++) {
			if (std::abs(coord.x - board.players.at(turn)->roadCoordAndAngle.at(j).first.x) < 59 && std::abs(coord.y - board.players.at(turn)->roadCoordAndAngle.at(j).first.y) < 59) {
				return true;

			}
		}
	}
	if (board.players.at(turn)->settleCoord.size() == 2) {
		if (std::abs(coord.x - board.players.at(turn)->settleCoord.at(0).x) < 30 && std::abs(coord.y - board.players.at(turn)->settleCoord.at(0).y) < 30) {
			return false;
		}
		if (std::abs(coord.x - board.players.at(turn)->settleCoord.at(1).x) < 30 && std::abs(coord.y - board.players.at(turn)->settleCoord.at(1).y) < 30) {
			return true;
		}

	}
	if (board.players.at(turn)->settleCoord.size() == 1) {
		if (std::abs(coord.x - board.players.at(turn)->settleCoord.at(0).x) < 30 && std::abs(coord.y - board.players.at(turn)->settleCoord.at(0).y) < 30) {
			return true;
		}

	}

	return false;
}

std::vector< unsigned int> stringToRGB(std::string color) {
	if (color == "red") {
		return { 250, 66, 66, 255 };
	}
	else if (color == "orange") {
		return { 251, 127, 3, 255 };
	}
	else if (color == "green") {
		return { 53,214,4,255 };
	}
	else {
		return { 35,20,250,255 };
	}
}

std::vector<sf::Vector2f> roadsFromSettle(sf::Vector2f coord, gameBoard& board) {
	std::vector<sf::Vector2f> coords;
	if (board.nearEdge({ coord.x - 33, coord.y - 13 }) != -1) {
		coords.push_back(board.edges.at(board.nearEdge({ coord.x - 33, coord.y - 13 })).first);

	}
	if (board.nearEdge({ coord.x + 33, coord.y - 13 }) != -1) {
		coords.push_back(board.edges.at(board.nearEdge({ coord.x + 33, coord.y - 13 })).first);

	}
	if (board.nearEdge({ coord.x , coord.y + 25 }) != -1) {
		coords.push_back(board.edges.at(board.nearEdge({ coord.x, coord.y + 25 })).first);

	}
	if (board.nearEdge({ coord.x , coord.y - 25 }) != -1) {
		coords.push_back(board.edges.at(board.nearEdge({ coord.x , coord.y - 25 })).first);
	}
	if (board.nearEdge({ coord.x - 33, coord.y + 13 }) != -1) {
		coords.push_back(board.edges.at(board.nearEdge({ coord.x - 33, coord.y + 13 })).first);

	}
	if (board.nearEdge({ coord.x + 33, coord.y + 13 }) != -1) {
		coords.push_back(board.edges.at(board.nearEdge({ coord.x + 33, coord.y + 13 })).first);

	}
	return coords;
}

std::vector<int> resourcesFromVertex(sf::Vector2f coord, gameBoard& board) {
	std::vector<int> tileNums;
	for (int i = 0; i < board.tiles.size(); i++) {
		//bottom
		if (std::abs((coord.x - board.tiles.at(i)->resource1.getSize().x / 2) - board.tiles.at(i)->coord.x) < 5 && std::abs((coord.y - board.tiles.at(i)->resource1.getSize().y) - board.tiles.at(i)->coord.y) < 5) {
			tileNums.push_back(i);

		}
		if (std::abs((coord.x - board.tiles.at(i)->resource1.getSize().x) - board.tiles.at(i)->coord.x) < 5 && std::abs((coord.y - board.tiles.at(i)->resource1.getSize().y / 4) - board.tiles.at(i)->coord.y) < 5) {
			tileNums.push_back(i);

		}
		if (std::abs((coord.x) - board.tiles.at(i)->coord.x) < 5 && std::abs((coord.y - board.tiles.at(i)->resource1.getSize().y / 4) - board.tiles.at(i)->coord.y) < 5) {
			tileNums.push_back(i);

		}
		//top
		if (std::abs((coord.x - board.tiles.at(i)->resource1.getSize().x / 2) - board.tiles.at(i)->coord.x) < 5 && std::abs((coord.y) - board.tiles.at(i)->coord.y) < 5) {
			tileNums.push_back(i);

		}
		if (std::abs((coord.x) - board.tiles.at(i)->coord.x) < 5 && std::abs((coord.y - (board.tiles.at(i)->resource1.getSize().y * 3) / 4) - board.tiles.at(i)->coord.y) < 5) {
			tileNums.push_back(i);

		}
		if (std::abs((coord.x - board.tiles.at(i)->resource1.getSize().x) - board.tiles.at(i)->coord.x) < 5 && std::abs((coord.y - (board.tiles.at(i)->resource1.getSize().y * 3) / 4) - board.tiles.at(i)->coord.y) < 5) {
			tileNums.push_back(i);

		}
	}
	return tileNums;
}

std::pair<int, std::string> getHighestPoints(gameBoard& board) {
	int highestPoints = 0;
	int playersNumber = -1;
	for (int i = 0; i < board.players.size(); i++) {
		int points = board.players.at(i)->settleCoord.size() + board.players.at(i)->cityCoord.size() + board.players.at(i)->playerDevCards["victory point"];
		if (points > highestPoints) {
			highestPoints = points;
			playersNumber = i;
		}
	}
	return { highestPoints, board.players.at(playersNumber)->color };
}
std::vector<sf::Text> sideMenuLeftSetUp(gameBoard& board) {
	std::vector<sf::Text> menu;

	sf::Text playerColor;
	playerColor.setString("You Are " + board.players.at(board.playerNum)->color);
	playerColor.setFillColor(sf::Color::White);
	playerColor.setFont(board.font);
	playerColor.setPosition({ 25.f, 25.f });
	menu.push_back(playerColor);

	sf::Text inventory;
	inventory.setString("Inventory:");
	inventory.setFillColor(sf::Color::White);
	inventory.setFont(board.font);
	inventory.setPosition({ 25.f, 125.f });
	menu.push_back(inventory);

	sf::Text wheat;
	wheat.setString(std::to_string(board.players.at(board.playerNum)->inventory["wheatTile"]) + " Wheat");
	wheat.setFillColor(sf::Color::White);
	wheat.setFont(board.font);
	wheat.setPosition(35.f, 175.f);
	menu.push_back(wheat);

	sf::Text stone;
	stone.setString(std::to_string(board.players.at(board.playerNum)->inventory["stoneTile"]) + " Stone");
	stone.setFillColor(sf::Color::White);
	stone.setFont(board.font);
	stone.setPosition(35.f, 225.f);
	menu.push_back(stone);

	sf::Text sheep;
	sheep.setString(std::to_string(board.players.at(board.playerNum)->inventory["sheepTile"]) + " Sheep");
	sheep.setFillColor(sf::Color::White);
	sheep.setFont(board.font);
	sheep.setPosition(35.f, 275.f);
	menu.push_back(sheep);

	sf::Text brick;
	brick.setString(std::to_string(board.players.at(board.playerNum)->inventory["brickTile"]) + " Brick");
	brick.setFillColor(sf::Color::White);
	brick.setFont(board.font);
	brick.setPosition(35.f, 325.f);
	menu.push_back(brick);

	sf::Text wood;
	wood.setString(std::to_string(board.players.at(board.playerNum)->inventory["woodTile"]) + " Wood");
	wood.setFillColor(sf::Color::White);
	wood.setFont(board.font);
	wood.setPosition(35.f, 375.f);
	menu.push_back(wood);

	sf::Text dev;
	dev.setString("Development Cards:");
	dev.setFillColor(sf::Color::White);
	dev.setFont(board.font);
	dev.setPosition({ 25.f,450.f });
	menu.push_back(dev);

	sf::Text knight;
	knight.setString(std::to_string(board.players.at(board.playerNum)->playerDevCards["knight"]) + " knights");
	knight.setFillColor(sf::Color::White);
	knight.setFont(board.font);
	knight.setCharacterSize(20);
	knight.setPosition({ 35.f, 490.f });
	menu.push_back(knight);

	sf::Text victory;
	victory.setString(std::to_string(board.players.at(board.playerNum)->playerDevCards["victory point"]) + " victory points");
	victory.setFillColor(sf::Color::White);
	victory.setFont(board.font);
	victory.setCharacterSize(20);
	victory.setPosition({ 35.f, 520.f });
	menu.push_back(victory);

	sf::Text roadB;
	roadB.setString(std::to_string(board.players.at(board.playerNum)->playerDevCards["road building"]) + " road building");
	roadB.setFillColor(sf::Color::White);
	roadB.setFont(board.font);
	roadB.setCharacterSize(20);
	roadB.setPosition({ 35.f, 550.f });
	menu.push_back(roadB);

	sf::Text monopoly;
	monopoly.setString(std::to_string(board.players.at(board.playerNum)->playerDevCards["monopoly"]) + " monopoly");
	monopoly.setFillColor(sf::Color::White);
	monopoly.setFont(board.font);
	monopoly.setCharacterSize(20);
	monopoly.setPosition({ 35.f, 580.f });
	menu.push_back(monopoly);

	sf::Text year;
	year.setString(std::to_string(board.players.at(board.playerNum)->playerDevCards["year of plenty"]) + " year of plenty");
	year.setFillColor(sf::Color::White);
	year.setFont(board.font);
	year.setCharacterSize(20);
	year.setPosition({ 35.f, 610.f });
	menu.push_back(year);

	return menu;
}
std::vector<sf::Text> sideMenuRightSetUp(gameBoard& board) {

	std::vector<sf::Text> menu;

	sf::Text roadText;
	roadText.setString("Build Road");
	roadText.setFont(board.font);
	roadText.setFillColor(sf::Color::White);
	roadText.setPosition({ 850.f, 50.f });
	menu.push_back(roadText);
	sf::Text settleText;
	settleText.setString("Build Settlement");
	settleText.setFont(board.font);
	settleText.setFillColor(sf::Color::White);
	settleText.setPosition({ 850.f,150.f });
	menu.push_back(settleText);
	sf::Text cityText;
	cityText.setString("Build City");
	cityText.setFont(board.font);
	cityText.setFillColor(sf::Color::White);
	cityText.setPosition({ 850.f,250.f });
	menu.push_back(cityText);
	sf::Text devText;
	devText.setString("Build Development");
	devText.setFont(board.font);
	devText.setFillColor(sf::Color::White);
	devText.setPosition({ 850.f, 350.f });
	menu.push_back(devText);
	sf::Text card;
	card.setString("Card");
	card.setFillColor(sf::Color::White);
	card.setFont(board.font);
	card.setPosition({ 950.f, 380.f });
	menu.push_back(card);
	sf::Text trade;
	trade.setString("Trade");
	trade.setFont(board.font);
	trade.setFillColor(sf::Color::White);
	trade.setPosition({ 850.f, 450.f });
	menu.push_back(trade);
	sf::Text endT;
	endT.setString("End Turn");
	endT.setFont(board.font);
	endT.setFillColor(sf::Color::White);
	endT.setPosition({ 800.f,600.f });
	menu.push_back(endT);
	return menu;
}

void updateResource(gameBoard& board, int roll) {

	for (int i = 0; i < board.players.size(); i++) {
		for (int j = 0; j < board.players.at(i)->settleCoord.size(); j++) {
			std::vector<int> resources = resourcesFromVertex(board.players.at(i)->settleCoord.at(j), board);
			for (int k = 0; k < resources.size(); k++) {
				if (board.tiles.at(resources.at(k))->tileNum == roll && !board.tiles.at(resources.at(k))->robber) {
					
					board.players.at(i)->inventory[board.tiles.at(resources.at(k))->name]++;
				}
			}
		}
	}

	for (int i = 0; i < board.players.size(); i++) {
		for (int j = 0; j < board.players.at(i)->cityCoord.size(); j++) {
			std::vector<int> resources = resourcesFromVertex(board.players.at(i)->cityCoord.at(j), board);
			for (int k = 0; k < resources.size(); k++) {
				if (board.tiles.at(resources.at(k))->tileNum == roll && !board.tiles.at(resources.at(k))->robber) {
					board.players.at(i)->inventory[board.tiles.at(resources.at(k))->name]++;
					
				}
			}
		}
	}
	board.sideMenuLeft = sideMenuLeftSetUp(board);
}

void sevenRolled(gameBoard& board) {
	bool playerMovedRobber = false;
	bool playerDiscarded = false;
	for (int i = 0; i < 4; i++) {

		int totalCards = board.players.at(i)->inventory["brickTile"] + board.players.at(i)->inventory["woodTile"] + board.players.at(i)->inventory["sheepTile"]
			+ board.players.at(i)->inventory["wheatTile"] + board.players.at(i)->inventory["stoneTile"];
		if (i == board.playerNum) {
			if (totalCards > 7 || board.turn % 4 == board.playerNum ) {
				if (totalCards > 7 && !playerDiscarded) {
					sf::Text discard;
					discard.setString("Discard " + std::to_string(totalCards / 2) + " cards");
					discard.setFillColor(sf::Color::White);
					discard.setFont(board.font);
					discard.setPosition({ 415.f, 25.f });
					board.sideMenuLeft.push_back(discard);
					board.drawer(board);
					int discarded = 0;
					while (discarded < totalCards / 2) {
						sf::Event click;
						while (board.window.pollEvent(click)) {
							if (click.type == sf::Event::Closed) {
								board.window.close();
							}
							if (click.type == sf::Event::MouseButtonPressed) {
								sf::Vector2f mouseLocation;

								mouseLocation.x = (float)sf::Mouse::getPosition(board.window).x;
								mouseLocation.y = (float)sf::Mouse::getPosition(board.window).y;
								if (board.sideMenuLeft.at(2).getGlobalBounds().contains(mouseLocation)) {
									board.sideMenuLeft.at(2).setOutlineColor(sf::Color::Yellow);
									board.sideMenuLeft.at(2).setOutlineThickness(1);
									board.drawer(board);
									std::chrono::milliseconds timeout(200);
									std::this_thread::sleep_for(timeout);
									board.sideMenuLeft.at(2).setOutlineColor(sf::Color::Transparent);
									board.players.at(i)->inventory["wheatTile"]--;
									board.sideMenuLeft = sideMenuLeftSetUp(board);


									board.sideMenuLeft.push_back(discard);
									board.drawer(board);
									discarded++;
								}
								if (board.sideMenuLeft.at(3).getGlobalBounds().contains(mouseLocation)) {
									board.sideMenuLeft.at(3).setOutlineColor(sf::Color::Yellow);
									board.sideMenuLeft.at(3).setOutlineThickness(1);
									board.drawer(board);
									std::chrono::milliseconds timeout(200);
									std::this_thread::sleep_for(timeout);
									board.sideMenuLeft.at(3).setOutlineColor(sf::Color::Transparent);
									board.players.at(i)->inventory["stoneTile"]--;
									board.sideMenuLeft = sideMenuLeftSetUp(board);


									board.sideMenuLeft.push_back(discard);
									board.drawer(board);
									discarded++;
								}
								if (board.sideMenuLeft.at(4).getGlobalBounds().contains(mouseLocation)) {
									board.sideMenuLeft.at(4).setOutlineColor(sf::Color::Yellow);
									board.sideMenuLeft.at(4).setOutlineThickness(1);
									board.drawer(board);
									std::chrono::milliseconds timeout(200);
									std::this_thread::sleep_for(timeout);
									board.sideMenuLeft.at(4).setOutlineColor(sf::Color::Transparent);
									board.players.at(i)->inventory["sheepTile"]--;
									board.sideMenuLeft = sideMenuLeftSetUp(board);

									board.sideMenuLeft.push_back(discard);
									board.drawer(board);
									discarded++;
								}
								if (board.sideMenuLeft.at(5).getGlobalBounds().contains(mouseLocation)) {
									board.sideMenuLeft.at(5).setOutlineColor(sf::Color::Yellow);
									board.sideMenuLeft.at(5).setOutlineThickness(1);
									board.drawer(board);
									std::chrono::milliseconds timeout(200);
									std::this_thread::sleep_for(timeout);
									board.sideMenuLeft.at(5).setOutlineColor(sf::Color::Transparent);
									board.players.at(i)->inventory["brickTile"]--;
									board.sideMenuLeft = sideMenuLeftSetUp(board);

									board.sideMenuLeft.push_back(discard);
									board.drawer(board);
									discarded++;
								}
								if (board.sideMenuLeft.at(6).getGlobalBounds().contains(mouseLocation)) {
									board.sideMenuLeft.at(6).setOutlineColor(sf::Color::Yellow);
									board.sideMenuLeft.at(6).setOutlineThickness(1);
									board.drawer(board);
									std::chrono::milliseconds timeout(200);
									std::this_thread::sleep_for(timeout);
									board.sideMenuLeft.at(6).setOutlineColor(sf::Color::Transparent);
									board.players.at(i)->inventory["woodTile"]--;
									board.sideMenuLeft = sideMenuLeftSetUp(board);

									board.sideMenuLeft.push_back(discard);
									board.drawer(board);
									discarded++;
								}
							}
						}
					}
					playerDiscarded = true;
					board.sideMenuLeft.erase(board.sideMenuLeft.begin() + (board.sideMenuLeft.size() - 1));
				}
				
				if (board.turn % 4 == board.playerNum) {
					sf::Text moveRobber;
					moveRobber.setString("Move the robber");
					moveRobber.setFillColor(sf::Color::White);
					moveRobber.setFont(board.font);
					moveRobber.setPosition({ 415.f, 25.f });
					board.sideMenuLeft.push_back(moveRobber);
					board.drawer(board);
					int robberTileIndex = -1;
					for (int k = 0; k < board.tiles.size(); k++) {
						if (board.tiles.at(k)->robber) {
							robberTileIndex = k;
						}
					}
					sf::Vector2f robberCoord;
					robberCoord.x = board.tiles.at(robberTileIndex)->coord.x + 30;
					robberCoord.y = board.tiles.at(robberTileIndex)->coord.y + 32;

					int robberIndex = -1;
					for (int k = 0; k < board.sprites.size(); k++) {
						if (board.sprites.at(k).getPosition() == robberCoord) {
							robberIndex = k;
						}
					}

					bool robberMoved = false;
					while (!robberMoved) {
						sf::Event click1;
						while (board.window.pollEvent(click1)) {
							if (click1.type == sf::Event::Closed) {
								board.window.close();
							}
							if (click1.type == sf::Event::MouseButtonPressed) {
								sf::Vector2f mouseLocation1;

								mouseLocation1.x = (float)sf::Mouse::getPosition(board.window).x;
								mouseLocation1.y = (float)sf::Mouse::getPosition(board.window).y;
								for (int l = 0; l < board.tiles.size(); l++) {
									if (board.tiles.at(l)->resource.getGlobalBounds().contains(mouseLocation1)) {
										board.sprites.at(robberIndex).setPosition({ board.tiles.at(l)->resource.getPosition().x + 30, board.tiles.at(l)->resource.getPosition().y + 32 });
										board.tiles.at(robberTileIndex)->robber = false;
										board.tiles.at(l)->robber = true;
										robberMoved = true;
										board.sideMenuLeft.erase(board.sideMenuLeft.begin() + (board.sideMenuLeft.size() - 1));
									}
								}
							}
						}
					}


					playerMovedRobber = true;
				}
			}
			
		}
		else {
			if (totalCards > 7) {
				int discarded = 0;
				while (discarded < totalCards / 2) {
					for (auto const& iter : board.players.at(i)->inventory) {
						if (board.players.at(i)->inventory[iter.first] > 0) {
							board.players.at(i)->inventory[iter.first]--;
							discarded++;
						}
					}
				}
			}
			if (!playerMovedRobber) {
				int robberTileIndex = -1;
				for (int k = 0; k < board.tiles.size(); k++) {
					if (board.tiles.at(k)->robber) {
						robberTileIndex = k;
					}
				}
				sf::Vector2f robberCoord;
				robberCoord.x = board.tiles.at(robberTileIndex)->coord.x + 30;
				robberCoord.y = board.tiles.at(robberTileIndex)->coord.y + 32;

				int robberIndex = -1;
				for (int k = 0; k < board.sprites.size(); k++) {
					if (board.sprites.at(k).getPosition() == robberCoord) {
						robberIndex = k;
					}
				}

				std::srand(time(0));
				int newRobberIndex = rand() % board.tiles.size();
				board.sprites.at(robberIndex).setPosition({ board.tiles.at(newRobberIndex)->coord.x + 30, board.tiles.at(newRobberIndex)->coord.y + 32 });
				board.tiles.at(robberTileIndex)->robber = false;
				board.tiles.at(newRobberIndex)->robber = true;

			}
		}
	}
}