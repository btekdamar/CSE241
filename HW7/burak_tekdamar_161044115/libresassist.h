#ifndef libresassist_h
#define libresassist_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class LibResAssist : public researchAssistant{
	public:
		LibResAssist(){}
		LibResAssist(string nm, string srnm);
		void work(Action type);
	private:
};

#endif