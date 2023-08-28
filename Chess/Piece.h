#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum class PieceType { PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN, NONE };
enum class Colour { WHITE, BLACK };

class Piece
{
public:
	Piece() = default;
	Piece(PieceType piece_type, Colour piece_colour, const sf::Texture& texture);
	Piece(PieceType piece_type);
	void setPosition(int x, int y);
	void draw(sf::RenderWindow& window);
private:
	PieceType type;
	Colour colour;
	sf::Sprite sprite;
};