#include "Game.h"
#include "test_object.h"

Game::Game()
{
	this->init();
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
}

void Game::init()
{
	// Setup the window
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game", sf::Style::Default | sf::Style::Close);
	//this->window->setFramerateLimit(60);
	//this->window->setVerticalSyncEnabled(false);

	// Load in the player
	this->loadPlayer();
	
}

void Game::update()
{
	this->handleWindowEvents();
	this->handleInput();
	this->player->update();
}

void Game::render()
{
	// Clear Screen
	this->window->clear();

	// Update screen
	this->player->render(*this->window);
	
	//Test_object test;
	//test.render(*this->window);
	// 
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

