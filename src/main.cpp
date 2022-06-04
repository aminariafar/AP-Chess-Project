#include "../headers/Board.h"
using namespace sf;

int main()
{
    string boardStr[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> boardStr[i][j];
    RenderWindow window (VideoMode(500, 560), "Amin's Chess", Style::Titlebar | Style::Close);
    Board currentBoard(&window);
    currentBoard.init(boardStr);
    currentBoard.run();
    return 0;
}