//
//  LettersBag.cpp
//  Scrabble
//

#include "LettersBag.h"
#include <fstream>
#include <math.h>

LettersBag::LettersBag()
{
	ifstream fichero;
	string nombreFichero = "data/Configuration/lettersBag.txt";
	fichero.open(nombreFichero);

	if (fichero.is_open())
	{
		char letra;
		int puntuacion, n_repeticiones;

		do
		{
			fichero >> letra >> puntuacion >> n_repeticiones;
			
			Tile tile = Tile(letra, puntuacion);

			for (int i = 0; i < n_repeticiones; i++)
			{
				m_letters.push_back(tile);
			}

		} while (!fichero.eof());

		fichero.close();
	}
}

bool LettersBag::isEmpty()
{
	if (m_letters.size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Tile LettersBag::getLetter()
{
	Tile tile;
	int random;

	srand(time(NULL));
	random = (rand() % m_letters.size());
	tile = m_letters[random];

	m_letters.erase(m_letters.begin() + random);

	return tile;
}