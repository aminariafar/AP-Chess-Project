#include "../headers/Board.h"

Board :: Board (sf::RenderWindow* w) : window(w)
{
    window->setFramerateLimit(60);
    loadBoardTextures();
    window->setKeyRepeatEnabled(false);

    font.loadFromFile("resources/fonts/Copenhagen-z3Z0.ttf");
    statusText.setFont(font);
    statusText.setCharacterSize(50);
    statusText.setStyle(sf::Text::Bold);
    statusText.setFillColor(sf::Color(151, 149, 147));
    statusText.setPosition(170.f, 505.f);

    marginFont.loadFromFile("resources/fonts/Caviar_Dreams_Bold.ttf");
    marginText.setFont(marginFont);
    marginText.setCharacterSize(10);
    marginText.setStyle(sf::Text::Regular);
    marginText.setFillColor(sf::Color(151, 149, 147));
    marginText.setPosition(355.f, 525.f);
    marginText.setString("   Press \'R\' to reset game\nPress \'U\' to undo last move");

    firstPageText.setFont(font);
    firstPageText.setCharacterSize(60);
    firstPageText.setStyle(sf::Text::Regular);
    firstPageText.setFillColor(sf::Color(240,222,176));

    inFirstPage = true;
}

void Board :: init(string s[8][8])
{
    finish = false;
    selectedPiece = nullptr;
    currentTurn = 1;
    clickNo = 1;
    movesCount = 0;
    movesHistory.clear();
    hitPiecesCount = 0;
    hitPieces.clear();
    int blackIndex = 0;
    int whiteIndex = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            primaryBoard[i][j] = s[i][j];
            if (s[i][j] == "--")
                boardMatrix[i][j] = nullptr;
            else
            {
                char type = s[i][j][0];
                char color = s[i][j][1];
                switch (type)
                {
                    case 'K':
                    {
                        Piece* piecePtr = new King(i, j, color, 'K');
                        boardMatrix[i][j] = piecePtr;
                        if (color == 'W')
                        {
                            currentPieces[1][whiteIndex] = piecePtr;
                            whiteKing = piecePtr;
                            whiteIndex++;
                        }
                        else
                        {
                            currentPieces[0][blackIndex] = piecePtr;
                            blackKing = piecePtr;
                            blackIndex++;
                        }
                        break;
                    }
                    case 'Q':
                    {
                        Piece* piecePtr = new Queen(i, j, color, 'Q');
                        boardMatrix[i][j] = piecePtr;
                        if (color == 'W')
                        {
                            currentPieces[1][whiteIndex] = piecePtr;
                            whiteIndex++;
                        }
                        else
                        {
                            currentPieces[0][blackIndex] = piecePtr;
                            blackIndex++;
                        }
                        break;
                    }
                    case 'B':
                    {
                        Piece* piecePtr = new Bishop(i, j, color, 'B');
                        boardMatrix[i][j] = piecePtr;
                        if (color == 'W')
                        {
                            currentPieces[1][whiteIndex] = piecePtr;
                            whiteIndex++;
                        }
                        else
                        {
                            currentPieces[0][blackIndex] = piecePtr;
                            blackIndex++;
                        }
                        break;
                    }
                    case 'N':
                    {
                        Piece* piecePtr = new Knight(i, j, color, 'N');
                        boardMatrix[i][j] = piecePtr;
                        if (color == 'W')
                        {
                            currentPieces[1][whiteIndex] = piecePtr;
                            whiteIndex++;
                        }
                        else
                        {
                            currentPieces[0][blackIndex] = piecePtr;
                            blackIndex++;
                        }
                        break;
                    }
                    case 'R':
                    {
                        Piece* piecePtr = new Rook(i, j, color, 'R');
                        boardMatrix[i][j] = piecePtr;
                        if (color == 'W')
                        {
                            currentPieces[1][whiteIndex] = piecePtr;
                            whiteIndex++;
                        }
                        else
                        {
                            currentPieces[0][blackIndex] = piecePtr;
                            blackIndex++;
                        }
                        break;
                    }
                    case 'P':
                    {
                        Piece* piecePtr = new Pawn(i, j, color, 'P');
                        boardMatrix[i][j] = piecePtr;
                        if (color == 'W')
                        {
                            currentPieces[1][whiteIndex] = piecePtr;
                            whiteIndex++;
                        }
                        else
                        {
                            currentPieces[0][blackIndex] = piecePtr;
                            blackIndex++;
                        }
                        break;
                    }
                }
            }
        }
    
    for (int i = blackIndex; i < 16; i++)
        currentPieces[0][i] = nullptr;
    for (int i = whiteIndex; i < 16; i++)
        currentPieces[1][i] = nullptr;
}

