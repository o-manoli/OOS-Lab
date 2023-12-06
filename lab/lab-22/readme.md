# AUFGABE 22 (BIS 07.12.2023, 13:30 UHR)

## THEMEN:

Stringformatierung

## IHRE AUFGABE:

Um die Ausgaben über einen Standard-Stream zu formatieren, stehen eine Reihe von Manipulatoren zur Verfügung (siehe die Folien aus der Vorlesung). Während die meisten Manipulatoren in der Bibliothek iostream enthalten sind, benötigen die Manipulatoren setprecision, setw und setfill die Bibliothek iomanip. Genaue Beschreibungen der Manipulatoren sowie Beispiele finden Sie unter der generell hilfreichen Webadresse http://www.cplusplus.com/reference. Ergänzen Sie das untenstehende Programm an den Stellen /_xxx_/, so dass es die nachfolgende Ausgabe erzeugt:

```bash
 Nr Oct  Hex String  Fixed     Scientific
  1  01  0x1 **+++++ +   1.234  1.234E+00
  2  02  0x2 ***++++ -   2.468 -2.468E+00
  3  03  0x3 ****+++ +   4.936  4.936E+00
  4  04  0x4 *****++ -   9.872 -9.872E+00
  5  05  0x5 *++++++ +  19.744  1.974E+01
  6  06  0x6 **+++++ -  39.488 -3.949E+01
  7  07  0x7 ***++++ +  78.976  7.898E+01
  8 010  0x8 ****+++ - 157.952 -1.580E+02
  9 011  0x9 *****++ + 315.904  3.159E+02
 10 012  0xa *++++++ - 631.808 -6.318E+02
```


```cpp


#include <string>
#include /*XXX*/
#include /*XXX*/
using namespace std;

int main(int argc, char* argv[]) {
	double d = 1.234;
	cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{
		cout << /* xxx */ << k;
		cout << /* xxx */ << k;
		cout << /* xxx */ << k << " ";
		cout << /* xxx */ <<  string(k % 5 + 1, '*')  << " ";
		cout << /* xxx */ << d;
		cout << /* xxx */ << d;
		d = d*-2;

		cout << endl;
	}
	return 0;
}


```

## ANS:

```cpp
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
	double d = 1.234;
	cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{
		cout << setw(3) << dec
			<< k;

		cout << setw(4) << showbase << oct
			<< k;

		cout << setw(5) << nouppercase << hex
			<< k;

		cout << " " << setw(7) << left << setfill('+')
			<< string(k % 5 + 1, '*') << " "; // repeat '*' (k % 5 + 1) times

		cout << setw(9) << internal << showpos
			<< setfill(' ') // reset fill
			<< setprecision(3) << fixed
			<< d;

		cout << setw(11) << right // rest to right alignment
			<< setprecision(3) << scientific
			<< noshowpos << uppercase
			<< d;

		d = d * -2;

		cout << endl;
	}
	return 0;
}


```

