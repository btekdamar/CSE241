#ifndef administrativepersonnel_h
#define administrativepersonnel_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class administrativePersonnel : public Employee{
	public:
		administrativePersonnel(){}
		void manageProcess();
	private:
	
};

#endif