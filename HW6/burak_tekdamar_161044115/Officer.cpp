#include <iostream>
#include <string>
#include "Employee.h"
#include "Officer.h"

using namespace std;

Officer::Officer(string nm, string srnm){
	name = nm;
	surname = srnm;
	happiness = 0;
	empType = "Officer";
}

void Officer::work(Action type){
	if(type==DrinkTea){
		happiness+=5;
		cout << name << " " << surname << " have slackness. Therefore, " << name << " " << surname
				<< " drinks tea. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==SubmitPetition){
		happiness+=1;
		cout << name << " " << surname << " have solution. Therefore, " << name << " " << surname
				<< " submit petition. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==MakeDoc){
		happiness-=2;
		cout << name << " " << surname << " have document. Therefore, " << name << " " << surname
				<< " make document. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==ManageProcess){
		happiness-=1;
		cout << name << " " << surname << " have administration. Therefore, " << name << " " << surname
				<< " manage process. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of uni is ";
		count++;
	}
}