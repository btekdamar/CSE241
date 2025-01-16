#ifndef university_h
#define university_h

#include <iostream>

class University{
	public:
		University();
		void addContribution(int num);
		int getContribution(){return contribution;}
	protected:
		int contribution;
	
};

#endif