/*
 * Shape.h
 *
 *  Created on: 2016年2月16日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
#include "Shape.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle
		:public Shape{
public:
	Triangle(int b = 0, int h = 0, int X = 0, int Y = 0, int S = 0)
		:Shape(X, Y, S), base(b), height(h){}

	void draw(){
		cout << "*" << endl;
		cout << "* *" << endl;
		cout << "*   *" << endl;
		cout << "*     *" << endl;
		cout << "*       *" << endl;
		cout << "*         *" << endl;
		cout << "* * * * * * * " << endl;
	}
	virtual double area(){
		return 0.5 * base * height;
	}
private:
		int base;
		int height;
};

#endif
