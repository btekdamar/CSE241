#ifndef university_h
#define university_h

#include <iostream>
#include <string>

using namespace std;

enum UniType{research, linguistic, technical};

template <class T>

class University{
	public:
		University(){}
		University(string nm);
		T contribute(T num);
		string getName(){return name;}
		void setCont(T num){cont = num;}
	protected:
		T cont;
		string name;
};

#endif