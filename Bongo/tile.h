#pragma once

#include "entity.h"
#include "collider.h"
#include <string>

class Tile : public Entity
{
private:
	sf::Sprite tileSprite;
	sf::Texture tileTexture;

	bool canMove = false;

	Collider* tileCollider;


public:
	int id;


public:
	Tile();
	Tile(int id, bool movable, std::string& textureLocation, sf::Vector2f position, sf::Vector2f scale);
	virtual ~Tile();

	void update() override;
	void render(sf::RenderTarget& target) override;
	
private:
	void initCollider();
	bool initSprite(std::string& textureLocation);
};

