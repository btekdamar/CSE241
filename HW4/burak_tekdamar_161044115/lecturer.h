#ifndef lecturer_h
#define lecturer_h

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

	class Lecturer{
		public:
			Lecturer():numberofCourse(0){}
			//BIG THREE
			Lecturer(const Lecturer &newLecturer);//COPY CONSTRUCTOR
			~Lecturer();//DESTRUCTOR
			Lecturer& operator =(const Lecturer &newLecturer);//ASSIGNMENT OPERATOR
			//GETTER AND SETTER FUNCTIONS
			void setProfessions(string prof);
			void setPersonalId(const int id){personalId = id;}
			void setName(const string nm){name = nm;}
			void setSurname(const string srnm){surname = srnm;}
			void setTitle(const string ttl){title = ttl;}
			int getNumberofCourse(){return numberofCourse;}
			string getName(){return name;}
			string getSurname(){return surname;}
			string getTitle(){return title;}

			void proposeCourse(vector <Course> &crs, Course &addC);
			bool assignCourse(Course &crs);
			bool assignCourse(vector <Course> &crs);
			
			friend bool fieldMatch(const Lecturer &teacher, const Course &crs);
			friend int findLecturer(const vector <Lecturer> &teacher, const int no);
		private:
			int personalId, numberofCourse;
			string name, surname, title;
			vector<string> profession; 
			vector<Course> courses;
	};

	void readLecturer(vector<Lecturer> &tchr);
}

#endif