#include "bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction, sf::Vector2f scale, float rotation)
{
	this->setPosition(position);
	this->setScale(scale);

	// make set function
	this->direction = direction;
	this->speed = 500.0f;
	

	this->initSprite();
	this->initCollider();
	this->bulletSprite.setRotation(rotation + 90);
}

Bullet::~Bullet()
{
	delete this->bulletCollider;
}

void Bullet::update(sf::Time dt)
{

	this->direction = Utility::normalizeVector(this->direction);

	this->setPosition(this->position + ((this->direction * this->speed) * dt.asSeconds()));

	this->bulletSprite.setPosition(this->position);
	this->bulletCollider->update(this->position);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->bulletSprite);
}

bool Bullet::initSprite()
{
	if (!this->bulletTexture.loadFromFile("textures/bullet.png")) {
		std::cout << "Bullet:: Failed to load texture at location " << "\n";
		return false;
	}

	this->bulletSprite.setPosition(this->position);
	this->bulletSprite.setScale(this->scale);
	this->bulletSprite.setTexture(this->bulletTexture);
	this->bulletSprite.setOrigin(this->bulletSprite.getLocalBounds().width / 2.0f, this->bulletSprite.getLocalBounds().height / 2.0f);

	return true;
}

void Bullet::initCollider()
{
	sf::Vector2f colliderSize = sf::Vector2f(this->bulletSprite.getLocalBounds().width, this->bulletSprite.getLocalBounds().height);

	this->bulletCollider = new Collider(colliderSize, this->position);
}
