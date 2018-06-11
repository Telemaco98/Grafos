#include <iostream>
using std::cout;
using std::endl;
#include <set>
using std::set;

#include "Pair.h"


Pair::Pair(int v, int k) {
	value = v;
	key = k;
}

/**
 * Destructor
 */
Pair::~Pair() { }

/**
 * Retuns the pair key
 * @return value
 */
int Pair::getValue () {
	return value;
}

/**
 * Retuns the pair key
 * @return key
 */
int Pair::getKey () {
	return key;
}

/** 
 * Overhead of the operator <
 * @param 	Pair 	&p
 * @return 	true/false
 */ 
bool Pair::operator== (Pair &p) {
	if(key == p.key) return true;
	return false;
}

/**
 * Overhead of the operator <
 * @param 	Pair 	&p
 * @param 	Pair 	&p2
 * @return 	true/false
 */ 
bool operator< (Pair const&p1, Pair const&p2) {
	return (p1.value < p2.value);
}

/**
 * Sobrecarga do operador << 
 * @param 	ostream 	&o
 * @param 	Pair 	&p
 * @return 	p.print()
 **/ 
ostream& operator<<(ostream &o, Pair &p) {
	o << "( " << p.value << ", " << p.key << " )" << endl;
	return o;
}
