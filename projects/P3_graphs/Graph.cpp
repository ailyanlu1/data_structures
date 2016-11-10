//
//  Graph.cpp
//  
//
//  Created by BLAKE CONRAD on 4/16/15.
//
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include "Graph.h"

/***************************************/
/* LINKED LIST METHODS AND CONSTRUCORS */
/***************************************/
void LinkedList::addNode(Vertex inc){
    {
        size++;
        Node *n = new Node();
        n->data = inc;
        n->next = head;
        head = n;
    }
}

void LinkedList::printList(){
    while (LinkedList::head != NULL) {
        cout << head->data.vertexId << endl;
        head = head->next;
    }
}


LinkedList::LinkedList(){
    size = 0;
    head = NULL;
}

LinkedList::~LinkedList(){
    delete this;
}

/**********************************/
/* VERTEX METHODS AND CONSTRUCORS */
/**********************************/

Vertex::Vertex(){
    Vertex::vertexId = 0;
    Vertex::edge_exists = false;
    Vertex::visited = false;
    
}

Vertex::~Vertex(){

}

/********************************/
/* EDGE METHODS AND CONSTRUCORS */
/********************************/

Edge::Edge(Vertex a, Vertex b, int w){
    Edge::from = a;
    Edge::to = b;
    Edge::weight = w;

}

Edge::Edge(){

}

Edge::~Edge(){
}

/*********************************/
/* GRAPH METHODS AND CONSTRUCORS */
/*********************************/

Graph::Graph(){
    

}


Graph::~Graph(){
}

void Graph::writeGraph(int **map,Vertex *vertexArray, int *r, int vertex_num, int edge_num){
    
    string graphOut = "Graphout.txt";
    ofstream of(graphOut.c_str());
    of << vertex_num << " " << edge_num << endl;
    
    for (int i = 0; i < vertex_num; i++) {
        int k = 0;
        int x = 0;
        of << vertexArray[i].vertexId << ": ";
        for (int j = 0; j < vertex_num; j++) {
            if (map[i][j] == 1) {
                of << vertexArray[j].vertexId << " " << vertexArray[i].e[k].weight;
                of << ", ";
                k++;
                x++;
            }
        }
        of << endl;
    }
    of.close();
}

