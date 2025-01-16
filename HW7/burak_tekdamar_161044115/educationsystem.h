#ifndef educationsystem_h
#define educationsystem_h

#include <iostream>
#include <string>
#include "university.h"
#include "employee.h"

using namespace std;

class EducationSystem{
	public:
		EducationSystem();
		template <typename T>
		University<T> foundUni(UniType type);
		virtual Employee* giveJob(string name, string surname, EmployeeType type);
		virtual void print()=0;
};

#endif