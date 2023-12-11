# AUFGABE 5 (BIS 12.10.2023, 13:30 UHR)

## THEMEN:

> Klassen, Attribute, Methoden

## IHRE AUFGABE:

Ergänzen Sie das Programmgerippe um die Klasse Punkt mit den Koordinaten x und y vom Typ double. Schreiben sie für die Klasse Punkt die Methode print() sowie getter- und setter-Methoden für die Koordinaten x und y, sodass das Hauptprogramm folgende Ausgabe erzeugt:

```bash
print-Methode:
X = 1
Y = 10
X ohne print(): 5
Y ohne print(): 10
```

```cpp


#include<iostream>
using namespace std;

// hier die Klasse Punkt implementieren

int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}


```

## ANS:

```cpp
#include<iostream>

using namespace std;

class Point{

   double _x, _y;

   public:

      void set_x(double x){ _x = x;}
      double get_x(){ return _x;}

      void set_y(double y){ _y = y;}
      double get_y(){ return _y;}


      void print(){
         cout << "print-Methode:\n";
         cout << "X = " << _x << '\n';
         cout << "Y = " << _y << endl;
      }
};

int main(int argc, char* argv[]) {
   Point p;
   p.set_x(1);
   p.set_y(10);
   p.print();
   p.set_x(5);
   cout << "X ohne print(): " << p.get_x() << endl;
   cout << "Y ohne print(): " << p.get_y() << endl;
   return 0;
}

```

