#ifndef comresassist_h
#define comresassist_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class ComResAssist : public researchAssistant{
	public:
		ComResAssist(){}
		ComResAssist(string nm, string srnm);
		void work(Action type);
	private:
};

#endif