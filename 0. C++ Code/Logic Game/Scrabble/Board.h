//
//  Board.hpp
//  Scrabble
//


#ifndef Board_hpp
#define Board_hpp

#include "../Scrabble_Defs.h"
#include <stdio.h>
#include <string>
#include <vector>

#include "Cell.h"
#include "Dictionary.h"
#include "BoardPosition.h"


using namespace std;

// (0,0) ----> X
//   |  (col:0, row:0), (col:1, row:0)
//   |  (col:0, row:1), (col:1, row:1)
//   |     <- Size X (width)->
//   |      Coordinate system
//   v
//   Y

typedef enum {
    HORIZONTAL = 0,
    VERTICAL,
    NOT_ALIGNED
} Alignment;

typedef enum {
    VALID_POSITION = 0,
    INVALID_POSITION,
    NOT_EMPTY
} PositionResult;

typedef enum {
    ALL_CORRECT = 0,
    //Tiles must be vertically or horizontally aligned and together
    INVALID_NOT_ALIGNED,
    //At least one letter must be next to the rest of the words.
    INVALID_NOT_CONNECTION,
    //You have to start using the center position
    INVALID_START_NOT_IN_CENTER,
    //Only words of two or more letters
    INVALID_WORD_OF_ONE_LETTER,
    //The new words are not in the dictionary
    INVALID_WORDS_NOT_IN_DICTIONARY,
} CurrentWordResult;
//-----------------------------




class Board
{
public:
    Board();
    PositionResult setTile(Tile& tile, const BoardPosition& boardPos);
    CurrentWordResult checkCurrentWord(int& points);
    Alignment currentWordAlignment();
    string readWordFromVector(vector<BoardPosition>& vector);
    char getLetterFromTile(BoardPosition& boardPos) { return m_cells[boardPos.getRow()][boardPos.getCol()].getTile().getLetter(); }
    bool currentWordConsecutive(Alignment& alineacion, int& min, int& max, bool& interseccion);
    bool currentWordConnected(Alignment& alineacion, int min, int max, vector<BoardPosition>& conexiones);
    bool isTileEmpty(BoardPosition& boardPos) { return m_cells[boardPos.getRow()][boardPos.getCol()].getEmpty(); }
    int pointsWord(vector<BoardPosition>& word);
    int pointsWords();
    void newWords(Alignment& alineacion, int& min, int& max, vector<BoardPosition>& conexiones);
    void sendCurrentWordToBoard();
    void removeCurrentWord();
    void removeTile(BoardPosition& boardPos);

private:
    Cell m_cells[BOARD_COLS_AND_ROWS][BOARD_COLS_AND_ROWS];
    Dictionary m_dictionary;
    vector<BoardPosition> m_currentWord;
    vector<vector<BoardPosition>> m_connectedWords;
    bool m_emptyBoard;
};

#endif /* Board_hpp */
