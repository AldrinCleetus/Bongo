#include "test_object.h"

void Test_object::init()
{
	this->shape.setFillColor(sf::Color(150,150,150));
	this->shape.setSize(sf::Vector2f(200.0f, 200.0f));
	this->shape.setPosition(sf::Vector2f(512.0f, 512.0f));
	this->shape.setOrigin(this->shape.getSize() / 2.0f);

	this->myCollider = new Collider(sf::Vector2f(200.0f, 200.0f), this->shape.getPosition());
}

void Test_object::update()
{
	this->myCollider->update(this->shape.getPosition());
}

void Test_object::render(sf::RenderTarget& target)
{
	this->update();
	target.draw(this->shape);
	myCollider->render(target);
}

Test_object::Test_object()
{
	this->init();
}
