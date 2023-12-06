# AUFGABE 21 (BIS 07.12.2023, 13:30 UHR)

## THEMEN:

Exception Handling, Polymorphie

## IHRE AUFGABE:

a) Leiten Sie von der Standardexceptionklasse exception eine eigene Klasse MyException ab.

Schreiben Sie einen parametrisierten Konstruktor, der in seperaten Parametern den Dateinamen und die Zeilennummer entgegegennimmt, in der eine Ausnahme auftritt. Zusätzlich soll ein dritter Parameter übergeben werden können, der den Namen bzw. eine Beschreibung der Ausnahme enthält.

Um die Zeile und den Dateinamen zu ermitteln sollen die Präprozessormakros `__LINE__` und `__FILE__` im Aufruf des Konstruktors genutzt werden. Stimmt die durch das Makro `__LINE__` zurückgegebene Zeilennummer nicht mit der erwarteten überein, kann entsprechen hinzuaddiert / substrahiert werden, z.B.: throw MyException(`__FILE__`, `__LINE__` + 7 , "Zooname zu kurz");

Überschreiben sie zusätzlich die Methode what() der Standardexception, die eine Beschreibung des Fehlers - bestehend aus der Angabe der Datei, der Zeile und des Namens des Fehlers - zurückgibt.

b) Ergänzen Sie den Programmcode an den gekennzeichneten Stellen (//HIER).

```cpp

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException // HIER {
    // HIER
};

// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse // HIER {
    // HIER
};

// Klasse der Tiere
class Animal
{
    // Name des Tiers
    string _name;

public:
    // Konstruktor
    Animal()
    {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    };
    // virtuelle print-Funktion
    virtual void print(bool nl) const
    {
        cout << _name;
        if (nl)
        {
            cout << endl;
        }
    }
    virtual Animal *clone() const = 0;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant // HIER {
    // HIER
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger // HIER {
    // HIER
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse // HIER {
    // HIER
};

class Zoo
{
    // Name des Zoos
    string _name;
    // Die Tiere werden in einem Vektor gespeichert
    vector<Animal *> animals;

public:
    // Konstruktor
    Zoo()
    {
        // Name zuweisen
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;
        // Wenn der String kuerzer als 4 Zeichen ist,
        // dann MyException werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        // HIER

        // Ansonsten, den 5. Buchstaben des Namens gross machen
        _name.at(4) = toupper(_name.at(4));
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal &animal)
    {
        // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum
        // dann Ausnahme werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        // HIER


        // sonst Tier hinzufuegen
        // HIER


    }
    // Alle Zootiere ausgeben
    void print() const
    {
        // HIER


    }
};

int main(int argc, char *argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    // HIER


        Zoo zoo;
        do
        {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                Elefant elefant = Elefant();
                zoo.add_animal(elefant);
                break;
            }
            case '2':
            {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3':
            {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                // Einen String als Ausnahme werfen
                // HIER

            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben
    catch (ElefantMeetsMouse &e)
    {
        cout << e.what() << endl;
    }
    // MyException auffangen und ausgeben
    // HIER


    // Alle anderen Standardausnahmen auffangen und ausgeben
    // HIER


    // Alle Strings auffangen und ausgeben
    // HIER


    // Alle anderen Ausnahmen auffangen
    // HIER


    return 0;
}

```

## ANS:

```cpp

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class MyException {
   string _exception;

   public:

   MyException(string file, int line, string exception = "")
   {
      _exception = "Fehler " + exception
      + " aufgetreten in Datei " + file
      + ", Zeile: " + to_string(line) + "." ;
   }

   virtual const char* what() const
   {
      return _exception.c_str();
   }

};

class ElefantMeetsMouse : public MyException {

   public:

   ElefantMeetsMouse(string file, int line)
   : MyException(file, line, "'Elefant trifft auf Maus'") {}
};


class Animal
{
   string _name;

   public:

   Animal()
   {
      cout << "Bitte Namen des Tieres eingeben: ";
      cin >> _name;
   };

   virtual void print(bool nl) const
   {
      cout << _name;
      if (nl) cout << endl;
   }

   virtual Animal *clone() const = 0;
};

class Elefant : public Animal
{
   public:

   Animal* clone() const
   {
      return new Elefant(*this);
   }
};

class Tiger : public Animal
{
   public:

   Animal* clone() const
   {
      return new Tiger(*this);
   }
};


class Mouse : public Animal
{
   public:

   Animal* clone() const
   {
      return new Mouse(*this);
   }
};

class Zoo
{
   string _name;
   vector<Animal *> animals;

   public:

   Zoo()
   {
      cout << "Bitte Name des Zoos eingeben: ";
      cin >> _name;

      if (_name.length() < 4)
         throw MyException(
            __FILE__, __LINE__ + 56,	// guess work
            "'Zooname zu kurz'"
         );

      _name.at(4) = toupper(_name.at(4));
   }

   void add_animal(const Animal &animal)
   {
      if (
         !animals.empty()
      ) {
      if(
         typeid(animal) == typeid(Elefant)
         || typeid(animal) == typeid(Mouse)
      ){
      if (
         typeid(*animals.back()) == typeid(Elefant)
         || typeid(*animals.back()) == typeid(Mouse)
      ) {
      if (
         typeid(animal) != typeid(*animals.back())
      ) throw ElefantMeetsMouse( // erst wenn alle Bedingen erfüllt sind!
            __FILE__, __LINE__ + 52   // also guessing
         );
            }
         }
      }
      animals.push_back(animal.clone()); // ansonsten
   }

   void print() const
   {
      for (const auto &a : animals)
         a->print(true);
   }
};

int main(int argc, char *argv[])
{
   char choice;
   string name;

   try
   {
      Zoo zoo;
      do
      {
         cout << endl
            << "Bitte Tierart auswaehlen:" << endl;
         cout << "1 = Elefant" << endl;
         cout << "2 = Tiger" << endl;
         cout << "3 = Maus" << endl;
         cout << "e = Ende mit Eingabe" << endl;
         cout << "Eingabe: ";
         cin >> choice;
         switch (choice)
         {
         case '1':
         {
            Elefant elefant = Elefant();
            zoo.add_animal(elefant);
            break;
         }
         case '2':
         {
            Tiger tiger = Tiger();
            zoo.add_animal(tiger);
            break;
         }
         case '3':
         {
            Mouse mouse = Mouse();
            zoo.add_animal(mouse);
            break;
         }
         case 'e':
            break;
         default:
            throw "falsch";
         }
         cout << endl;
         zoo.print();
      } while (choice != 'e');
   }
   catch (ElefantMeetsMouse& e)
   {
      cout << e.what() << endl;
   }
   catch (MyException& e)
   {
      cout << e.what() << endl;
   }
   catch (exception& e)
   {
      cout << "Standardausnahme: " << e.what() << endl;
   }
   catch (string& str)
   {
      cout << "Standardausnahme " << str << endl;
   }
   catch (...) // default. Error not listed
   {
      cout << "Fehlerhafte Eingabe!" << endl;
   }

   return 0;
}


```

Testcases can be added as plain `.txt` files.
