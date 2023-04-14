#include "tile.h"


Tile::Tile(int id, bool movable, std::string& textureLocation, sf::Vector2f position, sf::Vector2f scale)
{
	this->setPosition(position);
	this->setScale(scale);

	this->initSprite(textureLocation);
	this->initCollider();
}

Tile::~Tile()
{
}

void Tile::initCollider()
{
	this->tileCollider = new Collider(this->scale, this->position);

}

bool Tile::initSprite(std::string& textureLocation)
{
	if (!this->tileTexture.loadFromFile(textureLocation)) {
		std::cout << "Tile:: Failed to load texture at location " << textureLocation << "\n";
		return false;
	}

	this->tileSprite.setTexture(this->tileTexture);
	this->tileSprite.setOrigin(this->tileSprite.getLocalBounds().width / 2.0 , this->tileSprite.getLocalBounds().height / 2.0);
	return true;

}

void Tile::update()
{
	this->tileCollider->update(this->position);
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->tileSprite);
}
