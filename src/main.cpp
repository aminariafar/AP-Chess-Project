#include "../headers/Board.h"
using namespace sf;

int main()
{
    RenderWindow window (VideoMode(500, 560), "Amin's Chess", Style::Titlebar | Style::Close);
    Board currentBoard(&window);
    currentBoard.run();
    return 0;
}