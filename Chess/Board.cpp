#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Board.h"

Board::Board(sf::RenderWindow& window) : window(window)
{
	squares.resize(8, std::vector<sf::RectangleShape>(8));
	pieces.resize(8, std::vector<Piece>(8));
	

	loadTextures();
	for (int i = 0; i < 8; i++)
	{;
		for (int j = 0; j < 8; j++)
		{
			squares[i][j].setSize(sf::Vector2f(squareSize, squareSize));
			if ((i + j) % 2 == 0)
			{
				squares[i][j].setFillColor(sf::Color::White);
			}
			else
			{
				squares[i][j].setFillColor(sf::Color(150, 75, 0, 255));
			}
			squares[i][j].setPosition(i * squareSize, j * squareSize);
		}

	}
	drawBoard();
	drawPieces();
}

bool Board::validateMove(int startX, int startY, int endX, int endY)
{
	int curPiece = board[startX][startY];
	int endPiece = board[endX][endY];
	if (endPiece * curPiece > 0) // Checks to make sure we arent taking a piece of the same colour
	{
		return false;
	}

	if (curPiece == 6) // White Pawn
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (xdif == -1 && ydif == 0)
		{
			return true;
		}
		else if (xdif == -1 && (ydif == 1 || ydif == -1) and endPiece != 0)
		{
			return true;
		}
		else if (xdif == -2 && ydif == 0 && startX == 6) {
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (curPiece == -6) // Black Pawn
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (xdif == 1 && ydif == 0)
		{
			return true;
		}
		else if (xdif == 1 && (ydif == 1 || ydif == -1) and endPiece != 0)
		{
			return true;
		}
		else if (xdif == 2 && ydif == 0 && startX == 1) {
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (abs(curPiece) == 1) // Rook
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (xdif != 0 && ydif == 0)
		{
			return true;
		}
		else if (xdif == 0 && ydif!=0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (abs(curPiece) == 3) // Bishop
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (abs(xdif) == abs(ydif))
		{
			return true;
		}
		//else if (xdif == 0 && ydif != 0)
		//{
		//	return true;
		//}
		else
		{
			return false;
		}

	}
	else if (abs(curPiece) == 2) // Knight
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (abs(xdif) == 1 && abs(ydif) == 2 || abs(xdif) == 2 && abs(ydif) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (abs(curPiece) == 4) // Queen
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (abs(xdif) == abs(ydif))
		{
			return true;
		}
		else if (xdif != 0 && ydif == 0)
		{
			return true;
		}
		else if (xdif == 0 && ydif != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (abs(curPiece) == 2) // Knight
	{
		std::cout << "Start: " << startX << "," << startY << "End: " << endX << "," << endY << std::endl;
		int xdif = endX - startX;
		int ydif = endY - startY;
		std::cout << "ValidateMove: " << xdif << "," << ydif << std::endl;
		if (abs(xdif) == 1 && abs(ydif) == 1 || abs(xdif) == 1 && abs(ydif) == 0 || abs(xdif) == 0 && abs(ydif) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	return true;
}

void Board::movePiece(int startX, int startY, int endX, int endY)
{
	if (validateMove(startX, startY, endX, endY))
	{
		int curPiece = board[startX][startY];

		board[startX][startY] = 0;
		board[endX][endY] = curPiece;
		pieces[startX][startY].setPosition(endX * squareSize, endY * squareSize);
		pieces[endX][endY] = pieces[startX][startY];
		pieces[startX][startY] = Piece(PieceType::NONE);
	}
	else
	{
		std::cout << "Not validated" << std::endl;
	}

}

void Board::loadTextures()
{
	pieceTextures.resize(2, std::vector<sf::Texture>(6));
	for (int i = 0; i <= 1; i++)// colour i = 0 - black pieces, i = 1 - White pieces
	{

		for (int j = 0; j <= 5; j++) // type
		{

			std::string path = "images/Chess_";
			int piece_val = j+1;
			switch (piece_val)
			{
			case 1:
				path += "r";
				break;
			case 2:
				path += "n";
				break;
			case 3:
				path += "b";
				break;
			case 4:
				path += "q";
				break;
			case 5:
				path += "k";
				break;
			case 6:
				path += "p";
				break;
			}
			(i == 0) ? path += "dt60.png" : path += "lt60.png";
			pieceTextures[i][j].loadFromFile(path);
			if (!pieceTextures[i][j].loadFromFile(path)) {
				std::cerr << "Failed to load texture: " << path << std::endl;
			}
		}
	}
}

void Board::drawPieces()
{
	for (int i = 0; i < 8; i++) // colour
	{
		for (int j = 0; j < 8; j++)//piece type
		{
			if (Board::board[i][j] > 0)
			{

				switch (Board::board[i][j])
				{
				case 1:
					Board::pieces[i][j] = Piece(PieceType::ROOK, Colour::WHITE, pieceTextures[1][0]);
					break;
				case 2:
					Board::pieces[i][j] = Piece(PieceType::KNIGHT, Colour::WHITE, pieceTextures[1][1]);
					break;
				case 3:
					Board::pieces[i][j] = Piece(PieceType::BISHOP, Colour::WHITE, pieceTextures[1][2]);
					break;
				case 4:
					Board::pieces[i][j] = Piece(PieceType::QUEEN, Colour::WHITE, pieceTextures[1][3]);
					break;
				case 5:
					Board::pieces[i][j] = Piece(PieceType::KING, Colour::WHITE, pieceTextures[1][4]);
					break;
				case 6:
					Board::pieces[i][j] = Piece(PieceType::PAWN, Colour::WHITE, pieceTextures[1][5]);
					break; 

				}
				std::cout << "WHITE" << std::endl;
				std::cout << j * squareSize <<" " << i* squareSize<< std::endl;

			}
			else if (Board::board[i][j] < 0)
			{
				switch (Board::board[i][j])
				{
				case -1:
					Board::pieces[i][j] = Piece(PieceType::ROOK, Colour::BLACK, pieceTextures[0][0]);
					break;
				case -2:
					Board::pieces[i][j] = Piece(PieceType::KNIGHT, Colour::BLACK, pieceTextures[0][1]);
					break;
				case -3:
					Board::pieces[i][j] = Piece(PieceType::BISHOP, Colour::BLACK, pieceTextures[0][2]);
					break;
				case -4:
					Board::pieces[i][j] = Piece(PieceType::QUEEN, Colour::BLACK, pieceTextures[0][3]);
					break;
				case -5:
					Board::pieces[i][j] = Piece(PieceType::KING, Colour::BLACK, pieceTextures[0][4]);
					break;
				case -6:
					Board::pieces[i][j] = Piece(PieceType::PAWN, Colour::BLACK, pieceTextures[0][5]);
					break;
				}
				std::cout << "BLACK" << std::endl;
				std::cout << i << "," << j << std::endl;
				std::cout << j * squareSize << " " << (j+1) * squareSize << std::endl;
			}
			if (Board::board[i][j] != 0)
			{
				Board::pieces[i][j].setPosition(i * squareSize, j * squareSize);
			}
			else
			{
				Board::pieces[i][j] = Piece(PieceType::NONE);
				Board::pieces[i][j].setPosition(j * squareSize, i * squareSize);
			}

		}
	}
}

void Board::drawBoard()
{
	window.clear();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			window.draw(squares[i][j]);
		    pieces[i][j].draw(window);
		}
	}
	
	/*sf::Sprite sprite;
	sprite.setTexture(pieceTextures[1][5]);
	sprite.setPosition(80*1, 80*5);
	window.draw(sprite);*/
	window.display();
	//drawPieces();
	/*sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition((7*80), (1*80));
	window.draw(rectangle);
	window.display();*/
}

void Board::run()
{
	bool isPieceSelected = false;
	int selectedX = -1;
	int selectedY = -1;

	Colour currentPlayer = Colour::WHITE;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				int mouseX = event.mouseButton.x / squareSize;
				int mouseY = event.mouseButton.y / squareSize;

				if (!isPieceSelected)
				{
					if (board[mouseX][mouseY] > 0 && currentPlayer == Colour::WHITE || board[mouseX][mouseY] < 0 && currentPlayer == Colour::BLACK)
					{
						selectedX = mouseX;
						selectedY = mouseY;
						isPieceSelected = true;
					}
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (isPieceSelected)
				{
					int destX = event.mouseButton.x / squareSize;
					int destY = event.mouseButton.y / squareSize;
					if (destX != selectedX || destY != selectedY) //Making sure if no move is made turn isnt switched
					{
						Board::movePiece(selectedX, selectedY, destX, destY);
						if (currentPlayer == Colour::WHITE && validateMove(selectedX, selectedY, destX, destY))
						{
							currentPlayer = Colour::BLACK;
						}
						else if(currentPlayer == Colour::BLACK && validateMove(selectedX, selectedY, destX, destY))
						{
							currentPlayer = Colour::WHITE;
						}
						isPieceSelected = false;
						drawBoard();
					}
					

				}
			}
		}

		drawBoard();
		//drawPieces();
	}
}