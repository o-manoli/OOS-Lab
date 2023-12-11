# AUFGABE 10 (BIS 02.11.2023, 13:30 UHR)

## THEMEN:

> Vererbung, Delegation von Konstruktoren und Methoden

## IHRE AUFGABE:

Für eine Bibliotheksanwendung benötigen Sie verschiedene Benutzergruppen, Dozenten (Klasse `Lecturer`) und Studenten (Klasse `Student`). Diese sollen von einer gemeinsamen Basisklasse `Person` erben. Die Ausleihdauer soll für Dozenten 90 Tage und für Studenten 30 Tage betragen. Ergänzen Sie die Vererbungshierarchie und implementieren Sie die angegebenen Methoden. Verwenden Sie Delegation, um den Konstruktor der Basisklasse aufzurufen und nutzen Sie in den print()-Methoden von Dozent und Student die print()-Methode der Basisklasse.

Das angegebene Hauptprogramm soll folgende Ausgabe erzeugen:

Ausgabe:

```bash
smith, Matrikelnummer 12345678
Ausleihdauer: 30 Tage(e)
miller, Prüfernummer 98
Ausleihdauer: 90 Tage(e)
```

Quelle: C010_person_student_lecturer.cpp.md2 vom 11.04.2023 18:58:29

Antwort:(Abzugssystem: 10, 20, ... %)

```cpp


#include <string>
#include <iostream>
using namespace std;

class Person {
   string _name;
   int _check_out_duration;
public:
   Person(string name, int check_out_duration = 0);
   int get_check_out_duration() const;
   void print() const;
};

// Implmentierung des Konstruktors und der Methoden

class Lecturer
{
   int _examiner_id;
public:
   Lecturer(string name, int examiner_id);
   void print() const;
};

// Implmentierung des Konstruktors und der Methoden

class Student
{
   int _matriculation_number;

public:
   Student(string name, int matriculation_number);
   void print() const;
};


// Implmentierung des Konstruktors und der Methoden

int main(int argc, char *argv[]) {
    Student smith = Student("smith", 12345678);
    Lecturer miller = Lecturer("miller", 98);
    smith.print();
    cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
    miller.print();
    cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

```

## ANS

```cpp


#include <string>
#include <iostream>

using namespace std;

class Person {
   string _name;
   int _check_out_duration;

   public:

   Person(
      string name, int check_out_duration = 0
      ) :
      _name{name}, _check_out_duration{check_out_duration}
      { }

   int get_check_out_duration() const
   {
      return _check_out_duration;
   }

   void print() const
   {
      cout << _name;
   }
};

// Implmentierung des Konstruktors und der Methoden

class Lecturer : public Person
{
   int _examiner_id;
   static const int _s_check_out_duration = 90;

   public:

   Lecturer(
      string name, int examiner_id
      ) :
      Person(name, _s_check_out_duration),
      _examiner_id {examiner_id}
      { }

   void print() const
   {
      Person::print();

      cout
      << ", Prüfernummer "
      << _examiner_id
      << endl;
   }
};

// Implmentierung des Konstruktors und der Methoden

class Student : public Person
{
   int _matriculation_number;
   static const int _s_check_out_duration = 30;

   public:

   Student(
      string name, int matriculation_number
   ) :
   Person(name, _s_check_out_duration),
   _matriculation_number{matriculation_number}
   { }

   void print() const
   {
      Person::print();

      cout
      << ", Matrikelnummer "
      << _matriculation_number
      << endl;
   }
};


// Implmentierung des Konstruktors und der Methoden

int main(int argc, char *argv[]) {
   Student smith = Student("smith", 12345678);
   Lecturer miller = Lecturer("miller", 98);
   smith.print();
   cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
   miller.print();
   cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

```

