//============================================================================
// Name        : hw5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : hw5.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "String.h"
using namespace std;
int String::allocations = 0;

//operator << and >>
ostream & operator << ( ostream & out, String str ){
	str.print(out);
	return out;
}
istream & operator >> ( istream & in, String & str ){
	str.read(in);
	return in;
}

//Constructor and Public function
void String::final_report_on_allocations(){
      if (allocations > 0){
    	  cout << "Error, Memory Leak in class String" << endl;
      }
      if (allocations < 0){
    	  cout << "Error, Too many delete[]s in class String" << endl;
      }
      if (allocations == 0){
          cout << "allocations: " << allocations << ", Allocations & deallocations match\n";
      }
}

String::String(const char * s){
	head = ListNode::stringToList(s);
}

String::String(const String & s){
	head = ListNode::copy(s.head);
}

String String::operator = (const String & s){
	ListNode::deleteList(head);
	head = ListNode::copy(s.head);
	return *this;
}

char & String::operator [] (const int index){
	int counter = 0;
	ListNode*temp = head;
	if(inBounds(index)){
		for(int i = 0; i < ListNode::length(head); i++){
			if(counter == index){
				return temp -> info;
			}
			else{
				temp = temp->next;
				counter++;
			}
		}
	}
	else{
		cout<<"ERROR, OUT OF RANGE"<<endl;
	}
}

int String::indexOf(char c) const{
	int i;
	ListNode *temp = head;
	for(i = 0; i < ListNode::length(head); i++){
		if( temp->info == c){
			return i;
		}
		else{
			temp = temp -> next;
		}
	}
	return -1;
}

bool String::operator == (const String & s) const{
	return ListNode::equal(head, s.head);
}

bool String::operator < (const String & s) const{
	if((ListNode::compare(head, s.head)) < 0){
		return true;
	}
	else{
		return false;
	}
}

String String::operator + (const String & s) const{
	ListNode *newlist = ListNode::copy(head);
	String newclass;
	newclass.head = ListNode::concat(newlist, s.head);
	return newclass;
}

String String::operator += (const String & s){
	ListNode * backup = head;
	head = ListNode::concat(head, s.head);
	ListNode::deleteList(backup);
	return *this;
}

void String::print(ostream & out){
	for(ListNode * temp = head; temp != 0; temp = temp -> next){
		out << temp -> info;
	}
}
void String::read(istream & in){
	ListNode::deleteList(head);
	char adptor[888];
	in.getline(adptor, 888);
	head = ListNode::stringToList(adptor);
}
String::~String(){
	ListNode::deleteList(head);
}

//Private function
char & String::ListNode::findByIndex(ListNode * Lk, int i){
	if(Lk == nullptr){
		return (char &) "\0";
	}
	else if(i == 0){
		return Lk->info;
	}
	else{
		return findByIndex(Lk->next, i - 1);
	}
}


String::ListNode * String::ListNode::stringToList(const char *s){
	ListNode * head = new ListNode(*s, nullptr);
	if(!*s){
		return nullptr;
	}
	else{
		s++;
		head -> next = stringToList(s);
	}
	return head;
}

String::ListNode * String::ListNode::copy(ListNode * L){
	if(L == nullptr){
		return nullptr;
	}
	else{
		return new ListNode(L->info, copy(L -> next));
	}
}

bool String::ListNode::equal(ListNode * L1, ListNode * L2){
	if(L1 == nullptr and L2  == nullptr){
		return true;
	}
	else if(L1 == nullptr and L2 != nullptr){
		return false;
	}
	else if(L1 != nullptr and L2 == nullptr){
		return false;
	}
	else if(L1 != nullptr and L2 != nullptr){
		if((L1 -> info) - (L2 -> info) == 0){
			return equal(L1 -> next, L2 -> next);
		}
		else{
			return false;
		}
	}
}

String::ListNode * String::ListNode::concat(ListNode * L1, ListNode * L2){
	if(L1 == nullptr){
		return copy(L2);
	}
	else{
		return new ListNode(L1 -> info, concat(L1 -> next, L2));
	}
}

int String::ListNode::compare(ListNode * L1, ListNode * L2){
	int cmp = 0;
	if(L1 == nullptr and L2 == nullptr){
		return cmp;
	}
	else if(L1 != nullptr and L2 == nullptr){
		cmp = L1 -> info - 0;
		return cmp;
	}
	else if(L1 == nullptr and L2 != nullptr){
		cmp = 0 - L2 -> info;
		return cmp;
	}
	else if(L1 != nullptr and L2 != nullptr){
		if(L1 -> info != L2 -> info){
			cmp = L1 -> info - L2 -> info;
			return cmp;
		}
		else{
			return compare(L1 -> next, L2 -> next);
		}
	}
}

void String::ListNode::deleteList(ListNode * L){
	if(L != nullptr){
		deleteList(L -> next);
	    delete L;
	}
}

int String::ListNode::length(ListNode * L){
	if(L == nullptr){
		return 0;
	}
	else{
		return 1 + length(L -> next);
	}
}




