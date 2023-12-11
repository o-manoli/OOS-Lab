#ifndef MANAGER_H

#define MANAGER_H

#include <string>
using namespace std;

#include "Employee.h"

class Manager : public Employee
{
   double _salary;

   public:

   Manager(const string, const string, double);
   double get_income() const;
   void print() const;
};

#endif /* MANAGER_H */