string Board :: displayMove(Movement m)
{
    string firstPos;
    char type = boardMatrix[m.x1][m.y1]->type;
    char color = boardMatrix[m.x1][m.y1]->color;
    firstPos = (char)((int)'a' + m.x1) + (char)((int)'1' + m.y1);
    string secondPos;
    secondPos = (char)((int)'a' + m.x2) + (char)((int)'1' + m.y2);
    return firstPos + type + color + secondPos;
}

bool Board :: validMove(int x1, int y1, int x2, int y2)
{
    if ( !( boardMatrix[x1][y1]->validateMove(x2, y2, boardMatrix) ) )
        return false;
    rearrangePieces(x1, y1, x2, y2);
    if (inCheck(boardMatrix[x2][y2]->color))
    {
        reverseMove();
        return false;
    }
    reverseMove();
    return true;
}

void Board :: printSmartMoves (char mode, char color)
{
    if (mode == 'D')
    {
        if (!smartDefence(color, 0))
            cout << "No Answer!";
        else
        {
            for (string move: smartDefenceList)
                cout << move << '\n';
        }
    }
    else
    {
        if (!smartMate(color, 0))
            cout << "No Answer!";
        else
        {
            for (string move: smartMateList)
                cout << move << '\n';
        }
    }
}

bool Board :: inCheck(char color)
{
    if (color == 'W')
    {
        for (int i = 0; i < 16; i++)
        {
            if(currentPieces[0][i] == nullptr || currentPieces[0][i]->positionX == -1) continue;
            if ( currentPieces[0][i]->validateMove( whiteKing->positionX, whiteKing->positionY, boardMatrix ) )
                return true;
        }
        return false;
    }
    else
    {
        for (int i = 0; i < 16; i++)
        {
            if(currentPieces[1][i] == nullptr || currentPieces[1][i]->positionX == -1) continue;
            if ( currentPieces[1][i]->validateMove(blackKing->positionX, blackKing->positionY, boardMatrix) )
                return true;
        }
        return false;
    }
}

bool Board :: checkMate(char color)
{
    if ( !inCheck(color) )
        return false;
    if (color == 'W')
    {
        for (int k = 0; k < 16; k++)
        {
            if (currentPieces[1][k] == nullptr || currentPieces[1][k]->positionX == -1) continue;
            for (int j = 0; j < 8; j++)
                for (int i = 0; i < 8; i++)
                    if ( validMove(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j) )
                        return false;
        }
        return true;
    }
    else
    {
        for (int k = 0; k < 16; k++)
        {
            if (currentPieces[0][k] == nullptr || currentPieces[0][k]->positionX == -1) continue;
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if ( validMove(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j) )
                        return false; 
        }
        return true;
    }
}

