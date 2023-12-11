# AUFGABE 23 (BIS 14.12.2023, 13:30 UHR)

## THEMEN:

Interfaces, Dependency Inversion Principle, Composite Pattern

## IHRE AUFGABE:

Der Preis für ein einzelnes Produkt soll auf die gleiche Art und Weise abgefragt werden können wie für ein Paket in dem Produkte und/oder weitere Pakete enthalten sein können, die wiederum Produkte und/oder weitere Pakete enthalten können. Nutzen Sie hierzu das Composite Pattern. Implementieren sie das Interface IComponent sowie die Klassen Product und Box, sodass das gegebene Hauptprogramm die folgende Ausgabe erzeugt:

```bash
Preisermittlung für ein einfaches Produkt:
Preis: 10

Preisermittlung für eine verschachtelte Box:
Preis: 19

Preisermittlung für eine erweiterte verschachtelte Box:
Preis: 26

```

```cpp

void calculate_price(IComponent *component)
{
    cout << "Preis: " << component->get_price() << endl;
}

int main(int argc, char* argv[]) {

    cout << "Preisermittlung für ein einfaches Produkt: " << endl;
    IComponent *product = new Product(10);
    calculate_price(product);
    cout << endl;

    cout << "Preisermittlung für eine verschachtelte Box: " << endl;
    IComponent *outer_box = new Box;
    IComponent *inner_box_1 = new Box;
    IComponent *product_1 = new Product(10);
    IComponent *product_2 = new Product(5);
    IComponent *product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent *inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    calculate_price(outer_box);
    cout << endl;

    cout << "Preisermittlung für eine erweiterte verschachtelte Box: " << endl;
    IComponent *product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl;

    return 0;
}


```

## ANS:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class IComponent
{

	public:

	virtual int get_price() = 0;
	virtual void add(IComponent*) = 0;
};


class Product : public IComponent
{
	int _price;


	public:

	Product(int number) :_price(number) {}

	int get_price() override {return _price;}

	void add(IComponent* component) override {}
};


class Box : public IComponent
{
	vector<IComponent*> _items;


	public:

	int get_price() override
	{
		int sum = 0;
		for(const auto &p: _items)
			sum += p->get_price();
		return sum;
	}

	void add(IComponent* item) override
	{
		_items.push_back(item);
	}
};


void calculate_price(IComponent* component)
{
	cout << "Preis: " << component->get_price() << endl;
}


int main(int argc, char* argv[])
{
	cout << "Preisermittlung für ein einfaches Produkt: " << endl;
	IComponent *product = new Product(10);
	calculate_price(product);
	cout << endl;

	cout << "Preisermittlung für eine verschachtelte Box: " << endl;
	IComponent *outer_box = new Box;
	IComponent *inner_box_1 = new Box;
	IComponent *product_1 = new Product(10);
	IComponent *product_2 = new Product(5);
	IComponent *product_3 = new Product(4);
	inner_box_1->add(product_1);
	inner_box_1->add(product_2);
	IComponent *inner_box_2 = new Box;
	inner_box_2->add(product_3);
	outer_box->add(inner_box_1);
	outer_box->add(inner_box_2);
	calculate_price(outer_box);
	cout << endl;

	cout << "Preisermittlung für eine erweiterte verschachtelte Box: " << endl;
	IComponent *product_4 = new Product(7);
	inner_box_2->add(product_4);
	calculate_price(outer_box);
	cout << endl;

	return 0;
}


```

