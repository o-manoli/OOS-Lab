module;

#include <iostream>
using namespace std;

import employee;

export module manager;

export class Manager : public Employee
{
	double _salary;

public:
	Manager(
		const string f_n, const string l_n,
		double s = 0
	) : Employee(f_n, l_n), _salary{ s } {}

	double get_income() const
	{
		return _salary;
	}

	void print() const
	{
		cout << "Manager: ";
		Employee::print();
	}
};

