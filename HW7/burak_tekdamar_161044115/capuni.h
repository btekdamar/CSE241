#ifndef capuni_h
#define capuni_h

#include <iostream>
#include <string>
#include "educationsystem.h"
#include "university.h"

class CapUni : public University{
	public:
		CapUni();
		virtual T contribute(T num);
		virtual void start();
		virtual Employee employ();
}

#endif