#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*Lecturer, Administrator Classes and Course, Classroom Structs Declerations*/
struct Course{
	int id, code, daySize, personalId; //daySize variable keep how many days in a week of selected lecture
	string name, lectureDate, field, teacher, classroomName[2];
	double credit, totalHours;
	vector<int> startLecture; //I use 3 different vector type for day of lecture and start and end time of lecture
	vector<int> endLecture;
	vector<string> lectureDay;
	bool isMandatory;
};

struct Classroom{
	int id, capacity, studentInroom;
	string c_no;
	vector<int> startLecture;
	vector<int> endLecture;
	vector<string> lectureDay;
	vector<string> courseName;
};

class Lecturer{
	public:
		Lecturer():numberofCourse(0){}
		void proposeCourse(vector <Course> &crs, Course &addC);
		bool assignCourse(Course &crs);
		bool assignCourse(vector <Course> &crs);
		void setProfessions(string prof);
		void setPersonalId(const int id){personalId = id;}
		void setName(const string nm){name = nm;}
		void setSurname(const string srnm){surname = srnm;}
		void setTitle(const string ttl){title = ttl;}
		int getNumberofCourse(){return numberofCourse;}
		friend bool fieldMatch(const Lecturer &teacher, const Course &crs);
		friend int findLecturer(const vector <Lecturer> &teacher, const int no);
	private:
		int personalId, numberofCourse;
		string name, surname, title;
		vector<string> profession; 
		vector<Course> courses;
};

class Administrator{
	public:
		Administrator(){}
		bool arrangeClassroom(Classroom &cls, Course &crs);
		bool arrangeClassroom(Classroom &cls1, Classroom &cls2, Course &crs);
		void arrangeClassroom(vector <Classroom> &cls, Course &crs);
		bool arrangeTimeTable(Course &crs);
	private:
		int pid, password;
};

void fillCourseClassroom(vector<Course> &cr, vector<Classroom> &cl);
int findCourse(const vector<Course> &crs, int num);
int findClassroom(const vector<Classroom> &cls, string num);
bool findCourseHelper(const vector<Course> &c, int num);
void readLecturer(vector<Lecturer> &tchr);
void test();

