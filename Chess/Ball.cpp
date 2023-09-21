#include "Ball.h"


Ball::Ball(float& posx, float& posy)
	: position(sf::Vector2f(posx, posy))
{
	velocity.x = 10.0f;
	velocity.y = 10.0f;

	shape.setRadius(10);
	shape.setPosition(posx, posy);
	shape.setFillColor(sf::Color::Magenta);
}

void Ball::update(Paddle paddle1, Paddle paddle2)
{
	shape.move(velocity);
	if (shape.getPosition().y < 0 || shape.getPosition().y + shape.getRadius() * 2 > 600) {
		// Reverse the vertical velocity to bounce off the top and bottom walls
		velocity.y = -velocity.y;
	}
	// Handle ball-paddle collisions
	if (shape.getGlobalBounds().intersects(paddle1.getShape().getGlobalBounds()) ||
		shape.getGlobalBounds().intersects(paddle2.getShape().getGlobalBounds())) {
		// Reverse the horizontal velocity to bounce off the paddles
		velocity.x = -velocity.x;
	}
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
bool Ball::isOutOfBounds()
{
	if (position.x < 0 || position.y < 0 || position.x > 800 || position.y > 600)
	{
		return true;
	}
}