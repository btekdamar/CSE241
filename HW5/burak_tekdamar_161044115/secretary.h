#ifndef secretary_h
#define secretary_h

#include <iostream>
#include <string>
#include "administrativepersonnel.h"

using namespace std;

class Secretary : public administrativePersonnel{
	public:
		Secretary(){}
		Secretary(string nm, string srnm);
		void receivePetition();
	private:
	
};

#endif