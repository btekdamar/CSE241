#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "classroom.h"
#include "student.h"

using namespace std;

namespace attendance{

	Student::Student():lectureNumber(0), credit(0), isInClassroom(false), attendanceCount(0){}
	//COPY CONSTRUCTOR
	Student::Student(const Student& newStudent){
		name = newStudent.name; surname = newStudent.surname;
		studentNo = newStudent.studentNo; 
		level = newStudent.level;
		lectureNumber = newStudent.lectureNumber;
		credit = newStudent.credit;
		boundaryofCredit = newStudent.boundaryofCredit;
		attendanceCount = newStudent.attendanceCount;
	}
	//ASSIGMENT OPERATOR
	Student& Student::operator =(const Student& newStudent){
		if(this->studentNo != newStudent.studentNo){
			name = newStudent.name; surname = newStudent.surname;
			studentNo = newStudent.studentNo; 
			level = newStudent.level;
			lectureNumber = newStudent.lectureNumber;
			credit = newStudent.credit;
			boundaryofCredit = newStudent.boundaryofCredit;
		}
		return *this;
	}
	//DESTRUCTOR
	Student::~Student(){}

	void Student::setLevel(int lvl){
		level = lvl;
		setBoundaryofCredit(level);
	}
	//this function assign credit limit amount to level
	void Student::setBoundaryofCredit(int lvl){
		if(lvl==1)
			boundaryofCredit = 20;
		else if(lvl==2)
			boundaryofCredit = 21;
		else if(lvl==3)
			boundaryofCredit = 22;
		else if(lvl==4)
			boundaryofCredit = 23;
	}

	bool studentNoControl(const vector<Student> &s, int num){
		for(unsigned int i=0; i<s.size(); ++i){
			if(s[i].studentNo == num){
				cout << "You enter same student number another student!" << endl;
				return false;
			}
		}
		return true;
	}

	int findStudent(const vector<Student> &stnd, int num){
		bool find;
		find = findStudentHelper(stnd, num);
		if(find==true){
			for(int i=0; i<stnd.size(); ++i){
				if(stnd[i].studentNo==num)
					return i;
			}
		}
		return -1;
	}

	bool findStudentHelper(const vector<Student> &s, int num){
		for(unsigned int i=0; i<s.size(); ++i)
			if(s[i].studentNo==num)
				return true;
		cout << "ERROR: NO STUDENT" << endl;
		return false;
	}

}