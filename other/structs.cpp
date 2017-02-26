//learning advanced structs


#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct s{
	int a;
	int b;
	//copy constructor	
	s(int x, int y) : a(x), b(y){ /* insert other features you want the incoming truct to impact*/}
	void getUpVals(int arg1, int arg2){
		a=arg1; b=arg2;
	}
	void printVals(){
		cout << a << "\t" << b << endl;
	}
}s;

int main(){
	
	cout << "Hello world!" << endl;
	
	s foo(4,5);
	foo.printVals();
	return 0;
}
