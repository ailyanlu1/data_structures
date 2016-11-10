
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
#include "cell.h"
using namespace std;

/****************/
/*** cell.cpp ***/
/****************/

Cell::Cell(){
    
    // INTIALIZE BRICKS
    Cell::walls[0] = 1;
    Cell::walls[1] = 1;
    Cell::walls[2] = 1;
    Cell::walls[3] = 1;
    Cell::visited = false;
}

//OVERLOADED CONSTRUCTOR
Cell::Cell(int w1, int w2, int w3, int w4){
    Cell::walls[0] = w1;
    Cell::walls[1] = w2;
    Cell::walls[2] = w3;
    Cell::walls[3] = w4;
}

Cell::~Cell(){
    //just in case
}

//GETTERS / SETTERS
void Cell::setVisited(bool){
    Cell::visited = true;
}

bool Cell::getVisited(){
    return Cell::visited;
}

int* Cell::getWalls(){
    return Cell::walls;
}

void Cell::setRow(int temp){
    Cell::row = temp;
}

int Cell::getRow(){
    return Cell::row;
}

void Cell::setCol(int temp){
    Cell::column = temp;
}

int Cell::getCol(){
    
    return Cell::column;
}




