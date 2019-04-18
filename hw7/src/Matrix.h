/*
 * Matrix.h
 *
 *  Created on: 2016年2月23日
 *      Author: xuyihan
 */

#include <iostream>
#include "Array.h"
#include "myex.h"

#ifndef MATRIX_H
#define MATRIX_H

template <typename M>
class Matrix{
private:
  int rows, cols;
  Array<Array<M>*> m;

public:
	Matrix( int newRows, int newCols )
	: rows( newRows ), cols( newCols ), m( rows ){
		for (int i = 0; i < rows; i++ )
			m[i] = new Array<M>( cols );
	}

	int numRows(){
		return rows;
	}

	int numCols(){
		return cols;
	}

	Array <M> & operator [] ( int row )
	throw(IndexOutOfBoundsException){
		if(row < 0 or row >= rows){
			throw IndexOutOfBoundsException();
		}
		else{
			return * m[row];
		}
	}

	void print( std::ostream & out ){
		for(int i = 0; i < rows; i++){
			out << m[i] << std::endl;;
		}
	}

	friend std::ostream & operator << ( std::ostream & out, Matrix & m ){
		m.print( out );
		return out;
	}

	~Matrix(){
		for(int i = 0; i < rows; i++){
			delete m[i];
		}
	}
};

#endif


