#pragma once
#include "ParentPiece.h"

class King : public Piece
{
public:

    King (int x, int y, char c, char t);

protected:

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]);
};

class Queen : public Piece
{
public:

    Queen (int x, int y, char c, char t);

protected:

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]);
};

class Bishop : public Piece
{
public:

    Bishop (int x, int y, char c, char t);

protected:

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]);
};

class Knight : public Piece
{
public:

    Knight (int x, int y, char c, char t);

protected:

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]);
};

class Rook : public Piece
{
public:

    Rook (int x, int y, char c, char t);

protected:

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]);
};

class Pawn : public Piece
{
public:

    Pawn (int x, int y, char c, char t);

protected:

    virtual bool validateMove(int x, int y, Piece* matrix[8][8]);
};
