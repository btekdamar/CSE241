#include <iostream>
#include <string>
#include "administrativepersonnel.h"
#include "secretary.h"

using namespace std;

Secretary::Secretary(string nm, string srnm){
	name = nm;
	surname = srnm;
	empi = nullptr;
	happiness = 0;
}

void Secretary::receivePetition(){
	if(isEmployee()){
		happiness-=1;
		empi->addContribution(-1);
		cout << name << " " << surname << " have incident. Therefore, " << name << " " << surname
				<< " receive petition. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is " << empi->getContribution() << endl;
	}
	else
		cout << "This personel is not employee at university" << endl;
}
