#include "../headers/Pieces.h"

// class King methods' definition

King :: King (int x, int y, char c, char t)
: Piece (x, y, c, t)
{
}

bool King :: validateMove(int x, int y, Piece* matrix[8][8])
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (matrix[x][y] != nullptr && matrix[x][y]->color == color)
        return false;
    canHit = false;
    int iDistance = absolute(x - positionX);
    int jDistance = absolute(y - positionY);
    if ((iDistance==1 && jDistance==1) || (iDistance==0 && jDistance==1) || (iDistance==1 && jDistance==0))
    {
        if (matrix[x][y] != nullptr) canHit = true;
        return true;
    }
    return false;
}

// class Queen methods' definition

Queen :: Queen (int x, int y, char c, char t)
: Piece (x, y, c, t)
{
}

bool Queen :: validateMove(int x, int y, Piece* matrix[8][8])
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (matrix[x][y] != nullptr && matrix[x][y]->color == color)
        return false;
    canHit = false;
    int iDistance = absolute(x - positionX);
    int jDistance = absolute(y - positionY);
    bool primaryValidation = false;
    if ((iDistance == jDistance && iDistance != 0) || (iDistance == 0 && jDistance > 0) || (iDistance > 0 && jDistance == 0))
        primaryValidation = true;
    if (primaryValidation)
    {
        if (iDistance == jDistance && iDistance != 0)
        {
            if (y > positionY && x > positionX)
            {
                for (int i = 1; i < y - positionY; i++)
                    if (matrix[positionX + i][positionY + i] != nullptr)    
                        return false;
            }
            else if (y > positionY && x < positionX)
            {
                for (int i = 1; i < y - positionY; i++)
                    if (matrix[positionX - i][positionY + i] != nullptr)
                        return false;
            }
            else if (y < positionY && x > positionX)
            {
                for (int i = 1; i < x - positionX; i++)
                    if (matrix[positionX + i][positionY - i] != nullptr)
                        return false;
            } 
            else
            {
                for (int i = 1; i < positionX - x; i++)
                    if (matrix[positionX - i][positionY - i] != nullptr)
                        return false;
            } 
        }
        else
        {
            if (iDistance == 0)
            {
                if (y > positionY)
                {
                    for (int i = positionY + 1; i < y; i++)
                        if (matrix[x][i] != nullptr)
                            return false;
                }
                else
                {
                    for (int i = positionY - 1; i > y; i--)
                        if (matrix[x][i] != nullptr)
                            return false;
                }
            }
            else
            {
                if (x > positionX)
                {
                    for (int i = positionX + 1; i < x; i++)
                        if (matrix[i][x] != nullptr)
                            return false;
                }
                else
                {
                    for (int i = positionX - 1; i > x; i--)
                        if (matrix[i][y] != nullptr)
                            return false;
                }
            } 
        }
    }
    if (primaryValidation)
    {
        if (matrix[x][y] != nullptr)
            canHit = true;
        return true;
    }
    return false;
}

// class Bishop methods' definition

Bishop :: Bishop (int x, int y, char c, char t)
: Piece (x, y, c, t)
{
}

bool Bishop :: validateMove(int x, int y, Piece* matrix[8][8])
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (matrix[x][y] != nullptr && matrix[x][y]->color == color)
        return false;
    canHit = false;
    int iDistance = absolute(x - positionX);
    int jDistance = absolute(y - positionY);
    bool primaryValidation = false;
    if (iDistance == jDistance && iDistance != 0)
        primaryValidation = true;
    if (primaryValidation)
    {
        if (y > positionY && x > positionX)
        {
            for (int i = 1; i < y - positionY; i++)
                if (matrix[positionX + i][positionY + i] != nullptr)    
                    return false;
        }
        else if (y > positionY && x < positionX)
        {
            for (int i = 1; i < y - positionY; i++)
                if (matrix[positionX - i][positionY + i] != nullptr)
                    return false;
        }
        else if (y < positionY && x > positionX)
        {
            for (int i = 1; i < x - positionX; i++)
                if (matrix[positionX + i][positionY - i] != nullptr)
                    return false;
        }
        else
        {
            for (int i = 1; i < positionX - x; i++)
                if (matrix[positionX - i][positionY - i] != nullptr)
                    return false;
        }
    }
    if (primaryValidation)
    {
        if (matrix[x][y] != nullptr)
            canHit = true;
        return true;
    }
    return false;
}

