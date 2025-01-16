#ifndef complex_h
#define complex_h

#include <iostream>
#include <string>
#include "University.h"

using namespace std;

class Complex{
	public:
		Complex():numInt(0), numDouble(0), sum(0){}
		Complex(double num):sum(num){}
		Complex& operator =(const Complex &newComplex);
		Complex& operator ++();
		Complex operator ++(int);
		Complex& operator +(const Complex &comp);
		Complex& operator -(const Complex &comp);
		void setNum(double num){numDouble = num; numInt = 0;}
		void setNum(int num){numInt = num; numDouble = 0;}
		friend ostream& operator <<(ostream& outputStream, Complex& com);
	private:
		int numInt;
		double numDouble, sum;
};

#endif