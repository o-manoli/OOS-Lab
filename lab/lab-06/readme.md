# AUFGABE 6 (BIS 19.10.2023, 13:30 UHR)

## THEMEN:

> Initialisierung von Objekten, Konstruktoren, Destruktoren

## IHRE AUFGABE:

Schreiben Sie eine Klasse `Student` mit den Attributen `_name` und `_first_name` vom Typ String. Schützen Sie die Attribute gegen Zugriff von außen. Die folgenden Methoden implementieren sie außerhalb der Klasse: Die Klasse soll einen parametrisierten Konstruktor haben, der Name und Vorname entgegennimmt und die beiden Attribute `_name` und `_first_name` entsprechend belegt. Verwenden Sie hierzu _keine_ Initialisierungsliste. Schreiben sie get-Methoden für beide Attribute und einen Destruktor. Schreiben Sie zwei print-Methoden, beide ohne Rückgabewert. Eine der beiden Methoden nimmt eine boolsche Variable entgegen, mit der gesteuert werden kann, ob am Ende der Zeile ein Zeilenumbruch erfolgen soll oder nicht. In der anderen Methode erfolgt immer ein Zeilenumbruch.

Schreiben Sie eine Klasse `Employee`, ebenfalls mit den Attributen `_name` und `_first_name` vom Typ String. Schützen Sie auch diese Attribute gegen einen Zugriff von außen. Die folgenden Methoden implementieren sie innerhalb der Klasse: Die Klasse soll einen parametrisierten Konstruktor haben, der Name und Vorname entgegennimmt und die beiden Attribute `_name` und `_first_name` entsprechend belegt. Verwenden Sie hierzu die Initialisierungsliste. Die Klasse soll einen Standardkonstruktor haben, die den Konstruktoraufruf an den parametrisierten Konstruktor delegiert. Nutzen Sie auch hier die Initialisierungsliste und setzen sie die Werte `Mustermann` für Name und `Erika` für Vorname. Schreiben Sie zusätzlich einen Konvertierkonstruktor, der einen Studenten entgegenimmt und die enthaltenen Daten zur Initialisierung von Name und Vorname verwendet. Schreiben sie einen Destruktor. Schreiben Sie auch für diese Klasse zwei print-Methoden, ebenfalls beide ohne Rückgabewert. Eine der beiden Methoden nimmt eine boolsche Variable entgegen, mit der gesteuert werden kann, ob am Ende der Zeile ein Zeilenumbruch erfolgen soll oder nicht. In der anderen Methode erfolgt immer ein Zeilenumbruch.

Die Methoden der beiden Klassen sollen jeweils eine Ausgabe enthalten, die zur Ausgabe der vorgegebenen main-Methode passt. Die Ausgabe ist unten angegeben.

Ausgabe:

```bash
Parametrisierter Konstruktor Student: Max Mustermann
Konvertierungskonstruktor Employee: Max Mustermann
Parametrisierter Konstruktor Employee: Erika Mustermann
Standardkonstruktor Employee: Erika Mustermann
print() ohne Parameter; Student: Max Mustermann
print() mit Parameter; Student: Max Mustermann
print() ohne Parameter; Mitarbeiter: Max Mustermann
print() ohne Parameter; Mitarbeiter: Erika Mustermann
Block wird betreten
Parametrisierter Konstruktor Student: Markus Mustermann
print() mit Parameter; Student: Markus Mustermann
Block wurde verlassen
Destruktor Student: Markus Mustermann
Destruktor Employee: Erika Mustermann
Destruktor Employee: Max Mustermann
Destruktor Student: Max Mustermann
```

```cpp

#include <string>
#include <iostream>
using namespace std;

// Klasse Student


// Klasse Employee


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


```

## ANS

```cpp

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

```