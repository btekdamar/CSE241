#ifndef liboff_h
#define liboff_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class LibOff : public Officer{
	public:
		LibOff(){}
		LibOff(string nm, string srnm);
		void work(Action type);
	private:
};

#endif