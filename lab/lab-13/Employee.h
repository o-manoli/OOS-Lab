#ifndef EMPLOYEE_H

#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
	string _first_name;
	string _last_name;

	public:

	Employee(const string, const string);
	void print() const;
};

#endif /* EMPLOYEE_H */

