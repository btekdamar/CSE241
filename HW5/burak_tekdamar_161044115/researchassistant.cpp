#include <iostream>
#include <string>
#include "academicpersonnel.h"
#include "researchassistant.h"

using namespace std;

researchAssistant::researchAssistant(string nm, string srnm){
	name = nm;
	surname = srnm;
	empi = nullptr;
	happiness = 0;
}

void researchAssistant::research(){
	if(isEmployee()){
		happiness+=3;
		empi->addContribution(4);
		cout << name << " " << surname << " have project. Therefore, " << name << " " << surname
				<< " research. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
void researchAssistant::readHW(){
	if(isEmployee()){
		happiness-=3;
		empi->addContribution(2);
		cout << name << " " << surname << " have homework timeout. Therefore, " << name << " " << surname
				<< " read HW. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
