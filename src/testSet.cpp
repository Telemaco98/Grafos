#include <iostream>
using std::pair;
using std::cout;
using std::endl;

#include <list>
using std::iterator;

#include <set>
using std::set;

#include "Pair.h"

int main() {
	set <Pair> setP;
	Pair* pair = new Pair(1000, 2);
	setP.insert(*pair);
	// pair = new Pair(1000, 4);
	// setP.insert(pair);
	// pair = new Pair(1000, 6);
	// setP.insert(pair);

	// Pair* searcher = new Pair(1000, 4);
	// auto it = setP.find(searcher);
	// Pair* p = (*it);

	// cout << "Pair enconxtrado: value " << p->getValue() << ", key" << p->getKey() << endl;
}