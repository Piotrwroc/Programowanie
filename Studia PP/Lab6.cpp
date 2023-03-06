/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 6
*/



#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

struct towar
{
	char nazwa[20];
	float cena;
	int ilosc;
};

void stworz(int& rozmiar, towar*& tab);
void wypisz(int rozmiar, towar *tab);
void dopisz(int& rozmiar, towar*& tab);
void usun(int& rozmiar, towar*& tab);
void reset(int& rozmiar, towar*& tab);
void zapis(int& rozmiar, towar*& tab);
void odczyt(int& rozmiar, towar*& tab);

int main()
{
	cout << "Autorem programu jest Piotr Jozefek" << endl;
	int rozmiar = 0;
	struct towar* tab;
	tab = NULL;
	int y = 1, x = 0;
	while (y == 1)
	{
		cout << endl;
		cout << "Adres tablicy to: " << tab << endl;
		cout << "Rozmiar tablicy to: " << rozmiar << endl;
		cout << endl;
		cout << "Wybierz dzialanie" << endl;
		cout << "1. Tworzenie tablicy dynamicznej" << endl;
		cout << "2. Wyswietlanie tablicy" << endl;
		cout << "3. Dodaj element" << endl;
		cout << "4. Usun element" << endl;
		cout << "5. Usun tablice" << endl;
		cout << "6. Zapisz plik" << endl;
		cout << "7. Wczytaj z pliku" << endl;
		cout << "8. Zakoncz program" << endl;
		cout << endl;
		cin >> x;
		cout << endl;
		switch (x)
		{
		case 1:
			stworz(rozmiar, *&tab);
			cout << endl;
			break;
		case 2:
			wypisz(rozmiar, *&tab);
			cout << endl;
			break;
		case 3:
			dopisz(rozmiar, tab);
			cout << endl;
			break;
		case 4:
			usun(rozmiar, *&tab);
			cout << endl;
			break;
		case 5:
			reset(rozmiar, *&tab);
			cout << endl;
			break;
		case 6:
			zapis(rozmiar, *&tab);
			cout << endl;
			break;
		case 7:
			odczyt(rozmiar, *&tab);
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
void stworz(int& rozmiar, towar*& tab)
{
	if (tab != NULL)
	{
		delete[] tab;
	}
	cout << "Podaj rozmiar nowej tablicy" << endl;
	cin >> rozmiar;
	tab = new towar[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		cout << "Podaj nazwe" << endl;
		cin.ignore();
		cin.getline(tab[i].nazwa, sizeof(char[20]));
		cout << "Podaj cene" << endl;
		cin >> tab[i].cena;
		cout << "Podaj ilosc" << endl;
		cin >> tab[i].ilosc;
	}
}
void wypisz(int rozmiar, towar* tab)
{
	if (tab == NULL)
	{
		cout << "Brak tablicy" << endl;
	}
	else
	{
		cout << "|       nazwa        |  cena   |  ilosc  |" << endl;
		cout << "|----------------------------------------|" << endl;
		for (int i = 0; i < rozmiar; i++)
		{

			cout << "|"; cout << setw(20) << tab[i].nazwa << "|"; cout << setw(9) << tab[i].cena << "|"; cout << setw(9) << tab[i].ilosc << "|" << endl;
		}
		cout << "|----------------------------------------|" << endl;
	}
}
void dopisz(int& rozmiar, towar*& tab)
{
	if (tab == NULL)
	{
		tab = new towar[rozmiar];
	}
		int zmiana = 0;
		cout << "Ile elementow chcesz dodac" << endl;
		cin >> zmiana;
		towar* new_tab = new towar[rozmiar + zmiana];
		for (int i = 0; i < rozmiar; i++)
		{
			new_tab[i] = *tab;
		}
		for (int i = rozmiar; i < rozmiar+zmiana; i++)
		{
			cout << "Podaj nazwe" << endl;
			cin.ignore();
			cin.getline(new_tab[i].nazwa, sizeof(char[20]));
			cout << "Podaj cene" << endl;
			cin >> new_tab[i].cena;
			cout << "Podaj ilosc" << endl;
			cin >> new_tab[i].ilosc;
		}
		delete[] tab;
		tab = new_tab;
		rozmiar +=zmiana;
}
void usun(int& rozmiar, towar*& tab)
{
	int nr;
	cout << "Podaj nr wiersza ktory chcesz usunac zaczynajac liczenie od 0" << endl;
	cin >> nr;
	if (nr >= rozmiar || nr < 0)
	{
		cout << "Nie ma takiego numeru do usuniecia" << endl;
	}
	else
	{
		for (int i = nr; i < rozmiar-1; i++)
		{
			tab[i] = tab[i + 1];
		}
		rozmiar--;
		tab = (towar*)realloc(tab, (rozmiar * sizeof(towar)));
	}
}
void reset(int& rozmiar, towar*& tab)
{
	if (tab == NULL)
	{
		cout << "Brak tablicy do usuniecia" << endl;
	}
	else 
	{
		delete[] tab;
		rozmiar = 0;
		tab = NULL;
	}
}
void zapis(int& rozmiar, towar*& tab)
{
	fstream plik;
	string nazwa;
	cout << "Podaj nazwe pliku do ktorego chcesz zapisac dane uwzgledniajac rozszerzenie pliku: ";
	cin >> nazwa;
	
	plik.open(nazwa, ios::out);
	cout << nazwa << endl;
	if (plik.good() == true)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			plik << tab[i].nazwa << endl;
			plik << tab[i].cena << endl;
			plik << tab[i].ilosc << endl;
		}
		plik.close();
	}
	else cout << "zapis nieduany" << endl;
}
void odczyt(int& rozmiar, towar*& tab)
{
	string nazwa;
	cout << "Podaj nazwe pliku z ktorego chcesz odczytac dane uwzgledniajac rozszerzenie pliku: ";
	cin >> nazwa;
	fstream plik;
	plik.open(nazwa, ios::in);
	
	if (plik.good() == true) 
	{
		rozmiar = 0;
		int i = 0;
		
		string linie;
		while (getline(plik, linie))
		{
			rozmiar++;
		}
		plik.close();
		plik.open(nazwa, ios::in);
		rozmiar /= 3;
		delete[] tab;
		tab= new towar[rozmiar];
		int j = 0;
		while (!plik.eof()) 
		{
			plik >> tab[j].nazwa>> tab[j].cena >> tab[j].ilosc;
			j++;
		}
		plik.close();
	}
	else
	{
		cout << "odczyt nieduany" << endl;
		delete[] tab;
		rozmiar = 0;
		tab = NULL;
	}
}
