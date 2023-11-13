# AUFGABE 7 (BIS 26.10.2023, 13:30 UHR)

## THEMEN:

> Klassen, Klassenvariablen

## IHRE AUFGABE:

Die Klasse 'Customer' soll folgende Attribute besitzen:

```cpp
static int _s_count;
static int _s_id_generator;
std::string _name;
std::string _location;
int _age;
double _business_done;
int _transaction_count;
int _id;
```
Das Attribut `_business_done` gibt an, welcher Umsatz in Euro in einer Transaktion (d.h. einem Einkauf) gemacht wird. Die Variable `_id` gibt die Kundennummer an. Sie wird in Abhängigkeit der statischen Variablen `_s_id_generator` gesetzt. Die statischen Variablen `_s_count` und `_s_id_generator` werden automatisch inkrementiert, wenn ein Objekt der Klasse `Customer` angelegt wird. Verfassen Sie a) einen Konstruktor mit Default-Parametern für `_name`, `_location` und `_age`.

b) einen Destruktor

c) die Methode 'do_business(double amount)', mit welcher '_business_done' um 'amount' erhöht und gleichzeitig das Atribut '_transaction_count' inkrementiert wird.

d) eine statische Methode 'get_s_count()', mit welcher die statische Variable '_s_count' zurückgegeben werden kann.

e) eine print()-Methode, mit welcher z.B. der unten angegebene Text ausgegeben werden kann:

```bash
Kunde Meier aus Esslingen (ID = 4, 28 Jahre) hatte 3 Transaktion(en) und 230 Euro Unsatz
```

Das angegebene Hauptprogramm soll folglich die folgende Ausgabe erzeugen:

Ausgabe:

```bash
Anzahl Kunden: 3
Kunde Simon aus Heilbronn (ID = 2, 23 Jahre) hatte 3 Transaktion(en) und 633.99 Euro Umsatz
Kunde Michael aus Karlsruhe (ID = 3, 21 Jahre) hatte 1 Transaktion(en) und 199 Euro Umsatz
Kunde Claudia aus Nagold (ID = 4, 30 Jahre) hatte 1 Transaktion(en) und 1000 Euro Umsatz
Anzahl Kunden: 2
```

```cpp


#include <iostream>
#include <string>

// Klasse Customer definieren

int main(int argc, char *argv[]) {
    Customer peter = Customer("Peter", 17, "Stuttgart");
	Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
	Customer micheal = Customer("Michael", 21, "Karlsruhe");
	Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	simon.do_business(230);
	simon.do_business(400);
	claudia.do_business(1000);
	micheal.do_business(199);
	simon.do_business(3.99);
	simon.print();
	micheal.print();
	claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	return 0;
}

```

## ANS:

```cpp
#include <iostream>
#include <string>

// Klasse Customer definieren

class Customer{

	std::string _name;
	int _age;
	std::string _location;

	double _business_done;
	int _transaction_count;

	const int _id;	// shouldn't be mutable

	// initialize static variable
	inline static int _s_count = 0;          // >= C++17
	inline static int _s_id_generator = 0;

	public:

	Customer(
		std::string name = "Max Mustermann",
		int age = 20,
		std::string location = "Musterstadt"
		) :
	_name{name}, _age{age}, _location{location},
	_business_done{0}, _transaction_count{0},
	_id{++_s_id_generator}
	// _id can only be written once! here!
	{
		++_s_count;
	}

	~Customer()
	{
		--_s_count;
	}

	void do_business(double amount){
		_business_done += amount;
		++_transaction_count;
	}

	static int get_s_count(){
		return _s_count;
	}

	void print(){
		std::cout << "Kunde " << _name
		<< " aus " << _location
		<< " (ID = "
		<< _id << ", " << _age
		<< " Jahre)"
		<< " hatte " << _transaction_count << " Transaktion(en)"
		<< " und " << _business_done << " Euro Umsatz"
		<< std::endl;
	}
};

// initialize static variable
// int Customer::_s_count = 0;
// int Customer::_s_id_generator = 0;


int main(int argc, char *argv[]) {
	Customer peter = Customer("Peter", 17, "Stuttgart");
	Customer simon = Customer("Simon", 23, "Heilbronn");
	peter.~Customer();
	Customer micheal = Customer("Michael", 21, "Karlsruhe");
	Customer claudia = Customer("Claudia", 30, "Nagold");
	std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	simon.do_business(230);
	simon.do_business(400);
	claudia.do_business(1000);
	micheal.do_business(199);
	simon.do_business(3.99);
	simon.print();
	micheal.print();
	claudia.print();
	claudia.~Customer();
	std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	return 0;
}

```

