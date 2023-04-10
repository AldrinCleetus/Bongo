#include "player.h"
#include "utility_functions.h"
#include <iostream>

Player::Player()
{
	this->init();
}

void Player::init()
{
	this->loadTextures();

	this->position = sf::Vector2f(0.0f, 0.0f);
	this->movementSpeed = 50.0f;
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}


void Player::update()
{
	//this->playerSprite.setPosition(this->position);

}

void Player::move(sf::Vector2f direction, sf::Time dt)
{

	direction = Utility::normalizeVector(direction);

	this->playerSprite.move( (direction * this->movementSpeed) * dt.asSeconds());
	std::cout << direction.x << "," << direction.y << std::endl;

}

void Player::shoot()
{
}

bool Player::loadTextures()
{
	if (!this->playerTexture.loadFromFile("Textures/test.png")) {
		std::cout << "Player::Player texture failed to load" << std::endl;
		return false;
	}

	this->playerSprite.setTexture(this->playerTexture);
	return true;
}
