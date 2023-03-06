/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 4
*/


#include <iostream>
#include <conio.h>
using namespace std;

char globalna_char = 'a';
int globalna_int = 10;
long globalna_long = 99999999;
float globalna_float = 21.37;
double globalna_double = 3.141592653589;

int const n = 10000;
void Wczytaj(char *tab);
int Wypisz2(char *tab);
char *Wypisz3(char *tab);
void Zad4();
void ilebajt(unsigned long long adres, int rozmiar);

int main()
{
	cout << "Autorem programu jest Piotr Jozefek" << endl;
	int y = 1,x = 0;
	while (y == 1)
	{
		char tab[n] = { NULL };
		cout << "Wybierz dzialanie" << endl;
		cout << "1. Zad 2 " << endl;
		cout << "2. Zad 3" << endl;
		cout << "3. Zad 4" << endl;
		cout << "4. Zakoncz program" << endl;
		cout << endl;
		cin >> x;
		cout << endl;
		switch (x) 
		{
		case 1:
			Wczytaj(tab);
			cout << "Usunieto tyle liczb " << Wypisz2(tab) << endl;
			cout << "Lancuch znakow to: " << tab << endl << endl;
			break;
		case 2:
			Wczytaj(tab);
			printf("Adres to: %p\n", Wypisz3(tab));
			cout << "Lancuch znakow to: " << tab << endl << endl;
			break;
		case 3:
			Zad4();
			cout << endl;
			break;
		case 4:
			cout << "Koniec programu" << endl;
			y = 2;
			break;
		default:
			cout << "Wybrano zly nr zadania" << endl << endl;;
		}
	}
	return 0;
}

void Wczytaj(char *tab)
{
	cout << "Podaj napis: " << endl;
	cin.ignore();
	cin.getline(tab, n);
}

int Wypisz2(char *tab)
{
	int licz = 0;
	for (int i = 0; i - licz < n; i++)
	{
		if (tab[i - licz] >= '0' && tab[i - licz] <= '9')
		{
			for (int j = i - licz; tab[j] != '\0'; j++)
				tab[j] = tab[j + 1];
			licz++;
		}
	}
	cout << endl;
	return licz;
}

char* Wypisz3(char *tab)
{
	int pierwszy, ostatni;
	for (int i = 0; tab[i] != 0; i++)
	{
		if (tab[i] == '/' && tab[i + 1] == '/')
		{
			tab[i] = 0;
		}
		if (tab[i] == '/' && tab[i + 1] == '*')
		{
			pierwszy = i;
			for (int j = i; tab[j] != 0; j++)
			{
				if (tab[j] == '*' && tab[j + 1] == '/')
				{
					ostatni = j + 2;
					while(tab[pierwszy] != 0)
					{
						tab[pierwszy] = tab[ostatni];
						pierwszy++;
						ostatni++;
					}
				}
			}
		}
	}
	return tab;
}

