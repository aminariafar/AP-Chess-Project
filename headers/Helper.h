#pragma once
#include <iostream>
#include<vector>
#include "SFML/Graphics.hpp"
using namespace std;

static int cellSize = 45, cellOffset = 20;

inline int absolute(int x)
{ return (x >= 0) ? x : -x; }

sf::Vector2f getCellPosition(int row,int column);

int getCellIndex(int x);

struct Movement
{
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    bool causeHitting = false;
};

struct Spot
{
    int x = -1, y = -1;
};