//
//  Cell.hpp
//  Scrabble
//

#ifndef Cell_hpp
#define Cell_hpp

#include "Tile.h"
#include <stdio.h>
#include <fstream>

using namespace std;

typedef enum {
    DL = 0,
    TL,
    DW,
    TW,
    NO_EFFECT
} ScoreEffect;

class Cell
{
public:
    Cell() { m_empty = true; m_tilePlayed = false; m_scoreEffect = NO_EFFECT; }
    ScoreEffect getScoreEffect() const { return m_scoreEffect; }
    Tile getTile() const { return m_tile; }
    bool getEmpty() const { return m_empty; }
    bool getTilePlayed() const { return m_tilePlayed; }
    void setScoreEffect(ScoreEffect& efectoPuntuacion) { m_scoreEffect = efectoPuntuacion; }
    void setTile(Tile& casilla) { m_tile = casilla; }
    void setEmpty(bool vacio) { m_empty = vacio; }
    void setTilePlayed(bool tilePlayed) { m_tilePlayed = tilePlayed; }
private:
    ScoreEffect m_scoreEffect;
    Tile m_tile;
    bool m_empty;
    bool m_tilePlayed;
};

ifstream& operator>>(ifstream& input, ScoreEffect& s);

#endif /* Cell_hpp */