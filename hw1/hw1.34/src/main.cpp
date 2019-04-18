//============================================================================
// Name        : main.cpp
// Author      : Yihan Xu
// Version     :
// Copyright   : Your copyright notice
// Description : hw1 question3,4
//============================================================================

#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
	string userinput = " ";
	Stack stack;
	do{
		cout << "Input a string: " << endl;
		getline(cin, userinput);
		for(int n = 0; n < userinput.length(); n++){
			stack.push(userinput[n]);
		}
		for(int n = 0; n < userinput.length(); n++){
			cout << stack.pop();
		}
		cout << endl;
	} while(userinput != "");
}
