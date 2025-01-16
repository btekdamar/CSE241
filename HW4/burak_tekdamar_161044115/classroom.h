#ifndef classroom_h
#define classroom_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "student.h"

using namespace std;

namespace attendance{

	struct Course{
		int id, code, daySize, personalId; //daySize variable keep how many days in a week of selected lecture
		string name, lectureDate, field, teacher, classroomName[2];
		double credit, totalHours;
		vector<int> startLecture; //I use 3 different vector type for day of lecture and start and end time of lecture
		vector<int> endLecture;
		vector<string> lectureDay;
		vector<int> hoursOfWeek;
		bool isMandatory;
	};

	class Classroom{
		public:
			Classroom(){}
			Classroom(string no, int capa, int num1):c_no(no), capacity(capa), id(num1), studentInroom(0){stdnt = new Student[capacity];}
			//BIG THREE
			Classroom(const Classroom &newClassroom);//COPY CONSTRUCTOR
			Classroom& operator =(const Classroom &newClassroom);//ASSIGMENT OPERATOR
			~Classroom();//DESTRUCTOR
			//SETTER AND GETTER FUNCTIONS
			void setCapacity(int num){capacity=num; stdnt = new Student[capacity];}
			Student& getStudent(){for(int i=0; i<capacity; i++){cout << stdnt[i].getName() << endl;}}
			void setId(int num){id=num;}
			void setStudentInroom(int num){studentInroom=num;}
			void setCourseNo(string no){c_no=no;}
			void setStart(int num){startLecture.push_back(num);}
			void setEnd(int num){endLecture.push_back(num);}
			void setDay(string day){lectureDay.push_back(day);}
			void setCourseName(string coursenm){courseName.push_back(coursenm);}
			int getCapacity(){return capacity;}
			int getId(){return id;}
			int getStudentInroom(){return studentInroom;}
			string getC_no(){return c_no;}

			int enterClassroom(Student& std, int hours);
			int quitClassroom(Student& std);
	
			friend int findClassroom(const vector<Classroom> &cls, string num);
			friend bool arrangeClassroom(Classroom &cls1, Classroom &cls2, Course &crs);
			friend void arrangeClassroom(vector <Classroom> &cls, Course &crs);
		private:
			int id, capacity, studentInroom;
			string c_no;
			vector<int> startLecture;
			vector<int> endLecture;
			vector<string> lectureDay;
			vector<string> courseName;
			Student *stdnt = nullptr;
	};

	void findHoursofWeek(Course &crs);
	int findCourse(const vector<Course> &crs, int num);
	int studentAttendance(Student &std, const Course &crs);
	void fillCourseClassroom(vector<Course> &cr, vector<Classroom> &cl);
	bool timeTable(Course &crs);

}

#endif