int main(){
	bool timeCheck; 
	bool controlFieldMatch = false, arrangeControl = false;
	int lecturerId, courseNo, controlCrs, class1, class2, courseCode, courseCredit, courseHours;
	int where = 0, lecturerIndex = 0, count = 0;
	string name, surname, classNo1, classNo2, courseName, courseField;
	string temp, temp1, temp2, temp3;
	vector<Course> crs;
	vector<Classroom> clsrm;
	vector<Lecturer> teacher;
	Administrator admin;
	test();
	fillCourseClassroom(crs, clsrm);
	readLecturer(teacher);
	srand(time(NULL));
	do{
		getline(cin, temp1);

		for(int i=0; temp1[i]!='\0'; ++i)
			++count;
		/*I get whole line and parse it*/
		where = temp1.find(' ');
		temp.assign(temp1,0,where);
		temp1.assign(temp1,where+1,count);

		if(temp=="-propose"){
			where = temp1.find(' '); temp.assign(temp1,0,where); temp1.assign(temp1,where+1,count); stringstream ss6(temp); ss6 >> lecturerId;
			where = temp1.find(' '); courseName.assign(temp1,0,where); temp1.assign(temp1,where+1,count);
			where = temp1.find(' '); temp.assign(temp1,0,where); temp1.assign(temp1,where+1,count); stringstream ss7(temp); ss7 >> courseCode;
			where = temp1.find(' '); temp.assign(temp1,0,where); temp1.assign(temp1,where+1,count); stringstream ss8(temp); ss8 >> courseCredit;
			where = temp1.find(' '); temp.assign(temp1,0,where); temp1.assign(temp1,where+1,count); stringstream ss9(temp); ss9 >> courseHours;
			courseField.assign(temp1,0,count);
			lecturerIndex = findLecturer(teacher, lecturerId);
			if(lecturerIndex!=-1){
				Course tempCourse;
				tempCourse.personalId = lecturerId; tempCourse.name = courseName; tempCourse.id = courseCode; tempCourse.credit = courseCredit; tempCourse.totalHours = courseHours;
				teacher[lecturerIndex].proposeCourse(crs, tempCourse);
			}
		}

		else if(temp=="-assign" && count > 7){
			where = temp1.find(' '); temp.assign(temp1,0,where);  stringstream ss1(temp); ss1 >> lecturerId;
			temp1.assign(temp1,where+1,count); stringstream ss2(temp1); ss2 >> courseNo;
			controlCrs = findCourse(crs, courseNo);
			if(controlCrs != -1)
				lecturerIndex = findLecturer(teacher, lecturerId);
			if(lecturerIndex != -1 && controlCrs != -1)
				controlFieldMatch = fieldMatch(teacher[lecturerIndex], crs[controlCrs]);
			if(controlFieldMatch == true && lecturerIndex != -1 && controlCrs != -1)
				teacher[lecturerIndex].assignCourse(crs[controlCrs]);
		}

		else if(temp=="-assign"){
			for(unsigned int i=0; i<teacher.size(); i++){
				teacher[i].assignCourse(crs);
			}
			cout << "DONE" << endl;
		}

		else if(temp=="-timetable" && count > 10){
			stringstream ss3(temp1); ss3 >> courseNo;
			controlCrs = findCourse(crs, courseNo);
			if(controlCrs != -1){
				timeCheck=admin.arrangeTimeTable(crs[courseNo]);
				if(timeCheck!=false)
					cout << "DONE" << endl;
			}

		}

		else if(temp=="-timetable"){
			for(unsigned int i=0; i<crs.size(); i++){
				admin.arrangeTimeTable(crs[i]);
			}
		}

		else if(temp=="-arrangeC" && (count <= 15 && count >= 11)){
			where = temp1.find(' '); temp.assign(temp1,0,where);  stringstream ss4(temp); ss4 >> courseNo;
			classNo1.assign(temp1,where+1,count);
			class1 = findClassroom(clsrm, classNo1);
			controlCrs = findCourse(crs, courseNo);
			if(class1 != -1 && controlCrs != -1){
				admin.arrangeClassroom(clsrm[class1], crs[controlCrs]);
			}
		}

		else if(temp=="-arrangeC" && count > 15){
			where = temp1.find(' '); temp.assign(temp1,0,where); temp1.assign(temp1,where+1,count);  stringstream ss5(temp); ss5 >> courseNo;
			where = temp1.find(','); classNo1.assign(temp1,0,where); classNo2.assign(temp1,where+1,count);
			class1 = findClassroom(clsrm, classNo1);
			class2 = findClassroom(clsrm, classNo2);
			controlCrs = findCourse(crs, courseNo);
			if(class1 != -1 && class2 != -1 && controlCrs != -1){
				arrangeControl = admin.arrangeClassroom(clsrm[class1], clsrm[class2], crs[controlCrs]);
				if(arrangeControl == true)
					cout << "DONE:(" << crs[controlCrs].id << ")" << crs[controlCrs].name << " in " << clsrm[class1].c_no << " at " << 
					crs[controlCrs].lectureDay[0] << "_" << crs[controlCrs].startLecture[0] << "-" << crs[controlCrs].endLecture[0] << "," << " in " << 
					clsrm[class1].c_no << " at " << crs[controlCrs].lectureDay[1] << "_" << crs[controlCrs].startLecture[1] << "-" << crs[controlCrs].endLecture[1] << endl;
				else
					cout << "Block: class is not available, there is another class assigned" << endl;
			}
		}

		else if(temp=="-arrangeC"){
			for(unsigned int i=0; i<crs.size(); i++)
				admin.arrangeClassroom(clsrm, crs[i]);
		}

		count = 0;
	}while(temp!="exit");
	return 0;
}
/*This function find classroom index by looking at the classroom no. if there is not classroom, it gives error*/
int findClassroom(const vector<Classroom> &cls, string num){
	for(int i=0; (unsigned)i<cls.size(); i++){
		if(cls[i].c_no == num)
			return i;
	}
	cout << "ERROR: NO CLASSROOM" << endl;
	return -1;
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

//This function fill given course and classroom vectors by reading to file
void fillCourseClassroom(vector<Course> &cr, vector<Classroom> &cl){
	string temp1;
	int i = 0, countCourse = 0, countClass = 0;
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
		readFile >> cl[i].id;
		readFile >> cl[i].c_no;
		readFile >> cl[i].capacity;
		cl[i].studentInroom = 0;
		i++;
	}
	readFile.close();
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

//This function search given course number, if it does not find course, it return -1
int findCourse(const vector<Course> &crs, int num){
	bool find;
	find = findCourseHelper(crs, num);
	if(find==true){
		for(int i=0; (unsigned)i<crs.size(); i++){
			if(crs[i].id==num)
				return i;
		}
	}
	return -1;

}
bool findCourseHelper(const vector<Course> &c, int num){
	for(unsigned int i=0; i<c.size(); i++){
		if(c[i].id==num){
			return true;
		}
	}
	cout << "ERROR: NO COURSE" << endl;
	return false;
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
/*This function arrange given course to given classroom*/
bool Administrator::arrangeClassroom(Classroom &cls, Course &crs){
	if(crs.classroomName[0] != "0" || crs.isMandatory!=true){
		cout << "Course arranged before" << endl;
		return false;
	}

	if(crs.lectureDay.size()==0){
		cout << "Error:(" << crs.id << ")" << crs.name << " timetable arrange yet" << endl;
		return false;
	}

	for(unsigned int i=0; i<cls.lectureDay.size(); i++){
		for(unsigned int j=0; j<crs.lectureDay.size(); j++){
			if(cls.lectureDay[i]==crs.lectureDay[j]){
				for(unsigned int t=0; t<cls.startLecture.size(); t++){
					if(cls.endLecture[t]>crs.startLecture[j] && cls.startLecture[t]<crs.endLecture[j]){
						cout << "Block: class is not available, there is another class assigned" << endl;
						return false;
					}
				}
			}
		}
	}

	crs.classroomName[0] = cls.c_no;
	crs.classroomName[1] = cls.c_no;
	for(unsigned int i=0; i<crs.lectureDay.size(); i++){
		cls.lectureDay.push_back(crs.lectureDay[i]);
		cls.startLecture.push_back(crs.startLecture[i]);
		cls.endLecture.push_back(crs.endLecture[i]);
	}
	cout << "DONE:(" << crs.id << ")" << crs.name << " in " << cls.c_no << " at " << 
	crs.lectureDay[0] << "_" << crs.startLecture[0] << "-" << crs.endLecture[0] << "," <<
	crs.lectureDay[1] << "_" << crs.startLecture[1] << "-" << crs.endLecture[1] << endl;

	return true;
}

bool Administrator::arrangeClassroom(Classroom &cls1, Classroom &cls2, Course &crs){
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
/*This function arrange time to given course randomly*/
bool Administrator::arrangeTimeTable(Course &crs){
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
	cout << "DONE:(" << crs.id << ")" << crs.name << " ";
	cout << crs.lectureDay[0] << "_" << crs.startLecture[0] << "-" << crs.endLecture[0] << ",";
	cout << crs.lectureDay[1] << "_" << crs.startLecture[1] << "-" << crs.endLecture[1] << endl;
	return true;
}

void Administrator::arrangeClassroom(vector <Classroom> &cls, Course &crs){
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
	crs.classroomName[1] << " at " << crs.lectureDay[1] << "_" << crs.startLecture[1] << "-" << crs.endLecture[1] << endl;
}

void test(){
	cout << "----------Test Start----------" << endl;
	bool timeCheck; 
	bool controlFieldMatch = false, arrangeControl = false;
	int controlCrs, classId;
	int where = 0, lecturerIndex = 0, i = 0;
	string name, surname, courseField;
	string temp;
	vector<Course> crs;
	vector<Classroom> clsrm;
	vector<Lecturer> teacher;
	Administrator admin;
	string courseName[3]={"DenemeDers1", "DenemeDers2", "DenemeDers3"};
	int lecturerId[3]={1,2,123}, courseCode[3]={232,511,142}, courseCredit[3]={3,4,5}, courseHours[3]={3,4,5}, courseNo[3]={1,2,20};
	string classNo[3]={"207","Z23","300"};
	fillCourseClassroom(crs, clsrm);
	readLecturer(teacher);
	srand(time(NULL));
	do{
		temp = "-propose";
		if(temp=="-propose"){
			cout << "----------Propose Function Test----------" << endl;
			lecturerIndex = findLecturer(teacher, lecturerId[i]);
			if(lecturerIndex!=-1){
				Course tempCourse;
				tempCourse.personalId = lecturerId[i]; tempCourse.name = courseName[i]; tempCourse.id = courseCode[i]; tempCourse.credit = courseCredit[i]; tempCourse.totalHours = courseHours[i];
				teacher[lecturerIndex].proposeCourse(crs, tempCourse);
			}
		}
		temp = "-assign";
		if(temp=="-assign"){
			cout << "----------Assign Function Test----------" << endl;
			cout << "Course No:" << courseNo[i] << " Lecturer Id:" << lecturerId[i] << endl;
			controlCrs = findCourse(crs, courseNo[i]);
			if(controlCrs != -1)
				lecturerIndex = findLecturer(teacher, lecturerId[i]);
			if(lecturerIndex != -1 && controlCrs != -1)
				controlFieldMatch = fieldMatch(teacher[lecturerIndex], crs[controlCrs]);
			if(controlFieldMatch == true && lecturerIndex != -1 && controlCrs != -1)
				teacher[lecturerIndex].assignCourse(crs[controlCrs]);
		}
		temp = "-assign";
		if(temp=="-assign" && i==2){
			cout << "----------All Courses Assign Function Test----------" << endl;
			for(unsigned int j=0; j<teacher.size(); j++){
				teacher[j].assignCourse(crs);
			}
			cout << "DONE" << endl;
		}
		temp = "-timetable";
		if(temp=="-timetable"){
			cout << "----------Timetable Function Test----------" << endl;
			cout << "Course No:" << courseNo[i] << endl;
			controlCrs = findCourse(crs, courseNo[i]);
			if(controlCrs != -1){
				timeCheck=admin.arrangeTimeTable(crs[courseNo[i]]);
				if(timeCheck!=false)
					cout << "DONE" << endl;
			}
		}
		temp = "-timetable";
		if(temp=="-timetable" && i==2){
			cout << "----------All Courses Timetable Function Test----------" << endl;
			for(unsigned int j=0; j<crs.size(); j++)
				if(crs[j].isMandatory!=false)
					admin.arrangeTimeTable(crs[j]);
			}

		temp = "-arrangeC";
		if(temp=="-arrangeC"){
			cout << "----------ArrangeC Function Test----------" << endl;
			cout << "Course No:" << courseNo[i] << " Class No:" << classNo[i] << endl;
			classId = findClassroom(clsrm, classNo[i]);
			controlCrs = findCourse(crs, courseNo[i]);
			if(classId != -1 && controlCrs != -1){
				admin.arrangeClassroom(clsrm[classId], crs[controlCrs]);
			}
		}
		temp = "-arrangeC";
		if(temp=="-arrangeC" && i==2){
			cout << "----------All Courses ArrangeC Function Test----------" << endl;
			for(unsigned int j=0; j<crs.size(); j++){
				if(crs[j].isMandatory!=false)
					admin.arrangeClassroom(clsrm, crs[j]);
			}
		}

		i++;
	}while(i!=3);
	cout << "----------Test End----------" << endl;
}