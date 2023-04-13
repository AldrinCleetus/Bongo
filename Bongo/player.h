#pragma once
#include "collider.h"
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

public:
	sf::Vector2f position;
	sf::Vector2f direction;
	

	Collider* playerCollider;
	sf::Vector2f colliderSize; // Fix later

	float movementSpeed;

public:
	Player();
	~Player();

	void init();
	void render(sf::RenderTarget& target);
	void update();
	void move(sf::Vector2f direction, sf::Time dt);
	void shoot();

	float getDirection();

	void aimAtMouse(sf::Vector2i mousePosition);


private:

	bool loadTextures();

	

};

