#include <iostream>
#include <string>
#include "administrativepersonnel.h"
#include "officer.h"

using namespace std;

Officer::Officer(string nm, string srnm){
	name = nm;
	surname = srnm;
	empi = nullptr;
	happiness = 0;
}

void Officer::makeDoc(){
	if(isEmployee()){
		happiness-=2;
		empi->addContribution(3);
		cout << name << " " << surname << " have document. Therefore, " << name << " " << surname
				<< " make document. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
