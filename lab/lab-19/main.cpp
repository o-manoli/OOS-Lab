#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Meal
{
   protected:

   string _name;
   vector<string> _toppings;

   public:

   Meal(string name) : _name(name) {}

   void list_toppings()
   {
      for (const auto &t : _toppings)
         cout << "- " << t <<endl;
   }

   virtual void add_topping(string topping)
   {
      _toppings.push_back(topping);
   }

   virtual void prepare() = 0;

   friend ostream& operator<<(ostream& S , const Meal& meal)
   {
      return S << meal._name;
   }
};


class Pizza : public Meal
{
   public:

   Pizza(string name) : Meal(name) {}

   void prepare()
   {
      cout
      << "Pizza " << *this
      << ". Pizzaboden, belegt mit: "
      << endl;

      list_toppings();
   }
};

class Burger : public Meal
{
   public:

   Burger(string name): Meal(name){}

   void prepare()
   {
      cout
      << *this
      << ". Brötchen mit: "
      << endl;

      list_toppings();
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

