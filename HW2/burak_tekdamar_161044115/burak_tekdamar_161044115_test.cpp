#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
/*Student Class, Course and Classroom Structs Declerations*/
struct Course{
	int id, code, daySize; //daySize variable keep how many days in a week of selected lecture
	string name, lectureDate;
	double credit, totalHours;
	vector<int> startLecture; //I use 3 different vector type for day of lecture and start and end time of lecture
	vector<int> endLecture;
	vector<string> lectureDay;
};

struct Classroom{
	int id, capacity, studentInroom;
	string c_no;
};

class Student{
	public:
		Student();
		int enrollCourse(Course);
		int disenroll(Course);
		string extractSchedule();
		void setName(string nm){name = nm;}
		string getName(){return name;}
		string getSurname(){return surname;}
		int getStudentNo(){return studentNo;}
		int getLevel(){return level;}
		int getCredit(){return credit;}
		int getBoundaryofCredit(){return boundaryofCredit;}
		void setSurname(string snm){surname = snm;}
		void setNo(int sno){studentNo = sno;}
		void setLevel(int lvl);
		void setBoundaryofCredit(int lvl);
		void enterClassroom(Classroom&);
		void quitClassroom(Classroom&);
		bool controlCredit(int num);
		void listLecture();
		friend ostream& operator <<(ostream& outputStream, Student& s); //I use two different stream operators for writting information on file and terminal
		friend ofstream& operator <<(ofstream& outputStream, Student& s);
		friend bool studentNoControl(const vector<Student> &s, int num);
		friend int findStudent(const vector<Student> &stnd, int num);//This function is searching given student number if there is no student that given number, it return -1
		friend bool findStudentHelper(const vector<Student> &s, int num);
		friend bool overlapCourseControl(const Student &s, const Course &c);//This function check course hourse overlap each other
	private:
		string name, surname;
		int studentNo, level, lectureNumber, credit, boundaryofCredit;
		vector<Course> lecture;
};

void fillCourseClassroom(vector<Course> &cr, vector<Classroom> &cl);
int findCourse(const vector<Course> &crs, int num);
bool findCourseHelper(const vector<Course> &c, int num);
void spritLectureDate(Course &c);
void testFunction();

int main(){
	cout << "----------Test Start----------" << endl;
	unsigned int i = 0;
	unsigned int controlStd;
	int studentNo[3], level[3], count = 0, t = 0, k = 1;
	string name[3], surname[3], file[3];
	string temp;
	vector<Course> crs;
	vector<Classroom> clsrm;
	vector<Student> stdnt;
	fillCourseClassroom(crs, clsrm);
	name[0] = "Murat"; surname[0]= "Boz"; studentNo[0] = 111; level[0] = 4; file[0] = "file1.txt";
	name[1] = "Seda"; surname[1]= "Akyol"; studentNo[1] = 112; level[1] = 1; file[1] = "file2.txt";
	name[2] = "Zafer"; surname[2]= "Çalış"; studentNo[2] = 113; level[2] = 2; file[2] = "file3.txt";
	do{
		temp = "-ns";
		if(temp=="-ns"){
			cout << "----------New Student Function Test----------" << endl;
			stdnt.push_back(Student()); 
			stdnt[i].setName(name[t]);stdnt[i].setSurname(surname[t]);stdnt[i].setNo(studentNo[t]);stdnt[i].setLevel(level[t]);
		}
		temp = "-list";
		if(temp=="-list"){
			unsigned int j = 0;
			cout << "-----------List Lecture Test----------" << endl;
			while(j<crs.size()){
				cout <<"(" << crs[j].id << ") " << crs[j].name << " ";
				++j;
			}
			cout << endl;
		}
		temp = "-e";
		if(temp=="-e"){
			cout << "----------Enroll Course Function Test----------" << endl;
			if(k==9)
				k=0;
			for(int z=0; z<3; ++z){
				stdnt[i].enrollCourse(crs[k]);
				k++;
			}
			cout << "DONE!" << endl;
		}
		temp = "-de";
		if(temp=="-de"){
			cout << "----------Disenroll Course Function Test----------" << endl;
			stdnt[i].disenroll(crs[k-1]);
			cout << "DONE!" << endl;
		}
		temp = "-o";
		count = 3;
		if(temp=="-o" && (count>=3 && count<=10)){
			cout << "----------Output Information and extractSchedule Function Test for Given Student Number Test----------" << endl;
			if(controlStd!=-1)
				cout << stdnt[i];
		}
		count = 15;
		if(temp=="-o" && count > 14){
			cout << "----------Output Information and extractSchedule Function Test for Given Student Number Test in File----------" << endl;
			ofstream writeFile;
			writeFile.open(file[i]);
			if(controlStd!=-1){
				writeFile << stdnt[i];
				cout << "DONE! " << file[i] << endl;
			}
			writeFile.close();
		}
		if(i==2)
			count = 14;
		if(temp=="-o" && count==14){
			cout << "----------Output Information and extractSchedule Function Test for All Students Test in File----------" << endl;
			ofstream writeFile;
			writeFile.open("fileTest.txt");
			for(unsigned int i = 0; i<stdnt.size(); ++i){
				writeFile << stdnt[i];
			}
			cout << "DONE! fileTest.txt" << endl;
			writeFile.close();
		}

		if(temp=="-o" && i == 2){
			cout << "----------Output Information and extractSchedule Function Test for All Students Test in Terminal----------" << endl;
			for(unsigned int i = 0; i<stdnt.size(); ++i)
				cout << stdnt[i];
		}

		count = 0;
		++i;
		++k;
		++t;
	}while(i!=3);

	cout << "----------enterClassroom Function Test----------" << endl;
	stdnt[0].enterClassroom(clsrm[1]);
	stdnt[1].enterClassroom(clsrm[1]);
	stdnt[2].enterClassroom(clsrm[1]);
	cout << "----------quitClassroom Function Test----------" << endl;
	stdnt[1].quitClassroom(clsrm[1]);

	cout << "----------Test End----------" << endl;
	
	return 0;
}

