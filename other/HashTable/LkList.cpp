// LkList.cpp

#include "LkList.h"
#include <vector>
#include <string.h>
LkList::LkList ()
{    
    pll=NULL;  
}
LkList::~LkList()
{ }

void LkList::insert (string name1, int phoneNr1)
{
   Node *p = new Node;
   
   p->data=name1;
   p->phoneNr=phoneNr1;   
   p->next = pll;
   
   pll = p;
}


int LkList::search (string name1)
{
     bool there=false;
           
     Node *p = pll;
      
     while (p != NULL)  
     {
       if(p->data==name1)
       {
          there=true;
          break;
       }
       p=p->next;
     }
     
     return p->phoneNr;
}

bool LkList::search2 (string name1)
{
     bool there=false;
           
     Node *p = pll;
      
     while (p != NULL)  
     {
       if(p->data==name1)
       {
          there=true;
          break;
       }
       p=p->next;
     }
     
     return there;
}
/*
void LkList::deleteNode (int nr1)
{
     Node* p = pll;
     Node* q;
     
     if(search(nr1))
     {
         while (p != NULL)  
         {
           if(p->data==nr1)
           {
              pll=p->next;
              
              delete p;             
              
              break;
           }
           else 
                if(p->next->data==nr1)
                   {
                      q=p->next;
                      
                      p->next=q->next;
                      
                      delete q;
                      
                      break;
                   }
               
           p=p->next;
         }
     }
     else
         cout<<nr1<<" is not in the list, so it cannot be deleted.\n";        
}
*/
void LkList::printL ()
{
   Node *p = pll;
      
   while (p != NULL)  
   {
       cout<<p->data;
       
       if(p->next!=NULL)
          cout<<"->";
          
       p=p->next;
   }   
}
