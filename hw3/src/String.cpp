//============================================================================
// Name        : string.cpp
// Author      : Yihan Xu
// Version     :
// Copyright   : Your copyright notice
// Description : hw3 main function and class definition
//============================================================================
#include <iostream>
#include "String.h"
using namespace std;

//Constructor and Public function
String::String(const char *s){
	int i;
	int end;
	for(i = 0; i < strlen(s); i++){
		buf[i] = s[i];
	}
	end = strlen(s);
	buf[end] = '\0';
}

String::String(const String & s){
	int i;
	int end;
	for(i = 0; i < strlen(s.buf); i++){
		buf[i] = s.buf[i];
	}
	end = strlen(s.buf);
	buf[end] = '\0';
}

String String::operator = (const String & s){
	String new_buf;
	strcpy(new_buf.buf, s.buf);
	return String(new_buf.buf);
}

char & String::operator [] (int index){
	if(inBounds(index)){
		return buf[index];
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
		return strstr(buf, pattern.buf) - buf;
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
	String copy_string;
	strcpy(copy_string.buf, buf);
	return String(strcat(copy_string.buf, s.buf));
}

String String::operator += (const String s){
	return String(strcat(buf, s.buf));
}

void String::print(ostream & out){
	int i;
	for(i = 0; i < strlen(buf); i++){
		out << buf[i];
	}
}
void String::read( istream & in ){
	in >> buf;
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
	int cmp;
	for(i = 0; left[i] != '\0' and right[i] != '\0'; i++){
		if(left[i] != right[i]){
			cmp = left[i] - right[i];
			return cmp;
		}
	}
	return 0;
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
	return 0;
	}
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
			if(haystack[i] == needle[i]){
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

String::~String(){
}

ostream & operator << ( ostream & out, String str ){
	str.print(out);
	return out;
}
istream & operator >> ( istream & in, String & str ){
	str.read(in);
	return in;
}








