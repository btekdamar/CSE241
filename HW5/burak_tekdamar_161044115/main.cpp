#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "university.h"
#include "employee.h"
#include "academicpersonnel.h"
#include "administrativepersonnel.h"
#include "lecturer.h"
#include "researchassistant.h"
#include "secretary.h"
#include "officer.h"

using namespace std;
//I use 4 different enum type for 4 different data type. These enum types keep function name. 
enum LecturerFunctions{Givehw, Givelesson, Lecsuccessfull, Lectea, Lecpetition};
enum OfficerFunctions{Makedoc, Officerprocess, Officertea, Officerpetition};
enum SecretaryFunctions{Receivepetition, Secprocess, Sectea, Secpetition};
enum ResarcherFunctions{Readhw, Research, Researchersuccessfull, Researchertea, Researcherpetition};

int main(){
	srand(time(NULL));

	int random;
	string name, surname, job, temp;
	vector<Lecturer> lec;
	vector<Officer> offic;
	vector<Secretary> sec;
	vector<researchAssistant> researcher;
	University* uni;
	uni = new University;

	ifstream readFile;

	readFile.open("personnellist.txt");

	while(!readFile.eof()){
		readFile >> job;
		readFile >> name;
		readFile >> surname;
		if(job=="Officer")
			offic.push_back(Officer(name, surname));
		else if(job=="Lecturer")
			lec.push_back(Lecturer(name, surname));
		else if(job=="Secretary")
			sec.push_back(Secretary(name, surname));
		else if(job=="ResearchAssistant")
			researcher.push_back(researchAssistant(name, surname));
	}

	readFile.close();

	for(int i=0; i<3; i++){
		do{
			random = rand() % researcher.size();
		}while(researcher[random].employ(uni));
	}

	for(int i=0; i<2; i++){
		do{
			random = rand() % lec.size();
		}while(lec[random].employ(uni));
	}

	for(int i=0; i<3; i++){
		do{
			random = rand() % sec.size();
		}while(sec[random].employ(uni));
	}

	for(int i=0; i<2; i++){
		do{
			random = rand() % offic.size();
		}while(offic[random].employ(uni));
	}
	//this code segment call functions randomly
	for(unsigned int i=0; i<lec.size(); i++){
		if(lec[i].isEmployee()){
			for(int j=0; j<5; j++){
				LecturerFunctions random = static_cast<LecturerFunctions>(rand() % 5);
				if(random == Givehw){lec[i].giveHW();}
				else if(random == Givelesson){lec[i].giveLesson();}
				else if(random == Lecsuccessfull){lec[i].seeSuccessfulStudent();}
				else if(random == Lectea){lec[i].drinkTea();}
				else if(random == Lecpetition){lec[i].submitPetition();}
			}
		}		
	}

	for(unsigned int i=0; i<researcher.size(); i++){
		if(researcher[i].isEmployee()){
			for(int j=0; j<5; j++){
				ResarcherFunctions random = static_cast<ResarcherFunctions>(rand() % 5);
				if(random == Readhw){researcher[i].readHW();}
				else if(random == Research){researcher[i].research();}
				else if(random == Researchersuccessfull){researcher[i].seeSuccessfulStudent();}
				else if(random == Researchertea){researcher[i].drinkTea();}
				else if(random == Researcherpetition){researcher[i].submitPetition();}
			}
		}
	}

	for(unsigned int i=0; i<offic.size(); i++){
		if(offic[i].isEmployee()){
			for(int j=0; j<5; j++){
				OfficerFunctions random = static_cast<OfficerFunctions>(rand() % 4);
				if(random == Makedoc){offic[i].makeDoc();}
				else if(random == Officerprocess){offic[i].manageProcess();}
				else if(random == Officertea){offic[i].drinkTea();}
				else if(random == Officerpetition){offic[i].submitPetition();}
			}
		}
	}

	for(unsigned int i=0; i<sec.size(); i++){
		if(sec[i].isEmployee()){
			for(int j=0; j<5; j++){
				SecretaryFunctions random = static_cast<SecretaryFunctions>(rand() % 4);
				if(random == Receivepetition){sec[i].receivePetition();}
				else if(random == Secprocess){sec[i].manageProcess();}
				else if(random == Sectea){sec[i].drinkTea();}
				else if(random == Secpetition){sec[i].submitPetition();}
			}
		}
	}

	delete uni;

	return 0;
}