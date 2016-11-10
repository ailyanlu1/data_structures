
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "maze.h"
#include "stack.h"
using namespace std;

//Define Macros
#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3

/****************/
/*** maze.cpp ***/
/****************/

Maze::Maze(){
}

Maze::Maze(string str){
    string tempstr = str.c_str();
    Maze::file = tempstr;
    Maze::readMaze();
}

Maze::~Maze(){
    //successful desconstruction
    cout << "Goodbye, cruel world." << endl;
    delete Maze::scroll;
}

Cell** Maze::getScroll(){
    return Maze::scroll;
}

int Maze::getRow(){ //easy access instead of returning int* with getWalls()
    return Maze::rows;
}

int Maze::getCol(){ //easy access instead of returning int* with getWalls()
    return Maze::columns;
}

//INITIALIZING THE SCROLL
void Maze::readMaze(){
    
    //create input filestream object
    ifstream mazeFile;
    mazeFile.open(Maze::file.c_str());
    
    //temp members used for storing data
    string line;
    int size[2];
    int info[6];
    
    //temp members used for manipulating text with spaces
    string delimiter = " ";
    size_t pos = 0;
    string token;
    
    getline(mazeFile, line);
    int i = 0;
    //resource:
    /*
     http://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
     */
    
    //each iteration create a new position and set it equal to the position of the delimiter in my line of text, and as long as that is not equal to the greatest possible value of a size_t, keepGoing, which in translation means go until you cant go anymore with my line and create little tokens along the way for each iteration through the line with ' ' as the delimiter. This and the preceeding lines cover JUST THE BASE CASE of this search. Inside of my preceeding while loop we cycle through all but the first line.
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0,pos);
        line.erase(0, pos+ delimiter.length());
        int temp = atoi(token.c_str());
        size[i] = temp;
        i++;
    }
    
    int temp = atoi(line.c_str());
    size[1] = temp;
    
    Maze::rows = size[0];
    Maze::columns = size[1];
    
    //dynamically create a 2d array
    Maze::scroll = new Cell*[Maze::columns];
    for (int i = 0; i < columns; ++i) {
        scroll[i] = new Cell[Maze::rows];
    }
    
    //give equal treatment to the rest of the file as we did to the first line of the file listed on line 72 (the last while loop), this time just populate info instead of size. after each iteration this time i want to take the info/data that i pulled from the last 4 chars and place that into a custom cell with a custom constructor to set its walls purposefully. Then drop that custom cell (with its row and col) into the scroll, which is my matrix of cells.
    while (!mazeFile.eof()) {
        getline(mazeFile, line);
        pos = 0;
        int i = 0;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0,pos);
            line.erase(0, pos + delimiter.length());
            int temp = atoi(token.c_str());
            info[i] = temp;
            i++;
        }
        int temp = atoi(line.c_str());
        info[5] = temp;
        
        //give the scroll that custom cell at that custom location
        Cell tempCell = Cell(info[2], info[3], info[4], info[5]);
        tempCell.setRow(info[0]);
        tempCell.setCol(info[1]);
        scroll[tempCell.getCol()][tempCell.getRow()] = tempCell;
    }
    mazeFile.close();
}
// GENERATING THE MAZE
void Maze::DFS(){
    
    //create a worst case scenario stack
    Stack ricky(Maze::rows * Maze::columns);
    //pathLength = 0;
    
    //set my initial cell to visited,push,and begin this algorithm.
    Maze::scroll[0][0].setVisited(true);
    ricky.push(Maze::scroll[0][0]);
    
    pathLength = ricky.getLength();
    
    
    //This while loop asks if we are at the last cell in the maze (m-1,n-1) and if we are NOT then we proceed. First by using a currentCell object to trace our way around the maze. I have to test my boundaries to see if I am actually allowed to move there because I was getting uncountable amounts of segmentation faults and errors due to my error of not respecting boundaries, therefore, this boundary 'isAllowed..." simply tells me if I am able to advance to the next cell I am desiring to go to. Thus, hopping into the algorithm, check my currentCells east wall to see if its open, and if my neighbor has not been visited, AND finally assuming it is allowed to go east, if the first two are true and the last is true, progress in marking the cell visited and adding that new cell to my scroll. I wrote up a general case for all existing posibilities (north, south, west, and east) so placing them on the map would be easier. Repeat this process for every case that this is good, and for the case that my criteria is not met, I assume I must be in a wall, so pop() out and check again for new options east,south,west,north is the order of preferrence I chose. I push on the cell to a stack everytime I progress through the maze.
    
    //is it the last cell? If not, GO!
    while (!((ricky.top().getRow() == Maze::rows-1)
             and
             (ricky.top().getCol() == Maze::columns-1)
             )){
        
        //create current cell
        Cell currentCell = ricky.top();
        int* currentWalls = currentCell.getWalls();
        
        //access into surrounding cells
        bool isAllowedNorth = false;
        bool isAllowedSouth = false;
        bool isAllowedWest = false;
        bool isAllowedEast = false;
        
        //determine whether or not the cell I want to go to actually exists
        if(currentCell.getRow() - 1 > -1){
            isAllowedNorth = true;
        }
        if(currentCell.getRow() + 1 < Maze::rows){
            isAllowedSouth = true;
        }
        if(currentCell.getCol() - 1 > - 1){
            isAllowedWest = true;
        }
        if(currentCell.getCol() + 1 < Maze::columns){
            isAllowedEast = true;
        }
        
        //if my east wall is open, my one cell right has NOT been visited, and it is a valid cell..
            //..mark it as visited and push it on the stack
        if ((currentWalls[EAST] == 0)
            and
            (Maze::scroll[currentCell.getCol() + 1][currentCell.getRow()].getVisited() == false)
            and
            (isAllowedEast)
            ){
            //cout << "inside east" << endl;
            Maze::scroll[currentCell.getCol() + 1][currentCell.getRow()].setVisited(true);
            
            ricky.push(Maze::scroll[currentCell.getCol() + 1][currentCell.getRow()]);
        }
        
        //if my south wall is open, my one cell down has NOT been visited, and it is a valid cell..
            //..mark it as visited and push it on the stack
        else if((currentWalls[SOUTH] == 0)
                and
                (Maze::scroll[currentCell.getCol()][currentCell.getRow() + 1].getVisited() == false)
                and
                (isAllowedSouth)
                ){
            //cout << "inside south" << endl;
            Maze::scroll[currentCell.getCol()][currentCell.getRow() + 1].setVisited(true);
            
            ricky.push(Maze::scroll[currentCell.getCol()][currentCell.getRow() + 1]);
        }
        
        //if my west wall is open, my one cell left has NOT been visited, and it is a valid cell..
            //..mark it as visited and push it on the stack
        else if((currentWalls[WEST] == 0)
                and
                (Maze::scroll[currentCell.getCol() - 1][currentCell.getRow()].getVisited() == false)
                and
                (isAllowedWest)
                ){
            //cout << "inside west" << endl;
            Maze::scroll[currentCell.getCol() - 1][currentCell.getRow()].setVisited(true);
            
            ricky.push(Maze::scroll[currentCell.getCol() - 1][currentCell.getRow()]);
        }
        //if my east north is open, my one cell up has NOT been visited, and it is a valid cell..
            //..mark it as visited and push it on the stack
        else if((currentWalls[NORTH] == 0)
                and
                (Maze::scroll[currentCell.getCol()][currentCell.getRow() - 1].getVisited() == false)
                and
                (isAllowedNorth)
                ){
            //cout << "inside north" << endl;
            Maze::scroll[currentCell.getCol()][currentCell.getRow() - 1].setVisited(true);
            
            ricky.push(Maze::scroll[currentCell.getCol()][currentCell.getRow() - 1]);
        }
        
        else{
            //if all else fails, I assume I have hit a wall. So pop it form the stack and repeat the while loop.
            ricky.pop();
            
        }

        //my only print statement to test any file you input
        //should print out row-1 " " col-1 if successful
        cout <<ricky.top().getCol() << "\t" << ricky.top().getRow() << endl;
    }
    
    // POPULATE LINKED LIST WITH THE EXISTING DATA FROM MY ALGORITHM
    Cell* temp = ricky.getList();
    pathLength = ricky.getLength();
    for (int j = 0; j < pathLength; j++) {
        path.insertCell(temp[j]);
    }
}

// PRINTING THE PATH TO A TEXT FILE
void Maze::printPath(){
    
    //basic output filestream object, unfortunately it must be converted to a c-based string first, so I convert my fileName to is inside of the object perameter.
    string file = "path.txt";
    ofstream pathFile (file.c_str());
    
    //the most general and accepted way to output basic text into a .txt file.
    if (pathFile.is_open()) {
        Cell temp = path.getStartData();
        cout << temp.getCol() << temp.getRow() << endl;
        for (int i = 0; i < pathLength; i++) {
            pathFile << path.getStartData().getRow() << " " << path.getStartData().getCol() << endl;
            path.deleteCell(path.getStartData());
        }
    }
    pathFile.close();
}





