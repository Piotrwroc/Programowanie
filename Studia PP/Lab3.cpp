/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 3
*/


#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>


using namespace std;
#define ROZMIAR 25
void wczytaj(float* tab)
{
	cout << "Wczytaj elementy tablicy" << endl;
	for (int i = 0; i < ROZMIAR; i++)
	{
		cout << "Tab[" << i << "] = ";
		cin >> tab[i];
	}
	cout << endl;
}
void wypisz(float* tab)
{
	cout << "Wypisywanie tablicy" << endl;
	cout << "Tab = [";
	for (int i = 0; i < ROZMIAR; i++)
	{
		printf("  %.1f", tab[i]);
	}
	cout << "  ]";
	cout << endl;
}
void dod_uj(float* tab)
{
	float liczba_d = 0, liczba_u = 0;
	float suma_d = 0, suma_u = 0;

	for (int i = 0; i < ROZMIAR; i++)
	{
		if (tab[i] > 0)
		{
			liczba_d++;
			suma_d += tab[i];
		}
		if (tab[i] < 0)
		{
			liczba_u++;
			suma_u += tab[i];
		}
	}
	if (liczba_d > 0)
	{
		cout << "Liczba liczb dodatnich wynosi: " << liczba_d << endl;
	}
	if (liczba_u > 0)
	{
		cout << "Liczba liczb ujemnych wynosi: " << liczba_u << endl;
	}
	if (liczba_d > 0)
	{
		cout << "Suma liczb dodatnich wynosi: " << suma_d << endl;
	}
	if (liczba_u > 0)
	{
		cout << "Suma liczb ujemnych wynosi: " << suma_u << endl;
	}
	if (liczba_d > 0)
	{
		cout << "Wartosc srednia liczb dodatnich wynosi: " << suma_d / liczba_d << endl;
	}
	if (liczba_u > 0)
	{
		cout << "Wartosc srednia liczb ujemnych wynosi: " << suma_u / liczba_u << endl;
	}
}
void uporzadkuj(float* tab)
{
	int war1 = 0, war2 = 0, war3 = 0, war4 = 0, war5 = 0;
	for (int i = 0; i < ROZMIAR-1; i++)
	{
		if (tab[i] == tab[i + 1])
		{
			war1++;
		}
		if (tab[i] < tab[i + 1])
		{
			war2++;	
		}
		if (tab[i] > tab[i + 1])
		{
			war3++;
		}
		if (tab[i] <= tab[i + 1])
		{
			war4++;
		}
		if (tab[i] >= tab[i + 1])
		{
			war5++;
		}
	}
	if (war1 == ROZMIAR-1)
	{
		cout << " wszystkie elementy maja jednakowa wartosc" << endl;
	}
	else if (war2 == ROZMIAR - 1)
	{
		cout << "wszystkie elementy tablicy sa uporzadkowane rosnaco" << endl;
	}
	else if (war3 == ROZMIAR - 1)
	{
		cout << "wszystkie elementy tablicy sa uporzadkowane malejaco" << endl;
	}
	else if (war4 == ROZMIAR - 1)
	{
		cout << "wszystkie elementy tablicy sa uporzadkowane niemalejaco" << endl;
	}
	else if (war5 == ROZMIAR - 1)
	{
		cout << "wszystkie elementy tablicy sa uporzadkowane nierosnaco" << endl;
	}
	else cout << "elementy tablicy sa nie uporzadkowane" << endl;
}
void losuj(float* tab)
{
	srand(time(NULL));
	int min, max, n;
	cout << "Wybierz liczby calowite lub rzeczywiste" << endl;
	cout << "1. calkowite" << endl;
	cout << "2. rzeczywiste" << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "Podaj zakres minimalny" << endl;
		cin >> min;
		cout << "Podaj zakres maksymalny" << endl;
		cin >> max;
		if (min <= max)
		{
			for (int i = 0; i < ROZMIAR; i++)
			{
				tab[i] = min + rand() % (max - min + 1);
			}
		}
		else cout << "Zakres minimalny nie moze byc wiekszy od maksymalnego" << endl;
	}
	else if (n == 2)
	{
		cout << "Podaj zakres minimalny" << endl;
		cin >> min;
		cout << "Podaj zakres maksymalny" << endl;
		cin >> max;
		for (int i = 0; i < ROZMIAR; i++)
		{
			tab[i] = min + (max - min) * rand() / ((double)RAND_MAX);
		}
	}
	else cout <<"Zla wartosc" << endl;
}
void sortuj(float* tab)
{
	float temp;
	for (int i = 1; i < ROZMIAR; i++)
	{
		temp = tab[i];
		int j = i - 1;
		while (j >= 0 && tab[j] > temp)
		{
			tab[j+1] = tab[j];
			j--;
		}
		tab[j + 1] = temp;
	}
}
void litery(int* alfabet)
{
	char znak=0;
	int xnumer =0;
	char ylitera = 65;
	cout << "Podawaj litery do momentu nacisniecia Esc" << endl << endl;
	do
	{
		znak = _getch();
		cout << znak;
		xnumer++;
		if (znak >= 'A' && znak <= 'Z')
		{
			alfabet[znak - 'A']++;
		}
		if (znak >= 'a' && znak <= 'z')
		{
			alfabet[znak - 'a']++;
		}
	} while (znak != 27);
	cout << endl;
	cout << "WWpaisano ogolem " << xnumer-1<< " znakow w tym : " << endl;
	for (int i=0; i < 26; i++)
	{
		cout << "Litera " << ylitera++ << " " << alfabet[i] << " ";
		int ilosc = alfabet[i];
		for (int j = 0; j < ilosc; j++)
		{
			cout << "#";
		}
		cout << endl;
	}
}
int main()
{
	float tab[ROZMIAR] = { NULL };
	int alfabet[26] = { NULL };
	int x, y = 1;
	cout << "Autorem programu jest Piotr Jozefek" << endl;
	while (y == 1)
	{
		cout << "Wybierz dzialanie" << endl;
		cout << "1. Funkcja wczytanie tablicy " << endl;
		cout << "2. Funkcja wypisanie tablicy" << endl;
		cout << "3. Funkcja do wypisywania liczb dodatnich i ujemnych" << endl;
		cout << "4. Funkcja do sprawdzania uporzadkowania liczb" << endl;
		cout << "5. Funkcja do losowania" << endl;
		cout << "6. Funkcja do sortowania" << endl;
		cout << "7. Zadanie dla ambitnych" << endl;
		cout << "8. Zakoncz program" << endl;
		cout << endl;
		cin >> x;
		cout << endl;
		switch (x)
		{
		case 1:
			wczytaj(tab);
			cout << endl;
			break;
		case 2:
			wypisz(tab);
			cout << endl;
			break;
		case 3:
			dod_uj(tab);
			cout << endl;
			break;
		case 4:
			uporzadkuj(tab);
			cout << endl;
			break;
		case 5:
			losuj(tab);
			cout << endl;
			break;
		case 6:
			sortuj(tab);
			cout << endl;
			break;
		case 7:
			litery(alfabet);
			cout << endl;
			break;
		case 8:
			cout << "Koniec programu" << endl;
			y = 2;
			break;
		default:
			cout << "Wybrano zly nr zadania" << endl << endl;;
		}
	}
	return 0;
}