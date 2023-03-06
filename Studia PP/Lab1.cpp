/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 1
*/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
	
	void zad_1()
	{
	cout << "Funkcja do rozwiazywania rownan kwadratowych" << endl;
	float a, b, c;
	cout << "Podaj wspolczyniki (a,b,c) w rownaniu ax^2+bx+c=0" << endl;
	cin >> a >> b >> c;
	if (a == 0)
	{
		cout << "Nie jest to rownanie kwadratowe" << endl;
	}
	else
	{
		if (b * b - 4 * a * c > 0)
		{
		cout << "Pierwiastki rzeczywiste rowniania to x1 = "<< (-b - sqrt(b * b - 4 * a * c)) / (2 * a) <<" i x2 = "<< (-b + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
		}
		else 
		{
			if (b* b - 4 * a * c == 0)
			{
				cout << "Pierwiastek rzeczywisty rownania to x1 = " << -b / (2 * a) << endl;
			}
			else cout << "Brak pierwiastkow rzeczywistych" << endl;
		}
	}
	system("PAUSE");
	system("cls");
	}
	void zad_2()
	{
		cout << "Funkcja do wypisywania daty" << endl;
		int d, m, rok;
		cout << "Podaj rok" << endl;
		cin >> rok;
		cout << "Podaj miesiac" << endl;
		cin >> m;
		cout << "Podaj dzien" << endl;
		cin >> d;
		if (rok % 4 != 0 || (rok % 100 == 0 && rok % 400 != 0))
		{
			if (m == 2)
			{
				if (d > 0 && d < 29)
				{
					cout << "Podana data to: " << d << ".";
					if (m < 10)
					{
						cout << "0";
					}
					cout << m << "." << rok << endl;
				}
				else cout << "Podana data nie istnieje" << endl;
			}
			else if (m > 0 && m < 13)
			{
				if ((((m / 2) * 2 != m) && (7 >= m)) || ((m / 2) * 2 == m && (7 < m)))
				{
					if (d > 0 && d < 32)
					{
						cout << "Podana data to: " << d << ".";
						if (m < 10)
						{
							cout << "0";
						}
						cout << m << "." << rok << endl;
					}
					else cout << "Podana data nie istnieje" << endl;
				}
				else
				{
					if (d > 0 && d < 31)
					{
						cout << "Podana data to: " << d << ".";
						if (m < 10)
						{
							cout << "0";
						}
						cout << m << "." << rok << endl;
					}
					else cout << "Podana data nie istnieje" << endl;
				}
			}
			else cout << "Podana data nie istnieje" << endl;

		}
		else
		{
			if (m == 2)
			{
				if (d > 0 && d < 30)
				{
					cout << "Podana data to: " << d << ".";
					if (m < 10)
					{
						cout << "0";
					}
					cout << m << "." << rok << endl;
				}
				else cout << "Podana data nie istnieje" << endl;
			}
			else if (m > 0 && m < 13)
			{
				if ((((m / 2) * 2 != m) && (7 >= m)) || ((m / 2) * 2 == m && (7 < m)))
				{
					if (d > 0 && d < 32)
					{
						cout << "Podana data to: " << d << ".";
						if (m < 10)
						{
							cout << "0";
						}
						cout << m << "." << rok << endl;
					}
					else cout << "Podana data nie istnieje" << endl;
				}
				else
				{
					if (d > 0 && d < 31)
					{
						cout << "Podana data to: " << d << ".";
						if (m < 10)
						{
							cout << "0";
						}
						cout << m << "." << rok << endl;
					}
					else cout << "Podana data nie istnieje" << endl;
				}
			}
			else cout << "Podana data nie istnieje" << endl;
		}
		system("PAUSE");
		system("cls");
	}
	void zad_3()
	{
		cout << "Funkcja do sprawdzania istnienia trojkata i wypisywania jego cech" << endl;
		float e, f, g;
		cout << "Podaj dlugosci trzech odcinkow" << endl;
		cin >> e >> f >> g;
		if (e > 0 && f > 0 && g > 0)
		{
			if (e + f > g && f + g > e && g + e > f)
			{
				if (e == f && e == g && f == g)
				{
					cout << "Trojkat jest rownoboczny" << endl;
				}
				if (e == f || e == g || f == g)
				{
					cout << "Trojkat jest rownoramienny" << endl;
				}
				if (e * e == f * f + g * g || f * f == e * e + g * g || g * g == e * e + f * f)
				{
					cout << "Trojkat jest prostokatny" << endl;
				}
				else if (e * e > f * f + g * g || f * f > e * e + g * g || g * g > e * e + f * f)
				{
					cout << "Trojkat jest rozwartokatny" << endl;
				}
				else if (e * e < f * f + g * g || f * f < e * e + g * g || g * g < e * e + f * f)
				{
					cout << "Trojkat jest ostrokatny" << endl;
				}
			}
			else cout << "Z tych odcinkow nie mozna zbudowac trojkata" << endl;
		}
		else cout << "Trojkat nie moze miec ujemnej dlugosci bokow" << endl;
		system("PAUSE");
		system("cls");
	}
	void zad_4()
	{
		cout << "Funkcja do tabelki z kolem" << endl;
		int lp;
		float min_r, max_r, r;
		cout << "Podaj minimalny promien" << endl;
		cin >> min_r;
		cout << "Podaj maksymalny promien" << endl;
		cin >> max_r;
		cout << "Podaj liczbe wierszy" << endl;
		cin >> lp;
		if (lp > 1)
		{
			if (min_r > 0 && max_r > 0)
			{
				printf("=================================================================\n");
				printf("|    Lp |   promien  |      obwod kola     |      pole kola     |\n");
				printf("=================================================================\n");
				for (int i = 0; i < lp; i++)
				{
					r = min_r + (((max_r - min_r) * i / (lp - 1)));
					printf("| %5d | %10.2f | %19.2f | %18.2f |\n", i + 1, r, M_PI * r * 2, M_PI * r * r);
				}
				printf("=================================================================\n");
			}
			else cout << "Promien musi byc dodatni" << endl;
		}
		else cout << "Liczba wierszy musi byc wieksza niz 1" << endl;
	}

	int main()
{
		cout << "Autorem programu jest Piotr Jozefek (WT/N 15:15)" << endl << endl;
		zad_1();
		zad_2();
		zad_3();
		zad_4();
	return 0;
}

