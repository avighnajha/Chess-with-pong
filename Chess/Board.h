#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Piece.h"

class Board {
public:
    int board[8][8] =
    {
        { -1,-2,-3,-4,-5,-3,-2,-1},
        { -6, -6, -6, -6, -6, -6, -6, -6},
        {0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {1, 2, 3, 4, 5, 3, 2, 1}
    };// make 0 empty

    Board(sf::RenderWindow& window);
    void run();

private:
    sf::RenderWindow& window;
    const int squareSize = 80;
    const int boardSize = 8; //Number of squares
    std::vector<std::vector<sf::RectangleShape>> squares;
    //std::vector<Piece> piece;
    std::vector<std::vector<Piece>> pieces;
    std::vector<std::vector<sf::Texture>> pieceTextures;
    //sf::Texture pieceTextures[2][6]; // White and Black, 6 piece types

    bool validateMove(int startX, int startY, int endX, int endY);
    void movePiece(int startX, int startY, int endX, int endY);
    void loadTextures();
    void drawBoard();
    void drawPieces();
    // Add other necessary member functions for move validation, updating, etc.
};
#endif