//============================================================================
// Name        : hw7.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Array.h"
#include "Matrix.h"
#include "myex.h"
using namespace std;

template
  < typename T >

void fillMatrix( Matrix <T> & m )
{
  int i, j;
  for ( i = 0; i < m.numRows(); i++ )
    m[i][0] = T();
  for ( j = 0; j < m.numCols(); j++ )
    m[0][j] = T();
  for ( i = 1; i < m.numRows(); i++ )
    for ( j = 1; j < m.numCols(); j++ )
    {
      m[i][j] = T(i * j);
    }
}


void test_int_matrix(){
		Matrix < int > m(10,5);
		fillMatrix( m );
		cout << "Test int matrix:" << endl;
		cout << m;
	    try{
	    	Matrix <int> m(8,8);
	    	cout << m[99][99];
	    }
		catch ( IndexOutOfBoundsException & e)
		{
			cout << "Catch IndexError for element type 'int': Index out of bounds" <<endl;
			cout << endl;
		}
}

void test_double_matrix(){
	Matrix < double > M(8, 10);
	fillMatrix( M );
	cout << "Test double matrix:" << endl;
    cout << M;
    try{
    	Matrix <double> M(8, 8);
    	cout << M[99][99];
    }
	catch ( IndexOutOfBoundsException & e)
	{
		cout << "Catch IndexError for element type 'double': Index out of bounds" <<endl;
		cout << endl;
	}
}


int main()
{
	test_int_matrix();
	test_double_matrix();
	return 0;
}
