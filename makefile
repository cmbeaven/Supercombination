
main: 
	clang++ -o calculate generator.cpp graph.cpp main.cpp

debug:
	clang++ -o calculate -D DEBUG generator.cpp graph.cpp main.cpp

clean:
	rm calculate