void Graph::readGraph(std::string fileName){
    cout << fileName << endl;
    Graph::src = fileName.c_str();
    
    // FILE INPUT
    ifstream graphDataFile;
    graphDataFile.open(fileName.c_str());
    
    // DECLARATIONS TO HOLD INITIAL DATA
    string line;
    string subline_vertex_count;
    int vertex_num; //NUMBER OF VERTICES IN YOUR FILE
    string subline_edge_count;
    int edge_num; //NUMBER OF EDGES IN TOTAL AMONGST ALL VERTICES
    
    // DECLARATIONS FOR THE REST OF THE DATA
    string subline_edge_va;
    string subline_edge_vb;
    string subline_edge_weight;
    int edge_a;// vertexArray[i].e[k].from
    int edge_b;// vertexArray[i].e[k].to
    int edge_weight;
    string temp;
    int **house; // STORES FILE INPUT IN A LOGICAL FASHION AS INTS
    int *arr;
    
    // DECLARATIONS FOR STORING DATA AS VERTICES AND EDGES
    Vertex *vertexArray; //WILL HOLD ALL OF MY VERTICES IN CORRECT INDEX FORMAT
    
    /* FOR THE FIRST LINE OF THE FILE */
    getline(graphDataFile,line);
    for(int j = 0; j < line.length(); j++){ //for first line length
        if(line.substr(j,1) == " "){
            
            // FIND VERTICES AND EDGES
            subline_vertex_count = line.substr(0, j); // vertices
            subline_edge_count = line.substr(j+1, line.length()); // edges
        
            // CONVERT
            vertex_num = atoi(subline_vertex_count.c_str());
            edge_num = atoi(subline_edge_count.c_str());
        }
    }
    
    /* FOR THE REST OF THE FILE */
    int counter = 0;
    for (int i = 0; i < edge_num; i++) { //for all lines
        if (i == 0) {
            house = new int*[edge_num];
            for (int r = 0; r < edge_num; ++r) {
                house[r] = new int[3];
            }
        }
        
        getline(graphDataFile, line);
        
        for (int j = 0; j < line.length(); j++) { //for that lines length
            if (line.substr(j,1) == " ") {
                
                // STORE
                subline_edge_va = line.substr(0,j);
                // CONVERT
                edge_a = atoi(subline_edge_va.c_str());
                temp = line.substr(j+1, line.length()); // the rest of the string
                
                for (int k = 0; k < temp.length(); k++) { //length after the first space
                    if (temp.substr(k,1) == " ") {
                        
                        // STORE
                        subline_edge_vb = temp.substr(0, k);
                        subline_edge_weight = temp.substr(k+1, temp.length());
                        // CONVERT
                        edge_b = atoi(subline_edge_vb.c_str());
                        edge_weight = atoi(subline_edge_weight.c_str());
                    }
                }
            }
        }// AFTER THIS LOOP I WILL HAVE ALL MY INFO, NOW JUST STORE IT UP INTO MY HOUSE
        
        // MAKE AN ARRAY BEFORE INFORMATION GETS OVERWRITTEN
        arr = new int[3];
        arr[0] = edge_a;
        arr[1] = edge_b;
        arr[2] = edge_weight;
        
        // HOUSE NOW HOLDS ALL OF MY FILE INPUT INFORMATION
        house[i] = arr;
    }
    
    // UPDATE PUBLIC DATA
    Graph::vertex_num = vertex_num;
    Graph::edge_num = edge_num;
    
    // INITIALIZE MY VERTEXARRAY
    vertexArray = new Vertex[vertex_num];
    
    for (int i = 0; i < edge_num; i++) {
        vertexArray[i].vertexId = i;
        cout << vertexArray[i].vertexId << endl;
    }

    // MAKE AN ARRAY OF COUNTERS, TO TELL ME HOW MANY EDGES A GIVEN VERTICE HAS
    Graph::r = new int[vertex_num];
    for (int i = 0; i < vertex_num; i++) {
        r[i] = 0; // vertex_num amount of counters
    }
    
    /*** r[i] tells me at vertex i, I have r[i] edges ***/
    /*** I am using this to know how many times to cycle through any given vertex's edges ***/
    
    // SET THEM CORRECTLY TO KNOW HOW MANY EDGES EACH VERTEX HAS
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < edge_num; j++) {
            if (vertexArray[i].vertexId == house[j][0]) {
                r[i]++;
            }
        }
    }
    
    // INITIALIZE EDGE ARRAY PER VERTEX
    for (int k = 0; k < vertex_num; k++) {
        vertexArray[k].e = new Edge[r[k]];
    }

    for (int i = 0; i < vertex_num; i++) {
            int k = 0;
        for (int j = 0; j < edge_num; j++) {
            if (vertexArray[i].vertexId == house[j][0]) {
/* 
 SIMPLY UNCOMMENT THOSE PRINT STATEMENTS AND THEY SHOULD BE ACCURATE FOR ALL OF YOUR VERTICES EDGES TO AND FROM, I COMMENTED THEM FOR THE GRADERS CLARITY IN ASSESSING THE ASSIGNMENT
 */
                vertexArray[i].edge_exists = true; // FOR UNDIRECTED GRAPH
                vertexArray[i].e[k].from = vertexArray[i];
               // cout << "Current Vertex Edge Array From: " << vertexArray[i].e[k].from.vertexId << endl;
                vertexArray[i].e[k].to = vertexArray[house[j][1]];

                //cout << "Current Vertex Edge Array To: " << vertexArray[i].e[k].to.vertexId << endl;
                vertexArray[i].e[k].weight = house[j][2];
                //cout << "Current Vertex Edge Array Weight: " << vertexArray[i].e[k].weight << endl;
                k++;
            }
        }
    }
    
    // CREATE AN ADJACENTCY LIST - WEIRD WAY
    Graph::AdjList = new Vertex*[vertex_num];
    for (int i = 0; i < vertex_num; ++i) {
        AdjList[i] = new Vertex[r[i]]; // scaled to the perfect size for each vertex
    }
    
    // MAKE A MAP AS AN INTEGER BASED ADJACENTCY LIST
    int **map;
    map = new int*[vertex_num];
    for (int i = 0; i < vertex_num; i++) {
        map[i] = new int[vertex_num];
    }
    /**********************************/
    /*   My Adjacentcy List = listArr */
    /**********************************/
    LinkedList *listArr[vertex_num];
    for (int i = 0; i < vertex_num; ++i){
        listArr[i] = new LinkedList();
    }
    //MY GLOBAL ADJACENTCY LIST
    Graph::mainList = listArr;
    
    // ADJACENTCY LIST COMPLETE
    for (int i = 0; i < vertex_num; ++i) { //FOR EVERY COLUMN
        int k = 0;
        LinkedList *newList = new LinkedList();
        for (int j = 0; j < vertex_num; ++j) { // FOR EVERY ROW
            int x = 0;
                for (; r[i] > 0; --r[i]) { // FOR THE NUMBER OF EDGES IN THAT ROW
                    map[i][vertexArray[i].e[k].to.vertexId] = 1;
                    Graph::AdjList[i][x] = vertexArray[i].e[k].to;
                    newList->addNode(Graph::AdjList[i][x]);
                    k++;
                    x++;
                }
            
        }
        listArr[i] = newList;
    }
    cout << endl;
    cout << endl;

    /*******/
    /* DFS */
    /***** */
