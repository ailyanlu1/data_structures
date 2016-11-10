
#ifndef MAZE_H_EXISTS
#define MAZE_H_EXISTS

#include "cell.h"
#include "linkedlist.h"

/**************/
/*** maze.h ***/
/**************/

class Maze{
private:
    std::string file;
    int columns;
    int rows;
    Cell** scroll;
    LinkedList path;
    int pathLength;
    
public:
    // CONSTRUCTOR / DECONSTRUCTOR
    Maze();
    Maze(std::string);
    ~Maze();
    
    // GETTERS / SETTERS
    int getRow();
    int getCol();
    Cell** getScroll();
    // OTHER PUBLIC METHODS
    
        // FOR BASELINE PROJECT
    void readMaze();
    void printPath();
    void DFS();
    
};


#endif /* defined(____maze__) */