bool Board :: smartDefence(char turn, int round = 0)
{
    if (round == 0)
    {
        if(turn == 'B')
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[0][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        cout << currentPieces[0][k]->positionX << ' ' << currentPieces[0][k]->positionY << ' ' << i << ' ' << j << '\n';
                        if (validMove(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j))
                        {
                            rearrangePieces(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j);
                            cout << "salam" << '\n';
                            if (smartDefence('W', 1))
                            {
                                smartDefenceList.push_back(displayMove(movesHistory[movesCount - 1]));
                                cout << (displayMove(movesHistory[movesCount - 1])) << '\n';
                            }
                            reverseMove();
                        }
                    }
            }
        }
        else
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[1][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j);
                            if (smartDefence('B', 1))
                                smartDefenceList.push_back(displayMove(movesHistory[movesCount - 1]));
                            reverseMove();
                        }
                    }
            }
        
        }
        if (smartDefenceList.size() == 0) return false;
        return true;
    }
    
    else if (round == 1)
    {
        // cout << "here?" << '\n';
        if(turn == 'B')
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[0][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j);
                            if (checkMate('W'))
                            {
                                reverseMove();
                                return true;
                            }
                            else
                            {
                                if (smartDefence('W', 2)) 
                                {
                                    reverseMove();
                                    return true;
                                }
                                else reverseMove();
                            }
                        }
                    }
            }
        }
        else
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[1][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j);
                            if (checkMate('B'))
                            {
                                reverseMove();
                                return true;
                            }
                            else
                            {
                                if (smartDefence('B', 2)) 
                                {
                                    reverseMove();
                                    return true;
                                }
                                else reverseMove();
                                    
                            }
                        }
                    }
            }
        }
        return false;
    }
    
    else if (round == 2)
    {
        if (turn == 'B')
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[0][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j);
                            if (!smartDefence('W', 3)) { reverseMove(); return false; }
                            else reverseMove();
                        }
                    }
            }
        }
        if (turn == 'W')
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[1][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j);
                            if (!smartDefence('B', 3)) { reverseMove(); return false; }
                            else reverseMove();
                        }
                    }
            }
        }
        return true;
    }

    else if (round == 3)
    {
        if (turn == 'B')
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[0][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[0][k]->positionX, currentPieces[0][k]->positionY, i, j);
                            if (checkMate('W')) { reverseMove(); return true; }
                            else { reverseMove(); return false; }
                        }
                    }
            }
        }
        else
        {
            for (int k = 0; k < 16; k++)
            {
                if (currentPieces[1][k] == nullptr) continue;
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if ( validMove(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j) )
                        {
                            rearrangePieces(currentPieces[1][k]->positionX, currentPieces[1][k]->positionY, i, j);
                            if (checkMate('B')) { reverseMove(); return true; }
                            else { reverseMove(); return false; }
                        }
                    }
            }
        }
        return false;
    }

    return false;
}

bool Board :: smartMate(char turn, int round = 0)
{
    return true;
}

bool Board :: isFinished()
{
    if (inFirstPage) return false;
    if ( checkMate( (currentTurn == 1) ? 'W' : 'B') )
    {
        winner = (currentTurn == 1) ? 'B' : 'W';
        finish = true;
        return true;
    }
    return false;
}

void Board :: announceWinner()
{ 
    if (winner == 'W')
        cout << "white win\n";
    
    else
        cout << "black win\n";
}

void Board :: printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (boardMatrix[i][j] == nullptr) cout << "-- ";
            else cout << boardMatrix[i][j]->type << boardMatrix[i][j]->color << ' ';
        }
        cout << '\n';
    }
}

void Board :: rearrangePieces(int x1, int y1, int x2, int y2)
{
    Movement m;
    m.x1 = x1;
    m.y1 = y1;
    m.x2 = x2;
    m.y2 = y2;
    if (boardMatrix[x1][y1]->canHit)
    {
        m.causeHitting = true;
        boardMatrix[x2][y2]->positionX = -1;
        boardMatrix[x2][y2]->positionY = -1;
        hitPieces.push_back(boardMatrix[x2][y2]);
        hitPiecesCount++;
        
    }
    movesHistory.push_back(m);
    movesCount++;
    boardMatrix[x1][y1]->positionX = x2;
    boardMatrix[x1][y1]->positionY = y2;
    boardMatrix[x2][y2] = boardMatrix[x1][y1];
    boardMatrix[x1][y1] = nullptr;
    currentTurn *= -1;
}