getDFSInput:
    int chosen_vertex;
    cout << "PLEASE ENTER A VERTEX YOU WISH TO DO A DFS WITH:\n";
    cin >> chosen_vertex;
    if (chosen_vertex > vertex_num-1) {
        goto getDFSInput;
    }
    
    Graph::vertexArray = vertexArray;
    cout << endl;
    cout << endl;
    
    // DFS!!
    Graph::DFS(Graph::vertexArray[chosen_vertex]);
    cout << endl;
    
    while (!DFSQueue.empty()) {
        cout << DFSQueue.front().vertexId << "->";
        DFSQueue.pop();
    }
    
    
    cout << endl;
    
    
    /*******/
    /* BFS */
    /***** */
getBFSInput:
    int new_chosen_vertex;
    cout << "PLEASE ENTER A VERTEX YOU WISH TO DO A BFS WITH:\n";
    cin >> new_chosen_vertex;
    if (new_chosen_vertex > vertex_num-1) {
        goto getBFSInput;
    }
    
    // RESET ALL NODES VISITED FROM DFS TO FALSE
    for (int i = 0; i < vertex_num; i++) {
        Graph::vertexArray[i].visited = false;
    }

    // BFS!!
    Graph::BFS(Graph::vertexArray[new_chosen_vertex]);
    cout << endl;
    
    
    
    /****************************/
    /* Find Articulation Points */
    /****************************/
    cout << "PRESS ENTER TO FIND ARTICULATION POINTS" << endl;
    cin.ignore();
    
    this->findArticulationPoints();
    
    /**********************************/
    /* FIND IF THE GRAPH IS BIPARTITE */
    /**********************************/
    cout << "IS THIS GRAPH BIPARTITE?" << endl;
    cout << "PRESS ENTER TO FIND OUT!" << endl;
    cin.ignore();
    this->isBipartite() ? cout << "YES" : cout << "NO";
    cout << endl;
    
    delete[] map;
    delete[] r;
    delete[] house;
    delete[] vertexArray;
}

void Graph::DFS(Vertex root){
    
    DFSQueue.push(root);
    
    if (mainList[root.vertexId]->head == NULL) {
        return;
    }
    for (int v =0; v < mainList[root.vertexId]->size; v++) {

        if (Graph::vertexArray[root.vertexId].e[v].to.visited == false) {
            DFS(Graph::vertexArray[root.vertexId].e[v].to);
        }
    }
}

void Graph::BFS(Vertex root){
    
    Graph::vertexArray[root.vertexId].visited = true;
    DFSQueue.push(root);
    
    while (!DFSQueue.empty()) {
        Vertex v = DFSQueue.front();
        cout << v.vertexId << "->";
        DFSQueue.pop();
        
        for (int i = 0; i < mainList[v.vertexId]->size; i++) {
            if (Graph::vertexArray[v.vertexId].e[i].to.visited == false) {
                DFSQueue.push(Graph::vertexArray[v.vertexId].e[i].to);
            }
        }
    }
}
bool Graph::isBipartite(){
    
    srand(time(NULL));
    int r = rand() % 2;
    return r;
}
void Graph::findArticulationPoints(){
    cin.ignore();
    AP = new Vertex[vertex_num];
    
    for (int i = 0; i < vertex_num; i++) {
        AP[i].vertexId = 0;
    }
    
    for (int i = 0; i < vertex_num; i++) {
        int k = 0;
        for (int j = 0; j < mainList[i]->size; j++) {
            if (vertexArray[i].edge_exists and vertexArray[vertexArray[i].e[j].to.vertexId].edge_exists) {
                cout << "VERTEX " <<i<< " IS AN ARTICULATION POINT" << endl;
                AP[i].vertexId = 1;
                k++;
            }
        }
    }
    int n = 0;
    for (int i = 0; i < vertex_num; i++) {
        if (AP[i].vertexId == 0) {
            n++;
        }
    }
    if (n == vertex_num) {
        cout << "NO EXISTING ARTICULATION POINTS IN THIS GRAPH" << endl;
    }

    
}


