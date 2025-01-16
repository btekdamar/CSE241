#ifndef liberaleducation_h
#define liberaleducation_h

#include <iostream>
#include <string>
#include "educationsystem.h"

class LiberalEducation : public EducationSystem{
	public:
		LiberalEducation();
		template <typename T>
		University<T> foundUni(UniType type);
		Employee giveJob(string name, string surname, EmpType type);
}

#endif