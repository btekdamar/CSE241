#ifndef communisteducation_h
#define communisteducation_h

#include <iostream>
#include <string>
#include "educationsystem.h"

class CommunistEducation : public EducationSystem{
	public:
		CommunistEducation();
		template <typename T>
		University<T> foundUni(UniType type);
		Employee* giveJob(string name, string surname, EmpType type);
}

#endif