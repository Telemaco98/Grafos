#ifndef _BELLMANFORD_H_
#define _BELLMANFORD_H_ value

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

int bellmanFord (int origin, int destiny, Graph* graph);

bool calculateBellmanFord(int origin, int destiny, Graph* graph, int* distances, int* origins);

bool hasNegativeCicle (Graph* graph, int* weigths, int* origins);

void doPathBellmanFord (int origin, int destiny, int* origins);

#endif