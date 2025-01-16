#ifndef comsec_h
#define comsec_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class ComSec : public Secretary{
	public:
		ComSec(){}
		ComSec(string nm, string srnm);
		void work(Action type);
	private:
};

#endif