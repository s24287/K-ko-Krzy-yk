//Piotr Maciejewski
#include <iostream>
#include <Windows.h>
using namespace std;


char tab[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';
int  wiersz, kolumna;
int liczbaruchow = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void plansza()
{
	
	system("cls");
	
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Green test" << endl;
    cout << "\n\n     Kolko i Krzyzyk " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Red test" << endl;
	cout << "\tGracz 1 [X] \n\tGracz 2 [O]" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "BLUE test" << endl;
	cout << "\t\t___________________\n";
	cout << "\t\t|     |     |     |\n";
	cout << "\t\t|  " << tab[0][0] << "  |  " << tab[0][1] << "  |  " << tab[0][2] << "  |\n";
	cout << "\t\t|_____|_____|_____|\n";
	cout << "\t\t|     |     |     |\n";
	cout << "\t\t|  " << tab[1][0] << "  |  " << tab[1][1] << "  |  " << tab[1][2] << "  |\n";
	cout << "\t\t|_____|_____|_____|\n";
	cout << "\t\t|     |     |     |\n";
	cout << "\t\t|  " << tab[2][0] << "  |  " << tab[2][1] << "  |  " << tab[2][2] << "  |\n";
	cout << "\t\t|_____|_____|_____|\n";
}

void ruch()
{
	if (turn == 'X')
		cout << "\n\tGracz 1 [X] ruch:";

	if (turn == 'O')
		cout << "\n\tGracz 2 [O] ruch:";

	int wybierz;
	cin >> wybierz;

	switch (wybierz)
	{
	case 1: wiersz = 0; kolumna = 0; break;
	case 2: wiersz = 0; kolumna = 1; break;
	case 3: wiersz = 0; kolumna = 2; break;
	case 4: wiersz = 1; kolumna = 0; break;
	case 5: wiersz = 1; kolumna = 1; break;
	case 6: wiersz = 1; kolumna = 2; break;
	case 7: wiersz = 2; kolumna = 0; break;
	case 8: wiersz = 2; kolumna = 1; break;
	case 9: wiersz = 2; kolumna = 2; break;

	default:
		cout << "zly wybor\n";
		return;
	}



	if (turn == 'X' && (tab[wiersz][kolumna] != 'X' && tab[wiersz][kolumna] != 'O'))
	{
		tab[wiersz][kolumna] = 'X';
		turn = 'O';
		liczbaruchow++;
	}
	else if (turn == 'O' && (tab[wiersz][kolumna] != 'X' && tab[wiersz][kolumna] != 'O'))
	{
		tab[wiersz][kolumna] = 'O';
		turn = 'X';
		liczbaruchow++;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "RED test" << endl;
		cout << "Pole zajete \n Wybierz inne! \n\n";
		ruch();
	}
}

bool czyKoniecGry()
{
	bool czyKoniecGry = false;
	char ktoWygral;

	//Poziome kreski
	if (tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2])
	{
		czyKoniecGry = true;
		ktoWygral = tab[0][0];
	}
	else if (tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2])
	{
		czyKoniecGry = true;
		ktoWygral = tab[1][0];
	}
	else if (tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2])
	{
		czyKoniecGry = true;
		ktoWygral = tab[2][0];
	}

	// Pionowe kreski
	else if (tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0])
	{
		czyKoniecGry = true;
		ktoWygral = tab[0][0];
	}
	else if (tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1])
	{
		czyKoniecGry = true;
		ktoWygral = tab[0][1];
	}
	else if (tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2])
	{
		czyKoniecGry = true;
		ktoWygral = tab[0][2];
	}

	//Na krzyż
	else if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2])
	{
		czyKoniecGry = true;
		ktoWygral = tab[0][0];
	}
	else if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0])
	{
		czyKoniecGry = true;
		ktoWygral = tab[0][2];
	}

	if (czyKoniecGry)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Green test" << endl;
		cout << "Wygral gracz " << ktoWygral << "!!! GOD JOB " << endl;
		system("pause");
	}
	else if (liczbaruchow == 9)
	{
		cout << "REMIS!" << endl;
		system("pause");
		czyKoniecGry = true;
	}

	return czyKoniecGry;
}

int main()
{
	do
	{
		/* Przywracamy stan pierwotny */
		tab[0][0] = '1';
		tab[0][1] = '2';
		tab[0][2] = '3';

		tab[1][0] = '4';
		tab[1][1] = '5';
		tab[1][2] = '6';

		tab[2][0] = '7';
		tab[2][1] = '8';
		tab[2][2] = '9';

		turn = 'X';
		wiersz, kolumna;
		liczbaruchow = 0;

		while (!czyKoniecGry())
		{
			plansza();
			ruch();
			plansza();
		}
	} while (true);
}