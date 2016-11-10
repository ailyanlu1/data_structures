// HashTable.cpp

#include "HashTable.h"


HashTable::HashTable(int sizeHT1)
{    
   sizeHT = sizeHT1;
}

HashTable::~HashTable()
{ }

void HashTable::insertHT (string name1, int phoneNr1)
{
  //ht[hashFct(name1)].insert(name1,phoneNr1);     
  ht[Find(name1)].insert(name1,phoneNr1);
}


void HashTable::searchHT(string name1)
{

    vector<string> v;
    for (int i=0 ; i < sizeHT; i++) {
        for (Node *p = ht[i].pll; p != NULL; p=p->next) {
            if(p->data.substr(0,name1.length()) == name1)
                v.push_back(p->data);
        }
    }
    cout << "We found " << v.size() << " hit(s). " << endl;
}

/*
void HashTable::searchHT(string name1)
{
    int nr1 = ht[Find2(name1)].search(name1);
    if(nr1 != 0)
        cout << "Number " << nr1 << " is in the HashTable in LkList number: " << Find2(name1)+1 << endl;
    else cout << "Number " << nr1 << " is not in the HashTable\n";
    

}
*/
void HashTable::printHT ()
{
   for (int i=0; i<sizeHT; i++)
   {
        ht[i].printL();
        cout<<endl;
   }     
}
/**** Hash Function 1 ****/
int HashTable::hashFct(string name1)
{
    return name1.size()%sizeHT;
}

/**** Hash Function 2 ****/
int HashTable::hashFct2(string name1)
{
    return (name1.size() * sizeHT - 1) % sizeHT;
}

/**** Double Hash Function To Insert ****/
int HashTable::Find(string name1){
    int hashVal = hashFct(name1);
    int stepSize = hashFct2(name1);

    //if the condition IS true we have collided and will resolve it with Double Hashing.
    //loop until resolved.
    while (ht[hashVal].pll != NULL && ht[hashVal].search2(name1) == true) 
    {
          hashVal = hashVal + stepSize;
          hashVal = hashVal % sizeHT;
    }
    return hashVal;
}

/**** Double Hash Function To Search ****/
int HashTable::Find2(string name1){
    int hashVal = hashFct(name1);
    int stepSize = hashFct2(name1);

    //if the condition IS NOT true we have NOT collided which means we have not found our LKLIST.
    //we will continue looping with our double hash algorithm until we find the right bucket
    //loop until resolved.
    while (ht[hashVal].search2(name1) != true) 
    {
          hashVal = hashVal + stepSize;
          hashVal = hashVal % sizeHT;
    }

    return hashVal;
}
