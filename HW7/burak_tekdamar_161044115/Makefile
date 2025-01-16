obj = main.o educationsystem.o capitalisteducation.o communisteducation.o comlec.o comoff.o university.o employee.o lecturer.o officer.o researchassistant.o secretary.o capuni.o comresassist.o comsec.o comuni.o liberaleducation.o liblec.o liboff.o libresassist.o libsec.o libuni.o

output : $(obj)
	g++ -g -Wno-deprecated -std=c++11 -ansi -pedantic -Wall $(obj) -o output

main.o : main.cpp
	g++  -g -Wno-deprecated -std=c++11 -c main.cpp

%.o : %.cpp %.h
	g++  -g -Wno-deprecated -std=c++11 -c $<

clean :
	rm *.o output