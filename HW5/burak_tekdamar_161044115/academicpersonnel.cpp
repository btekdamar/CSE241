#include <iostream>
#include <string>
#include "employee.h"
#include "academicpersonnel.h"

using namespace std;

void academicPersonnel::seeSuccessfulStudent(){
	if(isEmployee()){
		happiness+=10;
		empi->addContribution(0);
		cout << name << " " << surname << " have seminar. Therefore, " << name << " " << surname
				<< " see successful student. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
void academicPersonnel::makePublish(){
	if(isEmployee()){
		happiness+=2;
		empi->addContribution(5);
		cout << name << " " << surname << " have academic paper. Therefore, " << name << " " << surname
				<< " make publish. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
