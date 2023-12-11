
#include <iostream>
#include <string>
#include <vector>
#include <exception>

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
            __FILE__, __LINE__ + 55,   // guess work
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

