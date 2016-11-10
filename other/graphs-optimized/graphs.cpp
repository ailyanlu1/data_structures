//an optimized version of my graphs problem from IUPUI in CSCI 362 
//Algorithms, I decided to make it a little better with my DFS and BFS 
//and clean it up on the file input for any general case

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;
class Edge;
class Vertex;
void converter(vector<vector<string> > *container_str, vector<vector<float> > *container_flt);

/***///////////////////////////////////////////////////////////***/
class Vertex{
public:
    float vertexId;
    vector<Edge> edgeContainer;
    bool visited;

    Vertex();
    Vertex(float);

	Vertex& operator=(const Vertex& rhs)
	{

        this->edgeContainer = rhs.edgeContainer;
        this->vertexId = rhs.vertexId;
        this->visited = rhs.vertexId;
		return *this;
	}

};

Vertex::Vertex(){
	visited = false;
}

Vertex::Vertex(float f){
	Vertex::vertexId = f;
	visited = false;
}

/***///////////////////////////////////////////////////////////***/
class Edge{
public:
    Vertex from;
    Vertex to;
    float weight;
    
    Edge();
    Edge(Vertex, Vertex, float);

};

Edge::Edge(){

}

Edge::Edge(Vertex from, Vertex to, float weight){


	Edge::from = from;
	Edge::to = to;
	Edge::weight = weight;
	cout << "its working??" << endl;
	cout << Edge::from.vertexId << endl;
	cout << Edge::to.vertexId << endl;
	cout << Edge::weight << endl;
}

/***///////////////////////////////////////////////////////////***/
class Graph{
public:
	float num_vertices_flt;
	float num_edges_flt;
	vector<Vertex> vertexContainer;
	vector<vector<string> > fileContainer_str;
	vector<vector<float> > fileContainer_flt;
	void readFile(string);
	void print();
	void createGraph();
	
};

void Graph::readFile(string fileName){

	cout << "Inside of Graph::readFile(string fileName)" << endl;

	/////////////////////////////  STL Containers  ////////////////////////////////////
	vector<vector<string> > fileContainer_str;
	vector<vector<float> > fileContainer_flt;
	/////////////////////////////  Native Data Types  ////////////////////////////////////
	string line;
	int num_lines=0;
	string num_vertices_str="";
	string num_edges_str="";
	int flag=false;	

	/////////////////////////////  File Objects  ////////////////////////////////////
	ifstream fileForNumLines;
	ifstream fileForData;


	/////////////////////////////////////////////////////////////////
	/* Open for file numbering */
	fileForNumLines.open(fileName.c_str());
	num_lines=std::count(std::istreambuf_iterator<char>(fileForNumLines), std::istreambuf_iterator<char>(), '\n');

	/////////////////////////////////////////////////////////////////
	/* open file to extract data */
	fileForData.open(fileName.c_str());

	/////////////////////////////////////////////////////////////////
	/* get the first line uniquely for special data, i.e.. vertice numbering and edge numbering */
	getline(fileForData,line);
	std::istringstream iss(line);
	do{
	    string sub;
        iss >> sub;
        if(sub!=""){
        	cout << sub << endl;
   	        if(flag!=true){
   	        	//store vertices num
   		     	num_vertices_str = sub;
   		     	flag=true;
       	 	}
        	else{
        		//store edges num
        		num_edges_str = sub;
        	}
        }

    } while (iss);


	/////////////////////////////////////////////////////////////////
	/* Store into globals */    
    Graph::num_vertices_flt = stof(num_vertices_str);
    Graph::num_edges_flt = stof(num_edges_str);

	/////////////////////////////////////////////////////////////////
	/* get the rest of our file data and store into our 2d vector array of strings */
	for(int i =0; i < num_lines; i++){
	    getline(fileForData,line);
	    vector<string> temp;

	    //chop into substrings
	    std::istringstream iss(line);
	    do{
	        string sub;
	        iss >> sub;
	        if(sub!="")
	        	temp.push_back(sub);
	    } while (iss);

		fileContainer_str.push_back(temp);
	}

	/////////////////////////////////////////////////////////////////
	// convert and store
	for(vector<string> v: fileContainer_str){
		vector<float> v_f;
		for(string s : v){
			cout << s << " ";
			v_f.push_back(stof(s));
		}
		cout << endl;
		Graph::fileContainer_flt.push_back(v_f);
	}


	/////////////////////////////////////////////////////////////////
	//print for debugging
	cout << "Graph::fileContainer_flt.size(): " << Graph::fileContainer_flt.size() << endl;
	cout << "Graph::fileContainer_flt.at(0).size(): " << Graph::fileContainer_flt.at(0).size() << endl;
	cout << "Graph::fileContainer_flt.at(0).at(0): " << Graph::fileContainer_flt.at(0).at(0) << endl;
	cout << "Graph::fileContainer_flt.at(0).at(1): " << Graph::fileContainer_flt.at(0).at(1) << endl;
	cout << "Graph::fileContainer_flt.at(0).at(2): " << Graph::fileContainer_flt.at(0).at(2) << endl;

	float index = 0;
	flag=false;
	vector<Edge> edgeArr;
	for(float x = 0; x < Graph::num_vertices_flt; x++){
		cout << x << "~" << endl;
		for(float i = 0; i < Graph::fileContainer_flt.size(); i++){
			for(float j = 0; j < Graph::fileContainer_flt.at(i).size(); j++){
			//cout << Graph::fileContainer_flt.at(i).at(j) << " ";
				if(Graph::fileContainer_flt.at(i).at(0) == index){
					//cout << Graph::fileContainer_flt.at(i).at(j) << " ";
					if(flag == false){
						Edge e(Graph::fileContainer_flt.at(i).at(0),Graph::fileContainer_flt.at(i).at(1), Graph::fileContainer_flt.at(i).at(2));
						edgeArr.push_back(e);
						flag=true;
					}//end if

				}//end if
			}//end for
		flag=false;
		//Graph::vertexContainer.at(x).edgeContainer=edgeArr;
		//cout << endl;
	}//end for
	index++;
	}

//I have an array of edges for each occurrence, now just find a way to store that into the correct 

	//main algorithm
	//setup vertex array
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;




}

/***///////////////////////////////////////////////////////////***/
int main(){

	cout << endl;
	Graph g;
	g.readFile("data.txt");
	return 0;
}
