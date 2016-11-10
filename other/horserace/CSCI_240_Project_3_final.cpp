//CSCI_240_Project_3_final.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>

using namespace std;

//  || class prototypes ||

//  ||  class prototype for horse  ||
class Horse{
private:
    int position;//private variables to keep data secure
public:
    Horse();
    int getPosition();
    void advance();
};//end prototype

//establish all my initial horses position to 0
Horse::Horse(){
    Horse::position = 0;
}
//getPosition is bult as a command to get my horses position at ANY given time whenever I want it, it will return my position.
int Horse::getPosition(){
    return Horse::position;
}
//advance needs to establish a variable coin that is going to have 2 values , a 0, or a 1, this will determine whether the horse will advance or not
//if the horse get a 1 advance the horse, if the horse gets a 0, do not advance the horse. This makes it a random inncreasing movement inside of the horse
//race whenever this method is called
void Horse::advance(){
    //establish a coin flip to see if the advance is worthy of moving forward or not
    int coin;
    coin = rand() % 2; // used to keep the value at 0 or 1
    if (coin == 1){
        //you could set position += speed where speed is its own determinate factor of how much the horse will increase
        Horse::position += 1; // increment position if 1
    }
    //This advance function needs to take my horse position and += it
}
//  ||  class prototype for race  ||
class Race{
private:
    int horses;
    Horse stables[25]; // C++ syntax make sme keep a fixed array length to work with. This could be created on the heap to dynamically allocate memory for
    // storage, but I found that this was more hastle than it was worth because I felt there was a need to constrain the horses to 25, any more is just crazy.
    int length;
public:
    Race(); // constructor for no perameters
    Race(int, int); // constructor for perameters, this is also used in the suddenDeath object later.
    void printLane(); //this will print out a lane for all of my horses with the horse name in the front, and will say "please press enter to proceed"
    //the cin.ignore() will be kept for the start() method
    void start();//starts the rodeo
};//end prototype

//establish race constructor without perameters
Race::Race(){
    horses = 10; //If no perameters given to the start method, it will instantiate 10 horses
    stables[horses]; // if no peramters given it will use the 10 horses given and create 10 stables, or holding places for my horse objects
    length = 10;
}
//establish race constructor with peramters
Race::Race(int length, int horses){
    Race::length = length;
    Race::horses = horses;
    Race::stables[horses];
}

//for however many horses given, create that many lanes at the legnth given
//Check the position of my horse for my horse loop and compare it to the variable in the length loop
//If they are the same, simply print out my horse name which will be i + 1 to avoid the 0 place holder
//This will only display the horse name once because the loops will only cross in the first part of their derivation, thus displaying
//all of my horses in a vertical column then the dots following in structures rows at length amount
//If they aren't the same, simply print a dot. then ask them to press enter to continue
void Race::printLane(){
    for(int i = 0; i < horses; i++){
        for(int j = 0; j < length; j++){
            if(stables[i].getPosition() == j){
                cout << i + 1;
            }
            else {
                cout << '.';
            }
		}
		cout << endl;
	}
	cout << "press enter to continue ";
}
//the start function is going to use a loop for however many horses they want to create
//for however many horses the user wants to create, create a horse object, and establish the horse at each stable of the amount of horses
//the user wanted to create and make that element = a horse, thus giving it horse characteristics, position, and each method attached.

//I use a while loop to keepGoing until I get a winner
//I use winners simply to see if I have any winners then go to sudden death
//but I neeed to print my horse lanes and I use my for loop to advance each horse in my stables randomly,
//if the horse reaches the length amount the track it is a winner
//if there are multiple winners, winners will trigger outside of the while loop and establish a SUDDEN DEATH!
//after the condition for the while loop (a winner) is met then we dont want to keepGoing, so it will be changed to, false.
void Race::start(){
    
	for (int i = 0; i < horses; i++){
		Horse horse;
		Race::stables[i] = horse;
	}
    int winners = 0;
	bool keepGoing = true;
	while (keepGoing){
        cin.ignore();
		Race::printLane();
		for (int i = 0; i < horses; i++){
			stables[i].advance();
			if (stables[i].getPosition() == length){
				cout << "Horse " << i + 1 << " is the winner!" << endl;
				winners += 1;
				keepGoing = false;
			}
            
		}
        
        //when the horses position becomes == the given length we have a winner
	}
	//for the same length
    if (winners > 1){
        cout <<endl<<endl<<endl<< "!*!*!*!*!*!!**! WE HAVE A TIE. FIGHT TO THE FINISH!  ****!*!***!*!*!!*" <<endl<<endl<<endl;
        Race suddenDeath(length, winners);
        suddenDeath.start();
        
    }
    
}
//declare variables
//seed time once to keep things random
//ask for horses and length
//start a rodeo with given data
//end code
int main()
{//start main
    int length;
    int horses;
    srand(time(NULL));
    cout << "How many horses do you want to sattle up for the rodeo?" << endl;
    cout << "This number must be greater than 2 and less than 25" << endl;
    cin >> horses;
    cout << "How long would you like the length to be?" << endl;
    cin >> length;
    Race rodeo(length, horses);
    rodeo.start();
    return 0;
}//end main
