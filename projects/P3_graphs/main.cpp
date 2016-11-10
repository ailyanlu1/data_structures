//
//  main.cpp
//  
//
//  Created by BLAKE CONRAD on 4/16/15.
//
//

#include <stdio.h>
#include "Graph.h"


int main(){
    
    string yourFile = "data.txt"; // to avoid delcaring literals inside of the argument
    Graph graph;
    graph.readGraph(yourFile);
    
    return 0;
}