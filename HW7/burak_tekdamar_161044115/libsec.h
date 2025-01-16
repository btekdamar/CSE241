#ifndef libsec_h
#define libsec_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class LibSec : public Secretary{
	public:
		LibSec(){}
		LibSec(string nm, string srnm);
		void work(Action type);
	private:
};

#endif