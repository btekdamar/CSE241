#include "University.h"

using namespace std;

template <class T>
University<T>::University(string nm){name = nm;}

template <class T>
T University<T>::contribute(T num){
	cont = cont + num;
	return cont;
}