void Zad4()
{
	char lokalna_char = 'b';
	int lokalna_int = 91;
	long lokalna_long = -99999999;
	float lokalna_float = 123.456;
	double lokalna_double = 2.7182818284590452353;

	cout << "Zmienna - " << "globalna_char" << " wartosc: " << globalna_char << "  adres: "; printf("%p", &globalna_char); ilebajt(globalna_char, sizeof(globalna_char));
	cout << "Zmienna - " << "lokalna_char" << " wartosc: " << lokalna_char << "  adres: "; printf("%p", &lokalna_char); ilebajt(lokalna_char, sizeof(lokalna_char));
	cout << "Zmienna - " << "globalna_int" << " wartosc: " << globalna_int << "  adres: " << &globalna_int; ilebajt(globalna_int, sizeof(globalna_int));
	cout << "Zmienna - " << "lokalna_int" << " wartosc: " << lokalna_int << "  adres: " << &lokalna_int; ilebajt(lokalna_int, sizeof(lokalna_int));
	cout << "Zmienna - " << "globalna_long" << " wartosc: " << globalna_long << "  adres: " << &globalna_long; ilebajt(globalna_long, sizeof(globalna_long));
	cout << "Zmienna - " << "lokalna_long" << " wartosc: " << lokalna_long << "  adres: " << &lokalna_long; ilebajt(lokalna_long, sizeof(lokalna_long));
	cout << "Zmienna - " << "globalna_float" << " wartosc: " << globalna_float << "  adres: " << &globalna_float; ilebajt(globalna_float, sizeof(globalna_float));
	cout << "Zmienna - " << "lokalna_float" << " wartosc: " << lokalna_float << "  adres: " << &lokalna_float; ilebajt(lokalna_float, sizeof(lokalna_float));
	cout << "Zmienna - " << "globalna_double" << " wartosc: " << globalna_double << "  adres: " << &globalna_double; ilebajt(globalna_double, sizeof(globalna_double));
	cout << "Zmienna - " << "lokalna_double" << " wartosc: " << lokalna_double << "  adres: " << &lokalna_double; ilebajt(lokalna_double, sizeof(lokalna_double));

	char *wsk_lokalna_char = &lokalna_char;
	int *wsk_lokalna_int = &lokalna_int;
	long *wsk_lokalna_long = &lokalna_long;
	float *wsk_lokalna_float = &lokalna_float;
	double *wsk_lokalna_double = &lokalna_double;
	char *wsk_globalna_char = &globalna_char;
	int *wsk_globalna_int = &globalna_int;
	long *wsk_globalna_long = &globalna_long;
	float *wsk_globalna_float = &globalna_float;
	double *wsk_globalna_double = &globalna_double;

	cout << "Zmienna - " << "wsk_globalna_char" << " wartosc: " << *wsk_globalna_char; ilebajt(*wsk_globalna_char, sizeof(wsk_globalna_char));
	cout << "Zmienna - " << "wsk_lokalna_char" << " wartosc: " << *wsk_lokalna_char;  ilebajt(*wsk_lokalna_char, sizeof(wsk_lokalna_char));
	cout << "Zmienna - " << "wsk_globalna_int" << " wartosc: " << *wsk_globalna_int; ilebajt(*wsk_globalna_int, sizeof(wsk_globalna_int));
	cout << "Zmienna - " << "wsk_lokalna_int" << " wartosc: " << *wsk_lokalna_int; ilebajt(*wsk_lokalna_int, sizeof(wsk_lokalna_int));
	cout << "Zmienna - " << "wsk_globalna_long" << " wartosc: " << *wsk_globalna_long; ilebajt(*wsk_globalna_long, sizeof(wsk_globalna_long));
	cout << "Zmienna - " << "wsk_lokalna_long" << " wartosc: " << *wsk_lokalna_long; ilebajt(*wsk_lokalna_long, sizeof(wsk_lokalna_long));
	cout << "Zmienna - " << "wsk_globalna_float" << " wartosc: " << *wsk_globalna_float; ilebajt(*wsk_globalna_float, sizeof(wsk_globalna_float));
	cout << "Zmienna - " << "wsk_lokalna_float" << " wartosc: " << *wsk_lokalna_float; ilebajt(*wsk_lokalna_float, sizeof(wsk_lokalna_float));
	cout << "Zmienna - " << "wsk_globalna_double" << " wartosc: " << *wsk_globalna_double; ilebajt(*wsk_globalna_double, sizeof(wsk_globalna_double));
	cout << "Zmienna - " << "wsk_lokalna_double" << " wartosc: " << *wsk_lokalna_double; ilebajt(*wsk_lokalna_double, sizeof(wsk_lokalna_double));

}

void ilebajt(unsigned long long adres, int rozmiar)
{
	const unsigned char* bajt = reinterpret_cast<const unsigned char*>(&adres);
	cout << " Bajty: ";
	for (int i = 0; i < rozmiar; i++) 
	{
		printf("%x ", *(bajt++));
	}
	cout << endl;
}
