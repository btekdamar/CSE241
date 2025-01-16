#ifndef researchassistant_h
#define researchassistant_h

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class researchAssistant : public Employee{
	public:
		researchAssistant(){}
		researchAssistant(string nm, string srnm);
		void work(Action type);
};

#endif