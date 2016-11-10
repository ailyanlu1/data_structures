
#ifndef CELL_H_EXISTS
#define CELL_H_EXISTS

/**************/
/*** cell.h ***/
/**************/

class Cell{
private:
    int walls[4];
    int row;
    int column;
    bool visited;
    
public:
    // CONSTRUCTOR / DECONSTRUCTOR
    Cell();
    Cell(int north, int south, int west, int east);
    ~Cell();
    
    // GETTERS / SETTERS
    int* getWalls();
    void setVisited(bool);
    bool getVisited();
    void setRow(int);
    int getRow();
    void setCol(int);
    int getCol();

};

#endif /* defined(____cell__) */
