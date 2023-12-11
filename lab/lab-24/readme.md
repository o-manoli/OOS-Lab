# AUFGABE 24 (BIS 14.12.2023, 13:30 UHR)

## THEMEN:

Interfaces, Dependency Inversion Principle, Composite Pattern, Exceptions

## IHRE AUFGABE:

Implementieren Sie das Observer Pattern, vgl. Foliensatz "11-1_Pattern", Folie 38 bis 41.

Implementieren Sie das Interface ISubscriber mit der rein virtuellen Methode update, die einen String als Parameter entgegennimmt. Implementieren Sie die Klassen Customer und GoldCustomer, die jeweils das Interface ISubscribers implementieren. Jedes Objekt der Klasse Customer und auch jedes Objekt der Klasse GoldCustomer soll eine eindeutige ID erhalten. Nutzen sie zur Erzeugung der IDs jeweils eine statische Variable.

Implementieren sie die Methoden subscribe, unsubscribe, notify_subscribers, deliver_products und sell_products der Klasse Store.

Die Methode deliver_products soll ausgeben, wie viele Artikel bisher verfügabr waren, wie viele Artikel ausgeliefert wurden und wie der neue Bestand ist. Waren vor der Lieferung keine Produkte verfügbar waren, sollen die Kunden darüber informiert werden.

Die Methode sell_products soll zunächst prüfen ob die angegebene Anzahl an Produkten verkauft werden kann. ist dies nicht der Fall, so soll eine OutOfStockException geworfen werden, die von der Standardexception erbt und die what-Methode überschreibt. Die letzte Zeile der Ausgabe unten zeigt die Fehlermeldung, die durch die Exception ausgelöst wird. Kann die angegebene Anzahl an Produkten verkauft werden, so soll die Methode ausgeben, wie viele Artikel bisher verfügabr waren, wie viele Artikel verkauft wurden und wie der neue Bestand ist. Sind nach dem Verkauf keine Produkte mehr verfügbar, sollen die Kunden darüber informiert werden.

Das gegebene Programm soll die folgende Ausgabe erzeugen:

```bash
Vorrätige Artikel vom Typ iPhone: 0
Ausgelieferte Artikel vom Typ iPhone: 5
Neuer Bestand: 5
Customer 101: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
GoldCustomer 1: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
GoldCustomer 2: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
Vorrätige Artikel vom Typ iPhone: 5
Verkaufte Artikel vom Typ iPhone: 3
Neuer Bestand: 2
Vorrätige Artikel vom Typ iPhone: 2
Ausgelieferte Artikel vom Typ iPhone: 5
Neuer Bestand: 7
Vorrätige Artikel vom Typ iPhone: 7
Verkaufte Artikel vom Typ iPhone: 7
Neuer Bestand: 0
Customer 101: neue Nachricht verfügbar --> Artikel vom Typ iPhone nicht mehr verfügbar
GoldCustomer 1: neue Nachricht verfügbar --> Artikel vom Typ iPhone nicht mehr verfügbar
Customer 102: neue Nachricht verfügbar --> Artikel vom Typ iPhone nicht mehr verfügbar
Vorrätige Artikel vom Typ iPhone: 0
Ausgelieferte Artikel vom Typ iPhone: 15
Neuer Bestand: 15
GoldCustomer 1: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
Customer 102: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
GoldCustomer 3: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
Es sind 5 Artikel vom Typ Galaxy verfügbar. Es können nicht 8 Artikel verkauft werden.
```

```cpp

#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

// Hier Exception implementieren


// Hier Interface implementieren


// Hier Klassen Customer und GoldCustomer implementieren



class Store
{
public:
    // Hier Methoden implementieren

private:
    list<ISubscriber *> _subscribers;
    map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};
};


int Customer::_id_generator = 100;
int GoldCustomer::_id_generator = 0;

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


```

## ANS:

```cpp
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


```

