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

