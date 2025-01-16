#ifndef researchassistant_h
#define researchassistant_h

#include <iostream>
#include <string>
#include "academicpersonnel.h"

using namespace std;

class researchAssistant : public academicPersonnel{
	public:
		researchAssistant(){}
		researchAssistant(string nm, string srnm);
		void research();
		void readHW();
	private:
	
};

#endif