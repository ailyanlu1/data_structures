#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
	int n;
	cout << "How long do you want your dynamic variable to be?"<<endl;
	
	cin >> n;
	cin.ignore();
	
	char *my_name;
	my_name = (char *) calloc (n, sizeof(char));
	int size = (sizeof(my_name)/sizeof(char));
	cout << "n: " << n << endl;
	cout << "size of my_name: " << sizeof(my_name) << endl;
	cout << "size of char: " << sizeof(char) << endl;

	return 0;
}
