#include "Dijkstra.h"
#define INFINITO 100000000

int dijkstra (int origin, int destiny, Graph* graph) {
	int size = graph->getNodesAmount();
	
	int* distances = new int[size];
	int* origins   = new int[size];
	set<Pair> nodesWithoutCoust;

	for (int i = 0; i < size; i++) {
		origins[i]   = -1;
		distances[i] = INFINITO;
		if (i != origin) {	
			Pair* pair = new Pair (INFINITO, i);
			nodesWithoutCoust.insert(*pair);
		}
	}

	Pair* pair = new Pair (0, origin);
	nodesWithoutCoust.insert(*pair);
	distances[origin] = 0;

	auto start_time = high_resolution_clock::now();
	calculateDijkstra (origin, destiny, graph, distances, origins, nodesWithoutCoust);
	auto end_time = high_resolution_clock::now();

	int tempo = duration_cast<microseconds>(end_time - start_time).count();

	doWay (origin, destiny, origins);

	return tempo;
}

void calculateDijkstra (int origin, int destiny, Graph* graph, int* distances, int* origins, set<Pair> nodesWithoutCoust) {
	while (!nodesWithoutCoust.empty()) {
		auto it = nodesWithoutCoust.begin();
		Pair pair = (*it);
		nodesWithoutCoust.erase(it);
		int node = pair.getValue(); // Node in the set with the smallest weigth

		auto adjacents = (graph->neighborhood(node));

		for (auto a : adjacents) {
			if (distances[a.first] > distances[node] + a.second) { // first = adjacent node, second = weigth
				distances[a.first] = distances[node] + a.second;
				origins[a.first] = node;

				Pair* p = new Pair (-1, a.first);
				Pair found = find (nodesWithoutCoust, *p);
				nodesWithoutCoust.erase(found);

				p = new Pair (distances[a.first], a.first);
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

void doWay (int origin, int destiny, int* origins) {
	int actual = destiny;
	cout << "Way: " << actual;
	while (actual != origin) {
		actual = origins[actual];
		cout << " " << actual;
	}

	cout << endl;
}