void Board :: reverseMove()
{
    int X1, Y1, X2, Y2;
    X1 = movesHistory[movesCount-1].x1;
    Y1 = movesHistory[movesCount-1].y1;
    X2 = movesHistory[movesCount-1].x2;
    Y2 = movesHistory[movesCount-1].y2;
    boardMatrix[ X1 ][ Y1 ] = boardMatrix[ X2 ][ Y2 ];
    boardMatrix[ X1 ][ Y1 ]->positionX = X1;
    boardMatrix[ X1 ][ Y1 ]->positionY = Y1;
    if (movesHistory[movesCount - 1].causeHitting)
    {
        boardMatrix[ X2 ][ Y2 ] = hitPieces[hitPiecesCount - 1];
        boardMatrix[ X2 ][ Y2 ]->positionX = X2;
        boardMatrix[ X2 ][ Y2 ]->positionY = Y2;
        hitPieces.pop_back();
        hitPiecesCount--;
    }
    else
        boardMatrix[ X2 ][ Y2 ] = nullptr;
    movesHistory.pop_back();
    movesCount--;
    currentTurn *= -1;
}

void Board :: updateStatusText()
{
    if (finish)
    {
        if (winner == 'W')
            statusText.setString("Player white won!");
        else
            statusText.setString("Player black won!");
    }
    else
    {
        if(currentTurn == 1)
            statusText.setString("It's white's turn");
        else
            statusText.setString("It's black's turn");
    }
}

void Board :: run()
{
    bool lockPressing;
    window->display();
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            if (!isFinished() && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && !lockPressing)
                {
                    mouseClicked(sf::Mouse::getPosition(*window));
                    lockPressing = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
                if(event.mouseButton.button == sf::Mouse::Left)
                    lockPressing = false;
            if (!inFirstPage && event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !lockPressing)
                    resetBoard();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && !lockPressing && movesCount > 0)
                    undo();
            }
        }
        window->clear(sf::Color(48, 46, 43));
        if (inFirstPage)
            drawFirstPage();
        else
        {
            updateStatusText();
            draw();
        }
        window->display();
    }
}

void Board :: draw()
{
    window->draw(boardImg);
    if (currentTurn == 1 && inCheck('W'))
    {
        redRect.setPosition(getCellPosition(whiteKing->positionX, whiteKing->positionY));
        window->draw(redRect);
    }
    if (currentTurn == -1 && inCheck('B'))
    {
        redRect.setPosition(getCellPosition(blackKing->positionX, blackKing->positionY));
        window->draw(redRect);
    }
    if (selectedPiece != nullptr)
        displaySelection();
    for (int row = 0; row < 8; row++)
        for (int column = 0; column < 8; column++)
        {
            if (boardMatrix[row][column] == nullptr) continue;
            boardMatrix[row][column]->sprite.setPosition(getCellPosition(row, column));
            window->draw(boardMatrix[row][column]->sprite);
        }
    window->draw(statusText);
    window->draw(marginText);
}

void Board :: loadBoardTextures()
{
    boardTexture.loadFromFile("resources/images/board.png");
    boardImg.setTexture(boardTexture);
    float scaleX = 500.f / boardImg.getTexture()->getSize().x;
    float scaleY = 500.f / boardImg.getTexture()->getSize().y;
    boardImg.setScale(scaleX, scaleY);
    boardImg.setPosition(0.f, 11.f);

    firstPageTexture.loadFromFile("resources/images/firstPage.png");
    firstPageImg.setTexture(firstPageTexture);
    firstPageImg.setScale(0.3, 0.3);
    firstPageImg.setPosition(90.f,255.f);

    redRect.setSize(sf::Vector2f(cellSize, cellSize));
    redRect.setFillColor(sf::Color::Red);

    yellowRect.setSize(sf::Vector2f(cellSize, cellSize));
    yellowRect.setFillColor(sf::Color::Yellow);

    yellowCircle.setRadius(cellSize/6);
    yellowCircle.setFillColor(sf::Color::Yellow);

    optionRect.setSize(sf::Vector2f(cellSize*7, cellSize));
    optionRect.setFillColor(sf::Color(182,138,93));
}