// class Knight methods' definition

Knight :: Knight (int x, int y, char c, char t)
: Piece (x, y, c, t)
{
}

bool Knight :: validateMove(int x, int y, Piece* matrix[8][8])
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (matrix[x][y] != nullptr && matrix[x][y]->color == color)
        return false;
    canHit = false;
    int iDistance = absolute(x - positionX);
    int jDistance = absolute(y - positionY);
    bool primaryValidation = false;
    if ((iDistance == 2 && jDistance == 1) || (iDistance == 1 && jDistance == 2))
        primaryValidation = true;
    if (primaryValidation)
    {
        if (matrix[x][y] != nullptr)
            canHit = true;
        return true;
    }
    return false;
}

// class Rook methods' definition

Rook :: Rook (int x, int y, char c, char t)
: Piece (x, y, c, t)
{
}

bool Rook :: validateMove(int x, int y, Piece* matrix[8][8])
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (matrix[x][y] != nullptr && matrix[x][y]->color == color)
        return false;
    canHit = false;
    int iDistance = absolute(x - positionX);
    int jDistance = absolute(y - positionY);
    bool primaryValidation = false;
    if ((iDistance == 0 && jDistance > 0) || (iDistance > 0 && jDistance == 0))
        primaryValidation = true;
    if (primaryValidation)
    {
        if (iDistance == 0)
        {
            if (y > positionY)
            {
                for (int i = positionY + 1; i < y; i++)
                    if (matrix[x][i] != nullptr)
                        return false;
            }
            else
            {
                for (int i = positionY - 1; i > y; i--)
                    if (matrix[x][i] != nullptr)
                        return false;
            }
        }
        else
        {
            if (x > positionX)
            {
                for (int i = positionX + 1; i < x; i++)
                    if (matrix[i][y] != nullptr)
                        return false;
            }
            else
            {
                for (int i = positionX - 1; i > x; i--)
                    if (matrix[i][y] != nullptr)
                        return false;
            }
        }    
    }    
    if (primaryValidation)
    {
        if (matrix[x][y] != nullptr)
            canHit = true;
        return true;
    }
    return false;
}

// class Pawn methods' definition

Pawn :: Pawn (int x, int y, char c, char t)
: Piece (x, y, c, t)
{
}

bool Pawn :: validateMove(int x, int y, Piece* matrix[8][8])
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
        return false;
    if (matrix[x][y] != nullptr && matrix[x][y]->color == color)
        return false;
    canHit = false;
    int iDistance = absolute(x - positionX);
    int jDistance = absolute(y - positionY);
    if (color == 'W')
    {   
        if (matrix[x][y]==nullptr && ((x == 4 && positionX == 6 && jDistance == 0 && matrix[5][y] == nullptr) || (x - positionX == -1 && jDistance == 0)))
            return true;
        if (x - positionX == -1 && jDistance == 1 && matrix[x][y] != nullptr)
        {
            canHit = true;
            return true;
        }
        return false;
    }
    else
    {
        if (matrix[x][y]==nullptr && ((x == 3 && positionX == 1 && jDistance ==  0 && matrix[2][y] == nullptr) || (x - positionX == 1 && jDistance == 0)))
            return true;
        if (x - positionX == 1 && jDistance == 1 && matrix[x][y] != nullptr)
        {
            canHit = true;
            return true;
        }
        return false;
    }
}