/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 4 1b
*/

#include <iostream>
#include <conio.h>
using namespace std;

void Wczytaj(float *a, float *b, float *c);
void Wynik(int n, float x, float y);
float Wyznacznik(float p1, float p2, float p3, float p4);
int  Oblicz(float *a1, float *b1, float *c1, float *a2, float *b2, float *c2, float *x, float *y);

int main()
{
	float a1, b1, c1;
	float a2, b2, c2;
	float x, y;
	int n;
	Wczytaj(&a1, &b1, &c1);
	Wczytaj(&a2, &b2, &c2);
	n = Oblicz(&a1, &b1, &c1, &a2, &b2, &c2, &x, &y);
	Wynik(n, x, y);
	_getch();
	return 0;
}

void Wczytaj(float *a, float *b, float *c)
{
	cout << "Podaj liczby a, b i c w rownaniu a*x+b*y=c" << endl;
	cin >> *a >> *b >> *c;
	cout << endl;
}
void Wynik(int n, float x, float y)
{
	if (n == 2)
	{
		cout << "Rownanie ma nieskonczenie wiele rozwiazan" << endl;
	}
	if (n == 1)
	{
		cout << "Rownanie ma jedno rozwiazanie" << endl;
		cout << "x= " << x << " y= " << y << endl;
	}
	if (n == 0)
	{
		cout << "Rownanie nie ma rozwiazan" << endl;
	}
}
float Wyznacznik(float p1, float p2, float p3, float p4)
{
	return p1 * p4 - p2 * p3;
}
int  Oblicz(float *a1, float *b1, float *c1, float *a2, float *b2, float *c2, float *x, float *y)
{
	float w = 0, wx = 0, wy = 0;
	w = Wyznacznik(*a1, *b2, *a2, *b1);
	wx = Wyznacznik(*c1, *b2, *c2, *b1);
	wy = Wyznacznik(*a1, *c2, *a2, *c1);

	if (w != 0)
	{
		*x = wx / w;
		*y = wy / w;
		return 1;
	}
	else if (w == 0 and wx == 0 and wy == 0)
	{
		return 2;
	}
	else if (w == 0 and wx != 0 and wy != 0)
	{
		return 0;
	}
}