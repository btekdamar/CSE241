#ifndef lecturer_h
#define lecturer_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class Lecturer : public Employee{
	public:
		Lecturer(){}
		Lecturer(string nm, string srnm);
		void work(Action type);
	private:
};

#endif