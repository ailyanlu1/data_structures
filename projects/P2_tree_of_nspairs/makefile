NSProject: NSPair.o BST.o main.o
	g++ NSPair.o BST.o main.o -o NSProject
    
NSPair.o: NSPair.cpp NSPair.h
	g++ -c NSPair.cpp -o NSPair.o
BST.o: BST.cpp BST.h NSPair.cpp NSPair.h
	g++ -c BST.cpp -o BST.o
main.o: main.cpp NSPair.h BST.h
	g++ -c main.cpp -o main.o
