# AUFGABE 0 (BIS 05.10.2023, 13:30 UHR)

### THEMEN:

> Ein-/Ausgabe, Schleifen, Arrays

## IHRE AUFGABE:

Schreiben Sie ein Programm, das den Nutzer fragt, wie viele ganze Zahlen eingelesen werden sollen (maximal 10). Lesen Sie dann die gewünschte Anzahl von ganzen Zahlen in ein Array ein. Geben Sie alle Zahlen im Array sowie deren Durchschnitt aus.

Wenn 3 Zahlen eingegeben werden sollen und die Zahlen 1, 3 und 6 eingegeben werden, muss die Ausgabe folgendermaßen aussehen:

```bash
Anzahl eingeben:
Zahl eingeben:
Zahl eingeben:
Zahl eingeben:
Zahl[0]: 1
Zahl[1]: 3
Zahl[2]: 6
Durchschnitt: 3.33333
```

```cpp


int main(int argc, char* argv[])
{
	return 0;
}


```


## ANS:

```cpp

#include <iostream>
#include <array>

using std::cout, std::cin, std::endl;
using std::array;

#define MAX_SIZE 10

int main(int argc, char* argv[]){

	int size;

	do {
		cout << "Anzahl eingeben:" << endl;
		cin >> size;
	} while (size > MAX_SIZE || size < 0);

	array<int, MAX_SIZE> A;

	int i = 0;

	while (i < size){
		cout << "Zahl eingeben:" << endl;
		cin >> A[i++];
	}

	int sum = 0;

	for (i = 0; i < size; i++){
		cout << "Zahl["<< i << "]: " << A[i] << "\n";
		sum += A[i];
	}

	float average = static_cast<float>(sum) / static_cast<float>(size);

	cout << "Durchschnitt: " << average << endl;

	return 0;
}

```