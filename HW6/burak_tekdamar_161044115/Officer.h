#ifndef officer_h
#define officer_h

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Officer : public Employee{
	public:
		Officer(){}
		Officer(string nm, string srnm);
		void work(Action type);
};

#endif