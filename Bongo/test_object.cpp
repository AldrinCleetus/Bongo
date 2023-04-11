#include "test_object.h"

void Test_object::init()
{
	this->shape.setFillColor(sf::Color(150,150,150));
	this->shape.setSize(sf::Vector2f(200.0f, 200.0f));
	this->shape.setPosition(sf::Vector2f(512.0f, 512.0f));
}

void Test_object::update()
{

}

void Test_object::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

Test_object::Test_object()
{
	this->init();
}
