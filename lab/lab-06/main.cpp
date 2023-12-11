
#include <string>
#include <iostream>
using namespace std;

// Klasse Student
class Student{

   string _last_name;
   string _first_name;

   public:

   Student(string last_name, string first_name) :
   _last_name{last_name}, _first_name{first_name}
   {
      cout
      << "Parametrisierter Konstruktor Student: "
      << _first_name << " "
      << _last_name
      << endl;
   }

   string get_first_name(){
      return _first_name;
   }

   string get_last_name(){
      return _last_name;
   }

   void print(){
      cout
      << "print() ohne Parameter; Student: "
      << _first_name << " "
      << _last_name
      << endl;
   }

   void print(bool B){
      cout
      << "print() mit Parameter; Student: "
      << _first_name << " "
      << _last_name;
      if (B) cout << endl;
   }

   ~Student(){
      cout
      << "Destruktor Student: "
      << _first_name << " "
      << _last_name
      << endl;
   }
};


// Klasse Employee

class Employee{
   string _last_name;
   string _first_name;

   public:

   Employee(string first_name, string last_name)
   :_last_name{last_name}, _first_name{first_name}
   {
      cout
      << "Parametrisierter Konstruktor Employee: "
      << _first_name << " "
      << _last_name
      << endl;
   }

   Employee() : Employee("Erika", "Mustermann") {
      cout
      << "Standardkonstruktor Employee: "
      << _first_name << " "
      << _last_name
      << endl;
   }

   Employee(Student& ST) :
      _last_name {ST.get_last_name()},
      _first_name {ST.get_first_name()}
   {
      cout
      << "Konvertierungskonstruktor Employee: "
      << _first_name << " "
      << _last_name
      << endl;
   }

   void print(){
      cout
      << "print() ohne Parameter; Mitarbeiter: "
      << _first_name << " "
      << _last_name
      << endl;
   }

   void print(bool B){
      cout
      << "print() mit Parameter; Mitarbeiter: "
      << _first_name << " "
      << _last_name;
      if (B) cout << endl;
   }

   ~Employee(){
      cout
      << "Destruktor Employee: "
      << _first_name << " "
      << _last_name
      << endl;
   }
};


int main(int argc, char *argv[])
{
   Student stud_mustermann = Student("Mustermann", "Max");
   Employee empl_mustermann = Employee(stud_mustermann);
   Employee mit_default = Employee();
   stud_mustermann.print();
   stud_mustermann.print(true);
   empl_mustermann.print();
   mit_default.print();
   Student *p_stud_mustermann = nullptr;
   cout << "Block wird betreten" << endl;
   {
      p_stud_mustermann = new Student("Mustermann", "Markus");
      p_stud_mustermann->print(true);
   }
   cout << "Block wurde verlassen" << endl;
   delete p_stud_mustermann;
   return 0;
}

