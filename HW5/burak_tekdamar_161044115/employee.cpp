#include <iostream>
#include <string>
#include "employee.h"
#include "university.h"

using namespace std;

void Employee::drinkTea(){
	if(isEmployee()){
		happiness+=5;
		empi->addContribution(-2);
		cout << name << " " << surname << " have slackness. Therefore, " << name << " " << surname
				<< " drinks tea. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
void Employee::submitPetition(){
	if(isEmployee()){
		happiness+=1;
		empi->addContribution(-2);
		cout << name << " " << surname << " have solution. Therefore, " << name << " " << surname
				<< " submit petition. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
bool Employee::employ(University* uni){
	if(empi == nullptr){
		empi = uni;
		return false;
	}

	return true;
}

bool Employee::isEmployee(){
	if(empi==nullptr){
		return false; 
	}
	
	return true;
}
