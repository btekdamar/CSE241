#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "lecturer.h"
#include "classroom.h"

using namespace std;

namespace attendance{
	//COPY CONSTRUCTOR
	Lecturer::Lecturer(const Lecturer &newLecturer){
		personalId = newLecturer.personalId;
		numberofCourse = newLecturer.numberofCourse;
		name = newLecturer.name; surname = newLecturer.surname; title = newLecturer.title;
		for(int i=0; i<newLecturer.profession.size(); i++){
			profession.push_back(newLecturer.profession[i]);
		}
		for(int i=0; i<newLecturer.courses.size(); i++){
			courses.push_back(newLecturer.courses[i]);
		}

	}
	//DESTRUCTOR
	Lecturer::~Lecturer(){}
	//ASSIGMENT OPERATOR
	Lecturer& Lecturer::operator =(const Lecturer &newLecturer){
		if(this->personalId != newLecturer.personalId){
			personalId = newLecturer.personalId;
			numberofCourse = newLecturer.numberofCourse;
			name = newLecturer.name; surname = newLecturer.surname; title = newLecturer.title;
			for(int i=0; i<newLecturer.profession.size(); i++){
				profession.push_back(newLecturer.profession[i]);
			}
			for(int i=0; i<newLecturer.courses.size(); i++){
				courses.push_back(newLecturer.courses[i]);
			}
		}
		return *this;
	}

	void Lecturer::setProfessions(string prof){
		unsigned int where, end = 0, i = 0;
		string temp;
		for(int j = 0; prof[j]!='\0'; j++)
			end++;
		for(unsigned int j = 0; prof.find(',') < end; j++){
			where = prof.find(','); temp.assign(prof, 0, where);
			profession.push_back(string());
			profession[i] = temp;
			prof.assign(prof, where+1, end);
			i++;
		}
		where = prof.find(' '); temp.assign(prof, 0, where);
		profession.push_back(string());
		profession[i] = temp;
	}
	/*this function assign given course to courses of lecturer*/
	bool Lecturer::assignCourse(Course &crs){
		if(crs.teacher!="0"){
			cout << "Block: this course assign another lecturer before" << endl;
			return false;
		}
		if(crs.isMandatory == true){
			for(unsigned int j=0; j<this->profession.size(); j++){
				if(this->numberofCourse<3){
					if(this->profession[j]==crs.field && crs.teacher=="0"){
						this->courses.push_back(Course());
						this->courses[this->numberofCourse] = crs;
						this->numberofCourse++;
						crs.teacher = this->name + ' ' + this->surname;
					}
				}

				if(this->numberofCourse>=3){
					cout << "Lecturer have 3 courses, so it is not added!" << endl;
					return false;
				}
			}
		}

		else if(crs.isMandatory == false && this->personalId == crs.personalId){
			for(unsigned int j=0; j<this->profession.size(); j++){
				if(this->numberofCourse<3){
					if(this->profession[j]==crs.field && crs.teacher=="0"){
						this->courses.push_back(Course());
						this->courses[this->numberofCourse] = crs;
						this->numberofCourse++;
						crs.teacher = this->name + ' ' + this->surname;
					}
				}

				if(this->personalId != crs.personalId){
					cout << "This lecturer doesn't have this course!" << endl;
					return false;
				}

				if(this->numberofCourse>=3){
					cout << "Lecturer have 3 courses, so it is not added!" << endl;
					return false;
				}
			}
		}
		cout << "DONE" << endl;
		return true;
	}
	/*this function assign given course vector to courses of lecturer*/
	bool Lecturer::assignCourse(vector <Course> &crs){
		vector <int> index;
		for(unsigned int i=0; i<this->profession.size(); i++){
			if(this->profession[i] == "NET" || this->profession[i] == "CYBER" || 
				this->profession[i] == "ARCH" || this->profession[i] == "PHY" || 
				this->profession[i] == "MATERIAL"){
				index.push_back(i);
			}
		}

		for(unsigned int j=0; j<index.size(); j++){
			if(this->numberofCourse<3){
				for(unsigned int i=0; i<crs.size(); i++){
					if(this->profession[index[j]]==crs[i].field && crs[i].teacher=="0" && this->numberofCourse<3 && crs[i].isMandatory==true){
						this->courses.push_back(Course());
						this->courses[this->numberofCourse] = crs[i];
						this->numberofCourse++;
						crs[i].teacher = this->name + ' ' + this->surname;
					}
				}
			}	
		}

		for(unsigned int j=0; j<this->profession.size(); j++){
			if(this->numberofCourse<3){
				for(unsigned int i=0; i<crs.size(); i++){
					if(this->profession[j]==crs[i].field && crs[i].teacher=="0" && this->numberofCourse<3 && crs[i].isMandatory==true){
						this->courses.push_back(Course());
						this->courses[this->numberofCourse] = crs[i];
						this->numberofCourse++;
						crs[i].teacher = this->name + ' ' + this->surname;
					}
				}
			}

			if(this->numberofCourse>=3)
				return false;
		}

		return true;
	}

	void Lecturer::proposeCourse(vector <Course> &crs, Course &addC){
		addC.isMandatory = false;
		crs.push_back(addC);
		cout << "DONE" << endl;
	}

	/*This function check matching lecturer professions and course field. if they don't match, it gives error*/
	bool fieldMatch(const Lecturer &teacher, const Course &crs){
		for(unsigned int i=0; i<teacher.profession.size(); i++){
			if(teacher.profession[i] == crs.field){
				return true;
			}
		}
		cout << "Block: field and profession mismatch" << endl;
		return false;
	}
	/*This function find lecturer index by looking at the lecturer personal id. if there is not lecturer, it gives error*/
	int findLecturer(const vector <Lecturer> &teacher, const int no){
		for(int i=0; (unsigned)i<teacher.size(); i++){
			if(teacher[i].personalId==no){
				return i;
			}
		}
		cout << "No Lecturer!" << endl;
		return -1;
	}

	/*This fuction fill given lecturer vector by reading to file*/
	void readLecturer(vector<Lecturer> &tchr){
		int i = 0, id, count = 0;
		string name, surname, title, professions, temp;
		ifstream readFile;
		readFile.open("lecturers.txt");
		while(!readFile.eof()){
			getline(readFile, temp);
			count++;
		}
		readFile.close();
		readFile.open("lecturers.txt");
		while(i<(count-1)){
			tchr.push_back(Lecturer());
			readFile >> id;
			readFile >> name;
			readFile >> surname;
			readFile >> title;
			readFile >> professions;
			tchr[i].setPersonalId(id); tchr[i].setName(name); tchr[i].setSurname(surname);
			tchr[i].setTitle(title); tchr[i].setProfessions(professions);
			i++;
		}
		readFile.close();
	}
}