
calculate: main.o generator.o graph.o
	g++ -o calculate generator.o main.o graph.o

generator.o: generator.cpp generator.h
	g++ -c generator.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

main.o: main.cpp generator.h graph.h 
	g++ -c main.cpp



clean:
	rm main.o
	rm generator.o
	rm calculate