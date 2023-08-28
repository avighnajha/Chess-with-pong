#include "Piece.h"


Piece::Piece(PieceType piece_type, Colour piece_colour, const sf::Texture& texture)
	: type(piece_type)
	, colour(piece_colour)
{
	sprite.setTexture(texture);
}
Piece::Piece(PieceType piece_type)
	: type(piece_type)
{}
void Piece::setPosition(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}

void Piece::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}