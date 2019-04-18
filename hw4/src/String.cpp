//============================================================================
// Name        : hw4.cpp
// Author      : Yihan Xu
// Version     :
// Copyright   : Your copyright notice
// Description : hw4 class definition
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
String::String(const char * s){
	buf = strdup(s);
}

String::String(const String & s){
	buf = strdup(s.buf);
}

String String::operator = (const String & s){
	buf = strdup(s.buf);
	return *this;
}

char &String::operator [] (int index){
	if(inBounds(index)){
		return buf[index];
	}
	else{
		cout << "Error, out of range" << endl;
	}
}

int String::size(){
	return strlen(buf);
}

String String::reverse(){
	String rev_str;
	int buf_len = strlen(buf);
	int i;
	for(i = 0; i < buf_len; i++){
		rev_str.buf[i] = buf[buf_len - 1 - i];
	}
	return rev_str;
}

int String::indexOf(const char c){
	if(strchr(buf, c) == 0){
		return -1;
	}
	else{
		return strchr(buf, c) - buf;
	}
}

int String::indexOf(const String pattern){
	if(strstr(buf, pattern.buf) == 0){
		return -1;
	}
	else{
		int index = strstr(buf, pattern.buf) - buf;
		return index;
	}
}

bool String::operator == (const String s){
	if(strcmp(buf, s.buf) == 0){
		return true;
	}
	else{
		return false;
	}
}
bool String::operator != (const String s){
	if(strcmp(buf, s.buf) == 0){
		return false;
	}
	else{
		return true;
	}
}
bool String::operator > (const String s){
	if(strcmp(buf, s.buf) > 0){
		return true;
	}
	else{
		return false;
	}
}
bool String::operator < ( const String s ){
	if(strcmp(buf, s.buf) < 0){
		return true;
	}
	else{
		return false;
	}
}
bool String::operator <= (const String s){
	if(strcmp(buf, s.buf) <= 0){
		return true;
	}
	else{
		return false;
	}
}
bool String::operator >= (const String s){
	if(strcmp(buf, s.buf) >= 0){
		return true;
	}
	else{
		return false;
	}
}

String String::operator + (const String s){
	char * another_char = strdup(buf);
	strcpy(another_char, buf);
	String plus = String(strcat(another_char, s.buf));
	delete_char_array(another_char);
	return plus;
}

String String::operator += (const String s){
	char * another_char = new_char_array(strlen(buf) + strlen(s.buf) + 1);
	strcpy(another_char, buf);
	String new_char = String(strcat(another_char, s.buf));
	delete_char_array(buf);
	buf = strdup(another_char);
	delete_char_array(another_char);
	return new_char;
}

void String::print(ostream & out){
	int i;
	for(i = 0; i < strlen(buf); i++){
		out << buf[i];
	}
}

void String::read( istream & in ){
	const int INPUT_SIZE = 888;
	char read[INPUT_SIZE];
	in.getline(read, 888);
	delete_char_array(buf);
	buf = strdup(read);
}

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

String::~String(){
	delete_char_array(buf);
}

//Private function
int String::strlen(const char *s){
	int string_len = 0;
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		++string_len;
	}
	return string_len;
}

char *String::strcpy(char *dest, const char *src){
	int i;
	for(i = 0; src[i] != '\0'; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

char *String::strcat(char *dest, const char *src){
	strcpy(dest + strlen(dest), src);
	return dest;
}

int String::strcmp(const char *left, const char *right){
	int i;
	int cmp = 0;
	for(i = 0; left[i] != '\0' and right[i] != '\0'; i++){
		if(left[i] != right[i]){
			cmp = left[i] - right[i];
			return cmp;
		}
	}
	return left[i] - right[i];
}


int String::strncmp(const char *left, const char *right, int n){
	int i;
	int ncmp;
	for(i = 0; i < n and left[i] != '\0' and right[i] != '\0'; i++){
		if(left[i] != right[i]){
			ncmp = left[i] - right[i];
			return ncmp;
		}
		else{
			continue;
		}
	}
	return 0;
}

char *String::strchr(const char *str, int c){
	for(; *str != '\0'; str++){
		if(*str == c){
			return (char*)str;
		}
	}
	return 0;
}

char *String::strstr(const char *haystack, const char *needle){
	int i;
	int haystack_len;
	int needle_len;
	haystack_len = strlen(haystack);
	needle_len = strlen(needle);
	if(needle_len < haystack_len){
		for(i = 0; i < haystack_len; i++){
			if(strncmp(haystack+i, needle, strlen(needle)) == 0){
				return (char*)haystack + i;
			}
			else{
				continue;
			}
		return 0;
		}
	}
	return 0;
}

char *String::strdup(const char *src){
	char *dest = new_char_array(strlen(src) + 1);
	return strcpy(dest, src);
}

char* String::new_char_array(int n_bytes){
	++allocations;
    return new char[n_bytes];
}

void String::delete_char_array(char *p){
    --allocations;
    if (allocations < 0){
    	cout << "Error, more delete[] than new[]" << endl;
    }
    delete [] p;
}
