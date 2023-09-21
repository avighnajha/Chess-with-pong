#pragma once
#include<SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle(float startX, float startY, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
	void update();
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getShape();
private:
	sf::RectangleShape shape;
	int speed;
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;

};