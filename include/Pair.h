#ifndef _PAIR_H_
#define _PAIR_H_

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

class Pair {
	private:
		int value;
		int key;
	public:
		Pair(int v, int k);

		~Pair();

		/** Returns the pair value */
		int getValue ();

		/** Returns the key value */
		int getKey ();

		/** Overhead of the operator */
		bool operator== (Pair &p);

		friend bool operator< (Pair const&p1, Pair const&p2);

		/** Overhead of the operator <= */ 
		friend ostream& operator<<(ostream &o, Pair &p);
};

#endif