/*
 * Shape.h
 *
 *  Created on: 2016年2月16日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
#include "Shape.h"

#ifndef PICTURE_H
#define PICTURE_H
class Picture{
private:
	struct LL_S{
		Shape * info;
		LL_S * next;
		LL_S(Shape * info_new, LL_S * next_new)
		:info(info_new), next(next_new){}

		static void deleteall(LL_S * L){
			if(L){
				deleteall(L -> next);
				delete L;
			}
		}
	};

	LL_S * head;

	static int length(LL_S * L){
		if(L == nullptr){
			return 0;
		}
		else{
			return 1 + length(L -> next);
		}
	}

public:
	Picture() : head(nullptr){}
	void drawAll(){
		LL_S * temp1 = head;
		for(int i = 0; i < length(head); i++){
			temp1 -> info -> draw();
			temp1 = temp1 -> next;

			cout << endl;
		}
	}

	double totalArea(){
		double Area = 0.0;
		LL_S * temp2 = head;
		for(int i = 0; i < length(head); i++){
			Area += temp2 -> info -> area();
			temp2 = temp2 -> next;

		}
		return Area;
	}

	void add(Shape * L){
		head = new LL_S(L, head);
	}

	~Picture(){
		LL_S::deleteall(head);
	}
};

#endif
