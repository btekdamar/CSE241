#ifndef comuni_h
#define comuni_h

#include <iostream>
#include <string>
#include "educationsystem.h"
#include "university.h"

class ComUni : public University{
	public:
		ComUni();
		virtual T contribute(T num);
		virtual void start();
		virtual Employee employ();
}

#endif