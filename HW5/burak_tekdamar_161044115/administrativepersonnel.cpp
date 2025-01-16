#include <iostream>
#include <string>
#include "employee.h"
#include "administrativepersonnel.h"

using namespace std;

void administrativePersonnel::manageProcess(){
	if(isEmployee()){
		happiness-=1;
		empi->addContribution(2);
		cout << name << " " << surname << " have administration. Therefore, " << name << " " << surname
				<< " manage process. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
