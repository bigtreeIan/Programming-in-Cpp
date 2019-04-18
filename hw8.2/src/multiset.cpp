//============================================================================
// Name        : 2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool odd_even(int n){
	if(n % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

int main() {
	ifstream in_random("rand_numbers.txt");
	multiset<int> D;
	for_each(istream_iterator<int>(in_random),
			istream_iterator<int>(),
			[&](int i){D.insert(i);}
	);

	ofstream out_odd("odd.txt");
	ofstream out_even("even.txt");
	for(auto E_d : D){
		if(odd_even(E_d)){
			out_even << E_d << endl;
		}
		else{
			out_odd << E_d << " ";
		}
	}
	cout << "File has been written successfully!" << endl;
	out_even.close();
	out_odd.close();
	return 0;
}
