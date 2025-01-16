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
	//COPY CONSTRUCTOR
	Classroom::Classroom(const Classroom &newClassroom){
        id = newClassroom.id;
        capacity = newClassroom.capacity;
        studentInroom = newClassroom.studentInroom;
        c_no = newClassroom.c_no;
      
        for(int i=0; i<newClassroom.lectureDay.size(); i++){
        	lectureDay[i] = newClassroom.lectureDay[i];
        	startLecture[i] = newClassroom.startLecture[i];
        	endLecture[i] = newClassroom.endLecture[i];
        }
    }
    //DESTRUCTOR
    Classroom::~Classroom(){
    	delete[] stdnt;
    }
    //ASSIGMENT OPERATOR
    Classroom& Classroom::operator =(const Classroom &newClassroom){
    	if(this->id != newClassroom.id){
    		id = newClassroom.id;
        	capacity = newClassroom.capacity;
        	studentInroom = newClassroom.studentInroom;
        	c_no = newClassroom.c_no;
        	for(int i=0; i < capacity;i++){
        		stdnt[i] = newClassroom.stdnt[i];
        	}
        	for(int i=0; i<newClassroom.lectureDay.size(); i++){
        		lectureDay[i] = newClassroom.lectureDay[i];
        		startLecture[i] = newClassroom.startLecture[i];
        		endLecture[i] = newClassroom.endLecture[i];
       		 }
    	}
    	return *this;
    }
 
    int Classroom::enterClassroom(Student& std, int hours){

    	if(!std.getInClassroom() && studentInroom<capacity){
    		std.setInClassroom(true);
    		std.setHours(hours);
    		std.setClassroomNo(c_no);
    		stdnt[studentInroom] = std;
    		studentInroom++;
    		return studentInroom;
    	}
    	else if(studentInroom == capacity)
    		cout << "Classroom is full" << endl;
    	else{
    		cout << "Student is at another classroom" << endl;
    		return -1;
    	}
    }

    int Classroom::quitClassroom(Student& std){
    	if(std.getInClassroom()){
    		studentInroom--;
    		std.setInClassroom(false);
    		return studentInroom;
    	}

    	else{
    		cout << "Student is not in any classroom" << endl;
    		return -1;
    	}
    }

    /*This function find classroom index by looking at the classroom no. if there is not classroom, it gives error*/
	int findClassroom(const vector<Classroom> &cls, string num){
		for(int i=0; (unsigned)i<cls.size()-1; i++){
			if(cls[i].c_no == num)
				return i;
		}
		cout << "ERROR: NO CLASSROOM" << endl;
		return -1;
	}

	//This function search given course number, if it does not find course, it return -1
	int findCourse(const vector<Course> &crs, int num){
		for(int i=0; (unsigned)i<crs.size(); i++){
			if(crs[i].id==num)
				return i;
		}
		return -1;
	}

    bool arrangeClassroom(Classroom &cls1, Classroom &cls2, Course &crs){
		int controlNum1 = 0, controlNum2 = 0;
		if(crs.classroomName[0] != "0" || crs.isMandatory!=true)
			return false;

		if(crs.lectureDay.size()==0){
			cout << "Error:(" << crs.id << ")" << crs.name << " timetable arrange yet" << endl;
			return false;
		}

		for(unsigned int i=0; i<cls1.lectureDay.size(); i++){
			if(cls1.lectureDay[i]==crs.lectureDay[0])
				for(unsigned int j=0; j<cls1.startLecture.size(); j++)
					if(cls1.endLecture[j]>crs.startLecture[0] && cls1.startLecture[j]<crs.endLecture[0])
						controlNum1 = -1;
		}

		if(controlNum1 == -1){
			for(unsigned int i=0; i<cls1.lectureDay.size(); i++){
				if(cls1.lectureDay[i]==crs.lectureDay[1]){
					for(unsigned int j=0; j<cls1.startLecture.size(); j++){
						if(cls1.endLecture[j]>crs.startLecture[1] && cls1.startLecture[j]<crs.endLecture[1]){
							return false;
						}
					}
				}
			}
		}

		if(controlNum1 == -1){
			for(unsigned int i=0; i<cls2.lectureDay.size(); i++){
				if(cls2.lectureDay[i]==crs.lectureDay[0]){
					for(unsigned int j=0; j<cls2.startLecture.size(); j++){
						if(cls2.endLecture[j]>crs.startLecture[0] && cls2.startLecture[j]<crs.endLecture[0]){
							return false;
						}
					}
				}
			}
		}
		controlNum2 = 1;

		if(controlNum1 != -1){
			for(unsigned int i=0; i<cls2.lectureDay.size(); i++){
				if(cls2.lectureDay[i]==crs.lectureDay[1]){
					for(unsigned int j=0; j<cls2.startLecture.size(); j++){
						if(cls2.endLecture[j]>crs.startLecture[1] && cls2.startLecture[j]<crs.endLecture[1]){
							return false;
						}
					}
				}
			}
		}
		controlNum2 = 2;

		if(controlNum1 == 0 && controlNum2 == 2){
			crs.classroomName[0] = cls1.c_no;
			crs.classroomName[1] = cls2.c_no;
			cls1.lectureDay.push_back(crs.lectureDay[0]);
			cls1.startLecture.push_back(crs.startLecture[0]);
			cls1.endLecture.push_back(crs.endLecture[0]);
			cls2.lectureDay.push_back(crs.lectureDay[1]);
			cls2.startLecture.push_back(crs.startLecture[1]);
			cls2.endLecture.push_back(crs.endLecture[1]);
		}

		else{
			crs.classroomName[0] = cls2.c_no;
			crs.classroomName[1] = cls1.c_no;
			cls1.lectureDay.push_back(crs.lectureDay[1]);
			cls1.startLecture.push_back(crs.startLecture[1]);
			cls1.endLecture.push_back(crs.endLecture[1]);
			cls2.lectureDay.push_back(crs.lectureDay[0]);
			cls2.startLecture.push_back(crs.startLecture[0]);
			cls2.endLecture.push_back(crs.endLecture[0]);
		}

		return true;
	}

	void arrangeClassroom(vector <Classroom> &cls, Course &crs){
		if(crs.lectureDay.size()==0){
			cout << "Error:(" << crs.id << ")" << crs.name << " timetable arrange yet" << endl;
			return;
		}
		if(crs.classroomName[0] != "0" && crs.classroomName[1] != "0"){
			cout << "(" << crs.id << ")" << crs.name << " arrange before" << " in " << crs.classroomName[0] << " at " << 
			crs.lectureDay[0] << "_" << crs.startLecture[0] << "-" << crs.endLecture[0] << "," << " in " << 
			crs.classroomName[1] << " at " << crs.lectureDay[1] << "_" << crs.startLecture[1] << "-" << crs.endLecture[1] << endl;
			return;
		}
		for(unsigned int i = 0; i<(cls.size()); i++){
			for(unsigned int j = 0; j<cls.size(); j++){
				if(crs.classroomName[0] == "0" && crs.classroomName[1] == "0"){
					arrangeClassroom(cls[i], cls[j], crs);
				}
			}
		}
		cout << "(" << crs.id << ")" << crs.name << " in " << crs.classroomName[0] << " at " << 
		crs.lectureDay[0] << "_" << crs.startLecture[0] << "-" << crs.endLecture[0] << "," << " in " << 
		crs.classroomName[1] << " at " << crs.lectureDay[1] << "_" << crs.startLecture[1] << "-" << crs.endLecture[1] << " Hours of week:";
		for(int i=0; i<crs.hoursOfWeek.size(); i++){
			cout << " " << crs.hoursOfWeek[i];
		}
		cout << endl;
	}

	void findHoursofWeek(Course &crs){
		for(int i=0; i<2; i++){
			int temp = crs.startLecture[i]-8;
			if(crs.lectureDay[i] == "Mon"){
				for(int j=0; j<(crs.endLecture[i]-crs.startLecture[i]); j++){
					if(j>=2)
						temp+=(j-(j-1));
					else
						temp+=j;
					crs.hoursOfWeek.push_back(temp);
				}
			}
			else if(crs.lectureDay[i] == "Tues"){
				temp += 8;
				for(int j=0; j<(crs.endLecture[i]-crs.startLecture[i]); j++){
					if(j>=2)
						temp+=(j-(j-1));
					else
						temp+=j;
					crs.hoursOfWeek.push_back(temp);
				}
			}
			else if(crs.lectureDay[i] == "Wed"){
				temp += 16;
				for(int j=0; j<(crs.endLecture[i]-crs.startLecture[i]); j++){
					if(j>=2)
						temp+=(j-(j-1));
					else
						temp+=j;
					crs.hoursOfWeek.push_back(temp);
				}
			}
			else if(crs.lectureDay[i] == "Thurs"){
				temp += 24;
				for(int j=0; j<(crs.endLecture[i]-crs.startLecture[i]); j++){
					if(j>=2)
						temp+=(j-(j-1));
					else
						temp+=j;
					crs.hoursOfWeek.push_back(temp);
				}
			}
			else if(crs.lectureDay[i] == "Fri"){
				temp += 32;
				for(int j=0; j<(crs.endLecture[i]-crs.startLecture[i]); j++){
					if(j>=2)
						temp+=(j-(j-1));
					else
						temp+=j;
					crs.hoursOfWeek.push_back(temp);
				}
			}
		}
	}

	int studentAttendance(Student &std, const Course &crs){
		for(int i=0; i<crs.hoursOfWeek.size();i++){
			for(int j=0; j<std.getSizeofClassroomHours(); j++){
				if(crs.hoursOfWeek[i]==std.getIndex(j)){
					std.attendeceCountIncrement();
				}
			}
		}
		return std.getAttendanceCount();
	}

	//This function fill given course and classroom vectors by reading to file
	void fillCourseClassroom(vector<Course> &cr, vector<Classroom> &cl){
		string temp1;
		string c_no;
		int i = 0, countCourse = 0, countClass = 0, id, capacity;
		ifstream readFile1;
		readFile1.open("courses_classrooms.txt");
		getline(readFile1, temp1);	
		while(!readFile1.eof()){
			getline(readFile1, temp1);
			if(temp1[0]!='C' && countClass == 0)
				countCourse++;
			else
				countClass++;
		}
		readFile1.close();

		ifstream readFile;
		readFile.open("courses_classrooms.txt");
		getline(readFile, temp1);	
		while(i<countCourse)
		{
			cr.push_back(Course());
	 		readFile >> cr[i].id;
			readFile >> cr[i].name;
			readFile >> cr[i].code;
			readFile >> cr[i].credit;
			readFile >> cr[i].totalHours;
			readFile >> cr[i].field;
			cr[i].isMandatory = true;
			cr[i].teacher = "0";
			cr[i].classroomName[0] = "0";
			cr[i].classroomName[1] = "0";
			i++;
		}

		i = 0;

		getline(readFile, temp1);
		getline(readFile, temp1);

		while(i<countClass-1){
			cl.push_back(Classroom());
			i++;
		}

		i = 0;

		while(i<countClass-1){
			readFile >> id;
			readFile >> c_no;
			readFile >> capacity;
			cl[i].setCourseNo(c_no);
			cl[i].setCapacity(capacity);
			cl[i].setId(id);
			cl[i].setStudentInroom(0);
			i++;
		}
		readFile.close();
	}

	//This function arrange time to given course randomly
	bool timeTable(Course &crs){
		string Days[5] = {"Mon", "Tues", "Wed", "Thurs", "Fri"};
		string temp;
		int index = -1, tempStart, tempEnd, dayNumber, tempNum = -1;

		if(crs.lectureDay.size()!=0){
			cout << "(" << crs.id << ")" << crs.name << " assign before ";
			cout << crs.lectureDay[0] << "_" << crs.startLecture[0] << "-" << crs.endLecture[0] << ",";
			cout << crs.lectureDay[1] << "_" << crs.startLecture[1] << "-" << crs.endLecture[1] << endl; 
			return false;
		}

		else if(crs.lectureDay.size()==0){
			if(crs.totalHours==3){
				dayNumber = (crs.totalHours/2)+1;
				for(int i = 0; i<dayNumber; i++){
					do{
						index = rand() % 5;
					}while((tempNum==index));
					temp = Days[index];
					crs.lectureDay.push_back(temp);
					if(i == 0){
						do{
							tempStart = rand() % 15 + 9;
						}while((tempStart+2>17));
						crs.startLecture.push_back(tempStart);
						tempEnd = tempStart + 2;
					}
					else{
						do{
							tempStart = rand() % 16 + 9;
						}while((tempStart+1>17));
						crs.startLecture.push_back(tempStart);
						tempEnd = tempStart + 1;
					}
					crs.endLecture.push_back(tempEnd);
					tempNum = index;
				}
			}
			if(crs.totalHours==4){
				dayNumber = crs.totalHours/2;
				for(int i = 0; i<dayNumber; i++){
					do{
						index = rand() % 5;
					}while((tempNum==index));
					temp = Days[index];
					crs.lectureDay.push_back(temp);
					do{
						tempStart = rand() % 15 + 9;
					}while((tempStart+2>17));
					crs.startLecture.push_back(tempStart);
					tempEnd = tempStart + 2;
					crs.endLecture.push_back(tempEnd);
					tempNum = index;
				}
			}
			if(crs.totalHours==5){
				dayNumber = crs.totalHours/2;
				for(int i = 0; i<dayNumber; i++){
					do{
						index = rand() % 5;
					}while((tempNum==index));
					temp = Days[index];
					crs.lectureDay.push_back(temp);
					if(i == 0){
						do{
							tempStart = rand() % 15 + 9;
						}while((tempStart+2>17));
						crs.startLecture.push_back(tempStart);
						tempEnd = tempStart + 2;
					}
					else{
						do{
							tempStart = rand() % 14 + 9;
						}while((tempStart+3>17));
						crs.startLecture.push_back(tempStart);
						tempEnd = tempStart + 3;
					}
					crs.endLecture.push_back(tempEnd);
					tempNum = index;
				}
			}
			if(crs.totalHours==6){
				dayNumber = (crs.totalHours/3);
				for(int i = 0; i<dayNumber; i++){
					do{
						index = rand() % 5;
					}while((tempNum==index));
					temp = Days[index];
					crs.lectureDay.push_back(temp);
					do{
						tempStart = rand() % 15 + 9;
					}while((tempStart+3>17));
					crs.startLecture.push_back(tempStart);
					tempEnd = tempStart + 3;
					crs.endLecture.push_back(tempEnd);
					tempNum = index;
				}
			}
		}

		findHoursofWeek(crs);

		return true;
	}

}
