/*
 * MapArray.h
 *
 *  Created on: 2016年3月6日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;

#ifndef MAPARRAY_H_
#define MAPARRAY_H_

template<typename K, typename V>
class MapArray{
private:
	pair<K, V> * buf;
	int SIZE;

public:
	class iterator{
        typedef std::random_access_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef pair<K, V> value_type;
        typedef pair<K, V> & reference;
        typedef pair<K, V>* pointer;
        typedef ptrdiff_t difference_type;

	private:
        pair<K ,V> * PAIR;

	public:
        iterator(pair<K, V> * ptr): PAIR(ptr){};
        self_type operator ++ (){
        	PAIR++;
        	return *this;
        }
        self_type operator ++ (int postfix){
        	self_type cpy = *this;
        	PAIR++;
        	return *this;
        }
        self_type operator -- (){
        	PAIR--;
        	return *this;
        }
        self_type operator -- (int postfix){
        	self_type cpy = *this;
        	PAIR--;
        	return *this;
        }
        reference operator * (){
        	return * PAIR;
        }
        pointer operator -> (){
        	return PAIR;
        }
        bool operator == (const self_type & rhs) const{
        	return PAIR -> first == rhs.PAIR -> first;
        }
        bool operator != (const self_type & rhs) const{
        	return PAIR -> first != rhs.PAIR -> first;
        }
	};

	class const_iterator{
        typedef random_access_iterator_tag iterator_category;
        typedef const_iterator self_type;
        typedef pair<K, V> value_type;
        typedef pair<K, V> & reference;
        typedef pair<K, V>* pointer;
        typedef ptrdiff_t difference_type;
	private:
        pair<K, V> * PAIR;

	public:
        const_iterator(pair<K, V> * ptr): PAIR(ptr){};
        self_type operator ++ (){
        	PAIR++;
        	return *this;
        }

        self_type operator ++ (int postfix){
        	self_type cpy = *this;
        	PAIR++;
        	return *this;
        }

        const reference operator * (){
        	return * PAIR;
        }

        const pointer operator -> (){
        	return PAIR;
        }

        bool operator == (const self_type & rhs) const{
        	return PAIR -> first == rhs.PAIR -> first;
        }

        bool operator != (const self_type & rhs) const{
        	return PAIR -> first != rhs.PAIR -> first;
        }
	};

	MapArray(): SIZE(0), buf(new pair<K, V>[SIZE]){}
	MapArray(initializer_list< pair<K, V> > P): SIZE(P.SIZE()), buf(new pair<K, V>[P.SIZE]){
    	uninitialized_copy(P.begin(), P.end(), buf);
	}
    iterator begin(){
    	return iterator(buf);
    }
    iterator end(){
    	return iterator(buf + SIZE);
    }
    const_iterator begin() const{
    	return const_iterator(buf);
    }
    const_iterator end() const {
    	return const_iterator(buf + SIZE);
    }
    V& operator [] (K key){
    	for(int i = 0; i < SIZE; i++){
    		if(key == buf[i].first()){
    			return buf[i].second;
    		}
    	}
    }
    const V& operator [] (K key) const{
    	for(int i = 0; i < SIZE; i++){
    		if(key == buf[i].first()){
    			return buf[i].second;
    		}
    	}
    }
    int size() const{
    	return SIZE;
    }
	~MapArray(){
		delete[] buf;
	}
};

#endif /* MAPARRAY_H_ */
