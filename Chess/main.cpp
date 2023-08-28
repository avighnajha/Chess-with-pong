#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "Chess");
	Board chessboard(window);
	chessboard.run();
	return 0;
}
