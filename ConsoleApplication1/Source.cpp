#include<stdio.h>
#include<locale.h>
#include<iostream>
#include<stdint.h>
#include<time.h>

//U1M6-2_2401

int isLeap(int year);
int MonthDays(int month, int year);
void NextDate(int day, int month, int year);
double f(double x, double y);
double dist(double x1, double y1, double x2, double y2);
int f( int a);
int f1(int a);
int f2(int a);
double heights(double x, double y, double z);

using namespace std;

void main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	do
	{
		cout << "введите номер задания:";
		cin >> n;

		switch (n) {
			//6.	Используя функцию MonthDays из задания 4, описать процедуру NextDate(D, M, Y), которая по информации о правильной дате, 
			//включаю- щей день D, номер месяца M и год Y, определяет следующую дату (пара- метры целого типа D, M, Y являются одновременно входными и выходными).
			//Применить процедуру NextDate к трем исходным датам и вывести полученные значения следующих дат
		case 1: {

			int month, year, day;
			cout << "Введите год: ";
			cin >> year;
			cout << "Введите месяц: ";
			cin >> month;
			cout << "Введите день: ";
			cin >> day;

			NextDate(day, month, year);

		} break;

			//7.	Используя функцию Dist из задания Proc59, описать процедуру Altitudes(xA, yA, xB, yB, xC, yC, hA, hB, hC), 
			//находящую высоты hA, hB, hC треугольника ABC (выходные параметры), проведенные соответственно из вершин A, B, C 
			//(их координаты являются входными параметрами). С помощью этой процедуры найти высоты треугольников ABC, ABD, ACD, если даны координаты точек A, B, C, D.
		case 2: {
			double xa, ya, xb, yb,xc,yc, a,b,c,ha,hb,hc;
			cout << "введите координаты: " << endl;
			cout << "xa: ";
			cin >> xa;
			cout << endl;
			cout << "ya:";
			cin >> ya;
			cout << "xb: ";
			cin >> xb;
			cout << endl;
			cout << "yb:";
			cin >> yb;
			cout << endl;
			cout << "xc: ";
			cin >> xc;
			cout << endl;
			cout << "yc:";
			cin >> yc;
			cout << endl;

			a = dist(xa, ya, xb, yb);
			b = dist(xb, yb, xc, yc);
			c = dist(xc, yc, xa, ya);

			cout << "Сторона a: " << a << endl;
			cout << "Сторона b: " << b << endl;
			cout << "Сторона c: " << c << endl;
			
			ha= heights( a,  b,c);
			hb = heights(b, c, a);
			hc = heights(c, a, b);

			cout << "высота ha: " << ha << endl;
			cout << "высота hb: " << hb << endl;
			cout << "высота hc: " << hc << endl;


		} break;

			//8.	Определите функцию double f(double x, double y), которая вычисляет и возвращает длину гипотенузы прямоугольного треугольника,
			//две другие стороны x и y которого известны
		case 3: {
			double x, y;
			cout << "Введите сторону x: ";
			cin >>x;
			cout << "Введите сторону y: ";
			cin >> y;

			double gip= f(x,y);
			cout << "гипотенуза: " << gip << endl;

		} break;

			//9.	Напишите функцию double f(double x1, double y1, double x2, double y2), которая вычисляет расстояние между двумя точками (xl, yl) и (x2, y2)
		case 4: {
			double x1, y1, x2, y2,d;
			cout << "введите координаты: "<<endl;
			cout << "x1: ";
			cin >> x1;
			cout<<endl;
			cout << "y1:";
			cin >> y1;
			cout << "x2: ";
			cin >> x2;
			cout << endl;
			cout << "y2:";
			cin >> y2;
			cout << endl;

			d = dist(x1, y1, x2, y2);
			cout << "расстояние между точками: " << d << endl;
		} break;

			//10.	Напишите функцию int f(int m2, int m1, int m0), которая вычисляет и возвращает натуральное число, первая (сотни),
			//вторая (десятки) и третья (единицы) цифры которого равны соответственно m2, m1, m0
		case 5: {
			int a,m2,m1,m0;
			a = 100 + rand() % 899;
			cout << "a: " << a << endl;
		m2= f(a);
			m1 = f1(a);
			m0 = f2(a);
			cout << "сотни m2: " << m2 << endl;
			cout << "десятки m1: " << m1 << endl;

			cout << "единицы m0: " << m0 << endl;
			
		} break;
		}
	} while (n > 0);
}

//Функция, определяющая високосный год или нет
int isLeap(int year)
{
	int isLeap = 0;
	if ((year % 4 == 0 && year % 100) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

//4
int MonthDays(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (isLeap(year) == 1)
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

void NextDate(int day, int month, int year)
{
	int leap = isLeap(year);
	if ((day < 1 && day>31) && (month<1 || month>12))
			{
				cout << "Введите правильную дату." << endl;
			}
	if ((MonthDays(month,year) == 30) || (MonthDays(month, year) == 31)|| (MonthDays(month, year) == 29) || (MonthDays(month, year) == 28))
	{
		day = 1;

		if (month == 12)
		{
			month = 1;
			year = year + 1;
		}
		else
			month = month + 1;
	}
	else
		day = day + 1;

	cout << "дату следующего дня: " <<
				day << "." <<
				month << "." <<
				year << endl;

}

//гипотенуза прямоугольного треугольника
double f(double x, double y)
{
	double c; //гипотенуза
	c = sqrt(x*x + y*y);
	return c;
}

//расстояни е между 2-мя точками
double dist(double x1, double y1, double x2, double y2)
{
	return((sqrt(abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2))));
}

//10
int f(int a)
{
	int x2 = a / 100;
	return x2;
}
int f1(int a)
{
	int x2 = a / 100;
	int x1 = (a - x2 * 100) / 10;
	return x1;
}
int f2(int a)
{
	int x2 = a / 100;
	int x1 = (a - x2 * 100) / 10;
	int x0 = a - x2 * 100 - x1 * 10;
	return x0;
}

//высота треугольника
double heights(double x, double y, double z)
{
	double s, p,hx;
	 p = (x + y + z) / 2;
	 s = sqrt(p*(p -x)*(p -y)*(p - z));
	 hx = (2 * s) / x;
	
	 return hx;
}