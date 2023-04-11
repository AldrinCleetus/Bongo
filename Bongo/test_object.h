#pragma once

#include "SFML/Graphics.hpp"


class Test_object
{
public:
	sf::RectangleShape shape;

	Test_object();

	void init();
	void update();
	void render(sf::RenderTarget& target);
};

