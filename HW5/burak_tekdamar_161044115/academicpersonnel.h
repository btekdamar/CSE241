#ifndef academicpersonnel_h
#define academicpersonnel_h

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class academicPersonnel : public Employee{
	public:
		academicPersonnel(){}
		void seeSuccessfulStudent();
		void makePublish();
	private:

};

#endif