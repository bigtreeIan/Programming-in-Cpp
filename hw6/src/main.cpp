//============================================================================
// Name        : hw6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
using namespace std;
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Picture.h"

int main(){
	Picture pc;
	Triangle FirstT(5, 5);
	Triangle SecondT(3, 4);
	Circle FirstC(5);
	Circle SecondC(10);
	Square FirstS(5);
	Square SecondS(10);
	Rectangle FirstR(8, 4);
	Rectangle SecondR(4, 8);
	pc.add(&FirstT);
	pc.add(&SecondT);
	pc.add(&FirstC);
	pc.add(&SecondC);
	pc.add(&FirstS);
	pc.add(&SecondS);
	pc.add(&FirstR);
	pc.add(&SecondR);
    pc.drawAll();
    cout << "Total area is " << pc.totalArea() << " Square units."<< endl;
return 0;

}
