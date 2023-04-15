#include "collider.h"
#include <iostream>


Collider::Collider(sf::Vector2f size, sf::Vector2f position)
{
    this->collider.setSize(size);
    this->collider.setOrigin(size / 2.0f);
    this->collider.setPosition(position);
    
}

// For debuging
void Collider::render(sf::RenderTarget& target)
{
    this->collider.setFillColor(sf::Color(240, 0, 0, 70));
    target.draw(this->collider);
}

void Collider::update(sf::Vector2f position)
{
    this->collider.setPosition(position);
}

bool Collider::isColliding(Collider& collidingObject)
{
    float aXmin = this->collider.getPosition().x - this->collider.getLocalBounds().width /2.0f;
    float aXmax = this->collider.getPosition().x + this->collider.getLocalBounds().width / 2.0f;

    float aYmin = this->collider.getPosition().y - this->collider.getLocalBounds().height / 2.0f;
    float aYmax = this->collider.getPosition().y + this->collider.getLocalBounds().height / 2.0f;

    float bXmin = collidingObject.collider.getPosition().x - collidingObject.collider.getLocalBounds().width / 2.0f;
    float bXmax = collidingObject.collider.getPosition().x + collidingObject.collider.getLocalBounds().width / 2.0f;
    float bYmin = collidingObject.collider.getPosition().y - collidingObject.collider.getLocalBounds().height / 2.0f;
    float bYmax = collidingObject.collider.getPosition().y + collidingObject.collider.getLocalBounds().height / 2.0f;

    

    if (aXmin <= bXmax && aXmax >= bXmin && aYmin <= bYmax && aYmax >= bYmin) {
        this->collision = true;
        return true;
    }

    this->collision = false;
    return false;
}

bool Collider::isColliding(sf::RectangleShape& collidingObject)
{
    sf::FloatRect currentObject = this->collider.getGlobalBounds();
    sf::FloatRect collisionObject = collidingObject.getGlobalBounds();

    if (currentObject.intersects(collisionObject)) {
        this->collision = true;
        return true;
    }

    this->collision = false;
    return false;
}

sf::Vector2f Collider::collisionResponse(sf::RectangleShape& collidingObject)
{
    sf::FloatRect currentObject = this->collider.getGlobalBounds();
    sf::FloatRect collisionObject = collidingObject.getGlobalBounds();


    if (currentObject.intersects(collisionObject,this->collisionIntersection)) {
        
        float dx = 0.0f;
        float dy = 0.0f;

        std::cout << this->collisionIntersection.width << "," << this->collisionIntersection.height << "\n";

        // Dont understand how this works.
        if (this->collisionIntersection.width < this->collisionIntersection.height) {
            
            if (currentObject.left < collisionObject.left) {
                dx = -this->collisionIntersection.width;
            }
            else {
                dx = this->collisionIntersection.width;
            }

            this->collisionResponseMoveAmount = sf::Vector2f(dx, 0);
        }
        else {
            if (currentObject.top < collisionObject.top) {
                dy = -this->collisionIntersection.height;
            }
            else {
                dy = this->collisionIntersection.height;
            }

            this->collisionResponseMoveAmount = sf::Vector2f(0, dy);
        }

        //this->collisionResponseMoveAmount = sf::Vector2f(dx, dy);

        return this->collisionResponseMoveAmount;
    }




    return sf::Vector2f(0,0);
}


