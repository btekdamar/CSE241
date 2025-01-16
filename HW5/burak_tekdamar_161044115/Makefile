obj = main.o university.o employee.o academicpersonnel.o administrativepersonnel.o lecturer.o officer.o researchassistant.o secretary.o

output : $(obj)
	g++ -g -Wno-deprecated -std=c++11 -ansi -pedantic -Wall $(obj) -o output

main.o : main.cpp
	g++  -g -Wno-deprecated -std=c++11 -c main.cpp

%.o : %.cpp %.h
	g++  -g -Wno-deprecated -std=c++11 -c $<

clean :
	rm *.o output
