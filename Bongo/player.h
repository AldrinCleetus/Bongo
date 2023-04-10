#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

public:
	sf::Vector2f position;
	sf::Vector2f direction;

	float movementSpeed;

public:
	Player();

	void init();
	void render(sf::RenderTarget& target);
	void update();
	void move(sf::Vector2f direction, sf::Time dt);
	void shoot();

	void aimAtMouse(sf::Vector2i mousePosition);


private:

	bool loadTextures();

	

};

