#ifndef student_h
#define student_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "classroom.h"

using namespace std;

namespace attendance{

	class Student{
		public:
			Student();
			//BIG THREE
			Student(const Student& newStudent);//COPY CONSTRUCTOR
			Student& operator =(const Student& newStudent);//ASSIGMENT OPERATOR
			~Student();//DESTRUCTOR
			//GETTER AND SETTER FUNCTIONS
			void setName(string nm){name = nm;}
			void setSurname(string snm){surname = snm;}
			void setNo(int sno){studentNo = sno;}
			void setClassroomNo(string num){classroomNo = num;}
			void setLevel(int lvl);
			void setBoundaryofCredit(int lvl);
			void setInClassroom(bool check){isInClassroom = check;}
			void setHours(int num){classroomHours.push_back(num);}
			string getName(){return name;}
			string getSurname(){return surname;}
			int getStudentNo(){return studentNo;}
			string getClassroomNo(){return classroomNo;}
			int getLevel(){return level;}
			int getAttendanceCount(){int temp = attendanceCount; attendanceCount = 0; return temp;}
			int getCredit(){return credit;}
			int getBoundaryofCredit(){return boundaryofCredit;}
			int getSizeofClassroomHours(){return classroomHours.size();}
			int getIndex(int i){return classroomHours[i];}
			bool getInClassroom(){return isInClassroom;}
			
			void attendeceCountIncrement(){attendanceCount++;}

			friend bool studentNoControl(const vector<Student> &s, int num);
			friend int findStudent(const vector<Student> &stnd, int num);//This function is searching given student number if there is no student that given number, it return -1
			friend bool findStudentHelper(const vector<Student> &s, int num);
		private:
			string name, surname, classroomNo;
			int studentNo, level, lectureNumber, credit, boundaryofCredit, attendanceCount;
			bool isInClassroom; //If student is in any classroom this value is true
			vector<int> classroomHours;
	};

}

#endif