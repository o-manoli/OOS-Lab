# AUFGABE 19 (BIS 30.11.2023, 13:30 UHR)

## THEMEN:

Polymorphismus, abstract classes

## IHRE AUFGABE:

Schreiben Sie die abstrakte Basisklasse 'Meal' mit den Methoden 'add_topping' und 'prepare'. Implementieren sie die Klassen Pizza und Burger, sodass das vorhandene Programmfragment kompiliert werden und mittels der Zeile *[1] folgendes auf der Konsole ausgegeben werden kann:

```bash
Pizza Mista. Pizzaboden, belegt mit:
- Salami
- Pilzen
Pizza Hawaii. Pizzaboden, belegt mit:
- Schinken
- Ananas
Hamburger. Brötchen mit:
- Hackfleisch
Cheesburger. Brötchen mit:
- Hackfleisch
- Käse
```

Nutzen Sie die Vererbung von Instanzvariablen und Instanzmethoden entsprechend.

```cpp

int main(int argc, char* argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}


```

## ANS:

```cpp

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Meal {
   string _name;

   public:

   Meal(string name) : _name(name) {}

   virtual void add_topping(string top) = 0;
   virtual void prepare() = 0;
   friend ostream& operator<<(ostream& S , const Meal& M)
   {
      return S << M._name;
   }
};


class Pizza : public Meal {
   vector<string> toppings;

   public:
   Pizza(string name) : Meal(name) {}

   void add_topping(string top) {toppings.push_back(top);}

   void prepare() {
      cout
      << "Pizza " << *this
      << ". Pizzaboden, belegt mit: "
      << endl;

      for (const auto &t : toppings)
         cout << "- " << t <<endl;
   }
};

class Burger : public Meal {
   vector<string>toppings;

   public:

   Burger(string name): Meal(name){}

   void add_topping(string top) {toppings.push_back(top);}

   void prepare() {
      cout
      << *this
      << ". Brötchen mit: "
      << endl;

      for (const auto &t : toppings)
         cout << "- " << t <<endl;
   }
};

int main(int argc, char* argv[])
{
   Pizza *mista = new Pizza("Mista");
   mista->add_topping("Salami");
   mista->add_topping("Pilzen");
   Meal *hawaii = new Pizza("Hawaii");
   hawaii->add_topping("Schinken");
   hawaii->add_topping("Ananas");
   Burger *hamburger = new Burger("Hamburger");
   hamburger->add_topping("Hackfleisch");
   Meal *cheesburger = new Burger("Cheesburger");
   cheesburger->add_topping("Hackfleisch");
   cheesburger->add_topping("Käse");
   array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
   for (Meal *g : menu)
   {
      g->prepare(); //*[1]
   }
   return 0;
}

```

