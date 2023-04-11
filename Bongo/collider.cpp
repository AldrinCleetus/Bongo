#include "collider.h"


Collider::Collider(sf::Vector2f size)
{
    this->collider.setSize(size);
    this->collider.setOrigin(size / 2.0f);
    
}

// For debuging
void Collider::render(sf::RenderTarget& target)
{
    this->collider.setFillColor(sf::Color(55, 223, 235, 70));
    target.draw(this->collider);
}

void Collider::update(sf::Vector2f position)
{
    this->collider.setPosition(position);
}

bool Collider::isColliding(sf::RectangleShape& collidingObject)
{
    //if(collisionObjectOne.getLocalBounds())


    return false;
}
