#ifndef comlec_h
#define comlec_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class ComLec : public Lecturer{
	public:
		ComLec(){}
		ComLec(string nm, string srnm);
		void work(Action type);
	private:
};

#endif