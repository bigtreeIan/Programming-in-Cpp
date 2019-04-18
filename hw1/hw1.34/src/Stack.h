/*
 * Stack
 *
 *  Created on: 2016.1.13
 *      Author: Yihan Xu
 */
#define STACK_CAPACITY 1000
using namespace std;

class Stack{
private:
	char stack[1000];
	int index;

public:
	Stack(){
		index = 0;
		 // constructor for a stack
	}

    void push(char c){
    	if (index != 1000){
    		stack[index++] = c;
    	}
    	// adds c to the top of the stack
    }

    char pop(){
    	if (index != 0){
    		index--;
    	}
    		return top();
    		// removes top element
    }

    char top(){
    	return stack[index];// returns the top element
    }

    bool isEmpty(){
    	return index == 0;// returns true iff the stack is empty
    }

    bool isFull(){
    	return index == 1000;// returns true iff the stack is full
    }

    ~Stack(){} // destructor for a stack
  };
