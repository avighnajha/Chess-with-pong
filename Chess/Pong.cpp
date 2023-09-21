#include "Pong.h"
#include "Paddle.h"
#include "Ball.h"
//#include "CollisionManager.h"
//#include "GameRenderer.h"
//#include "Player.h"
#include <SFML/Graphics.hpp>

Pong::Pong()
	:window(sf::VideoMode(800, 600), "Pong")
{
	player1Paddle = Paddle(50, 250, sf::Keyboard::W, sf::Keyboard::S);
	player2Paddle = Paddle(730, 250, sf::Keyboard::Up, sf::Keyboard::Down);
}

void Pong::run()
{
	while (window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

void Pong::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void Pong::update() {
	player1Paddle.update();
	player2Paddle.update();
	ball.update(player1Paddle, player2Paddle);

	// Add game over condition and reset logic if needed
	// For example, if you want to end the game on a miss, you can check if the ball is out of bounds.
	if (ball.isOutOfBounds()) {
		// Handle game over logic (e.g., display a message or reset the ball)
		ball.resetPosition();
	}
}

void Pong::render() {
	window.clear();

	// Render game objects
	gameRenderer.renderGame(ball, player1Paddle, player2Paddle);

	// Render additional game elements such as scores, messages, etc.

	window.display();
}
