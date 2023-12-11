#include<exception>
#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

class OutOfStockException : public exception
{
   string _exception_info;

   public:

   OutOfStockException(
      string article, int available, int purchased
   )
   {
      _exception_info = "Es sind " + to_string(available)
      + " Artikel vom Typ " + article
      + " verfügbar. Es können nicht " + to_string(purchased)
      + " Artikel verkauft werden.";
   }

   const char* what() const noexcept
   {
      return _exception_info.c_str();
   }
};


class ISubscriber
{
   public:
   virtual void update(string) = 0;
};

class CustomerInfo
{
   protected:

   const unsigned int _id;


   public:

   CustomerInfo(unsigned int id): _id{id} {}
};

class Customer: CustomerInfo, public ISubscriber
{
   static inline unsigned int _id_generator = 100;


   public:

   Customer(): CustomerInfo(++_id_generator) {}

   void update(string message) override
   {
      cout
      << "Customer " << _id
      << ": neue Nachricht verfügbar --> " << message
      << endl;
   }
};

class GoldCustomer: CustomerInfo, public ISubscriber
{
   static inline unsigned int _id_generator = 0;


   public:

   GoldCustomer(): CustomerInfo(++_id_generator) {}

   void update(string message) override
   {
      cout
      << "GoldCustomer " << _id
      << ": neue Nachricht verfügbar --> " << message
      << endl;
   }
};


class Store
{
   list<ISubscriber *> _subscribers;
   map<string, unsigned int> _inventory
   {
      {"iPhone", 0}, {"Galaxy", 5}
   };


   public:

   void subscribe(ISubscriber *member)
   {
      _subscribers.push_back(member);
   }

   void unsubscribe(ISubscriber *member)
   {
      _subscribers.remove(member);
   }

   void notify_subscriber(string broadcast)
   {
      for (const auto &member: _subscribers)
         member->update(broadcast);
   }

   void sell_products(string article, int amount)
   {
      if (amount > static_cast<int>(_inventory[article]))
         throw OutOfStockException(
            article, _inventory[article], amount
         );


      cout
      << "Vorrätige Artikel vom Typ " << article
      << ": " << _inventory[article]
      << endl;

      cout
      << "Verkaufte Artikel vom Typ " << article
      << ": " << amount
      << endl;

      _inventory[article] -= amount;

      cout << "Neuer Bestand: " << _inventory[article] << endl;

      if (_inventory[article] == 0)
         notify_subscriber(
            "Artikel vom Typ " + article + " nicht mehr verfügbar"
         );
   }

   void deliver_products(string article, int amount)
   {
      bool notify = _inventory[article]== 0;

      cout
      << "Vorrätige Artikel vom Typ " << article
      << ": " << _inventory[article]
      << endl;

      _inventory[article] += amount;

      cout
      << "Ausgelieferte Artikel vom Typ " << article << ": " << amount
      << endl;

      cout << "Neuer Bestand: " << _inventory[article] << endl;

      if (notify)
         notify_subscriber(
            "Neue Artikel vom Typ " + article + " verfügbar."
         );
   }
};



void manage_store()
{
   try
   {
      Store *store = new Store;
      ISubscriber *customer_1 = new Customer();
      store->subscribe(customer_1);
      ISubscriber *customer_2 = new GoldCustomer();
      store->subscribe(customer_2);
      ISubscriber *customer_3 = new GoldCustomer();
      store->subscribe(customer_3);
      store->deliver_products("iPhone", 5);
      store->unsubscribe(customer_3);
      store->sell_products("iPhone", 3);
      ISubscriber *customer_4 = new Customer();
      store->subscribe(customer_4);
      store->deliver_products("iPhone", 5);
      store->sell_products("iPhone", 7);
      store->unsubscribe(customer_1);
      ISubscriber *customer_5 = new GoldCustomer();
      store->subscribe(customer_5);
      store->deliver_products("iPhone", 15);
      store->sell_products("Galaxy", 8);
   }
   catch (exception &e)
   {
      cout << e.what() << endl;
   }
   catch (...)
   {
      cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
   }
}

int main(int argc, char *argv[])
{
   manage_store();
   return 0;
}

