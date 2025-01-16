#ifndef secretary_h
#define secretary_h

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Secretary : public Employee{
	public:
		Secretary(){}
		Secretary(string nm, string srnm);
		void work(Action type);
};

#endif