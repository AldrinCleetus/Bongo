#include "player.h"
#include "utility_functions.h"
#include <iostream>

Player::Player()
{
	this->init();

	this->colliderSize = sf::Vector2f(this->playerSprite.getLocalBounds().width, this->playerSprite.getLocalBounds().height);
	this->playerCollider = new Collider(colliderSize,this->playerSprite.getPosition());
}

Player::~Player()
{
	delete this->playerCollider;
}

void Player::init()
{
	this->loadTextures();

	this->position = sf::Vector2f(0.0f, 0.0f);
	this->movementSpeed = 100.0f;
	
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
	this->playerCollider->render(target); // Debug Purposes
}


void Player::update()
{	
	/*if (this->playerCollider->collision) {
		this->playerSprite.move(this->playerCollider->collisionResponseMoveAmount);
	}*/

	this->playerCollider->update(this->playerSprite.getPosition());

}

void Player::move(sf::Vector2f direction, sf::Time dt)
{

	// Collision Handling
	for (auto tile : *this->levelTiles) {
		if (this->playerCollider->isColliding(*tile->tileCollider)) {
			
			this->playerCollider->collisionResponse(*tile->tileCollider);

			if (tile->canMove) {
				tile->move(-this->playerCollider->collisionResponseMoveAmount);
			}
			else {
				this->playerSprite.move(this->playerCollider->collisionResponseMoveAmount);
			}
			
		}
		
	}

	direction = Utility::normalizeVector(direction);
	this->playerSprite.move( (direction * this->movementSpeed) * dt.asSeconds());

}

void Player::shoot()
{
}

bool Player::loadTextures()
{
	if (!this->playerTexture.loadFromFile("textures/test.png")) {
		std::cout << "Player::Player texture failed to load" << std::endl;
		return false;
	}

	// Set Player Texture and Set its origin to middle
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setOrigin(this->playerSprite.getLocalBounds().width / 2, this->playerSprite.getLocalBounds().height / 2);
	
	return true;
}

void Player::setWorldTiles(std::vector<Tile*>& Tiles)
{
	this->levelTiles = &Tiles;
}

void Player::aimAtMouse(sf::Vector2i mousePosition)
{
	float dx = mousePosition.x - this->playerSprite.getPosition().x;
	float dy = mousePosition.y - this->playerSprite.getPosition().y;
	float rotation = std::atan2(dy, dx) * 180 / 3.14159f;

	this->playerSprite.setRotation(rotation);

}

float Player::getDirection()
{
	return this->playerSprite.getRotation();
}

