#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_ value

#include <list>
using std::list;

#include <set>
using std::set;

#include <stack>
using std::stack;

#include <chrono>
using namespace std::chrono;

#include "Graph.h"
#include "Pair.h"

int dijkstra (int origin, int destiny, Graph* graph);

void calculateDijkstra (int origin, int destiny, Graph* graph, int* weigths, int* origins, set<Pair> nodesWithoutCoust);

Pair find (set<Pair> nodesWithoutCoust, Pair p);

void doPathDijkstra (int origin, int destiny, int* origins);


#endif