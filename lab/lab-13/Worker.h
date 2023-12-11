#ifndef WORKER_H

#define WORKER_H

#include <string>
using namespace std;

#include "Employee.h"

class Worker : public Employee
{
   double _hourly_earnings;
   double _hours;

   public:

   Worker(const string, const string, double, double);
   double get_income() const;
   void print() const;
};

#endif /* WORKER_H */

