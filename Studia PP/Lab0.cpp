/*
Autor:  Piotr Józefek   
Temat:  Laboratorium 0
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int a = 0, b = 0, c = 0;
float r = 0;

void wizytowka_1()
{
	cout << "Autor: Piotr Jozefek" << endl;
	cout << endl;
	cout << "Imie: Piotr" << endl;
	cout << "Nazwisko: Jozefek" << endl;
	cout << "Adres: ul. Szybka 12/5" << endl;
	cout << "Nr telefonu: 123456789" << endl;
	cout << "Adres email: 2137@student.pwr.edu.pl" << endl;
	system("PAUSE");
}
void wizytowka_2()
{
	printf("\n");
	printf("Imie: Baldwin \n");
	printf("Nazwisko: Plantagenet \n");
	printf("Adres: ul. Wolna 21/37 \n");
	printf("Nr telefonu: 987654321 \n");
	printf("Adres email: 272312@student.pwr.edu.pl \n");
	system("PAUSE");
}
void liczenie_1()
{
	cout << endl;
	cout << "Podaj wartosc 1 liczby:";
	cin >> a;
	cout << "Podaj wartosc 2 liczby:";
	cin >> b;
	cout << "Podaj wartosc 3 liczby:";
	cin >> c;
	float d = a + b + c;
	cout << "Suma liczb wynosi " << a + b + c << endl;
	cout << "Iloczyn liczb wynosi " << a * b * c << endl;
	cout << "Srednia arytmetyczna wynosi " << d / 3 << endl;
	system("PAUSE");
}
void liczenie_2()
{
	printf("\n");
	printf("Podaj wartosc 1 liczby: ");
	scanf("%d", &a);
	printf("Podaj wartosc 2 liczby: ");
	scanf("%d", &b);
	printf("Podaj wartosc 3 liczby: ");
	scanf("%d", &c);
	float d = a + b + c;
	printf("Suma liczb wynosi %d \n", a + b + c);
	printf("Iloczyn liczb wynosi %d \n", a* b* c);
	printf("Srednia arytmetyczna wynosi %f \n", d / 3);
	system("PAUSE");
}
void kolo_1()
{
	printf("\n");
	printf("Podaj wartosc promienia r: \n");
	scanf("%f", &r);
	printf("Obwod wynosi %f \n", M_PI * 2 * r);
	printf("Pole wynosi %f \n", M_PI* r* r);
	system("PAUSE");
}
void kolo_2()
{
	cout << endl;
	cout << "Podaj wartosc promienia r: " << endl;
	cin >> r;
	cout << "Obwod wynosi " << M_PI * 2 * r << endl;
	cout << "Pole wynosi " << M_PI * r * r << endl;
	system("PAUSE");
}

int main()
{
	wizytowka_1();
	wizytowka_2();
	liczenie_2();
	liczenie_2();
	kolo_1();
	kolo_2();
	return 0;
}
