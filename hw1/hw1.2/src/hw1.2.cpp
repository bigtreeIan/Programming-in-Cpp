//============================================================================
// Name        : hw1.2
// Author      : Yihan Xu
// Version     :
// Copyright   : Your copyright notice
// Description : hw1.2
//============================================================================

#include <iostream>
using namespace std;

double transfer(int knot) {
	double miles;
	double mph;
	miles = (6076 * (double) knot) / 5280;
	mph = miles / 60;
	return mph;
}

int main(){
	int integerinput;
	double integeroutput;
	cout << "Input the integer: " << endl;
	cin >> integerinput;
	integeroutput = transfer(integerinput);
	cout << integeroutput;
	cout << " miles/minute" << endl;
	return 0;
}

