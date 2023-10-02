#include <iostream>
#include<conio.h>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	unsigned short int h, m, hour_12;
	string den, chasi, minuti;
	cout << "Введите время(часы минуты) ";
	cin >> h >> m;

	if (h < 0 || m < 0 || h > 24 || m > 60)
	{
		cout << "Введено неправильное время ";
		cout << endl;
		_getch();
		return 0;
	}
	if ((h == 00 || h == 24) && m == 00)
	{
		cout << "Полночь";
		cout << endl;
		_getch();
		return 0;
	}
	if (h == 12 && m == 00)
	{
		cout << "Полдень";
		cout << endl;
		_getch();
		return 0;
	}

	if (h > 12) hour_12 = h - 12;
	else hour_12 = h;

	switch (hour_12)
	{
	case 1: chasi = " час ";
		break;
	case 2:
	case 3:
	case 4: chasi = " часа ";
		break;
	default: 
		chasi = " часов ";
	}

	if (m >= 10 && m <= 20) minuti = " минут ";
	else 
	{
		switch (m % 10)
		{
		case 00:
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			minuti = " минуты ";
			break;
		default:
			minuti = " минут ";
		}
	}

	if (h - 12 > -12 && h - 12 <= -7 ) den = "ночи";
	if (h - 12 > -7 && h - 12 < 0) den = "утра";
	if (h - 12 >= 0 && h - 12 < 6) den = "дня";
	if (h - 12 >= 6 && h - 12 <= 12)den = "вечера";
	if (m == 00) cout << hour_12 << chasi << den << " ровно";
	else cout << hour_12 << chasi << m << minuti << den;
	_getch();
	return 0;
}
