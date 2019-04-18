//============================================================================
// Name        : hw2.cpp
// Author      : Yihan Xu
// Version     :
// Copyright   : Your copyright notice
// Description : hw2 CoinMenu
//============================================================================

#include <iostream>
#include "Coins.h"
using namespace std;
int main() {
	int temp = 0;
	Coins myCoins(0, 0, 0, 0);
	while(temp != 1){
		int quarter_d = -999;
		int dime_d = -999;
		int nickels_d = -999;
		int pennies_d = -999;
		cout << "Enter 'D' to Deposit change; 'E' to Extract change; 'P' to Print balance; 'Q' to Quit: " << endl;
		string command;
		cin >> command;
		if(command == "D"){
			cout << "How many quarters do you want to deposit: "<< endl;
			cin >> quarter_d;
			while(quarter_d < 0){
				cout << "Invalid, Enter again" << endl;
				cin >> quarter_d;
			}
			cout << "How many dimes do you want to deposit: "<< endl;
			cin >> dime_d;
			while(dime_d < 0){
				cout << "Invalid, Enter again" << endl;
				cin >> dime_d;
			}
			cout << "How many nickels do you want to deposit: "<< endl;
			cin >> nickels_d;
			while(nickels_d < 0){
				cout << "Invalid, Enter again" << endl;
				cin >> nickels_d;
			}
			cout << "How many pennies do you want to deposit: "<< endl;
			cin >> pennies_d;
			while(pennies_d < 0){
				cout << "Invalid, Enter again" << endl;
				cin >> pennies_d;
			}
			Coins new_myCoins(quarter_d, dime_d, nickels_d, pennies_d);
			myCoins.depositChange(new_myCoins);
		}
		else if(command == "E"){
			cout << "How many cents do you want to extract: "<< endl;
			int money_transfered;
			cin >> money_transfered;
			while (! myCoins.hasSufficientAmount(money_transfered) or money_transfered < 0){
				cout << "Invalid, Enter again: ";
				cin >> money_transfered;
			}
			myCoins.extractChange(money_transfered);
		}

		else if(command == "P"){
			cout << "Current balance is: " << myCoins << endl;
		}
		else if(command == "Q"){
			cout << "The program is now quit." << endl;
			break;
		}
		else{
			cout << "This command does not exist, please enter again." << endl;
			continue;
		}
		}
	return 0;
}
