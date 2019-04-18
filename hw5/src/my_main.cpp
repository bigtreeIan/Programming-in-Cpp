/*
 * my_main.cpp
 *
 *  Created on: 2016年2月8日
 *      Author: xuyihan
 */
#include<iostream>
#include "String.h"
using namespace std;

void test_constructor(){
	String test_1("Hello Ian!");
	String test_2("Hello Professor!");
	String test_3(test_1);
	String test_4(test_2);
	cout << "test1 for constructor(pass char): " << test_1 << endl;
	cout << "test2 for constructor(pass char): " << test_2 << endl;
	cout << "test3 for constructor(pass String class): " << test_3 << endl;
	cout << "test4 for constructor(pass String class): " << test_4 << endl;
	cout << "------------------------------------------" << endl;
}

void test_equal(){
	String test_1 = String("Hello Ian!");
	String test_2 = String("Hello Professor!");
	cout << "test1 for '=' operator: " << test_1 << endl;
	cout << "test2 for '=' operator: " << test_2 << endl;
	cout << "------------------------------------------" << endl;
}

void test_index(){
	String test_string("Hello");
	String test_string2("NiHao");
	char test_1 = test_string[1];
	char test_2 = test_string2[1];
	cout << "test1 for '[]' operator: " << test_1 << endl;
	cout << "test2 for '[]' operator: " << test_2 << endl;
	cout << "------------------------------------------" << endl;
}

void test_indexOf_char(){
	String test_string_1("Hello Ian!");
	int test_1 = test_string_1.indexOf('I');
	int test_2 = test_string_1.indexOf('G');
	cout << "test1 for indexOf_char: " << test_1 << endl;
	cout << "test2 for indexOf_char: " << test_2 << endl;
	cout << "------------------------------------------" << endl;
}

void test_equalequal(){
	String test_string_1("Hello Ian!");
	String test_string_2("Hello Tammy!");
	String test_string_3("Hello Ian!");
	if(test_string_1 == test_string_2){
		cout << "test_1: test_string_1 equal to test_string_2, return true" <<endl;
	}
	else{
		cout << "test_1: test_string_1 not equal to test_string_2, return false" <<endl;
	}
	if(test_string_1 == test_string_3){
		cout << "test_2: test_string_1 equal to test_string_3, return true" <<endl;
	}
	else{
		cout << "test_2: test_string_1 not equal to test_string_3, return false" <<endl;
	}
	cout << "------------------------------------------" << endl;
}

void test_smallerthan(){
	String test_string_1("Hello Ian!");
	String test_string_2("Hello Tammy!");
	String test_string_3("Hello Ia!");
	if(test_string_1 < test_string_2){
		cout << "test_1: test_string_1 is smaller than test_string_2, return true" <<endl;
	}
	else{
		cout << "test_1: test_string_1 is not smaller than test_string_2, return false" <<endl;
	}
	if(test_string_1 < test_string_3){
		cout << "test_2: test_string_1 is smaller than test_string_3, return true" <<endl;
	}
	else{
		cout << "test_2: test_string_1 is not smaller than test_string_3, return false" <<endl;
	}
	cout << "------------------------------------------" << endl;
}

void test_plus(){
	String test_string_1("Hello,");
	String test_string_2("Tammy!");
	String test_string_3("Prof!");
	String test_1 = test_string_1 + test_string_2;
	String test_2 = test_string_1 + test_string_3;
	cout << test_1 << endl;
	cout << test_2 << endl;
	cout << "------------------------------------------" << endl;
}

void test_plusequal(){
	String test_string_1("Hello,");
	String test_string_2("Tammy!");
	String test_string_3("Eon,");
	String test_string_4("Prof!");
	test_string_1 += test_string_2;
	test_string_3 += test_string_4;
	cout << test_string_1 << endl;
	cout << test_string_3 << endl;
	cout << "------------------------------------------" << endl;
}

void test_print(){
	String test_string_1("Hello Ian,");
	String test_string_2("Hello Tammy!");
	cout << test_string_1 <<endl;
	cout << test_string_2 <<endl;
	cout << "------------------------------------------" << endl;
}

void test_read(){
	String test_1;
	String test_2;
	cout << "Please enter first test String: " << endl;
	cin >> test_1;
	cout << "Please enter second test String: " << endl;
	cin >> test_2;
	cout << "First test String: " << test_1 << endl;
	cout << "Second test String: " << test_2 << endl;
	cout << "------------------------------------------" << endl;
}

int main(){
	test_constructor();
	test_equal();
	test_index();
	test_indexOf_char();
	test_equalequal();
	test_smallerthan();
	test_plus();
	test_plusequal();
	test_print();
	test_read();
	String::final_report_on_allocations();

	return 0;
}