Student::Student():lectureNumber(0), credit(0){}
//I use for write lecture list of student 
void Student::listLecture(){
	for(unsigned int i=0; i<lectureNumber; ++i)
		cout << this->lecture[i].name << " ";
}

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
//This function check student credit right is overlap before add new lecture
bool Student::controlCredit(int num){
	if(((this->credit)+(num))<=(this->boundaryofCredit))
		return true;
	else{
		cout << "BLOCK! Because of credits overlap" << endl;
		return false;
	}
}

int Student::enrollCourse(Course c){
	this->lecture.push_back(Course());
	this->lecture[lectureNumber] = c;
	this->lectureNumber++;
	this->credit+=c.credit;
	return (this->boundaryofCredit - this->credit);
}

int Student::disenroll(Course c){
	int index=-1;
	for(unsigned int i=0; i<this->lecture.size(); ++i)
		if(this->lecture[i].id==c.id)
			index=i;

	if(index != -1){
		this->lecture.erase(lecture.begin()+index);
		this->lectureNumber--;
		this->credit-=c.credit;
	}

	return (this->boundaryofCredit - this->credit);
}

string Student::extractSchedule(){
	string temp[4];
	string schedule;
	stringstream ss[lectureNumber];
	int count1 = 0, count2 = 0;
	temp[2] = " ";
	for(unsigned int i=0; i<lectureNumber; ++i){
		for(int j=0; lecture[i].name[j]!='\0'; ++j)
			count1++;
		temp[0].assign(this->lecture[i].name, 0, count1);
		for(int j=0; lecture[i].lectureDate[j]!='\0'; ++j)
			count2++;
		temp[1].assign(this->lecture[i].lectureDate, 0, count2);
		ss[i] << this->lecture[i].credit;
		temp[3] = ss[i].str();
		schedule += temp[0] + temp[2] + temp[1] + temp[2] + "Credit:" + temp[3] + temp[2];
	}
	return schedule;
}

void Student::enterClassroom(Classroom& cls){
	cls.studentInroom++;
	cout << cls.c_no << " classroom student inroom now: " << cls.studentInroom << endl;
}

