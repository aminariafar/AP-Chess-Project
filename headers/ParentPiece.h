#pragma once
#include "Helper.h"

class Piece
{
friend class Board;
friend class King;
friend class Queen;
friend class Bishop;
friend class Knight;
friend class Rook;
friend class Pawn;
public:

    Piece(int x, int y, char c, char t );

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]) = 0;

    string getPngPath();

    void loadTexture();

protected:
  
    char color, type;
    int positionX, positionY;
    bool canHit;
    sf::Sprite sprite;
};
