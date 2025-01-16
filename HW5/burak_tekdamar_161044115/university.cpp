#include <iostream>
#include <string>
#include "university.h"

using namespace std;

University::University():contribution(0){}
void University::addContribution(int num){
	contribution+=num;
}