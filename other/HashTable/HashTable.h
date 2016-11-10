// HashTable.h

#ifndef HashTable_h
#define HashTable_h

#include "LkList.h"
#include <string.h>
class HashTable
{
    private:
        LkList ht[20];
        int sizeHT;
           
    public:
        HashTable (int sizeHT1);
        ~HashTable();
        void insertHT (string name1, int phoneNr1);
        void searchHT (string name1);
        void printHT();
        int hashFct (string name1);
        int hashFct2 (string name1);
        int Find (string name1);
        int Find2 (string name1);
};

#endif 
