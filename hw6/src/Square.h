/*
 * Shape.h
 *
 *  Created on: 2016年2月16日
 *      Author: xuyihan
 */

#include <iostream>
using namespace std;
#include "Shape.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square
		:public Shape{
public:
	Square(int sd = 0, int X = 0, int Y = 0, int S = 0)
		:Shape(X, Y, S), side(sd){}
	void draw(){
		cout << "********************" << endl;
		cout << "*                  *" << endl;
		cout << "*                  *" << endl;
		cout << "*                  *" << endl;
		cout << "*                  *" << endl;
		cout << "*                  *" << endl;
		cout << "*                  *" << endl;
		cout << "*                  *" << endl;
		cout << "********************" << endl;
	}

	virtual double area(){
		return side * side;
	}

private:
	int side;
};

#endif
