#pragma once
#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Paddle.h"

class Ball
{
public:
	Ball(float& posx, float& posy);
	void update(Paddle paddle1, Paddle paddle2);
	void draw(sf::RenderWindow& window);
	bool isOutOfBounds();
private:
	sf::CircleShape shape;
	sf::Vector2f velocity;
	sf::Vector2f position;
};

#endif
