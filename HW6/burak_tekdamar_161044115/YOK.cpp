#include "YOK.h"

using namespace std;

template <typename T>

University<T> YOK::buildUniversity(UniType type){
	string nameUni;
		if(type == linguistic)
			nameUni = "İstanbul Üniversitesi";
		else if(type == research)
			nameUni = "Marmara Üniversitesi";
		else if(type == technical)
			nameUni = "Gebze Teknik Üniversitesi";

		University<T> uni1(nameUni);

		return uni1;
}
