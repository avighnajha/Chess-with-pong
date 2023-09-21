#pragma once
#include"SFML/Graphics.hpp"

class Pong
{
public:
	Pong() = default;
	Pong();
	void run();
	
private:
	sf::RenderWindow window;
	Paddle player1Paddle;
	Paddle player2Paddle;
	Ball ball;
	GameRenderer gameRenderer;

	void handleEvents();
	void update();
	void render();
};