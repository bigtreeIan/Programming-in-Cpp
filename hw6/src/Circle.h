/*
 * Shape.h
 *
 *  Created on: 2016年2月16日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
#include "Shape.h"


#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
		:public Shape{
public:
	Circle(double radius = 0.0, int X = 0, int Y = 0, int S = 0)
	:Shape(X, Y, S), radius(radius){}
	void draw(){
		cout << "          * * *         " << endl;
		cout << "      *           *     " << endl;
		cout << "    *               *   " << endl;
		cout << "   *                 *  " << endl;
		cout << "   *                 *  " << endl;
		cout << "    *               *   " << endl;
		cout << "      *           *     " << endl;
		cout << "          * * *         " << endl;

	}
	virtual double area(){
		return 3.141592653589793238462643383 * radius * radius;
	}

private:
	int radius;
};

#endif


