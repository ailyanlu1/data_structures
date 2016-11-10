#include <iostream>
#include <stack>
#include <fstream>
#include "maze.h"
#include "stack.h"
using namespace std;

/****************/
/*** main.cpp ***/
/****************/

int main(int argc, const char * argv[])
{
    
    Maze maze("maze2.txt");
    maze.DFS();
    maze.printPath();
    
    //just a little test comment
    return 0;
}

