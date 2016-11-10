// Blake Conrad HW3 - Double Hasing
/*
My Solution: Apply Double Hashing to display a name's phone number from our phone book
Additional Solution: When searching for your name, I will find all copies of it in our PhoneBook and print them out;

Additions:
          hashFct1(string) //hashing by string length
          hashFct2(string)//steps backward 1 char in the string length
          Find(string) //implements double hashing to insert, unique key designated
          Find2(string) // implements double hasing to search, unique key designated
          searchHT(string) //searches to find our name in our phone book then displays the number using double hasing
*/

#include "HashTable.h"

////////////  main  /////////////////
int main()
{
    int sizeHT1;
    string name1;
    
   // we create a HashTable object
   
   cout<<"Enter size of HashTable: ";
   cin>>sizeHT1;
   
   HashTable htObj(sizeHT1);
    
   htObj.insertHT("Pat",1386);
   htObj.insertHT("Nick",1111);
   htObj.insertHT("Dean",3646);
   htObj.insertHT("Blake",4172);
   htObj.insertHT("Mike",4107);
   htObj.insertHT("Amy",9236);
   //htObj.insertHT("Blake",5555);
   htObj.insertHT("Jacolby",3163);
   htObj.insertHT("Andy",7775);
   htObj.insertHT("Dan",1382);
   htObj.insertHT("Mashi",7631);
   //htObj.insertHT("Blake",2222);
   htObj.insertHT("Fahad",3193);
   //htObj.insertHT("Blake",3333);
   htObj.insertHT("Dalton",2501);
   htObj.insertHT("Abdul",5977);     
   //htObj.insertHT("Dan",1414);
   //htObj.insertHT("Mashi",2525);
   
   cout<<"Here is our Hash Table: "<<endl; 
   htObj.printHT();  

   cout << "\nEnter a name to search: \n";
   cin >> name1;
   htObj.searchHT(name1);
   
    cout<<endl<<endl;
   system("pause");
}
