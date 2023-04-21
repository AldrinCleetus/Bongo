#pragma once
#include "entity.h"
#include "collider.h"
#include "utility_functions.h"
#include <vector>
#include <iostream>

class Bullet :
    public Entity
{
private:

    sf::Sprite bulletSprite;
    sf::Texture bulletTexture;

   

public:
    float speed;


    Collider* bulletCollider;


public:
    Bullet(sf::Vector2f position, sf::Vector2f direction, sf::Vector2f scale, float rotation);
    virtual ~Bullet();

    void update(sf::Time dt) override;
    void render(sf::RenderTarget& target) override;
    
    bool initSprite();
    void initCollider();



};

