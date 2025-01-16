#ifndef employee_h
#define employee_h

#include <iostream>
#include <string>
#include "university.h"

using namespace std;

class Employee : public University{
	public:
		Employee(){}
		string getName(){return name;}
		string getSurname(){return surname;}
		int getHappiness(){return happiness;}
		bool isEmployee(); //if the personel work for a university, this function return true.
		bool employ(University* uni);
		void drinkTea();
		void submitPetition();
	protected:
		int happiness;
		string name, surname;
		University *empi;
};

#endif