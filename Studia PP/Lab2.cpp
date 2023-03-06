/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 2
*/


#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

int NWD(int x, int y)
{
	while (x != y)
	{
		if (x < y)
		{
			y -= x;
		}
		else x -= y;
	}
	return x;
}
int NWW(int x, int y)
{
	return x / NWD(x, y) * y;
}
void zad_1()
{
	int wiersz, kolumna;
	cout << "Podaj liczbe wierszy" << endl;
	cin >> wiersz;
	cout << "Podaj liczbe kolumn" << endl;
	cin >> kolumna;

	if (kolumna > 31 || wiersz > 31)
	{
		cout << "Podano za duza liczbe" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(11) << " " << "|";
		for (int i = 1; i <= wiersz; i++)
		{
			cout << setw(6) << i;
		}
		cout << endl;
		for (int i = -1; i <= wiersz; i++)
		{
			cout << "------";
		}
		cout << endl;
		for (int i = 1; i <= wiersz; i++)
		{
			cout << setw(6) << i;
			cout << setw(6) << "|";
			for (int j = 1; j <= kolumna; j++)
			{
					cout << setw(6) << i * j;
			}
			cout << endl;
		}
	}
}
void zad_2()
{
	unsigned long liczba;
	int system,suma;
	cout << "Podaj liczbe w systemie dziesietnym" << endl;
	cin >> liczba;
	cout << "Podaj system liczbowy od 2 do 32" << endl;
	cin >> system;
	if (system > 1 && system < 33)
	{
		suma = 0;
		while (liczba)
		{
			suma = suma + (liczba % system);
			liczba = liczba / system;
		}
		cout << "Suma cyfr wynosi: " << suma << endl;
	}
	else
	{
		cout << "Podano zly zakres" << endl;
	}
	
}
void zad_3()
{
	int x, y;
	cout << "Podaj liczbe nr 1 i liczbe nr 2" << endl;
	cin >> x >> y;
	cout << "Najwiekszy wspolny dzielnik wynosi: " << NWD(x, y) << endl;
	cout << "Najmniejesza wspolna wielokrotnosc wynosi: " << NWW(x, y) << endl;
}
void zad_4()
{
	double S1 = 1, S2 = 1, S1_suma=0, S2_suma=1, dokladnosc, precyzja;
	cout << "Podaj dokladnosc obliczen" << endl;
	cin >> dokladnosc;
	if (dokladnosc > 0.1)
	{
		cout << "Zly zakres" << endl;
	}
	else
	{
		int precyzja = to_string(dokladnosc).length();
		double n = 3,m=2;
		int	i = 1;
		while (abs(S1) > dokladnosc)
		{
			S1_suma += S1;
			S1 = 1 / n;
			if (i%2 != 0)
			{
				S1 *= -1;
			}
			n += 2;
			i++;
		}
		S1_suma *= 4;
		while (abs(S2) > dokladnosc)
		{
			S2_suma += S2;
			S2 *= 1 / m;
			m ++;
		}
		cout << setprecision(precyzja+1) << "Wartosc S1 wynosi: " << S1_suma << endl;
		cout << setprecision(precyzja+1) << "Wartosc S2 wynosi: " << S2_suma << endl;
	}
}
void zad_5()
{
	int ilosc, min_l, max_l, losu, suma_d = 0, suma_u = 0;
	float ilosc_d=0, ilosc_u=0;
	srand(time(NULL));
	cout << "Podaj zakres minimalny" << endl;
	cin >> min_l;
	cout << "Podaj zakres maksymalny" << endl;
	cin >> max_l;
	cout << "Podaj ilosc liczb" << endl;
	cin >> ilosc;
	if (min_l > max_l)
	{
		cout << "Zakres minimalny nie moze byc wiekszy od maksymalnego" << endl;
	}
	else
	{
		for (int i = 0; i < ilosc; i++)
		{
			losu = min_l + rand() % (max_l - min_l + 1);
			if (losu < 0)
			{
				suma_u += losu;
				ilosc_u++;
			}
			else
			{
				suma_d += losu;
				ilosc_d++;
			}
		}
		if (ilosc_d > 0)
		{
			cout << "Ilosc liczb dodatnich to: " << ilosc_d << endl;
			cout << "Srednia liczb dodatnich to: " << suma_d / ilosc_d << endl;
		}
		if (ilosc_u > 0)
		{
			cout << "Ilosc liczb ujemnych to:" << ilosc_u << endl;
			cout << "Srednia liczb ujemnych to:" << suma_u / ilosc_u << endl;
		}
	}
}
int main()
{
	int x,y=1;
	while (y == 1)
	{
		cout << "Wybierz dzialanie" << endl;
		cout << "1. Zadanie nr 1" << endl;
		cout << "2. Zadanie nr 2" << endl;
		cout << "3. Zadanie nr 3" << endl;
		cout << "4. Zadanie nr 4" << endl;
		cout << "5. Zadanie nr 5" << endl;
		cout << "6. Zakoncz program" << endl;
		cout << endl;
		cin >> x;
		cout << endl;
		switch (x)
		{
		case 1:
			zad_1();
			cout << endl;
			break;
		case 2:
			zad_2();
			cout << endl;
			break;
		case 3:
			zad_3();
			cout << endl;
			break;
		case 4:
			zad_4();
			cout << endl;
			break;
		case 5:
			zad_5();
			cout << endl;
			break;
		case 6:
			cout << "Koniec programu" << endl;
			y = 2;
			break;
		default:
			cout << "Wybrano zly nr zadania" << endl << endl;;
		}
	}
	return 0;
}