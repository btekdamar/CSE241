#ifndef lecturer_h
#define lecturer_h

#include <iostream>
#include <string>
#include "academicpersonnel.h"

using namespace std;

class Lecturer : public academicPersonnel{
	public:
		Lecturer(){}
		Lecturer(string nm, string srnm);
		void giveHW();
		void giveLesson();
	private:
	
};

#endif