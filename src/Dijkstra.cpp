#include "Dijkstra.h"
#define INFINITO 100000000

int dijkstra (int origin, int destiny, Graph* graph) {
	int size = graph->getNodesAmount();
	
	int* weigths = new int[size];
	int* origins   = new int[size];
	set<Pair> nodesWithoutCoust;

	for (int i = 0; i < size; i++) {
		origins[i]   = -1;
		weigths[i] = INFINITO;
		if (i != origin) {	
			Pair* pair = new Pair (INFINITO, i);
			nodesWithoutCoust.insert(*pair);
		}
	}

	Pair* pair = new Pair (0, origin);
	nodesWithoutCoust.insert(*pair);
	weigths[origin] = 0;

	auto start_time = high_resolution_clock::now();
	calculateDijkstra (origin, destiny, graph, weigths, origins, nodesWithoutCoust);
	auto end_time = high_resolution_clock::now();

	int tempo = duration_cast<milliseconds>(end_time - start_time).count();

	// doPathDijkstra (origin, destiny, origins);

	return tempo;
}

void calculateDijkstra (int origin, int destiny, Graph* graph, int* weigths, int* origins, set<Pair> nodesWithoutCoust) {
	while (!nodesWithoutCoust.empty()) {
		auto it = nodesWithoutCoust.begin();
		Pair pair = (*it);
		nodesWithoutCoust.erase(it);
		int node = pair.getKey(); // Node in the set with the smallest weigth

		auto adjacents = (graph->neighborhood(node));

		for (auto a : adjacents) {
			if (weigths[a.first] > weigths[node] + a.second) { // first = adjacent node, second = weigth
				weigths[a.first] = weigths[node] + a.second;
				origins[a.first] = node;

				Pair* p = new Pair (-1, a.first);
				Pair found = find (nodesWithoutCoust, *p);
				nodesWithoutCoust.erase(found);

				p = new Pair (weigths[a.first], a.first);
				nodesWithoutCoust.insert(*p);
			}
		}
	}
}

Pair find (set<Pair> nodesWithoutCoust, Pair p) {
	for (auto it = nodesWithoutCoust.begin(); it != nodesWithoutCoust.end(); it++) {
		Pair pairIt = (*it);
		if (p == pairIt) return pairIt;
	}
	return p;
}

void doPathDijkstra (int origin, int destiny, int* origins) {
	stack<int> path;
	int actual = destiny;

	while (actual != origin) {
		path.push(actual);
		actual = origins[actual];
	}
	path.push(actual);
	
	cout << " # | Path: " ;
	while (!path.empty()) {
		actual = path.top();
		cout << " " << actual;
		path.pop();
		
	}

	cout << endl;
}