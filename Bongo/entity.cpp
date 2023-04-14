#include "entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::update()
{
	
}

void Entity::render(sf::RenderTarget& target)
{
	
}

void Entity::move(sf::Vector2f movePosition)
{
	this->position += movePosition;
}

void Entity::setPosition(sf::Vector2f newPosition)
{
	this->position = newPosition;
}

void Entity::setScale(sf::Vector2f scale)
{
	this->scale = scale;
}
