# AUFGABE 15 (BIS 16.11.2023, 13:30 UHR)

## THEMEN:

> Templates, Bubble Sort

## IHRE AUFGABE:

Implementieren Sie eine generische Sortierfunktion auf Basis des Bubble-Sort Algorithmus. Die Funktion soll dabei ein Array als Eingabeparameter enthalten und das sortierte Array zurückgeben.

Der Bubble-Sort Algorithmus durchläuft ein Feld / Array in einer Schleife und vergleicht zwei benachbarte Elemente. Sind diese falsch angeordnet, so werden sie vertauscht. Ist man am Ende des Feldes / des Arrays angelangt, so beginnt man wieder von vorne. Dieser Vorgang wird so lange wiederholt bis das Feld / Array ein Mal durchlaufen wird, ohne dabei ein einzelnes Element auszutauschen.

```cpp

#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;

// hier die Funktion 'sort' implementieren

int main(int argc, char *argv[])
{
    array<int,length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, length> sorted_int_container = sort(int_container);

    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char,length> char_container = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }

    array<string,length> string_container = {"Im", "Sommer", "ist", "es", "meistens", "heiß", "und", "es", "regnet", "wenig."};
    array<string, length> sorted_string_container = sort(string_container);

    for (size_t i = 0; i < sorted_string_container.size(); i++) {
        cout << i << ": " << sorted_string_container[i] << endl;
    }
}



```

## ANS:

```cpp

#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;


template<typename T, size_t SIZE>
bool not_sorted(array<T, SIZE> Array){
   for(unsigned int i=0, j=1; j < SIZE; i++, j++)
      if (Array[i] > Array[j])   return true;
   return false;
}

template<typename T, size_t SIZE>
array<T, SIZE> sort(array<T, SIZE> Array){

   unsigned int i, j;   T t;

   while(not_sorted(Array))
      for(i=0, j=1; j < SIZE; i++, j++)
         if (Array[i] > Array[j]){
            t = Array[j];
            Array[j] = Array[i];
            Array[i] = t;
         }

   return Array;
}

int main(int argc, char *argv[])
{
   array<int,length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
   array<int, length> sorted_int_container = sort(int_container);

   for (size_t i = 0; i < sorted_int_container.size(); i++) {
      cout << i << ": " << sorted_int_container[i] << endl;
   }

   array<char,length> char_container = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
   array<char, length> sorted_char_container = sort(char_container);

   for (size_t i = 0; i < sorted_char_container.size(); i++) {
      cout << i << ": " << sorted_char_container[i] << endl;
   }

   array<string,length> string_container = {"Im", "Sommer", "ist", "es", "meistens", "heiß", "und", "es", "regnet", "wenig."};
   array<string, length> sorted_string_container = sort(string_container);

   for (size_t i = 0; i < sorted_string_container.size(); i++) {
      cout << i << ": " << sorted_string_container[i] << endl;
   }
}



```

