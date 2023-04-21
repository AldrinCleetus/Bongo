#include "tile.h"


Tile::Tile()
{
	this->setPosition(sf::Vector2f(1.0f,1.0f));
	this->setScale(sf::Vector2f(1.0f, 1.0f));
	this->id = 0;
	this->initCollider();

	std::cout << "Default Contructor called" << "\n";
}

Tile::Tile(int id, bool movable, std::string& textureLocation, sf::Vector2f position, sf::Vector2f scale)
{
	this->id = id;
	this->canMove = movable;
	this->setPosition(position);
	this->setScale(scale);
	

	this->initSprite(textureLocation);
	this->initCollider();

}

Tile::~Tile()
{
	std::cout << "Decontructor called on " << this->id << "\n";

	if (this->tileCollider != nullptr) {
		delete this->tileCollider;
	}
}

void Tile::initCollider()
{
	sf::Vector2f colliderSize = sf::Vector2f(this->tileSprite.getLocalBounds().width, this->tileSprite.getLocalBounds().height);

	this->tileCollider = new Collider(colliderSize, this->position);
}

bool Tile::initSprite(std::string& textureLocation)
{
	if (!this->tileTexture.loadFromFile(textureLocation)) {
		std::cout << "Tile:: Failed to load texture at location " << textureLocation << "\n";
		return false;
	}

	this->tileSprite.setPosition(this->position);
	this->tileSprite.setScale(this->scale);
	this->tileSprite.setTexture(this->tileTexture);
	this->tileSprite.setOrigin(this->tileSprite.getLocalBounds().width / 2.0f , this->tileSprite.getLocalBounds().height / 2.0f);
		
	return true;

}

void Tile::update()
{
	this->tileSprite.setPosition(this->position);
	this->tileCollider->update(this->position);
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->tileSprite);
	// draw collider - debug
	this->tileCollider->render(target);
}
