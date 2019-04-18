/*
 * Array.h
 *
 *  Created on: 2016年2月23日
 *      Author: xuyihan
 */
#include <iostream>
#include <iomanip>
#include "myex.h"
#ifndef ARRAY_H
#define ARRAY_H

template <typename A>
class Array{
private:
	int len;
	A * buf;

public:
	Array(int newLen)
: len(newLen), buf(new A[newLen]){}

	Array(const Array & l)
: len(l.len), buf(new A[l.len]){
		for(int i = 0; i < l.len; i++){
			buf[i] = l.buf[i];
		}
	}

	int length(){
		return len;
	}

	A & operator [] (int i)
	throw(IndexOutOfBoundsException){
		if (i < 0 or i >= len){
			throw IndexOutOfBoundsException();
		}
		else{
			return buf[i];
		}
	}

	void print(std::ostream & out){
		for(int i = 0; i < len; i++){
			out << std::setw(8) << std::setprecision(2) << std::fixed << buf[i];
		}
	}

	friend std::ostream & operator << (std::ostream & out, Array & a){
		a.print(out);
		return out;
	}

	friend std::ostream & operator << (std::ostream & out, Array * ap){
		ap -> print(out);
		return out;
	}

	~Array(){
		delete[] buf;
	}

};

#endif

