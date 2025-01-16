#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "YOK.h"
#include "YOK.cpp"
#include "University.h"
#include "Employee.h"
#include "Complex.h"
#include "Lecturer.h"
#include "Researchassistant.h"
#include "Secretary.h"
#include "Officer.h"

using namespace std;

int main(){
	srand(time(NULL));

	vector<string> name;
	vector<string> surname;
	string nm, srnm;
	int random1, random2, count1 = 0, count2 = 0, i = 0;
	EmployeeType type;
	YOK yuksekOgretimKurumu;
	vector<Employee*> emps1;
	vector<Employee*> emps2;
	vector<Employee*> emps3;
	bool control = true;
	Complex com;
	Complex com1;

	ifstream readFile;

	readFile.open("personnellist.txt");

	while(!readFile.eof()){
		readFile >> nm;
		readFile >> srnm;
		name.push_back(nm);
		surname.push_back(srnm);
		count2++;
	}
	readFile.close();

	University<double> univ1 = yuksekOgretimKurumu.buildUniversity<double>(linguistic);
	University<int> univ2 = yuksekOgretimKurumu.buildUniversity<int>(research);
	University<Complex> univ3 = yuksekOgretimKurumu.buildUniversity<Complex>(technical);
	cout  << endl << "------------------------------- Give employee to " << univ1.getName() << " -------------------------------" << endl << endl;
	do{
		type = static_cast<EmployeeType>(rand()%4);
		cout << univ1.getName() << " requests ";

		if(type == LecturerType){
			cout << "Lecturer" << endl;
			emps1.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		else if(type == OfficerType){
			cout << "Officer" << endl;
			emps1.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type)); 
		}
		else if(type == ResearchAssistantType){
			cout << "ResearchAssistant" << endl;
			emps1.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		else if(type == SecretaryType){
			cout << "Secretary" << endl;
			emps1.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		count1++;
		i++;
	}while(count1<10);
	cout << endl << "------------------------------- Give employee to " << univ2.getName() << " -------------------------------" << endl << endl;
	count1 = 0;
	do{
		type = static_cast<EmployeeType>(rand()%4);
		cout << univ2.getName() << " requests ";

		if(type == LecturerType){
			cout << "Lecturer" << endl;
			emps2.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		else if(type == OfficerType){
			cout << "Officer" << endl;
			emps2.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type)); 
		}
		else if(type == ResearchAssistantType){
			cout << "ResearchAssistant" << endl;
			emps2.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		else if(type == SecretaryType){
			cout << "Secretary" << endl;
			emps2.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		count1++;
		i++;
	}while(count1<10);
	cout << endl << "------------------------------- Give employee to " << univ3.getName() << " -------------------------------" << endl << endl;
	count1 = 0;
	do{
		type = static_cast<EmployeeType>(rand()%4);
		cout << univ3.getName() << " requests ";

		if(type == LecturerType){
			cout << "Lecturer" << endl;
			emps3.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		else if(type == OfficerType){
			cout << "Officer" << endl;
			emps3.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type)); 
		}
		else if(type == ResearchAssistantType){
			cout << "ResearchAssistant" << endl;
			emps3.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		else if(type == SecretaryType){
			cout << "Secretary" << endl;
			emps3.push_back(yuksekOgretimKurumu.giveJob(name[i], surname[i], type));
		}
		count1++;
		i++;
	}while(count1<10);
	cout << endl << "----------------------------- Actions for University<int> -----------------------------" << endl << endl;
	univ2.setCont(0);
	for(int i = 0; i<emps1.size(); i++){
		while(emps1[i]->getCount()<5){
			Action random = static_cast<Action>(rand() % 12);
			emps1[i]->work(random);
			if(random == MakeDoc && emps1[i]->getEmpType() == "Officer") cout << univ2.contribute(5) << endl;
			else if(random == DrinkTea)cout << univ2.contribute(-2) << endl;
			else if(random == Research && emps1[i]->getEmpType() == "researchAssistant")cout << univ2.contribute(4) << endl;
			else if(random == GiveLesson && emps1[i]->getEmpType() == "Lecturer") cout << univ2.contribute(5) << endl;
			else if(random == MakePublish && (emps1[i]->getEmpType() == "Lecturer" || emps1[i]->getEmpType() == "researchAssistant"))cout << univ2.contribute(5) << endl;
			else if(random == ManageProcess && (emps1[i]->getEmpType() == "Officer" || emps1[i]->getEmpType() == "Secretary"))cout << univ2.contribute(2) << endl;
			else if(random == GiveHW && emps1[i]->getEmpType() == "Lecturer")cout << univ2.contribute(1) << endl;
			else if(random == ReadHW && emps1[i]->getEmpType() == "researchAssistant")cout << univ2.contribute(2) << endl;
			else if(random == ReceivePetition && emps1[i]->getEmpType() == "Secretary")cout << univ2.contribute(-1) << endl;
			else if(random == SubmitPetition)cout << univ2.contribute(-2) << endl;
			else if(random == SeeSuccessfullStudent && (emps1[i]->getEmpType() == "Lecturer" || emps1[i]->getEmpType() == "researchAssistant"))cout << univ2.contribute(0) << endl;
		}
	}
	cout << endl << "----------------------------- Actions for University<double> -----------------------------" << endl << endl;
	univ1.setCont(0.0);
	for(int i = 0; i<emps2.size(); i++){
		while(emps2[i]->getCount()<5){
			Action random = static_cast<Action>(rand() % 12);
			emps2[i]->work(random);
			if(random == MakeDoc && emps2[i]->getEmpType() == "Officer") cout << univ1.contribute(5.4) << endl;
			else if(random == DrinkTea) cout << univ1.contribute(-2.7) << endl;
			else if(random == Research && emps2[i]->getEmpType() == "researchAssistant")cout << univ1.contribute(4.1) << endl;
			else if(random == GiveLesson && emps2[i]->getEmpType() == "Lecturer") cout << univ1.contribute(5.2) << endl;
			else if(random == MakePublish && (emps2[i]->getEmpType() == "Lecturer" || emps2[i]->getEmpType() == "researchAssistant"))cout << univ1.contribute(5.2) << endl;
			else if(random == ManageProcess && (emps2[i]->getEmpType() == "Officer" || emps2[i]->getEmpType() == "Secretary"))cout << univ1.contribute(2.9) << endl;
			else if(random == GiveHW && emps2[i]->getEmpType() == "Lecturer")cout << univ1.contribute(1.0) << endl;
			else if(random == ReadHW && emps2[i]->getEmpType() == "researchAssistant")cout << univ1.contribute(2.2) << endl;
			else if(random == ReceivePetition && emps2[i]->getEmpType() == "Secretary")cout << univ1.contribute(-1.4) << endl;
			else if(random == SubmitPetition)cout << univ1.contribute(-2.6) << endl;
			else if(random == SeeSuccessfullStudent && (emps2[i]->getEmpType() == "Lecturer" || emps2[i]->getEmpType() == "researchAssistant"))cout << univ1.contribute(0.0) << endl;
		}
	}
	cout << endl << "----------------------------- Actions for University<Complex> -----------------------------" << endl << endl;

	for(int i = 0; i<emps3.size(); i++){
		while(emps3[i]->getCount()<5){
			Action random = static_cast<Action>(rand() % 12);
			emps3[i]->work(random);
			if(random == MakeDoc && emps3[i]->getEmpType() == "Officer"){ 
				com.setNum(5);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == DrinkTea){
				com.setNum(-2.7); 
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == Research && emps3[i]->getEmpType() == "researchAssistant"){
				com.setNum(3);
				com1 = univ3.contribute(com); 
				cout << com1 << endl;}
			else if(random == GiveLesson && emps3[i]->getEmpType() == "Lecturer"){
				com.setNum(-2);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == MakePublish && (emps3[i]->getEmpType() == "Lecturer" || emps3[i]->getEmpType() == "researchAssistant")){
				com.setNum(10);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == ManageProcess && (emps3[i]->getEmpType() == "Officer" || emps3[i]->getEmpType() == "Secretary")){
				com.setNum(3.5);
				com1 = univ3.contribute(com); 
				cout << com1 << endl;}
			else if(random == GiveHW && emps3[i]->getEmpType() == "Lecturer"){
				com.setNum(2.1);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == ReadHW && emps3[i]->getEmpType() == "researchAssistant"){
				com.setNum(-4);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == ReceivePetition && emps3[i]->getEmpType() == "Secretary"){
				com.setNum(1.1);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == SubmitPetition){
				com.setNum(-2);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
			else if(random == SeeSuccessfullStudent && (emps3[i]->getEmpType() == "Lecturer" || emps3[i]->getEmpType() == "researchAssistant")){
				com.setNum(5);
				com1 = univ3.contribute(com);
				cout << com1 << endl;}
		}
	}
}