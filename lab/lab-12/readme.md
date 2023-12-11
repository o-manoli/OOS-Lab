# AUFGABE 12 (BIS 09.11.2023, 13:30 UHR)

## THEMEN:

> Mehrfache Vererbung, Vermeidung von mehrfachem Erbgut

## IHRE AUFGABE:

Das gegebene Programm erzeugt die folgende Ausgabe:

```bash
D1::print() ...
---------------------
C2::a = D1C2A
---------------------
C3::a = D1C3A
---------------------
C2::b = D1C2B
---------------------
C3::b = D1C3B
---------------------

D2::print() ...
---------------------
C1::a = D2C1A
---------------------
C2::a = D2C2A
---------------------
C3::a = D2C3A
---------------------
C1::b = D2C1B
---------------------
C2::b = D2C2B
---------------------
C3::b = D2C3B
---------------------
```

Die Funktionen `search` und `cell` zusammen geben die Instanzvariablen der Objekte _d1_object_ und _d2_object_ aus. Instanzvariablen, die bei der Ausgabe in getrennten Zeilen ausgegeben werden, sind eigenständige Instanzvariablen, die eigenen Speicherplatz in Anspruch nehmen. In der Ausgabe oben werden daher die Instanzvariablen `a` und `b` mehrfach an `D1` und `D2` vererbt. Ändern Sie die Klassen im Programm so ab, dass die folgende Ausgabe erzeugt wird:

```bash
D1::print() ...
---------------------
C2::a C3::a = D1A
---------------------
C2::b C3::b = B
---------------------

D2::print() ...
---------------------
C1::a C2::a C3::a = A
---------------------
C1::b = D2C1B
---------------------
C2::b C3::b = D2B
---------------------
```

Es soll also für das Attribut `a` ein gemeinsames Erbgut über alle abgeleiteten Klassen geben und für das Attribut `b` ein gemeinsames Erbgut für die Klassen `C2` und `C3` aber ein separates Erbgut für die Klasse `C1`.

Verwenden Sie dazu virtuelle Ableitung und ergänzen Sie Initialisierungslisten wenn notwendig. Ändern Sie _nicht_ die Default-Parameter der Konstruktoren und ändern sie _nicht_ die existierende Delegation an Konstruktoren der abgeleiteten Klassen.

```cpp


#include <iostream>
#include <string>
using namespace std;

// Name name und Wert val einer Instanzvariable ausgeben
void cell(string name, int value) {
   cout << "---------------------" << endl;
   cout << name << "= " << value << endl;
}

// Die Instanzvariablen raussuchen und ausgeben,
// die wegen virtuellen Basisklassen zusammenfallen
void search(string names[], int* p_values[], int n) {
    // Zustand von cout zwischenspeichern
   ios::fmtflags cout_flags = cout.flags();
   // Hilfsvariablen initialisieren
   int i = 0;
   int k = 0;
   string str = "";
   // cout für Ausgabe der Instanzvariablen konfigurieren
   cout << hex << uppercase;
   // Schauen, ob Instanzvariable i (p_values[i])
   // evtl. mit Variable k (p_values[k]) zusammenfällt
   while (i < n) {
      // Wenn Variable i+k und i+k+1 identisch ...
      if ((i + k < n - 1) && (p_values[i + k] == p_values[i + k + 1])) {
         // erhöhe k
         k++;
        } else {
         // andernfalls gib die zusammengefallenen Variablen
         // auf einer Zeile aus
            // Text für Ausgabe zusammenstellen
         for (int m = i; m <= i + k; m++) {
            str += names[m] + " ";
         }
         // Text und Wert ausgeben
         cell(str, *p_values[i]);
         // Hilfsvariablen für nächste Prüfung zurücksetzen
         str = "";
         i += k + 1;
         k = 0;
      }
   }
   cout << "---------------------" << endl << endl;
   // Ursprünglicher Zustand von cout wieder herstellen
   cout.flags(cout_flags);
}

// Klassenhierarchie
class A {
public:
   int _a;
   A(int a = 0xA) : _a(a) {}
};

class B : public A {
public:
   int _b;
   B(int a = 0xBA, int b = 0xB) : A(a), _b(b) {}
};

class C1 : public B {
public:
   C1(int a = 0xC1A, int b = 0xC1B)
      : B(a, b) {}
};

class C2 : public B {
public:
   C2(int a = 0xC2A, int b = 0xC2B)
      : B(a, b) {}
};

class C3 : public B {
public:
   C3(int a = 0xC3A, int b = 0xC3B)
      : B(a, b) {}
};

class D1 : public C2, public C3 {
public:
   D1(int c2_a = 0xD1C2A, int c3_a = 0xD1C3A,
      int c2_b = 0xD1C2B, int c3_b = 0xD1C3B)
      : C2(c2_a, c2_b), C3(c3_a, c3_b) {}
   void print() {
      cout << "D1::print() ..." << endl;
        string names[] = { "C2::a", "C3::a", "C2::b", "C3::b" };
        int* p_values[] = { &(C2::_a), &(C3::_a), &(C2::_b), &(C3::_b) };
      search(names, p_values, 4);
   }
};

class D2 : public C1, public C2, public C3 {
public:
   D2(int c1_a = 0xD2C1A, int c2_a = 0xD2C2A, int c3_a = 0xD2C3A,
      int c1_b = 0xD2C1B, int c2_b = 0xD2C2B, int c3_b = 0xD2C3B)
      : C1(c1_a, c1_b), C2(c2_a, c2_b), C3(c3_a, c3_b) {}

   void print() {
      cout << "D2::print() ..." << endl;
        string names[] = { "C1::a", "C2::a", "C3::a", "C1::b", "C2::b", "C3::b" };
        int* p_values[] = { &(C1::_a), &(C2::_a), &(C3::_a), &(C1::_b), &(C2::_b), &(C3::_b) };
      search(names, p_values, 6);
   }
};

int main(int argc, char *argv[]) {
   D1 d1_object;
   D2 d2_object;
   d1_object.print();
   d2_object.print();
   return 0;
}



```

