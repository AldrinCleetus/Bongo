#pragma once
#include "collider.h"
#include "tile.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	std::vector<Tile*>* levelTiles;
	std::vector<Entity*> bullets;

public:
	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Vector2f aimDirection;
	

	Collider* playerCollider;
	sf::Vector2f colliderSize; // Fix later

	float movementSpeed;

	sf::Clock bulletClock;
	float lastBulletTime;
	float bulletInterval;



public:
	Player();
	~Player();

	void init();
	void render(sf::RenderTarget& target);
	void update(sf::Time dt);
	void move(sf::Vector2f direction, sf::Time dt);
	void shoot();

	float getDirection();

	void aimAtMouse(sf::Vector2i mousePosition);
	void setWorldTiles(std::vector<Tile*>& Tiles);

private:

	bool loadTextures();

	

};

