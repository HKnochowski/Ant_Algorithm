#include <cstdlib>
#include <iostream>
#include "world.h"
#include "mrowisko.h"

using namespace std;

// inicjacja �wiata
const int lp = 7;    // liczba punkt�w �wiata
int tabela[3][lp] = { 'a','b','c','d','e','f','g',
6, 13,  4,  4,  8,  6,  10,
1,  1,  3,  5,  5,  8,  8 };
void inicjuj(World swiat); // inicjuje konkretny �wiat

int main(int argc, char *argv[])
{
	World swiat(7, 'a', 'g', 3);
	// parametry �wiata: liczba punkt�w, home, food,
	//                   liczba punkt�w wyboru dla mr�wek
	inicjuj(swiat); // inicjacja �wiata warto�ciami
	Mrowisko m(&swiat, 15, 1); // parametry mrowiska: nazwa �wiata,
							   // liczba mr�wek, ilo�� pozostawianego feromonu przez mr�wk�
	cout << "---------- stan poczatkowy\n";
	m.pokaz();                // mrowisko - stan pocz�tkowy
	swiat.pokaz(); cout << endl;// �wiat    - stan pocz�tkowy
	for (int i = 1; i <= 8; i++) {
		if ((i == 1) or (i == 4) or (i == 7) or (i == 10))
			cout << "---------- " << i << " cykl ----------\n";
		else cout << "\n";
		m.move(); m.pokaz();
		swiat.pokaz(); cout << endl;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}

void inicjuj(World swiat) {
	for (int i = 0; i<lp; i++)
	{
		swiat.punkty[i].name = tabela[0][i];
		swiat.punkty[i].x = tabela[1][i];
		swiat.punkty[i].y = tabela[2][i];
	}
}

