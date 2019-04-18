/*
 * Shape.h
 *
 *  Created on: 2016年2月16日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
#include "Shape.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
		:public Square{
public:
	Rectangle(int sd, int l)
	:Square(sd), width(sd), length(l){}
	void draw(){
		cout << "*********************" << endl;
		cout << "*                   *" << endl;
		cout << "*                   *" << endl;
		cout << "*                   *" << endl;
		cout << "*                   *" << endl;
		cout << "*********************" << endl;
	}

	virtual double area(){
		return width * length;
	}
private:
	int width;
	int length;
};

#endif
