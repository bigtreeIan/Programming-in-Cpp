/*
 * SetList.h
 *
 *  Created on: 2016年3月6日
 *      Author: xuyihan
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#ifndef SETLIST_H_
#define SETLIST_H_

template <typename S>
class SetList{
private:
	template <typename L>
	struct ListNode{
		L info;
		ListNode *next;
		ListNode(L newinfo, ListNode * newnext): info(newinfo), next(newnext){};
		static int length(ListNode * N){
			if(N == nullptr){
				return 0;
			}
			else{
				return (1 + length(N -> next));
			}
		}

        static ListNode * copy(ListNode * N){
        	if(N == nullptr){
        		return nullptr;
        	}
        	else{
        		return new ListNode(N -> info, copy(N -> next));
        	}
        }

        static char & findByIndex(ListNode * N, int n){
        	if(N == nullptr){
        		return (char &) "\0";
        	}
        	else if(n == 0){
        		return N -> info;
        	}
        	else{
        		return findByIndex(N -> next, n - 1);
        	}
        }

        static void inserter(ListNode * N, S something){
        	if((N -> info).compare(something) > 0){
        		ListNode * temp = N;
        		for(int i = 0; temp -> next; i++){
        			temp = temp -> next;
        			if((temp -> info).compare(something) < 0){
        				break;
        			}
        		}
        		temp -> next = new ListNode<S> (something, temp -> next);
        	}
        	else{
        		ListNode * temp1 = N;
        		temp1 = new ListNode<S> (something, N);
        	}
        }

        static void deleteList(ListNode * N){
        	if(N != nullptr){
        		deleteList(N -> next);
        	    delete N;
        	}
        }
	};
    ListNode<S> * head;

public:
	class iterator{
        typedef std::forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef S value_type;
        typedef S & reference;
        typedef S* pointer;
        typedef ptrdiff_t difference_type;
        private:
        ListNode<S> * head_i;
        public:
        iterator(ListNode<S> * ptr): head_i(ptr){};
        self_type operator ++ (){
        	head_i = head_i -> next;
        	return *this;
        }
        self_type operator ++ (int postfix){
        	self_type cpy = *this;
        	head_i = head_i -> next;
        	return *this;
        }
        reference operator * (){
        	return head_i -> info;
        }
        pointer operator -> (){
        	return &(head_i -> info);
        }
        bool operator == (const self_type & rhs) const{
        	return head_i -> info == rhs.head_i -> info;
        }
        bool operator != (const self_type & rhs) const{
        	return head_i -> info != rhs.head_i -> info;
        }
	};

	class const_iterator{
		typedef std::forward_iterator_tag iterator_category;
        typedef const_iterator self_type;
        typedef S value_type;
        typedef S & reference;
        typedef S * pointer;
        typedef ptrdiff_t difference_type;
        private:
        ListNode<S> * head_iconst;
        public:
        const_iterator(ListNode<S> * ptr): head_iconst(ptr){};
        self_type operator ++ (){
        	head_iconst = head_iconst -> next;
        	return *this;
        }
        self_type operator ++ (int postfix){
        	self_type cpy = *this;
        	head_iconst = head_iconst -> next;
        	return *this;
        }
        const reference operator * (){
        	return head_iconst -> info;
        }
        const pointer operator -> (){
        	return &(head_iconst -> info);
        }
        bool operator == (const self_type & rhs) const{
        	return head_iconst -> info == rhs.head_iconst -> info;
        }
        bool operator != (const self_type & rhs) const{
        	return head_iconst -> info != rhs.head_iconst -> info;
        }
	};

	SetList( S s1 = S()) : head(new ListNode<S>(s1, nullptr)) {}
    SetList(initializer_list<S> s2): head(s2.head){
    	uninitialized_copy(s2.begin(), s2.end(), head);
    }

    S & operator[](int index){
    	return ListNode<S>::findByIndex(head, index);
    };

    const S& operator[](int index) const {
    	return ListNode<S>::findByIndex(head, index);
    }

    iterator begin(){
    	return iterator(head);
    }

    iterator end(){
    	ListNode<S> * temp_head = head;
    	for(int i = 0; temp_head; i++){
    		temp_head = temp_head -> next;
    	}
    	return iterator(temp_head);
    }

    const_iterator begin() const{
    	return const_iterator(head);
    }

    const_iterator end() const {
    	ListNode<S> * temp_head = head;
    	for(int i = 0; temp_head; i++){
    		temp_head = temp_head -> next;
    	}
    	return const_iterator(temp_head);
    }

    iterator find(S something){
    	ListNode<S> * temp = head;
    	for(int i = 0; i < ListNode<S>::length(head); i++){
    		if(temp -> info == something){
    			return iterator(temp);
    		}
    		else{
    		temp = temp -> next;
    		}
    	}
		return end();
    }

    const_iterator find(S something) const{
    	ListNode<S> * temp = head;
    	for(int i = 0; i < ListNode<S>::length(head); i++){
    		if(temp -> info == something){
    			return iterator(temp);
    		}
    		else{
    		temp = temp -> next;
    		}
    	}
		return end();
    }

    void insert(S something){
    	ListNode<S>::inserter(head, something);
    }

    int size(){
    	return ListNode<S>::length(head);
    }

    ~SetList(){
    	ListNode<S>::deleteList(head);
    };
};

#endif /* SETLIST_H_ */
