
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <memory>

using namespace std;

class MyException
{
   string _exception;

   public:

   MyException(string file, int line, string exception = "")
   {
      _exception = "Fehler " + exception
      + " aufgetreten in Datei " + file
      + ", Zeile: " + to_string(line) + "." ;
   }

   const char* what() const noexcept
   {
      return _exception.c_str();
   }

};

class ElefantMeetsMouse : public MyException
{
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

template<class Species>
class Cloneable: public Animal
{
   public:
    virtual Animal *clone() const
    {
        return new Species(static_cast<Species const&>(*this));
    }
};

class Elefant : public Cloneable<Elefant> {};

class Tiger : public Cloneable<Tiger> {};

class Mouse : public Cloneable<Mouse> {};

class Zoo
{
   string _name;
   vector<Animal *> _animals;

   public:

   Zoo()
   {
      cout << "Bitte Name des Zoos eingeben: ";
      cin >> _name;

      if (_name.length() < 4)
         throw MyException(
            __FILE__, __LINE__ + 70,   // guess work
            "'Zooname zu kurz'"
         );

      _name.at(4) = toupper(_name.at(4));
   }

   void add_animal(const Animal &animal)
   {
      if (!_animals.empty())
      if (
         Animal
         *A = const_cast<Animal *>(&animal),
         *B = _animals.back();
         (
            dynamic_cast<Mouse *>(A) && dynamic_cast<Elefant *>(B)
         ) || (
            dynamic_cast<Mouse *>(B) && dynamic_cast<Elefant *>(A)
         )
      )
         throw ElefantMeetsMouse( // erst wenn alle Bedingen erfüllt sind!
               __FILE__, __LINE__ + 69   // also guessing
         );

      _animals.push_back(animal.clone()); // ansonsten
   }

   void print() const
   {
      for (const auto &a : _animals)
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
            throw "Fehlerhafte Eingabe!";
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
   catch (...) // Error not listed above!
   {
      cout << "Fehlerhafte Eingabe!" << endl;
   }

   return 0;
}

