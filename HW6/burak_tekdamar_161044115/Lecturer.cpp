#include <iostream>
#include <string>
#include "Employee.h"
#include "Lecturer.h"

using namespace std;

Lecturer::Lecturer(string nm, string srnm){
	name = nm; 
	surname = srnm;
	happiness = 0;
	empType = "Lecturer";
}

void Lecturer::work(Action type){
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

	else if(type==GiveLesson){
		happiness+=1;
		cout << name << " " << surname << " have lesson. Therefore, " << name << " " << surname
				<< " give lesson. Happiness of " << name << " " << surname << " is " << happiness
					<< ", contribution of the uni is ";
		count++;
	}

	else if(type==GiveHW){
		happiness-=2;
		cout << name << " " << surname << " have homework time. Therefore, " << name << " " << surname
				<< " give HW. Happiness of " << name << " " << surname << " is " << happiness
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