install: main


main.o: main.cpp
	clang++ -c main.cpp $(TH)
