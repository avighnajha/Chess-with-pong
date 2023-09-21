#include "Paddle.h"

Paddle::Paddle(float startX, float startY, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
	: upKey(upKey)
	, downKey(downKey)
{
	shape.setSize(sf::Vector2f(20, 80));
	shape.setPosition(startX, startY);
	shape.setFillColor(sf::Color::White);
	int speed = 5;
}

void Paddle::update()
{
	if (sf::Keyboard::isKeyPressed(upKey) && shape.getPosition().y > 0)
	{
		shape.move(0, speed);
	}
	if (sf::Keyboard::isKeyPressed(downKey) && shape.getPosition().y + shape.getSize().y > 600)
	{
		shape.move(0, -speed);
	}
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::RectangleShape Paddle::getShape()
{
	return shape;
}