void Board :: mouseClicked(const sf::Vector2i& position)
{
    if (inFirstPage)
    {
        if (45 <= position.x && position.x <= 45 + 7*cellSize)
        {
            if (70 <= position.y && position.y <= 70 + cellSize)
                setAsDefault();
            if (180 <= position.y && position.y <= 180 + cellSize)
                setWithTerminal();
        }
    }
    else
    {
        static int clickNo = 1;
        int column = getCellIndex(position.x), row = getCellIndex(position.y);
        if (row == -1 || column == -1)
            return;
        if(clickNo == 1)
        {
            firstClick(row, column);
            if (selectedPiece != nullptr) clickNo++;
        }
        else
        {
            secondClick(row, column);
            clickNo--;
            selectedPiece = nullptr;
        }
    }
}

void Board :: firstClick(int row, int column)
{
    if (boardMatrix[row][column] == nullptr)
        return;
    if (currentTurn == 1 && boardMatrix[row][column]->color == 'B')
        return;
    if (currentTurn == -1 && boardMatrix[row][column]->color == 'W')
        return;
    selectedPiece = boardMatrix[row][column];
}

void Board :: secondClick(int row, int column)
{
    if (!validMove(selectedPiece->positionX, selectedPiece->positionY, row, column))
        return;
    else
        rearrangePieces(selectedPiece->positionX, selectedPiece->positionY, row, column);
}

void Board :: resetBoard()
{
    init(primaryBoard);
}

void Board :: undo()
{
    reverseMove();
    finish = false;
    selectedPiece = nullptr;
    clickNo = 1;
}

void Board :: displaySelection()
{
    yellowRect.setPosition(getCellPosition(selectedPiece->positionX, selectedPiece->positionY));
    window->draw(yellowRect);
    sf::Vector2f tempVector;
    vector<Spot> spots = getAllValidMoves(selectedPiece);
    for (int i = 0; i < spots.size(); i++)
    {
        if (boardMatrix[spots[i].x][spots[i].y] != nullptr) continue;
        tempVector = getCellPosition(spots[i].x, spots[i].y);
        tempVector.x += cellSize/3;
        tempVector.y += cellSize/3;
        yellowCircle.setPosition(tempVector);
        window->draw(yellowCircle);
    }
}

vector<Spot> Board :: getAllValidMoves(Piece* piecePtr)
{
    vector<Spot> spots;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (validMove(piecePtr->positionX, piecePtr->positionY, i, j))
            {
                Spot s;
                s.x = i;
                s.y = j;
                spots.push_back(s);
            }
        }
    return spots;
}

void Board :: drawFirstPage()
{
    optionRect.setPosition(sf::Vector2f(45,70));
    window->draw(optionRect);
    optionRect.setPosition(sf::Vector2f(45,180));
    window->draw(optionRect);
    firstPageText.setPosition(135.f, 65.f);
    firstPageText.setString("Set pieces as default form");
    window->draw(firstPageText);
    firstPageText.setPosition(135.f, 175.f);
    firstPageText.setString("Set pieces with terminal");
    window->draw(firstPageText);
    window->draw(firstPageImg);
}

void Board :: setAsDefault()
{
    string defaultPositions[8][8] = 
    {
        {"RB", "NB", "BB", "QB", "KB", "BB", "NB", "RB"},
        {"PB", "PB", "PB", "PB", "PB", "PB", "PB", "PB"},
        {"--", "--", "--", "--", "--", "--", "--", "--"},
        {"--", "--", "--", "--", "--", "--", "--", "--"},
        {"--", "--", "--", "--", "--", "--", "--", "--"},
        {"--", "--", "--", "--", "--", "--", "--", "--"},
        {"PW", "PW", "PW", "PW", "PW", "PW", "PW", "PW"},
        {"RW", "NW", "BW", "QW", "KW", "BW", "NW", "RW"}
    };
    init(defaultPositions);
    inFirstPage = false;
}

void Board :: setWithTerminal()
{
    string boardStr[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> boardStr[i][j];
    init(boardStr);
    inFirstPage = false;
}