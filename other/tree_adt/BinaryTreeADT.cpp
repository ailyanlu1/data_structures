//
//  BinaryTreeADT.cpp
//  
//
//  Created by BLAKE CONRAD on 2/27/15.
//
//

#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include <stdlib.h>

using namespace std;
vector<string> string_split(string a, char del);
void print_tree(node * n, int hight);
int number_of_char(string a , char del);
void insert_node(node * n, int numb);

class node {
public:
    int value;
    node * parrent;
    node* left;
    node* right;
};

int main(int argc, const char * argv[]) {
    
    string filename = "/Users/Blake/Desktop/TestData.txt";
    string line;
    ifstream myfile (filename);
    vector<string> string_seg;
    node* root;
    root= new node();
    
    if (myfile.is_open())
    {
        int l=0;
        while ( getline (myfile,line) )
        {
            l++;
            
            string_seg = string_split(line, ' ');
            
            //match and count
            for (int i=0; i < string_seg.size();i++){ // for each item in the itemset of this line
                int numb;
                numb=atoi(string_seg[i].c_str());
                
                if (i==0) {
                    root->value = numb;
                    root->left = NULL;
                    root->right = NULL;
                    cout<< root->value << " root\n";
                }
                else{
                    insert_node(root, numb);
                    
                }
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    print_tree(root,0);
    return 0;
}

//get the number of chars between ' ' spaces
int number_of_char(string a , char del){
    char *p = new char[a.size()+1];
    int i = 0;
    int number_of_item = 0;
    
    strcpy(p,a.c_str());
    
    for (i=0; i<a.size(); i++) {
        if (p[i]==' ') {
            number_of_item++;
        }
    }
    return number_of_item;
}

vector<string> string_split(string a, char del){
    char *p = new char[a.size()+1];
    int i =0;
    int number_of_item;
    vector<string> string_seg;
    
    strcpy(p, a.c_str()); //a.c_str() makes string a = char a[]; so it can hand it off to char p[];
    
    //number_of_item=number_of_char(a, del)+1;
    
    
    char *tokenPtr=strtok(p," ");
    while(tokenPtr != NULL) { //tokenPtr is in memory checking if its not NULL
        string_seg.push_back((string)tokenPtr); //push on that token to my vector
        i++;
        tokenPtr=strtok(NULL," ");//reset my tokenPtr
    }
    return string_seg;
}

void print_tree(node * n, int hight){
    int i=0;
    for (i=0; i<hight; i++) {
        cout<<'~';
    }
    cout<<n->value<<'\n';
    if (n->left!=NULL) {
        print_tree(n->left, hight+1);
    }
    if (n->right==NULL) {
        return;
    }
    else{
        print_tree(n->right, hight+1);
    }
}

void insert_node(node * n, int numb){
    if (n->value>numb) { // current node
        if(n->left==NULL){
            n->left=new node();
            n->left->value=numb;
            n->left->left=NULL;
            n->left->right=NULL;
            cout<<n->left->value<<" is inserted to left of"<< n->left->value<<'\n';
            return;
            
        }
        else{
            insert_node(n->left, numb);
        }
    }
    else{
        if (n->right==NULL) {
            n->right=new node();
            n->right->value=numb;
            cout<<n->right->value<<" is inserted to rightof"<< n->value<<'\n';
            return;
        }
        else{
            insert_node(n->right, numb);
        }
    }
}
