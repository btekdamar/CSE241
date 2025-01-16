#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "lecturer.h"
#include "classroom.h"
#include "student.h"

using namespace std;
using namespace attendance;

void test();

int main(){
	bool noControl, overlapControl, controlCredit;
	vector<Course> crs;
	vector<Classroom> clsrm;
	vector<Student> stdnt;
	vector<Lecturer> teacher;
	bool timeCheck; 
	bool controlFieldMatch = false, arrangeControl = false;
	int lecturerId, courseNo, controlStd, controlCrs, classId, courseCode, courseCredit, courseHours, studentNo, level, hourOfWeek, studentInroom, attendance = 0;
	int where = 0, lecturerIndex = 0, count = 0, i = 0, classIndex = 0;
	string name, surname, classNo1, classNo2, courseName, courseField;
	string temp, temp1, temp2, temp3;
	test();
	fillCourseClassroom(crs, clsrm);
	readLecturer(teacher);
	srand(time(NULL));
	for(unsigned int i=0; i<crs.size(); i++)
		timeTable(crs[i]);
	for(unsigned int i=0; i<crs.size(); i++)
		arrangeClassroom(clsrm, crs[i]);

	do{
		getline(cin, temp1);

		for(int i=0; temp1[i]!='\0'; ++i)
			++count;

		where = temp1.find(' ');
		temp.assign(temp1,0,where);
		temp1.assign(temp1,where+1,count);
		//For add new student you write, you can write like HW02: -ns name surname studentNo level
		if(temp == "-ns"){
			stdnt.push_back(Student());
			where = temp1.find(' '); name.assign(temp1,0,where); temp1.assign(temp1,where+1,count);
			where = temp1.find(' '); surname.assign(temp1,0,where); temp1.assign(temp1,where+1,count);
			where = temp1.find(' '); temp2.assign(temp1,0,where); stringstream ss1(temp2); ss1 >> studentNo;
			temp1.assign(temp1,where+1,count); stringstream ss2(temp1); ss2 >> level;
			noControl = studentNoControl(stdnt, studentNo);
			while(noControl==false){
				cout << "Please enter student number again:";
				cin >> studentNo;
				noControl = studentNoControl(stdnt, studentNo);
			}
			stdnt[i].setName(name);stdnt[i].setSurname(surname);stdnt[i].setNo(studentNo);stdnt[i].setLevel(level);stdnt[i].setInClassroom(false);
			++i;
		}

		if(temp == "-enter"){
			where = temp1.find(' '); temp2.assign(temp1,0,where); temp1.assign(temp1,where+1,count); stringstream ss3(temp2); ss3 >> studentNo;
			where = temp1.find(' '); classNo1.assign(temp1,0,where);
			temp1.assign(temp1,where+1,count); stringstream ss4(temp1); ss4 >> hourOfWeek;
			classIndex = findClassroom(clsrm, classNo1);
			controlStd = findStudent(stdnt, studentNo);
			if(controlStd != -1 && classIndex != -1){
				studentInroom = clsrm[classIndex].enterClassroom(stdnt[controlStd], hourOfWeek);
				if(studentInroom!=-1)
					cout << studentInroom << endl;
			}
		}

		if(temp == "-quit"){
			stringstream ss6(temp1); ss6 >> studentNo;
			controlStd = findStudent(stdnt, studentNo);
			if(controlStd != -1 && (stdnt[controlStd].getInClassroom())){
				classIndex = findClassroom(clsrm, stdnt[controlStd].getClassroomNo());
				studentInroom = clsrm[classIndex].quitClassroom(stdnt[controlStd]);
				if(studentInroom!=-1)
					cout << studentInroom << endl;
			}
		}

		if(temp == "-attendance"){
			stringstream ss7(temp1); ss7 >> courseNo;
			controlCrs = findCourse(crs, courseNo);
			if(controlCrs != -1){
				for(int j=0; j<stdnt.size(); j++){
					attendance = studentAttendance(stdnt[j], crs[controlCrs]);
					if(attendance != 0){
						cout << stdnt[j].getName() << " " << attendance << " ";
						attendance = 0;
					}
				}
			}
			cout << endl;
		}


	}while(temp!="exit");
}

void test(){
	cout << "----------Test Start----------" << endl;
	int i=0;
	bool noControl, overlapControl, controlCredit;
	vector<Course> crs;
	vector<Classroom> clsrm;
	vector<Student> stdnt;
	vector<Lecturer> teacher;
	bool timeCheck; 
	bool controlFieldMatch = false, arrangeControl = false;
	int studentNo[3], level[3], courseNo, classIndex, studentInroom=0, attendance;
	string name[3], surname[3], classroom[3], temp;
	fillCourseClassroom(crs, clsrm);
	readLecturer(teacher);

	for(unsigned int i=0; i<crs.size(); i++)
		timeTable(crs[i]);
	for(unsigned int i=0; i<crs.size(); i++)
		arrangeClassroom(clsrm, crs[i]);

	name[0] = "Murat"; surname[0]= "Boz"; studentNo[0] = 111; level[0] = 4; classroom[0] = "Z06";
	name[1] = "Seda"; surname[1]= "Akyol"; studentNo[1] = 112; level[1] = 1; classroom[1] = "Z11";
	name[2] = "Zafer"; surname[2]= "Çalış"; studentNo[2] = 113; level[2] = 2; classroom [2] = "207";

	stdnt.push_back(Student());
	stdnt.push_back(Student());
	stdnt.push_back(Student());

	stdnt[0].setName(name[0]); stdnt[0].setSurname(surname[0]); stdnt[0].setNo(studentNo[0]); stdnt[0].setLevel(level[0]); stdnt[0].setInClassroom(false);
	stdnt[1].setName(name[1]); stdnt[1].setSurname(surname[1]); stdnt[1].setNo(studentNo[1]); stdnt[1].setLevel(level[1]); stdnt[1].setInClassroom(false);
	stdnt[2].setName(name[2]); stdnt[2].setSurname(surname[2]); stdnt[2].setNo(studentNo[2]); stdnt[2].setLevel(level[2]); stdnt[2].setInClassroom(false);

	do{
		temp="-enter";
		cout << "----------Enter Classroom Function Test----------" << endl;
		if(temp=="-enter"){
			classIndex = findClassroom(clsrm, classroom[i]);
			studentInroom = clsrm[classIndex].enterClassroom(stdnt[i], 18);
			cout << studentInroom << endl;
		}
		temp="-quit";
		cout << "----------Quit Classroom Function Test----------" << endl;
		if(temp=="-quit"){
			classIndex = findClassroom(clsrm, stdnt[i].getClassroomNo());
			studentInroom = clsrm[classIndex].quitClassroom(stdnt[i]);
			cout << studentInroom << endl;

		}
		temp="-attendance";
		if(temp=="-attendance" && i==2){
			cout << "----------Attendance Function Test----------" << endl;
			for(int j=0; j<crs.size(); j++){
				cout << crs[j].name << " ";
				for(int t=0; t<stdnt.size(); t++){
					attendance = studentAttendance(stdnt[t], crs[j]);
					if(attendance != 0){
						cout << stdnt[t].getName() << " " << attendance << " ";
						attendance = 0;
					}
				}
				cout << endl;
			}
			cout << endl;
		}
		i++;
	}while(i<3);

	cout << "----------Test End----------" << endl;
}