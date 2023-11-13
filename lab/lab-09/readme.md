# AUFGABE 9 (BIS 02.11.2023, 13:30 UHR)

## THEMEN:

> Operatoren

## IHRE AUFGABE:

Implementieren Sie den Konstruktor und die Operatoren, die für die Klasse Datum angegeben sind. Sie können zur Vereinfachung davon ausgehen, dass ein Jahr 360 Tage und jeder Monat 30 Tage hat.

Das angegebene Hauptprogramm soll folgende Ausgabe erzeugen:

Ausgabe:

```bash
Die Aufgabe beginnt am 26.10.2023
Die Aufgabe endet am 2.11.2023
Ein Jahr und ein Monat nach Aufgabenbeginn ist der 26.11.2024
Drei Jahre und 11 Monate nach Aufgabenbeginn ist der 26.9.2027
```

```cpp


#include<iostream>
using namespace std;

class Date {

	int _day, _month, _year;

public:
	Date(int = 0, int = 0, int = 0);
	Date operator+(int days);
	friend ostream & operator<<(ostream &, const Date &);
};


int main(int argc, char *argv[])
{
    Date begin_task = Date(26,10,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}



```

## ANS:

```cpp

#include<iostream>

using namespace std;

class Date {

	int _day, _month, _year;

public:
	Date(
		int day = 0, int month = 0, int year = 0
		) :
		_day{day}, _month{month}, _year{year} {};

	Date operator+(int days){
		int day = _day, month = _month, year = _year;

		int sum = days + day;
		int carryover = sum / 30;
		day = sum % 30;					// Rest

		sum = month + carryover;
		carryover = sum / 12;
		month = sum % 12;

		year += carryover;

		return Date(day, month, year);
	}

	friend ostream & operator<<(ostream &, const Date &);

};

ostream& operator<< (ostream& S, const Date &D){
	return S
	<< D._day
	<< "." << D._month
	<< "." << D._year;
}

int main(int argc, char *argv[])
{
	Date begin_task = Date(26,10,2023);
	cout << "Die Aufgabe beginnt am " << begin_task << endl;
	Date end_task = begin_task + 6;
	cout << "Die Aufgabe endet am " << end_task << endl;
	Date one_year_and_one_month_later = begin_task + 390;
	cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
	Date three_years_and_eleven_months_later = begin_task + 1410;
	cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;

	return 0;
}

```

