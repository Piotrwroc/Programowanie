/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 5 1
*/


#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

void InitTab(char**& wsk);
void DodajImie(char* buf, char**& wsk);
void UsunNr(int numer, char**& wsk);
void UsunImie(char* buf, char**& wsk);
void WszystkieImionna(char** wsk);
void LiteraImiona(char literka, char** wsk);
void SortAlfabet(char** wsk);
void SortDlugosc(char** wsk);

int main()
{
	cout << "Autorem programu jest Piotr Jozefek" << endl;
	char** wsk;
	int numer = 0;
	char literka = 0;
	int y = 1, x = 0;
	char* buf;
	InitTab(wsk);
	while (y == 1)
	{
		cout << endl;
		cout << "Wybierz dzialanie" << endl;
		cout << "1. dodawanie do slownika nowego imienia wprowadzanego z klawiatury" << endl;
		cout << "2. drukowanie na ekranie wszystkich imion zapamietanych w slowniku" << endl;
		cout << "3. drukowanie na ekranie wszystkich imion rozpoczynajacych wskazana litera alfabetu" << endl;
		cout << "4. usuwanie imienia znajdujacego sie na wskazanej pozycji w tablicy (nalezy podac indeks pozycji, na ktorej znajduje sie imie do usuniecia)" << endl;
		cout << "5. usuwanie z tablicy imienia, wprowadzonego z klawiatury" << endl;
		cout << "6. sortowanie wszystkich imion zawartych w tablicy wedlug alfabetu" << endl;
		cout << "7. sortowanie wszystkich imion zawartych w tablicy wedlug dlugosci lancuch znakow" << endl;
		cout << "8. Zakoncz program" << endl;
		cout << endl;
		cin >> x;
		cout << endl;
		switch (x)
		{
		case 1:
			buf = (char*)malloc(85 * sizeof(char));
			cout << "Wprowadz imie: " << endl;
			cin.ignore();
			cin.getline(buf, 85);
			DodajImie(buf, wsk);
			free(buf);
			cout << endl;
			break;
		case 2:
			WszystkieImionna(wsk);
			cout << endl;
			break;
		case 3:
			cout << "Podaj litere na ktora imiona chcesz wyswietlic" << endl;
			cin >> literka;
			LiteraImiona(literka, wsk);
			cout << endl;
			break;
		case 4:
			cout << "Podaj nr wiersza ktory chcesz usunac, zaczynajac liczenie od 0" << endl;
			cin >> numer;
			UsunNr(numer, wsk);
			cout << endl;
			break;
		case 5:
			buf = (char*)malloc(85 * sizeof(char));
			cout << "Podaj imie ktore chcesz usunac: " << endl;
			cin.ignore();
			cin.getline(buf, 85);
			UsunImie(buf, wsk);
			free(buf);
			cout << endl;
			break;
		case 6:
			SortAlfabet(wsk);
			cout << "Posortowano" << endl;
			cout << endl;
			break;
		case 7:
			SortDlugosc(wsk);
			cout << "Posortowano" << endl;
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
void InitTab(char**& wsk)
{
	wsk = (char**)malloc(sizeof(char*));
	wsk[0] = NULL;
}
void DodajImie(char* buf, char**& wsk)
{
	int pozycja = 0;
	while (wsk[pozycja] != NULL) pozycja++;
	wsk = (char**)realloc(wsk, (pozycja + 2) * sizeof(char*));
	wsk[pozycja + 1] = NULL;
	wsk[pozycja] = _strdup(buf);
}
void UsunNr(int numer, char**& wsk)
{
	int pozycja = 0;
	while (wsk[pozycja] != NULL) pozycja++;
	if (numer >= pozycja || numer < 0)
	{
		cout << "Nie ma takiego numeru do usuniecia" << endl;
	}
	else
	{
		free(wsk[numer]);
		for (int i = numer; i < pozycja; i++)
		{
			wsk[i] = wsk[i + 1];
		}
		wsk = (char**)realloc(wsk, (pozycja * sizeof(char*)));
	}
}
void UsunImie(char* buf, char**& wsk)
{
	for (int i = 0; wsk[i] != NULL; i++)
	{
		for (int j = 0; wsk[i][j] == buf[j]; j++)
		{
			if (wsk[i][j] == NULL)
			{
				UsunNr(i, wsk);
				i--;
				break;
			}
		}
	}
}
void WszystkieImionna(char** wsk)
{
	for (int i = 0; wsk[i] != NULL; i++)
	{
		cout << i << ". ";
		for (int j = 0; wsk[i][j] != NULL; j++)
		{
			cout << wsk[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void LiteraImiona(char literka, char** wsk)
{
	for (int i = 0; wsk[i] != NULL; i++)
	{
		if (*wsk[i] == literka)
		{
			cout << i << ". ";
			for (int j = 0; wsk[i][j] != NULL; j++)
			{
				cout << wsk[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
}
void SortAlfabet(char** wsk)
{
	char* temp;
	for (int i = 1; wsk[i] != NULL; i++)
	{
		temp = wsk[i];
		int j = i - 1;
		while (j >= 0 && strcmp(wsk[j], temp) > 0)
		{
			wsk[j + 1] = wsk[j];
			j--;
		}
		wsk[j + 1] = temp;
	}
}
void SortDlugosc(char** wsk)
{
	char* temp;
	for (int i = 1; wsk[i] != NULL; i++)
	{
		temp = wsk[i];
		int j = i - 1;
		while (j >= 0 && strlen(wsk[j]) > strlen(temp))
		{
			wsk[j + 1] = wsk[j];
			j--;
		}
		wsk[j + 1] = temp;
	}
}
