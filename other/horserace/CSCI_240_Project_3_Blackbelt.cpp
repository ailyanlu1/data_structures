//CSCI_240_Project_3_Blackbelt
//Added sudden death feature, finish line bars, and integrated horse names, and domain restriction with no crashing for ints or strings in the main.
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <ctype.h>
using namespace std;

//  || class prototypes ||

//  ||  class prototype for horse  ||
class Horse{
private:
    int position;
    int acceleration;
    string name;
    
public:
    Horse();
    //   Horse(string);
    int getPosition();
    void advance();
    void setName(string);
    string getName();
};//end prototype

Horse::Horse(){
    Horse::position = 0;
    //Horse::acceleration = rand() % 4;//accelerates the horse from 0-3 units randomly
    
}
//Horse::Horse(string name){
//    Horse::name = name;
//}
/*  Horse::position = 0;
 Horse::acceleration;
 Horse::name = name;
 }*/
int Horse::getPosition(){
    return Horse::position;
}
void Horse::advance(){
    //establish a coin flip to see if the advance is worthy of moving forward or not
    int coin;
    coin = rand() % 2;
    if (coin == 1){
        //you could set position += speed where speed is its own determinate factor of how much the horse will increase
        Horse::position += 1; //acceleration;
    }
    //This advance function needs to take my horse position and += it
}
void Horse::setName(string name){
    Horse::name = name;
}
string Horse::getName(){
    return Horse::name;
}
//  ||  class prototype for race  ||
class Race{
private:
    int horses;
    Horse stables[20]; //set bounds of horses to 10
    int length;
public:
    Race();
    Race(int, int);
    void printLane(); //possibly int horseNum
    void start();
};//end prototype

//establish race constructor without perameters
Race::Race(){
    horses = 10;
    stables[horses];
    length = 10;
}
//establish race constructor with peramters
Race::Race(int length, int horses){
    Race::length = length;
    Race::horses = horses;
    Race::stables[horses];
}

void Race::printLane(){
    for(int i = 0; i < horses; i++){
        for(int j = 0; j < length; j++){
            if(stables[i].getPosition() == j){
                cout << stables[i].getName();
            }
            else {
                cout << '.';
            }
		}
		cout << "|" << endl;
	}
	cout << "press enter to continue ";
}
//
void Race::start(){
    string nameList[20] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t"};
    string horseName;
	for (int i = 0; i < horses; i++){
		Horse horse;
		Race::stables[i] = horse;//horse(nameList[i]
        //cout << "What would you like horse " << i+1 <<"'s name to be?" << endl;
        //cin >> horseName;
        stables[i].setName(nameList[i]); //horseName
	}
    int winners = 0;
	bool keepGoing = true;
	while (keepGoing){
        cin.ignore();
		Race::printLane();
		for (int i = 0; i < horses; i++){
			stables[i].advance();
			if (stables[i].getPosition() >= length){
				cout << "Horse " << stables[i].getName() << " is the winner!" << endl;
				winners += 1;
				keepGoing = false;
			}
            
		}
        
        //when the horses position becomes == the given length we have a winner
	}
    if (winners > 1){
        cout <<endl<<endl<<endl<< "!*!*!*!*!*!!**! WE HAVE A TIE. FIGHT TO THE FINISH!  ****!*!***!*!*!!*" <<endl<<endl<<endl;
        Race suddenDeath(length, winners);
        suddenDeath.start();
        
    }
    
}
//set my variables length and horses = 1 to initially offset my first while loop and enter into it
//I will then check and see if horses is divisible by one (or in english to see if it an integer)
//if it is, ask them to pick a new number and I will set it = horses
//immediately and forever my loop will check to see IF{ my given is an int ( horses / 1) represents this OR ELSE{ its not, so I clear what they give me
// or what is stored in the buffer, then I will clear 1000 and print a new line because this starts a fresh line, not manditory but preferred
//after we will continue to ask the user for horses until it is an interger inside of my domain.
//repeat for length with a new domain to keep the race within reasonability
//start the rodeo
int main()
{
    int length = 1;
    int horses = 1;
    srand(time(NULL));
    while (horses < 2 or horses > 20){
        if(horses/1){
            cout << "Please pick a number of horses between 2 and 20: ";
            cin >> horses;
        }
        else{
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Please pick a number of horses between 2 and 20: ";
            cin >> horses;
        }
    }
    // if horses given is not an integer < 20 i need to throw what they give me and ask again
    //if (int horses == ){}
    while (length < 5 or length > 20){
        if(length/1){
            cout << "Please pick a track length between 5 and 20: ";
            //if length given is not an integar < 20 i need to throw what they give me and ask again
            cin >> length;
        }
        else{
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please pick a track length between 5 and 20: ";
            //if length given is not an integar < 20 i need to throw what they give me and ask again
            cin >> length;
        }
    }
    
    
    Race rodeo(length, horses);//(length, horses)
    rodeo.start();
    return 0;
}
