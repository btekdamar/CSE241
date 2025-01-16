obj = main.o YOK.o University.o Complex.o Employee.o Lecturer.o Officer.o Researchassistant.o Secretary.o

output : $(obj)
	g++ -g -Wno-deprecated -std=c++11 -ansi -pedantic -Wall $(obj) -o output

main.o : main.cpp
	g++  -g -Wno-deprecated -std=c++11 -c main.cpp

%.o : %.cpp %.h
	g++  -g -Wno-deprecated -std=c++11 -c $<

clean :
	rm *.o output
