#ifndef liblec_h
#define liblec_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class LibLec : public Lecturer{
	public:
		LibLec(){}
		LibLec(string nm, string srnm);
		void work(Action type);
	private:
};

#endif