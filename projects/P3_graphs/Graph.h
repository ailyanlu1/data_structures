//
//  Graph.h
//  
//
//  Created by BLAKE CONRAD on 4/16/15.
//
//

#ifndef ____Graph__
#define ____Graph__

#include <iostream>
#include <stdio.h>
#include <stack>          // std::stack
#include <list>
#include <queue>
#include <time.h>
#include <stdlib.h>

using namespace std;
//DECLARATIONS TO AVOID DEPENDENCY COLLISION
class Edge;
class VertexList;

class Vertex{
public:
    // VERTEX DATA
    int vertexId;
    Vertex *next;
    Edge *e;
    bool edge_exists;
    bool visited;
    
    // CONSTRUCTORS / DECONSTRUCTORS
    Vertex();
    ~Vertex();
    
    // INSTANCE METHODS
    bool hasEdge();
    void updateEdgeArray(int*);

};

class Edge{
public:
    // EDGE DATA
    Vertex from;
    Vertex to;
    int weight;
    
    // CONSTRUCTORS / DECONSTRUCTORS
    Edge();
    Edge(Vertex, Vertex, int);
    ~Edge();
};

class LinkedList{
public:
    // LINKED LIST DATA
    struct Node{
        Vertex data;
        int ID;
        Node *next;
    };
    Node *head; // MY REPRESENATIVE OF THE CLASS INSTANCE; HE POINTS TO THE NEXT
    int size;
    
    // CONSTRUCTOR / DECONSTRUCTOR
    LinkedList();
    ~LinkedList();
    
    // CLASS / INSTANCE METHODS
    void addNode(Vertex inc);
    void printList();
};

class Graph{
public:
    
    // GRAPH DATA
    int vertex_num;
    int edge_num;
    int *r;
    std::string src;
    Vertex *V;
    Vertex **AdjList;
    LinkedList **mainList;
    std::queue<Vertex> DFSQueue;
    Vertex *vertexArray;
    Vertex *AP;
    
    
    // CONSTRUCTORS / DECONSTRUCTORS
    Graph();
    ~Graph();
    Graph(std::string);
    

    
    // CLASS / INSTANCE METHODS
    bool isBipartite();
    void findArticulationPoints();
    void initDFS(LinkedList**, int);
    void DFS(Vertex);
    void BFS(Vertex);
    void writeGraph(int**,Vertex*, int*, int, int);
    void readGraph(std::string);
    
};

#endif /* defined(____Graph__) */