## ANS:

```cpp

#include <iostream>
#include <string>
using namespace std;

// Name name und Wert val einer Instanzvariable ausgeben
void cell(string name, int value)
{
   cout << "---------------------" << endl;
   cout << name << "= " << value << endl;
}

// Die Instanzvariablen raussuchen und ausgeben,
// die wegen virtuellen Basisklassen zusammenfallen
void search(string names[], int *p_values[], int n)
{
   // Zustand von cout zwischenspeichern
   ios::fmtflags cout_flags = cout.flags();
   // Hilfsvariablen initialisieren
   int i = 0;
   int k = 0;
   string str = "";
   // cout für Ausgabe der Instanzvariablen konfigurieren
   cout << hex << uppercase;
   // Schauen, ob Instanzvariable i (p_values[i])
   // evtl. mit Variable k (p_values[k]) zusammenfällt
   while (i < n)
   {
      // Wenn Variable i+k und i+k+1 identisch ...
      if ((i + k < n - 1) && (p_values[i + k] == p_values[i + k + 1]))
      {
         // erhöhe k
         k++;
      }
      else
      {
         // andernfalls gib die zusammengefallenen Variablen
         // auf einer Zeile aus
         // Text für Ausgabe zusammenstellen
         for (int m = i; m <= i + k; m++)
         {
            str += names[m] + " ";
         }
         // Text und Wert ausgeben
         cell(str, *p_values[i]);
         // Hilfsvariablen für nächste Prüfung zurücksetzen
         str = "";
         i += k + 1;
         k = 0;
      }
   }
   cout << "---------------------" << endl
        << endl;
   // Ursprünglicher Zustand von cout wieder herstellen
   cout.flags(cout_flags);
}

// Klassenhierarchie
class A
{
public:
   int _a;
   A(int a = 0xA) : _a(a) {}
};

class B : virtual public A
{
public:
   int _b;
   B(int a = 0xBA, int b = 0xB) : A(a), _b(b) {}
};

class C1 : public B
{
public:
   C1(int a = 0xC1A, int b = 0xC1B)
       : B(a, b) {}
};

class C2 : virtual public B
{
public:
   C2(int a = 0xC2A, int b = 0xC2B)
       : B(a, b) {}
};

class C3 : virtual public B
{
public:
   C3(int a = 0xC3A, int b = 0xC3B)
       : B(a, b) {}
};

class D1 : public C2, public C3
{
public:
   D1(int c2_a = 0xD1C2A, int c3_a = 0xD1C3A,
      int c2_b = 0xD1C2B, int c3_b = 0xD1C3B)
      // D1::._a, C2::_a, C3::_a müssen auf die selbe Adresse verweisen
      // da C2 und C3 virtuell von A erben, erbt D1 auch virtuell von A
      // Es reicht also von der Klasse D1 die A Konstruktor aufzurufen,
         // sodass es nicht mehr von C1 bzw. C3 aufgerufen wird
      // wenn schon den Konstruktor von A aufgerufen wurde,
         // werden die Konstuktoren von C2 und C3 gar nicht ausgeführt
   // das heißt, _b wird nur von dem "Standart" Konstruktor von B intialisiert
       : A(0xD1A), C2(c2_a, c2_b), C3(c3_a, c3_b) {}      // Konstruktor von A
   void print()
   {
      cout << "D1::print() ..." << endl;
      string names[] = {"C2::a", "C3::a", "C2::b", "C3::b"};
      int *p_values[] = {&(C2::_a), &(C3::_a), &(C2::_b), &(C3::_b)};
      search(names, p_values, 4);
   }
};

class D2 : public C1, public C2, public C3
{
public:
   D2(int c1_a = 0xD2C1A, int c2_a = 0xD2C2A, int c3_a = 0xD2C3A,
      int c1_b = 0xD2C1B, int c2_b = 0xD2C2B, int c3_b = 0xD2C3B)
      // dadurch dass C2 und C3 von B virtuell erben und C1 nicht,
         // existiert zwei attribute von _b.
      // da alle Klassen treffen sich "upstream" bei der Klasse A
         // und manche Erb-Beziehnung virteull sind und manche nicht
            // wird den Konstruktor von A implizit aufgerufen
       :B(c1_a, 0xD2B), C1(c1_a, c1_b), C2(c2_a, c2_b), C3(c3_a, c3_b) {}

   void print()
   {
      cout << "D2::print() ..." << endl;
      string names[] = {"C1::a", "C2::a", "C3::a", "C1::b", "C2::b", "C3::b"};
      int *p_values[] = {&(C1::_a), &(C2::_a), &(C3::_a), &(C1::_b), &(C2::_b), &(C3::_b)};
      search(names, p_values, 6);
   }
};

int main(int argc, char *argv[])
{
   D1 d1_object;
   D2 d2_object;
   d1_object.print();
   d2_object.print();
   return 0;
}

```

