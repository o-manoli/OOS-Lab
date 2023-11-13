# AUFGABE 3 (BIS 12.10.2023, 13:30 UHR)

## THEMEN:

> Default Parameter

## IHRE AUFGABE:

Ergänzen Sie das Programmgerippe um _eine_ Funktion print_rectangle, die zwei Parameter entgegennimmt und ein Rechteck auf der Konsole ausgibt. Die Kantenlängen des Rechtecks entsprechen den jeweils übergebenen Parametern. Wird nur ein Parameter übergeben, so soll ein Quadrat ausgegeben werden, dessen Kantenlängen dem übergebenen Parameter entspricht.

Nutzen sie _kein_ Überladen. Verwenden Sie für die Lösung geeignete Defaultwerte für Parameter.

Der Aufruf der print_rectangle()-Funktion mit den Werten 2 und 5 führt z.B. zu folgender Ausgabe:

```bash
X X
X X
X X
X X
X X
```

Der Aufruf der print_rectangle()-Funktion mit dem Wert 4 führt z.B. zu folgender Ausgabe:

```bash
X X X X
X X X X
X X X X
X X X X
```

```cpp

#include <iostream>


int main(int argc, char *argv[])
{
	std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);

	std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);

	std::cout << "x = 4: " << std::endl;
	print_rectangle(4);

	return 0;
};


```

## ANS:

```cpp
#include <iostream>
#include <sstream>

using namespace std;

string join(const string joiner, const string repeated, int repeat){
	// repetitive string joiner

	if (repeat < 1)			return "";

	ostringstream S;

	S << repeated;

	while (--repeat)
		S << joiner << repeated;

	return S.str();
}

void print_rectangle(int width, int height){
	string line = join(" ", "X", width);
	cout << join("\n", line, height) << '\n' <<endl;
}

void print_rectangle(int dimension){
	print_rectangle(dimension, dimension);
}

int main(int argc, char *argv[])
{
	cout << "x = 2, y = 5: " << endl;
	print_rectangle(2, 5);

	cout << "x = 3, y = 3: " << endl;
	print_rectangle(3, 3);

	cout << "x = 4: " << endl;
	print_rectangle(4);

	return 0;
};

```

