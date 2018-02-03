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
		cout << "������� ����� �������:";
		cin >> n;

		switch (n) {
			//6.	��������� ������� MonthDays �� ������� 4, ������� ��������� NextDate(D, M, Y), ������� �� ���������� � ���������� ����, 
			//�������- ��� ���� D, ����� ������ M � ��� Y, ���������� ��������� ���� (����- ����� ������ ���� D, M, Y �������� ������������ �������� � ���������).
			//��������� ��������� NextDate � ���� �������� ����� � ������� ���������� �������� ��������� ���
		case 1: {

			int month, year, day;
			cout << "������� ���: ";
			cin >> year;
			cout << "������� �����: ";
			cin >> month;
			cout << "������� ����: ";
			cin >> day;

			NextDate(day, month, year);

		} break;

			//7.	��������� ������� Dist �� ������� Proc59, ������� ��������� Altitudes(xA, yA, xB, yB, xC, yC, hA, hB, hC), 
			//��������� ������ hA, hB, hC ������������ ABC (�������� ���������), ����������� �������������� �� ������ A, B, C 
			//(�� ���������� �������� �������� �����������). � ������� ���� ��������� ����� ������ ������������� ABC, ABD, ACD, ���� ���� ���������� ����� A, B, C, D.
		case 2: {
			double xa, ya, xb, yb,xc,yc, a,b,c,ha,hb,hc;
			cout << "������� ����������: " << endl;
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

			cout << "������� a: " << a << endl;
			cout << "������� b: " << b << endl;
			cout << "������� c: " << c << endl;
			
			ha= heights( a,  b,c);
			hb = heights(b, c, a);
			hc = heights(c, a, b);

			cout << "������ ha: " << ha << endl;
			cout << "������ hb: " << hb << endl;
			cout << "������ hc: " << hc << endl;


		} break;

			//8.	���������� ������� double f(double x, double y), ������� ��������� � ���������� ����� ���������� �������������� ������������,
			//��� ������ ������� x � y �������� ��������
		case 3: {
			double x, y;
			cout << "������� ������� x: ";
			cin >>x;
			cout << "������� ������� y: ";
			cin >> y;

			double gip= f(x,y);
			cout << "����������: " << gip << endl;

		} break;

			//9.	�������� ������� double f(double x1, double y1, double x2, double y2), ������� ��������� ���������� ����� ����� ������� (xl, yl) � (x2, y2)
		case 4: {
			double x1, y1, x2, y2,d;
			cout << "������� ����������: "<<endl;
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
			cout << "���������� ����� �������: " << d << endl;
		} break;

			//10.	�������� ������� int f(int m2, int m1, int m0), ������� ��������� � ���������� ����������� �����, ������ (�����),
			//������ (�������) � ������ (�������) ����� �������� ����� �������������� m2, m1, m0
		case 5: {
			int a,m2,m1,m0;
			a = 100 + rand() % 899;
			cout << "a: " << a << endl;
		m2= f(a);
			m1 = f1(a);
			m0 = f2(a);
			cout << "����� m2: " << m2 << endl;
			cout << "������� m1: " << m1 << endl;

			cout << "������� m0: " << m0 << endl;
			
		} break;
		}
	} while (n > 0);
}

//�������, ������������ ���������� ��� ��� ���
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
				cout << "������� ���������� ����." << endl;
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

	cout << "���� ���������� ���: " <<
				day << "." <<
				month << "." <<
				year << endl;

}

//���������� �������������� ������������
double f(double x, double y)
{
	double c; //����������
	c = sqrt(x*x + y*y);
	return c;
}

//��������� � ����� 2-�� �������
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

//������ ������������
double heights(double x, double y, double z)
{
	double s, p,hx;
	 p = (x + y + z) / 2;
	 s = sqrt(p*(p -x)*(p -y)*(p - z));
	 hx = (2 * s) / x;
	
	 return hx;
}