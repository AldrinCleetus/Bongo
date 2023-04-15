#include "Game.h"
#include <iostream>

std::string TestLocation = "textures/box.png";
//Tile* test = new Tile(0, false, TestLocation, sf::Vector2f(512.0f, 500.0f), sf::Vector2f(1.0f, 1.0f));
//Tile* test2 = new Tile(1, false, TestLocation, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(1.0f, 1.0f));


Game::Game()
{
	this->init();
	
	this->tiles.push_back(new Tile(0, false, TestLocation, sf::Vector2f(512.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));
	this->tiles.push_back(new Tile(1, false, TestLocation, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();

		this->deltaTime = this->deltaClock.restart();
	}
}

Game::~Game()
{
	delete this->player;
	delete this->window;

	for (auto tile : this->tiles) {
		delete tile;
	}
}

void Game::init()
{
	// Setup the window
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game", sf::Style::Default | sf::Style::Close);
	this->window->setFramerateLimit(60);
	//this->window->setVerticalSyncEnabled(false);

	// Load in the player
	this->loadPlayer();
	
}

void Game::update()
{
	this->handleWindowEvents();
	this->handleInput();

	this->player->update();


	/*test.update();*/

	for (auto tile : this->tiles) {
		(*tile).update();
	}

	
	/*if (this->player->playerCollider->isColliding(*this->testsObjects[0].myCollider)) {
		std::cout << "Collided" << std::endl;
		
	}*/

	//if (this->player->playerCollider->isColliding(this->testsObjects[0].shape)) {
	//	//std::cout << "Collided" << std::endl;
	//	this->player->playerCollider->collisionResponse(this->testsObjects[0].shape);
	//	//std::cout << this->player->playerCollider->collisionResponseMoveAmount.x << "," << this->player->playerCollider->collisionResponseMoveAmount.y << std::endl;
	//}
	
	

	
}

void Game::render()
{
	// Clear Screen
	this->window->clear();

	// Update screen
	this->player->render(*this->window);
	
	//this->testsObjects[0].render(*this->window);
	//(*this->tiles[0]).render(*this->window);
	//test.render(*this->window);
	for (auto& tile : this->tiles) {
		(*tile).render(*this->window);
	}

	// Render
	this->window->display();



}

void Game::handleWindowEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::handleInput()
{
	sf::Vector2f currentDirection(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		currentDirection.x = -1.0f;
		//this->player->move(sf::Vector2f(-1.0f,0.0f), this->deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		currentDirection.x = 1.0f;
		//this->player->move(sf::Vector2f(1.0f, 0.0f), this->deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		currentDirection.y = -1.0f;
		//this->player->move(sf::Vector2f(0.0f, -1.0f), this->deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		currentDirection.y = 1.0f;
		//this->player->move(sf::Vector2f(0.0f, 1.0f), this->deltaTime);
	}

	this->player->move(currentDirection, this->deltaTime);
	this->player->aimAtMouse(sf::Mouse::getPosition(*this->window));

}

void Game::handleGameState()
{
	// do later
}

void Game::loadPlayer()
{
	this->player = new Player();
}

