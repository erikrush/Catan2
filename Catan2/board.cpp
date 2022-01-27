#include "board.h"
#include "helpers.h"
#include <random>
#include <iostream>
void gameBoard::initialize(gameBoard& temp) {

	std::srand(time(0));
	std::vector<int> cardList = { 14,5,2,2,2 };
	while (temp.devCards.size() < 25) {
		int cardIndex = rand() % 5;
		if (cardList.at(cardIndex) > 0) {
			if (cardIndex == 0) {
				temp.devCards.push("knight");
			}
			else if (cardIndex == 1) {
				temp.devCards.push("victory point");
			}
			else if (cardIndex == 2) {
				temp.devCards.push("road building");
			}
			else if (cardIndex == 3) {
				temp.devCards.push("monopoly");
			}
			else if (cardIndex == 4) {
				temp.devCards.push("year of plenty");
			}
			cardList.at(cardIndex)--;
		}
	}

	std::map<int, int> tileAmount;
	std::map<int, std::string> numRes;
	std::map<int, int> numberFreq;

	temp.setUpTurns = { 0,1,2,3,3,2,1,0 };

	sf::Texture* back = new sf::Texture();
	(*back).loadFromFile("catanImages/oceanBackground.jpg");
	temp.textureList.push_back(back);
	temp.sprites.push_back(sf::Sprite(*back));


	numberFreq[2] = 1;
	numberFreq[3] = 2;
	numberFreq[4] = 2;
	numberFreq[5] = 2;
	numberFreq[6] = 2;
	numberFreq[7] = 0;
	numberFreq[8] = 2;
	numberFreq[9] = 2;
	numberFreq[10] = 2;
	numberFreq[11] = 2;
	numberFreq[12] = 1;

	tileAmount[0] = 1;
	tileAmount[1] = 3;
	tileAmount[2] = 3;
	tileAmount[3] = 4;
	tileAmount[4] = 4;
	tileAmount[5] = 4;

	numRes[0] = "desertTile";
	numRes[1] = "stoneTile";
	numRes[2] = "brickTile";
	numRes[3] = "woodTile";
	numRes[4] = "wheatTile";
	numRes[5] = "sheepTile";

	Player* play = new Player();
	play->numSignature = 0;
	play->color = "red";
	temp.players.push_back(play);
	Player* play1 = new Player();
	play1->numSignature = 1;
	play1->color = "blue";
	temp.players.push_back(play1);
	Player* play2 = new Player();
	play2->numSignature = 2;
	play2->color = "green";
	temp.players.push_back(play2);
	Player* play3 = new Player();
	play3->numSignature = 3;
	play3->color = "orange";
	temp.players.push_back(play3);

	std::srand(time(0));
	temp.playerNum = rand() % 4;
	
	int i1 = 0;
	int num2 = rand() % 11 + 2;
	while (temp.tiles.size() < 19) {
		int num = rand() % 6;

		sf::Texture tiles;

		sf::Texture numberT;

		gameTile* temper = new gameTile();

		if (tileAmount[num] > 0) {

			tiles.loadFromFile("catanImages/" + numRes[num] + ".png");


			temper->index = i1;
			temper->name = numRes[num];
			temper->resource1 = tiles;

			if (temper->name != "desertTile") {
				while (numberFreq[num2] == 0) {

					num2 = rand() % 11 + 2;
				}

				numberT.loadFromFile("catanImages/" + std::to_string(num2) + ".png");

				temper->number = numberT;
				temper->tileNum = num2;
				numberFreq[num2]--;
				num2 = rand() % 11 + 2;
			}
			temp.tiles.push_back(temper);

			temp.tiles.at(i1)->resource.setTexture(temp.tiles.at(i1)->resource1);

			temp.tiles.at(i1)->num.setTexture(temp.tiles.at(i1)->number);
			tileAmount[num]--;
			i1++;

		}
	}
	
	sf::Vector2f location = { 400,100 };
	for (int i = 0; i < 3; i++) {
		temp.tiles.at(i)->coord = location;
		temp.tiles.at(i)->resource.setPosition(location);
		temp.tiles.at(i)->num.setPosition({ location.x + 30, location.y + 15 });

		//vertices
		temp.vertices.push_back({ location.x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
		temp.vertices.push_back({ location.x + (float)(temp.tiles.at(0)->resource1.getSize().x / 2.0), location.y });

		location.x += temp.tiles.at(i)->resource1.getSize().x;
	}
	location.x -= temp.tiles.at(0)->resource1.getSize().x;
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
	location.x = temp.tiles.at(0)->coord.x - (temp.tiles.at(0)->resource1.getSize().x / 2.0);
	location.y = temp.tiles.at(0)->coord.y + (temp.tiles.at(0)->resource1.getSize().y - (temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))));

	for (int i = 3; i < 7; i++) {
		temp.tiles.at(i)->coord = location;
		temp.tiles.at(i)->resource.setPosition(location);
		temp.tiles.at(i)->num.setPosition({ location.x + 30, location.y + 15 });

		//vertices
		temp.vertices.push_back({ location.x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
		temp.vertices.push_back({ location.x + (float)(temp.tiles.at(0)->resource1.getSize().x / 2.0), location.y });




		location.x += temp.tiles.at(i)->resource1.getSize().x;
	}
	location.x -= temp.tiles.at(0)->resource1.getSize().x;
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
	location.x = temp.tiles.at(3)->coord.x - (temp.tiles.at(3)->resource1.getSize().x / 2.0);
	location.y = temp.tiles.at(3)->coord.y + (temp.tiles.at(3)->resource1.getSize().y - (temp.tiles.at(3)->resource1.getSize().x / (2 * std::sqrt(3))));

	for (int i = 7; i < 12; i++) {
		temp.tiles.at(i)->coord = location;
		temp.tiles.at(i)->resource.setPosition(location);
		temp.tiles.at(i)->num.setPosition({ location.x + 30, location.y + 15 });

		//vertices
		temp.vertices.push_back({ location.x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
		temp.vertices.push_back({ location.x + (float)(temp.tiles.at(0)->resource1.getSize().x / 2.0), location.y });

		location.x += temp.tiles.at(i)->resource1.getSize().x;
	}
	location.x -= temp.tiles.at(0)->resource1.getSize().x;
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x , location.y + (float)(temp.tiles.at(12)->resource1.getSize().y - (temp.tiles.at(12)->resource1.getSize().x / (2 * std::sqrt(3)))) });
	location.x = temp.tiles.at(7)->coord.x + (temp.tiles.at(7)->resource1.getSize().x / 2.0);
	location.y = temp.tiles.at(7)->coord.y + (temp.tiles.at(7)->resource1.getSize().y - (temp.tiles.at(7)->resource1.getSize().x / (2 * std::sqrt(3))));
	temp.vertices.push_back({ location.x - (float)(temp.tiles.at(7)->resource1.getSize().x / 2.0), location.y });
	for (int i = 12; i < 16; i++) {
		temp.tiles.at(i)->coord = location;
		temp.tiles.at(i)->resource.setPosition(location);
		temp.tiles.at(i)->num.setPosition({ location.x + 30, location.y + 15 });


		//vertices
		temp.vertices.push_back({ location.x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
		temp.vertices.push_back({ location.x + (float)(temp.tiles.at(0)->resource1.getSize().x / 2.0), location.y });

		location.x += temp.tiles.at(i)->resource1.getSize().x;
	}
	location.x -= temp.tiles.at(0)->resource1.getSize().x;
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x , location.y + (float)(temp.tiles.at(12)->resource1.getSize().y - (temp.tiles.at(12)->resource1.getSize().x / (2 * std::sqrt(3)))) });
	location.x = temp.tiles.at(12)->coord.x + (temp.tiles.at(12)->resource1.getSize().x / 2.0);
	location.y = temp.tiles.at(12)->coord.y + (temp.tiles.at(12)->resource1.getSize().y - (temp.tiles.at(12)->resource1.getSize().x / (2 * std::sqrt(3))));
	temp.vertices.push_back({ location.x - (float)(temp.tiles.at(7)->resource1.getSize().x / 2.0), location.y });
	for (int i = 16; i < 19; i++) {
		temp.tiles.at(i)->coord = location;
		temp.tiles.at(i)->resource.setPosition(location);
		temp.tiles.at(i)->num.setPosition({ location.x + 30, location.y + 15 });

		//vertices
		temp.vertices.push_back({ location.x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
		temp.vertices.push_back({ location.x + (float)(temp.tiles.at(0)->resource1.getSize().x / 2.0), location.y });
		temp.vertices.push_back({ location.x, location.y + (float)(temp.tiles.at(12)->resource1.getSize().y - (temp.tiles.at(12)->resource1.getSize().x / (2 * std::sqrt(3)))) });
		temp.vertices.push_back({ location.x + (float)(temp.tiles.at(0)->resource1.getSize().x / 2.0) , location.y + (float)temp.tiles.at(0)->resource1.getSize().y });

		location.x += temp.tiles.at(i)->resource1.getSize().x;
	}
	location.x -= temp.tiles.at(0)->resource1.getSize().x;
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x, location.y + (float)(temp.tiles.at(0)->resource1.getSize().x / (2 * std::sqrt(3))) });
	temp.vertices.push_back({ location.x + temp.tiles.at(2)->resource1.getSize().x , location.y + (float)(temp.tiles.at(12)->resource1.getSize().y - (temp.tiles.at(12)->resource1.getSize().x / (2 * std::sqrt(3)))) });

	//edge generation
	
	for (int i = 0; i < temp.tiles.size(); i++) {
		std::pair<sf::Vector2f, int> temper;
		temper.first = { temp.tiles.at(i)->coord.x, temp.tiles.at(i)->coord.y + (temp.tiles.at(i)->resource1.getSize().y / 2) };
		temper.second = 90;
		temp.edges.push_back(temper);

		temper.first = { temp.tiles.at(i)->coord.x + (temp.tiles.at(i)->resource1.getSize().x / 4), temp.tiles.at(i)->coord.y + (temp.tiles.at(i)->resource1.getSize().y / 8) };
		temper.second = 330;
		temp.edges.push_back(temper);

		temper.first = { temp.tiles.at(i)->coord.x + (float)(temp.tiles.at(i)->resource1.getSize().x * (0.75)),  temp.tiles.at(i)->coord.y + (temp.tiles.at(i)->resource1.getSize().y / 8) };
		temper.second = 30;
		temp.edges.push_back(temper);

		if (i == 2 || i == 6 || i == 11 || i == 15 || i == 18) {
			temper.first = { temp.tiles.at(i)->coord.x + temp.tiles.at(i)->resource1.getSize().x, temp.tiles.at(i)->coord.y + (temp.tiles.at(i)->resource1.getSize().y / 2) };
			temper.second = 90;
			temp.edges.push_back(temper);
		}
		if (i == 7 || i == 12) {
			temper.first = { temp.tiles.at(i)->coord.x + (float)(temp.tiles.at(i)->resource1.getSize().x / 4), temp.tiles.at(i)->coord.y + (float)(temp.tiles.at(i)->resource1.getSize().y * (0.875)) };
			temper.second = 30;
			temp.edges.push_back(temper);
		}
		if (i == 11 || i == 15) {
			temper.first = { temp.tiles.at(i)->coord.x + (float)(temp.tiles.at(i)->resource1.getSize().x * (0.75)) ,temp.tiles.at(i)->coord.y + (float)(temp.tiles.at(i)->resource1.getSize().y * (0.875)) };
			temper.second = 330;
			temp.edges.push_back(temper);
		}
	}
	std::pair<sf::Vector2f, int> temper;
	for (int i = 16; i < temp.tiles.size(); i++) {
		temper.first = { temp.tiles.at(i)->coord.x + (float)(temp.tiles.at(i)->resource1.getSize().x / 4), temp.tiles.at(i)->coord.y + (float)(temp.tiles.at(i)->resource1.getSize().y * (0.875)) };
		temper.second = 30;
		temp.edges.push_back(temper);
		temper.first = { temp.tiles.at(i)->coord.x + (float)(temp.tiles.at(i)->resource1.getSize().x * (0.75)), temp.tiles.at(i)->coord.y + (float)(temp.tiles.at(i)->resource1.getSize().y * (0.875)) };
		temper.second = 330;
		temp.edges.push_back(temper);
	}
	for (int j = 0; j < temp.tiles.size(); j++) {
		if (temp.tiles.at(j)->name == "desertTile") {
			temp.tiles.at(j)->robber = true;
			sf::Texture* robber = new sf::Texture();
			(*robber).loadFromFile("catanImages/robber.png");
			sf::Sprite robber1(*robber);
			robber1.setPosition({ temp.tiles.at(j)->coord.x + 30, temp.tiles.at(j)->coord.y + 32 });
			temp.textureList.push_back(robber);
			temp.sprites.push_back(robber1);
		}
	}
	//testing edge positions and angles and rectangle shapes....actually looks good we'll keep it. 
	for (int i = 0; i < temp.edges.size(); i++) {
		sf::RectangleShape rect(sf::Vector2f(60.f, 6.f));
		rect.setOrigin(sf::Vector2f(30.f, 3.f));
		rect.setFillColor(sf::Color(255, 255, 255));
		sf::Vector2f vect12 = temp.edges.at(i).first;

		rect.setRotation((float)temp.edges.at(i).second);
		rect.setPosition(vect12.x, vect12.y);
		sf::RectangleShape* rect1 = new sf::RectangleShape(rect);
		temp.shapes.push_back(rect1);
	}
	temp.sideMenuLeft = sideMenuLeftSetUp(temp);
	temp.drawer(temp);
	
	
}

void gameBoard::setUp(gameBoard& board) {
	
	for (int i = 0; i < board.setUpTurns.size(); i++) {
		if (board.setUpTurns.at(i) == board.playerNum) {
			bool secHouse = false;
			sf::Event click;
			int numHouses = board.players.at(board.setUpTurns.at(i))->settleCoord.size();
			if (numHouses == 1) {
				secHouse = true;
			}
			while (board.players.at(board.setUpTurns.at(i))->settleCoord.size() <= numHouses) {
				while (board.window.pollEvent(click)) {
					if (click.type == sf::Event::Closed) {
						board.window.close();
					}
					if (click.type == sf::Event::MouseButtonPressed) {
						int verticeClick = -2;
						verticeClick = board.nearVertex(sf::Mouse::getPosition(board.window), true);
						if (verticeClick < 0) {
							break;
						}
						else if (!validSetUpHouse(board.vertices.at(verticeClick), board)) {
							break;
						}
						else {
							board.players.at(board.setUpTurns.at(i))->settleCoord.push_back(board.vertices.at(verticeClick));
							sf::Texture* text1 = new sf::Texture();
							text1->loadFromFile("catanImages/" + board.players.at(board.setUpTurns.at(i))->color + "House.png");
							board.textureList.push_back(text1);
							sf::Sprite sp;
							sp.setTexture(*text1);
							sp.setPosition({ board.vertices.at(verticeClick).x - 15, board.vertices.at(verticeClick).y - 16 });
							board.sprites.push_back(sp);
							board.drawer(board);
							if (secHouse) {
								std::vector<int> res = resourcesFromVertex(board.vertices.at(verticeClick), board);
								for (int k = 0; k < res.size(); k++) {
									board.players.at(board.setUpTurns.at(i))->inventory[board.tiles.at(res.at(k))->name]++;
								}
								board.sideMenuLeft = sideMenuLeftSetUp(board);
								secHouse = false;
							}
							std::chrono::milliseconds timeSpan(350);
							std::this_thread::sleep_for(timeSpan);
						}
					}
				}
			}
			
			
			int numRoads = board.players.at(board.setUpTurns.at(i))->roadCoordAndAngle.size();
			while (board.players.at(board.setUpTurns.at(i))->roadCoordAndAngle.size() <= numRoads) {
				
				while (board.window.pollEvent(click)) {
					if (click.type == sf::Event::Closed) {
						board.window.close();
					}
					if (click.type == sf::Event::MouseButtonPressed) {
						
						int roadClick = -2;
						sf::Vector2i mouseClick = sf::Mouse::getPosition(board.window);
						roadClick = board.nearEdge({ (float)mouseClick.x, (float)mouseClick.y });
						if (roadClick < 0) {
							break;
						}
						else if (!validRoad(board.edges.at(roadClick).first, board, board.setUpTurns.at(i))) {
							break;
						}
						else {
							board.players.at(board.setUpTurns.at(i))->roadCoordAndAngle.push_back(board.edges.at(roadClick));
							sf::RectangleShape rect(sf::Vector2f(58.f, 4.f));
							rect.setOrigin(sf::Vector2f(29.f, 2.f));
							std::vector<unsigned int> test = stringToRGB(board.players.at(board.setUpTurns.at(i))->color);
							rect.setFillColor(sf::Color(test.at(0), test.at(1), test.at(2)));
							sf::Vector2f vect12 = board.edges.at(roadClick).first;

							rect.setRotation((float)board.edges.at(roadClick).second);
							rect.setPosition(vect12.x, vect12.y);
							sf::RectangleShape* rect1 = new sf::RectangleShape(rect);
							board.shapes.push_back(rect1);
							board.drawer(board);
							std::chrono::milliseconds timeSpan(350);
							std::this_thread::sleep_for(timeSpan);
						}
					}
				}
			}
		}
		else {
			std::srand(time(0));
			int settleVert;
			bool secHouse = false;
			int numHouse = board.players.at(board.setUpTurns.at(i))->settleCoord.size();
			if (numHouse == 1) {
				secHouse = true;
			}
			while (board.players.at(board.setUpTurns.at(i))->settleCoord.size() <= numHouse) {
				 settleVert = rand() % board.vertices.size();
				if (validSetUpHouse(board.vertices.at(settleVert), board)) {
					board.players.at(board.setUpTurns.at(i))->settleCoord.push_back(board.vertices.at(settleVert));
					sf::Texture* text1 = new sf::Texture();
					text1->loadFromFile("catanImages/" + board.players.at(board.setUpTurns.at(i))->color + "House.png");
					board.textureList.push_back(text1);
					sf::Sprite sp;
					sp.setTexture(*text1);
					sp.setPosition({ board.vertices.at(settleVert).x - 15, board.vertices.at(settleVert).y - 16 });
					board.sprites.push_back(sp);
					board.drawer(board);
					if (secHouse) {
						std::vector<int> res = resourcesFromVertex(board.vertices.at(settleVert), board);
						for (int k = 0; k < res.size(); k++) {
							if (board.tiles.at(res.at(k))->name != "desertTile") {
								
								board.players.at(board.setUpTurns.at(i))->inventory[board.tiles.at(res.at(k))->name]++;
							}
						}
						secHouse = false;
					}
					std::chrono::milliseconds timeSpan(350);
					std::this_thread::sleep_for(timeSpan);
				}
			}
			int numRoad = board.players.at(board.setUpTurns.at(i))->roadCoordAndAngle.size();
			while (board.players.at(board.setUpTurns.at(i))->roadCoordAndAngle.size() <= numRoad) {
				int roadVert = 0;
				std::vector<sf::Vector2f> possRoads = roadsFromSettle(board.players.at(board.setUpTurns.at(i))->settleCoord.at(board.players.at(setUpTurns.at(i))->settleCoord.size() - 1), board);
				
				for (int j = 0; j < possRoads.size(); j++) {
					if (validRoad(possRoads.at(j), board, board.setUpTurns.at(i))) {
						roadVert = nearEdge(possRoads.at(j));
						break;
					}
				}
				if (validRoad(board.edges.at(roadVert).first, board, board.setUpTurns.at(i))) {
					board.players.at(board.setUpTurns.at(i))->roadCoordAndAngle.push_back(board.edges.at(roadVert));
					sf::RectangleShape rect(sf::Vector2f(58.f, 4.f));
					rect.setOrigin(sf::Vector2f(29.f, 2.f));
					std::vector<unsigned int> test = stringToRGB(board.players.at(board.setUpTurns.at(i))->color);
					rect.setFillColor(sf::Color(test.at(0), test.at(1), test.at(2)));
					sf::Vector2f vect12 = board.edges.at(roadVert).first;

					rect.setRotation((float)board.edges.at(roadVert).second);
					rect.setPosition(vect12.x, vect12.y);
					sf::RectangleShape* rect1 = new sf::RectangleShape(rect);
					board.shapes.push_back(rect1);
					board.drawer(board);
					std::chrono::milliseconds timeSpan(350);
					std::this_thread::sleep_for(timeSpan);
				}
			}
		}
		
	}
}

void gameBoard::playerTurn(gameBoard& board, int roll){
	updateResource(board, roll);
	
	//testing resources
	
	board.drawer(board);

	

	bool endTurn = false;

	while (!endTurn) {
		sf::Event click;
		while (board.window.pollEvent(click)) {
			if (click.type == sf::Event::Closed) {
				board.window.close();
			}
			else if (click.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f mouseLocation;
				
				mouseLocation.x = (float)sf::Mouse::getPosition(board.window).x;
				mouseLocation.y = (float)sf::Mouse::getPosition(board.window).y;
				if (board.sideMenuRight.at(6).getGlobalBounds().contains(mouseLocation)) {
					board.sideMenuRight.at(6).setOutlineColor(sf::Color::Yellow);
					board.sideMenuRight.at(6).setOutlineThickness(1);
					board.drawer(board);
					std::chrono::milliseconds timeout(200);
					std::this_thread::sleep_for(timeout);
					board.sideMenuRight.at(6).setOutlineColor(sf::Color::Transparent);
					board.drawer(board);
					endTurn = true;
					
				}
				 if (board.sideMenuRight.at(0).getGlobalBounds().contains(mouseLocation) && board.players.at(board.turn % 4)->inventory.at("brickTile") >= 1 && board.players.at(board.turn % 4)->inventory.at("woodTile") >= 1) {
					board.sideMenuRight.at(0).setOutlineColor(sf::Color::Yellow);
					board.sideMenuRight.at(0).setOutlineThickness(1);
					board.drawer(board);
					std::chrono::milliseconds timeout(200);
					std::this_thread::sleep_for(timeout);
					board.sideMenuRight.at(0).setOutlineColor(sf::Color::Transparent);
					board.drawer(board);
					int numRoads = board.players.at(board.turn % 4)->roadCoordAndAngle.size();

					while (board.players.at(board.turn % 4)->roadCoordAndAngle.size() <= numRoads) {
						int roadClick = -2;
						sf::Event clicker3;
						while (window.pollEvent(clicker3)) {
							if (clicker3.type == sf::Event::MouseButtonPressed) {
								sf::Vector2i mouseClick = sf::Mouse::getPosition(board.window);
								roadClick = board.nearEdge({ (float)mouseClick.x, (float)mouseClick.y });
								if (roadClick < 0) {
									break;
								}
								else if (!validRoad(board.edges.at(roadClick).first, board, (board.turn % 4))) {
									break;
								}
								else {
									board.players.at(board.turn % 4)->roadCoordAndAngle.push_back(board.edges.at(roadClick));
									sf::RectangleShape rect(sf::Vector2f(58.f, 4.f));
									rect.setOrigin(sf::Vector2f(29.f, 2.f));
									std::vector<unsigned int> test = stringToRGB(board.players.at(board.turn % 4)->color);
									rect.setFillColor(sf::Color(test.at(0), test.at(1), test.at(2)));
									sf::Vector2f vect12 = board.edges.at(roadClick).first;

									rect.setRotation((float)board.edges.at(roadClick).second);
									rect.setPosition(vect12.x, vect12.y);
									sf::RectangleShape* rect1 = new sf::RectangleShape(rect);
									board.shapes.push_back(rect1);
									board.players.at(board.turn % 4)->inventory["brickTile"]--;
									board.players.at(board.turn % 4)->inventory["woodTile"]--;
									board.sideMenuLeft = sideMenuLeftSetUp(board);
									board.drawer(board);
								}
							}
						}
					}

				}
				 bool canBuild = false;
				for (int k = 0; k < board.vertices.size(); k++) {
					canBuild = validHouse(board.vertices.at(k), board);
					if (canBuild) {
						break;
					}
				}
				 if (board.sideMenuRight.at(1).getGlobalBounds().contains(mouseLocation) && canBuild && board.players.at(board.turn % 4)->inventory.at("brickTile") >= 1 && board.players.at(board.turn % 4)->inventory.at("woodTile") >= 1 && board.players.at(board.turn % 4)->inventory.at("sheepTile") >= 1 && board.players.at(board.turn % 4)->inventory.at("wheatTile") >= 1) {
					board.sideMenuRight.at(1).setOutlineColor(sf::Color::Yellow);
					board.sideMenuRight.at(1).setOutlineThickness(1);
					board.drawer(board);
					std::chrono::milliseconds timeout(200);
					std::this_thread::sleep_for(timeout);
					board.sideMenuRight.at(1).setOutlineColor(sf::Color::Transparent);
					board.drawer(board);
					int numHouses = board.players.at(board.turn % 4)->settleCoord.size();
	while (board.players.at(board.turn % 4)->settleCoord.size() <= numHouses) {
	sf::Event clicker1;
	while (window.pollEvent(clicker1)) {
		if (clicker1.type == sf::Event::MouseButtonPressed) {
			int verticeClick = -2;
			verticeClick = board.nearVertex(sf::Mouse::getPosition(board.window), true);
			if (verticeClick < 0) {

				break;
			}
			else if (!validHouse(board.vertices.at(verticeClick), board)) {

				break;
			}
			else {

				board.players.at(board.turn % 4)->settleCoord.push_back(board.vertices.at(verticeClick));
				sf::Texture* text1 = new sf::Texture();
				text1->loadFromFile("catanImages/" + board.players.at(board.turn % 4)->color + "House.png");
				board.textureList.push_back(text1);
				sf::Sprite sp;
				sp.setTexture(*text1);
				sp.setPosition({ board.vertices.at(verticeClick).x - 15, board.vertices.at(verticeClick).y - 16 });
				board.sprites.push_back(sp);

				board.players.at(board.turn % 4)->inventory["woodTile"]--;
				board.players.at(board.turn % 4)->inventory["brickTile"]--;
				board.players.at(board.turn % 4)->inventory["sheepTile"]--;
				board.players.at(board.turn % 4)->inventory["wheatTile"]--;
				board.sideMenuLeft = sideMenuLeftSetUp(board);
				board.drawer(board);
				std::chrono::milliseconds timeSpan(350);
				std::this_thread::sleep_for(timeSpan);
			}
		}
	}
}
				}
				if (board.sideMenuRight.at(2).getGlobalBounds().contains(mouseLocation) && board.players.at(board.turn % 4)->cityCoord.size() != board.players.at(board.turn % 4)->settleCoord.size() && board.players.at(board.turn % 4)->inventory["wheatTile"] >= 2 && board.players.at(board.turn % 4)->inventory["stoneTile"] >= 3) {
					board.sideMenuRight.at(2).setOutlineColor(sf::Color::Yellow);
					board.sideMenuRight.at(2).setOutlineThickness(1);
					board.drawer(board);
					std::chrono::milliseconds timeout(200);
					std::this_thread::sleep_for(timeout);
					board.sideMenuRight.at(2).setOutlineColor(sf::Color::Transparent);
					board.drawer(board);
					int numCities = board.players.at(board.turn % 4)->cityCoord.size();

					while (board.players.at(board.turn % 4)->cityCoord.size() <= numCities) {
						sf::Event clicker2;
						while (window.pollEvent(clicker2)) {
							if (clicker2.type == sf::Event::MouseButtonPressed) {
								int verticeClick = -2;
								verticeClick = board.nearVertex(sf::Mouse::getPosition(board.window), true);
								if (verticeClick < 0) {

									break;
								}
								bool onSettlement = false;
								for (int i = 0; i < board.players.at(board.turn % 4)->settleCoord.size(); i++) {

									if (board.vertices.at(verticeClick) == board.players.at(board.turn % 4)->settleCoord.at(i)) {
										onSettlement = true;
									}
								}

								if (onSettlement) {
									for (int i = 0; i < board.sprites.size(); i++) {
										sf::Vector2f mouseClickPlus;
										mouseClickPlus.x = board.vertices.at(verticeClick).x - 15;
										mouseClickPlus.y = board.vertices.at(verticeClick).y - 16;
										if (board.sprites.at(i).getPosition() == mouseClickPlus) {
											board.sprites.erase(board.sprites.begin() + i);
											board.textureList.erase(board.textureList.begin() + i);

										}
									}
									board.players.at(board.turn % 4)->cityCoord.push_back(board.vertices.at(verticeClick));
									sf::Texture* text1 = new sf::Texture();
									text1->loadFromFile("catanImages/" + board.players.at(board.turn % 4)->color + "City.png");
									board.textureList.push_back(text1);
									sf::Sprite sp;
									sp.setTexture(*text1);
									sp.setPosition({ board.vertices.at(verticeClick).x - 20, board.vertices.at(verticeClick).y - 22 });
									sp.setScale({ 0.8,0.8 });
									board.sprites.push_back(sp);
									board.players.at(board.turn % 4)->inventory["wheatTile"] = board.players.at(board.turn % 4)->inventory["wheatTile"] - 2;
									board.players.at(board.turn % 4)->inventory["stoneTile"] = board.players.at(board.turn % 4)->inventory["stoneTile"] - 3;
									board.sideMenuLeft = sideMenuLeftSetUp(board);
									board.drawer(board);
									std::chrono::milliseconds timeSpan(350);
									std::this_thread::sleep_for(timeSpan);
								}
							}
						}
					}
				}
				if ((board.sideMenuRight.at(3).getGlobalBounds().contains(mouseLocation) || board.sideMenuRight.at(4).getGlobalBounds().contains(mouseLocation)) && board.devCards.size() > 0 && board.players.at(board.turn % 4)->inventory["wheatTile"] >= 1 && board.players.at(board.turn % 4)->inventory["sheepTile"] >= 1 && board.players.at(board.turn % 4)->inventory["stoneTile"] >= 1) {
					board.sideMenuRight.at(3).setOutlineColor(sf::Color::Yellow);
					board.sideMenuRight.at(3).setOutlineThickness(1);
					board.sideMenuRight.at(4).setOutlineColor(sf::Color::Yellow);
					board.sideMenuRight.at(4).setOutlineThickness(1);
					board.drawer(board);
					std::chrono::milliseconds timeout(200);
					std::this_thread::sleep_for(timeout);
					board.sideMenuRight.at(3).setOutlineColor(sf::Color::Transparent);
					board.sideMenuRight.at(4).setOutlineColor(sf::Color::Transparent);
					board.drawer(board);
					board.players.at(board.turn % 4)->playerDevCards[board.devCards.top()]++;
					board.devCards.pop();
			
					board.players.at(board.turn % 4)->inventory["wheatTile"]--;
					board.players.at(board.turn % 4)->inventory["sheepTile"]--;
					board.players.at(board.turn % 4)->inventory["stoneTile"]--;
					sideMenuLeft = sideMenuLeftSetUp(board);
					board.drawer(board);
				}
			}
		}
		
		
		board.sideMenuLeft = sideMenuLeftSetUp(board);
	}
	
	
	std::chrono::milliseconds timer(2000);
	std::this_thread::sleep_for(timer);

}

void gameBoard::botTurn(gameBoard& board, int roll) {

	updateResource(board, roll);
	board.sideMenuLeft = sideMenuLeftSetUp(board);
	board.drawer(board);
	std::chrono::milliseconds timer(2000);
	std::this_thread::sleep_for(timer);
}

void gameBoard::drawer(gameBoard& board) {
	
	board.window.clear();
	this->window.draw(this->sprites.at(0));
	for (int i = 0; i < this->tiles.size(); i++) {
		this->window.draw(this->tiles.at(i)->resource);
		this->window.draw(this->tiles.at(i)->num);
	}
	for (int i = 0; i < this->shapes.size(); i++) {
		this->window.draw((*this->shapes.at(i)));
	}
	for (int i = 1; i < this->sprites.size(); i++) {
		this->window.draw(this->sprites.at(i));
	}
	for (int i = 0; i < this->sideMenuRight.size(); i++) {
		this->window.draw(this->sideMenuRight.at(i));
	}
	for (int i = 0; i < this->sideMenuLeft.size(); i++) {
		this->window.draw(this->sideMenuLeft.at(i));
	}
	if (this->diceSprites.size() == 2) {
		this->window.draw(this->diceSprites.at(0));
		this->window.draw(this->diceSprites.at(1));
	}
	board.window.display();
}



void gameBoard::gameLoop() {
	this->turn++;
	while (getHighestPoints(*this).first < 10) {
		

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		// mt19937 is a standard mersenne_twister_engine
		std::mt19937 generator(seed);


		int rollOne = generator() % 6 + 1;
		int rollTwo = generator() % 6 + 1;
		sf::Texture *d1 = new sf::Texture();
		sf::Texture *d2 = new sf::Texture();
		d1->loadFromFile("catanImages/Dice" + std::to_string(rollOne) + ".png");
		d2->loadFromFile("catanImages/Dice" + std::to_string(rollTwo) + ".png");
		sf::Sprite dice1(*d1);
		sf::Sprite dice2(*d2);
		this->diceTexts.push_back(d1);
		this->diceTexts.push_back(d2);
		dice1.setPosition({ 1000.f, 575.f });
		dice2.setPosition({ 1100.f, 575.f });
		this->diceSprites.push_back(dice1);
		this->diceSprites.push_back(dice2);
		/*this->players.at(this->playerNum)->inventory["woodTile"] = 2;
		this->players.at(this->playerNum)->inventory["brickTile"] = 2;
		this->players.at(this->playerNum)->inventory["sheepTile"] = 2;
		this->players.at(this->playerNum)->inventory["wheatTile"] = 2;
		this->players.at(this->playerNum)->inventory["stoneTile"] = 2;
		this->sideMenuLeft = sideMenuLeftSetUp(*this);*/
		this->drawer(*this);
		std::cout << this->playerNum << std::endl;
		std::cout << "!!!" << this->turn << "!!!" << std::endl;
		if (rollOne + rollTwo == 7) {
			sevenRolled(*this);
		}
		if (this->turn % 4 == this->playerNum) {
			playerTurn((*this), rollOne + rollTwo);
		}
		else {
			botTurn((*this) , rollOne + rollTwo);
		}

		
		this->turn++;
		this->diceSprites.pop_back();
		this->diceSprites.pop_back();
		this->diceTexts.pop_back();
		this->diceTexts.pop_back();
		
	}
	sf::Text winner;
	if (getHighestPoints(*this).second == this->players.at(this->playerNum)->color) {
		winner.setString("You Win!");
	}
	else {
		winner.setString(getHighestPoints(*this).second + " Wins!");
	}
	winner.setFont(this->font);
	winner.setFillColor(sf::Color::White);
	winner.setPosition({ 500.f,25.f });
	this->sideMenuLeft.push_back(winner);
	this->drawer(*this);
	std::chrono::milliseconds timer(20000);
	std::this_thread::sleep_for(timer);
}

int gameBoard::nearVertex(sf::Vector2i coord, bool house) {

	for (int i = 0; i < this->vertices.size(); i++) {
		if (std::abs(this->vertices.at(i).x - coord.x) < 20 && std::abs(this->vertices.at(i).y - coord.y) < 20 && house) {
			return i;
		}
	}
	return -1;
}

int gameBoard::nearEdge(sf::Vector2f coord) {
	for (int i = 0; i < this->edges.size(); i++) {
		if (std::abs(this->edges.at(i).first.x - coord.x) < 15 && std::abs(this->edges.at(i).first.y - coord.y) < 15) {
			return i;
		}
	}
	return -1;
}

gameBoard::gameBoard() {
	this->window.create(sf::VideoMode(1200, 675), "Catan", sf::Style::Default);
	this->window.setFramerateLimit(60);
	this->turn = -1;
	this->setUpHouse = 0;
	this->housePlaced = false;
	this->roadPlaced = false;
	
	this->playerNum = -1;

	this->font.loadFromFile("Fonts/ALGER.TTF");
	this->sideMenuRight = sideMenuRightSetUp(*this);
}

gameBoard::~gameBoard() {
	for (int i = 0; i < this->tiles.size(); i++) {
		delete this->tiles.at(i);
	}
	for (int i = 0; i < this->shapes.size(); i++) {
		delete this->shapes.at(i);
	}
	for (int i = 0; i < 4; i++) {
		delete this->players.at(i);
	}
	for (int i = 0; i < this->textureList.size(); i++) {
		delete this->textureList.at(i);
	}
	
}