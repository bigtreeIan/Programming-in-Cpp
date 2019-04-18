/*
 * hw5.h
 *
 *  Created on: 2016年2月8日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
class String{
	public:
    /// Both constructors should construct
    /// from the parameter s
	String( const char * s = "");
    String( const String & s );
    String operator = ( const String & s );
    char & operator [] ( const int index );
    int length() const {return ListNode::length(head);}
    int indexOf( char c ) const;
    bool operator == ( const String & s ) const;
    bool operator < ( const String & s ) const;
    /// concatenates this and s
    String operator + ( const String & s ) const;
    /// concatenates s onto end of this
    String operator += ( const String & s );
    void print( ostream & out );
    void read( istream & in );
    ~String();
    static void final_report_on_allocations();
    private:
    static int allocations;
    bool inBounds( int i )
    {
      return i >= 0 && i < length();
    }
    struct ListNode{
    	char info;
    	ListNode * next;
        ListNode(char newInfo, ListNode * newNext)
    	: info( newInfo ), next( newNext ){
        }// HINT: some primitives you *must* write and use, recursion?
        static ListNode * stringToList(const char *s);
        static char & findByIndex(ListNode * L, int n);

        static ListNode * copy(ListNode * L);
        static bool equal(ListNode * L1, ListNode * L2);
        static ListNode * concat(ListNode * L1, ListNode * L2);
        static int compare(ListNode * L1, ListNode * L2);
        static void deleteList(ListNode * L);
        static int length(ListNode * L); // O(N) so call rarely
        };
    ListNode * head; // no other data members!! - especially no len!
    };
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );
