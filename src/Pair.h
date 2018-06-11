#ifndef _PAIR_H_
#define _PAIR_H_

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

		/** Overhead of the operator < */ 
		bool operator< (Pair &p);

		/** Overhead of the operator <= */ 
		bool operator<= (Pair &p);
};

#endif