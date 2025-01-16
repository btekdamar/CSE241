#ifndef employee_h
#define employee_h

#include <iostream>
#include <string>
#include "University.h"

using namespace std;

enum Action{MakeDoc, DrinkTea, Research, GiveLesson, MakePublish, ManageProcess, GiveHW, ReadHW, ReceivePetition, SubmitPetition, SeeSuccessfullStudent};
enum EmployeeType{LecturerType, OfficerType, SecretaryType, ResearchAssistantType};


class Employee{
	public:
		void setName(string nm){name = nm;}
		void setSurname(string srnm){surname = srnm;}
		bool getIsEmployee(){return inWork;}
		int getCount(){return count;}
		string getEmpType(){return empType;}
		string getName(){return name;}
		string getSurname(){return surname;}
		virtual void work(Action type) = 0;
	protected:
		int pid, happiness, count = 0;
		string name, surname, empType;
		bool inWork;
};


#endif