#ifndef comoff_h
#define comoff_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class ComOff : public Officer{
	public:
		ComOff(){}
		ComOff(string nm, string srnm);
		void work(Action type);
	private:
};

#endif