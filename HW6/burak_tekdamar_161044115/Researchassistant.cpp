#include <iostream>
#include <string>
#include "Employee.h"
#include "Researchassistant.h"

using namespace std;

researchAssistant::researchAssistant(string nm, string srnm){
	name = nm;
	surname = srnm;
	happiness = 0;
	empType = "researchAssistant";
}

void researchAssistant::work(Action type){
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

	else if(type==Research){
		happiness+=3;
		cout << name << " " << surname << " have project. Therefore, " << name << " " << surname
				<< " research. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==ReadHW){
		happiness-=3;
		cout << name << " " << surname << " have homework timeout. Therefore, " << name << " " << surname
				<< " read HW. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==SeeSuccessfullStudent){
		happiness+=10;
		cout << name << " " << surname << " have seminar. Therefore, " << name << " " << surname
				<< " see successful student. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==MakePublish){
		happiness+=2;
		cout << name << " " << surname << " have academic paper. Therefore, " << name << " " << surname
				<< " make publish. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}
}