#include <iostream>
#include <string>
#include "academicpersonnel.h"
#include "lecturer.h"

using namespace std;

Lecturer::Lecturer(string nm, string srnm){
	name = nm;
	surname = srnm;
	empi = nullptr;
	happiness = 0;
}

void Lecturer::giveHW(){
	if(isEmployee()){
		happiness-=2;
		empi->addContribution(1);
		cout << name << " " << surname << " have homework time. Therefore, " << name << " " << surname
				<< " give HW. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
void Lecturer::giveLesson(){
	if(isEmployee()){
		happiness+=1;
		empi->addContribution(5);
		cout << name << " " << surname << " have lesson. Therefore, " << name << " " << surname
				<< " give lesson. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
