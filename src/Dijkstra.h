#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_ value

#import <list>
using std::list;

#import <set>
using std::set;

#import "Graph.h"

void dijkstra (int origin, int destiny, Graph* graph);

void calculateDijkstra (int origin, int destiny, Graph* graph, int* distances, int* origins, set<int> nodesWithoutCoust);

int extractMin(int* distances, int size);

void doWay (int origin, int destiny, int* origins);

#endif