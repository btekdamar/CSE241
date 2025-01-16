#ifndef libuni_h
#define libuni_h

#include <iostream>
#include <string>
#include "educationsystem.h"
#include "university.h"

class LibUni : public University{
	public:
		LibUni();
		virtual T contribute(T num);
		virtual void start();
		virtual Employee employ();
}

#endif