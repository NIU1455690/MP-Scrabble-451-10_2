//
//  LettersBag.h
//  MP_Practica
//

#ifndef LettersBag_h
#define LettersBag_h

#include <vector>
#include "Tile.h"

using namespace std;

class LettersBag
{
public:
	LettersBag();
	bool isEmpty();
	Tile getLetter();
private:
	vector<Tile> m_letters;
};

#endif // !LettersBag