void Student::quitClassroom(Classroom& cls){
	cls.studentInroom--;
	cout << cls.c_no << " classroom student inroom now: " << cls.studentInroom << endl;
}
//This function fill given course and classroom vectors by reading to file
void fillCourseClassroom(vector<Course> &cr, vector<Classroom> &cl){
	string temp1;
	int i = 0;
	int countCourse = 0;
	int countClass = 0;
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
		readFile >> cr[i].lectureDate;
		++i;
	}
	i = 0;
	getline(readFile, temp1);
	getline(readFile, temp1);

	while(i<countClass-2){
		cl.push_back(Classroom());
		readFile >> cl[i].id;
		readFile >> cl[i].c_no;
		readFile >> cl[i].capacity;
		cl[i].studentInroom = 0;
		++i;
	}
	readFile.close();
	for(unsigned int i=0; i<cr.size(); ++i)
		spritLectureDate(cr[i]);
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
//This function search given course number, if it does not find course, it return -1
int findCourse(const vector<Course> &crs, int num){
	bool find;
	find = findCourseHelper(crs, num);
	if(find==true){
		for(int i=0; i<crs.size(); ++i){
			if(crs[i].id==num)
				return i;
		}
	}
	return -1;

}
bool findCourseHelper(const vector<Course> &c, int num){
	for(unsigned int i=0; i<c.size(); ++i)
		if(c[i].id==num)
			return true;
	cout << "ERROR: NO COURSE" << endl;
	return false;
}
//This funcion sprit full date as day, start and end hours
void spritLectureDate(Course &c){
	string temp1, temp2;
	size_t where;
	int count = 0, count2 = 0, num = 0;
	temp1 = c.lectureDate;
	for(int i=0; c.lectureDate[i]!='\0'; ++i)
		++count2;

	for(int i=0; c.lectureDate[i]!='\0'; ++i){

		if(temp1.find('_')){
			where = temp1.find('_');
			c.lectureDay.push_back(temp2.assign(temp1,0,where));
			temp1.assign(temp1,where+1,count2);
		}
		if(temp1.find('-')){
			where = temp1.find('-');
			temp2.assign(temp1,0,where);
			stringstream ss1(temp2); ss1 >> num;
			c.startLecture.push_back(num);
			temp1.assign(temp1,where+1,count2);
		}

		if(temp1.size()==2){
			temp2.assign(temp1,0,2);
			stringstream ss2(temp2); ss2 >> num;
			c.endLecture.push_back(num);
			++count;
			break;
		}

		if(temp1.find(',')){
			where = temp1.find(',');
			temp2.assign(temp1,0,where);
			stringstream ss3(temp2); ss3 >> num;
			c.endLecture.push_back(num);
			temp1.assign(temp1,where+1,count2);
			++count;
		}
	}

	c.daySize = count;
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

ostream& operator<<(ostream& outputStream, Student& s){
	string schedule = s.extractSchedule();
	outputStream << s.name << " " << s.surname << " "; 
	outputStream << schedule;
	outputStream << "Total credits:" << s.credit << " Credit right:" << s.boundaryofCredit << endl;
	return outputStream; 
}

bool overlapCourseControl(const Student &s, const Course &c){
	for(unsigned int i = 0; i<s.lectureNumber; ++i)
		for(unsigned int j = 0; j<c.daySize; ++j)
			for(unsigned int t = 0; t<s.lecture[i].daySize; ++t)
				if(s.lecture[i].lectureDay[t] == c.lectureDay[j])
					if((s.lecture[i].startLecture[t] == c.startLecture[j]) && 
						(((((c.endLecture[j]-c.startLecture[j])) < (s.lecture[i].endLecture[t]-s.lecture[i].startLecture[t])) && 
						(((c.endLecture[j]-c.startLecture[j])*2) > (s.lecture[i].endLecture[t]-s.lecture[i].startLecture[t]))) ||
							((((c.endLecture[j]-c.startLecture[j])) > (s.lecture[i].endLecture[t]-s.lecture[i].startLecture[t])) && 
							(((c.endLecture[j]-c.startLecture[j])*2) < (s.lecture[i].endLecture[t]-s.lecture[i].startLecture[t])))))
								return false;
					else if(((c.startLecture[j]>=s.lecture[i].startLecture[t] && c.startLecture[j]<=s.lecture[i].endLecture[t]) && 
							(((s.lecture[i].endLecture[t]-c.startLecture[j])*2)>(c.endLecture[j]-c.startLecture[j]))) || 
							((s.lecture[i].startLecture[t]>= c.startLecture[j] && s.lecture[i].endLecture[t]<=c.startLecture[j]) &&
							(((c.startLecture[j]-s.lecture[i].endLecture[t])*2)>(s.lecture[i].endLecture[t]-s.lecture[i].startLecture[t]))))
								return false;
	return true;
}

ofstream& operator <<(ofstream& outputStream, Student& s){
	string schedule = s.extractSchedule();
	outputStream << s.name << " " << s.surname << " ";
	outputStream << schedule; 
	outputStream << "Total credits:" << s.credit << " Credit right:" << s.boundaryofCredit << endl;
	return outputStream; 
}
