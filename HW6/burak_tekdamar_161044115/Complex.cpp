#include <iostream>
#include <string>
#include "University.h"
#include "Complex.h"

using namespace std;

Complex& Complex::operator +(const Complex &comp){
	if(comp.numInt!=0)
		this->sum += comp.numInt;
	else
		this->sum += comp.numDouble;
	return *this;
}
Complex& Complex::operator -(const Complex &comp){
	if(comp.numInt!=0)
		this->sum -= comp.numInt;
	else
		this->sum -= comp.numDouble;
	return *this;
}

Complex& Complex::operator =(const Complex &newComplex){
	this->sum = newComplex.sum;
	return *this;
}

Complex& Complex::operator ++(){
	this->sum++;
	return *this;
}

Complex Complex::operator ++(int){
	double temp;
	temp = this->sum;
	this->sum++;
	return Complex(temp);
}

ostream& operator <<(ostream& outputStream, Complex& com){
	outputStream << com.sum;
	return outputStream;
}