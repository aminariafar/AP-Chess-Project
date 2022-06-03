#include "../headers/ParentPiece.h"
map<string, sf::Texture> pieceTextures;

Piece :: Piece(int x, int y, char c, char t ) : positionX(x), positionY(y), color(c), type(t)
{
    loadTexture();
}

string Piece :: getPngPath()
{
    string path = "resources/images/";
    if (color == 'B') path += "B";
    else path += "W";
    switch (type)
    {
    case 'K':
        path += "K";
        break;
    case 'Q':
        path += "Q";
        break;
    case 'B':
        path += "B";
        break;
    case 'P':
        path += "P";
        break;
    case 'N':
        path += "N";
        break;
    case 'R':
        path += "R";
        break;
    }
    return path + ".png";
}

void Piece :: loadTexture()
{
    string pieceID = "";
    if (color == 'B') pieceID += "B";
    else pieceID += "W";
    switch (type)
    {
    case 'K':
        pieceID += "K";
        break;
    
    case 'Q':
        pieceID += "Q";
        break;
    case 'B':
        pieceID += "B";
        break;
    case 'P':
        pieceID += "P";
        break;
    case 'N':
        pieceID += "N";
        break;
    case 'R':
        pieceID += "R";
        break;
    }
    if (pieceTextures.find(pieceID) == pieceTextures.end())
        pieceTextures[pieceID].loadFromFile(getPngPath());
    sprite.setTexture(pieceTextures[pieceID]);
    float pieceScaleX = (float)cellSize / sprite.getTexture()->getSize().x;
    float pieceScaleY = (float)cellSize / sprite.getTexture()->getSize().y;
    sprite.setScale(pieceScaleX, pieceScaleY);
}