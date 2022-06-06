#pragma once
#include "Pieces.h"
#include <SFML/Graphics.hpp>

class Board
{
public:

    Board(sf::RenderWindow* w);

    void init(string s[8][8]);

    string displayMove(Movement m);

    bool validMove(int x1, int y1, int x2, int y2);

    void printSmartMoves (char mode, char color);

    bool inCheck(char color);
    
    bool checkMate(char color);

    bool smartDefence(char turn, int round);

    bool smartMate(char turn, int round);

    bool isFinished();

    void announceWinner();

    void printBoard();

    void updateStatusText();

    void mouseClicked(const sf::Vector2i& position);

    void firstClick(int row, int column);

    void secondClick(int row, int column);

    void run();

    void draw();

    void loadBoardTextures();

    void displaySelection();

    void deselectPiece();

    void displayCheck();

    void resetBoard();

    void undo();

    void drawFirstPage();

    void setAsDefault();

    void setWithTerminal();

    vector<Spot> getAllValidMoves(Piece* piecePtr);

protected:

    void rearrangePieces(int x1, int y1, int x2, int y2);

    void reverseMove();

    Piece *boardMatrix[8][8], *currentPieces[2][16];
    string primaryBoard[8][8];
    Piece *whiteKing, *blackKing, *selectedPiece;
    vector<Piece*> hitPieces;
    int hitPiecesCount;
    vector<Movement> movesHistory;
    int movesCount;
    short currentTurn;
    vector<string> smartDefenceList, smartMateList;
    bool finish, inFirstPage;
    char winner;
    sf::Font font, marginFont;
    sf::Text statusText, marginText, firstPageText;
    sf::Sprite boardImg, firstPageImg;
    sf::Texture boardTexture, firstPageTexture;
    sf::RenderWindow* window;
    sf::RectangleShape redRect, yellowRect, optionRect;
    sf::CircleShape yellowCircle;
    int clickNo;
};


