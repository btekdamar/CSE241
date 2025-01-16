#ifndef capitalisteducation_h
#define capitalisteducation_h

#include <iostream>
#include <string>
#include "educationsystem.h"

class CapitalistEducation : public EducationSystem{
	public:
		CapitalistEducation();
		template <typename T>
		University<T> foundUni(UniType type);
		Employee giveJob(string name, string surname, EmpType type);
}

#endif