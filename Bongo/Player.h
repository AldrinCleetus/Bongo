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

public:
	Player();

	void init();
	void render(sf::RenderTarget& target);
	void update();
	void move();
	void shoot();


private:

	bool loadTextures();

	

};

