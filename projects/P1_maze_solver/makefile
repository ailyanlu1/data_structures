MazeProject: linkedlist.o cell.o maze.o stack.o main.o
	g++  linkedlist.o cell.o maze.o stack.o main.o -o MazeProject

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c linkedlist.cpp -o linkedlist.o
cell.o: cell.cpp cell.h
	g++ -c cell.cpp -o cell.o
maze.o: maze.cpp maze.h cell.h linkedlist.h
	g++ -c maze.cpp -o maze.o
stack.o: stack.cpp stack.h
	g++ -c stack.cpp -o stack.o
main.o: main.cpp maze.h
	g++ -c main.cpp -o main.o