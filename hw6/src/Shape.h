/*
 * Shape.h
 *
 *  Created on: 2016年2月16日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
#ifndef SHAPE_H
#define SHAPE_H

class Shape{
public:
	Shape(int centerX_p = 0, int centerY_p = 0, int size_p = 0)
	:centerX(centerX_p), centerY(centerY_p), size(size_p){}
	virtual void draw() = 0;
	virtual double area() = 0;
	virtual ~Shape(){};

private:
	int centerX;
	int centerY;
	int size;
};
#endif
