#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
	
	sf::RenderWindow* window;


public:
	Game();
	void run();

private:

	void init();
	void update();
	void render();
};

