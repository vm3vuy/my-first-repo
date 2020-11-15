
CROSSGCC = g++ -std=c++14
#CROSSGCC = clang++ -std=c++14


.PHONY: all clean cleanOut

#main.cpp為主程式，lib.h lib.cpp 為函式庫
all: main.cpp lib.h lib.cpp 
	$(CROSSGCC) -Wall -c main.cpp
	$(CROSSGCC) -Wall -c lib.cpp
	$(CROSSGCC) -Wall -o myApp.out main.o lib.o


clean:
	rm -f  *.o 

cleanOut:
	rm -f  *.out  *.o 









