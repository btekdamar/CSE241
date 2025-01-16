#ifndef officer_h
#define officer_h

#include <iostream>
#include <string>
#include "administrativepersonnel.h"

using namespace std;

class Officer : public administrativePersonnel{
	public:
		Officer(){}
		Officer(string nm, string srnm);
		void makeDoc();
	private:
	
};

#endif