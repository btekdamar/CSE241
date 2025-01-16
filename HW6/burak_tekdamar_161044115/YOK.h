#ifndef yok_h
#define yok_h

#include <iostream>
#include <string>
#include <vector>
#include "Complex.h"
#include "Employee.h"
#include "University.h"
#include "University.cpp"
#include "Officer.h"
#include "Lecturer.h"
#include "Secretary.h"
#include "Researchassistant.h"

using namespace std;

class YOK{
	public:
		YOK(){}
		Employee* giveJob(string nm, string srnm, EmployeeType type){
			if(type == LecturerType){
				employ = new Lecturer(nm, srnm);
				cout << "YOK give job to " << employ->getName() << " " << employ->getSurname() << " as Lecturer" << endl;
			}
			else if(type == OfficerType){
				employ = new Officer(nm, srnm);
				cout << "YOK give job to " << employ->getName() << " " << employ->getSurname() << " as Officer" << endl;
			}
			else if(type == ResearchAssistantType){
				employ = new researchAssistant(nm, srnm);
				cout << "YOK give job to " << employ->getName() << " " << employ->getSurname() << " as ResearchAssistant" << endl;
			}
			else if(type == SecretaryType){
				employ = new Secretary(nm, srnm);
				cout << "YOK give job to " << employ->getName() << " " << employ->getSurname() << " as Secretary" << endl;
			}

			return employ;
		}

		template <typename T>
		University<T> buildUniversity(UniType type);
	private:
		Employee* employ = nullptr;		
};

#endif