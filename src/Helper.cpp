#include "../headers/Helper.h"

sf::Vector2f getCellPosition(int row,int column)
{
    return sf::Vector2f(
        cellOffset + column * cellSize,
        cellOffset + row * cellSize);
}

int getCellIndex(int x)
{
    x -= cellOffset;
    if (x<0)
        return -1;
    int cellPlus_space = cellSize;
    int index = x / cellSize;
    if (index > 7 || x > index * cellSize + cellSize)
        return -1;
    return index;
}