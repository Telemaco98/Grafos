#import "Dijkstra.h"
#define INFINITO 100000000

int dijkstra (int origin, int destiny, Graph* graph) {
	int size = graph->getNodesAmount();
	
	int* distances = new int[size];
	int* origins   = new int[size];
	set<int> nodesWithoutCoust;

	for (int i = 0; i < size; i++) {
		distances[i] = INFINITO;
		origins[i]   = -1;
		nodesWithoutCoust.insert(i);
	}

	distances[origin] = 0;
}

void calculateDijkstra (int origin, int destiny, Graph* graph, int* distances, int* origins, set<int> nodesWithoutCoust) {
	for (!nodesWithoutCoust.empty()) {
		node = extractMin(distances, graph->getNodesAmount());
		nodesWithoutCoust.erase(node);

		list<pair<int, int>> adjacents = graph->neighborhood(node);

		for (a : adjacents) {
			if (distances[a.first] > distances[node] + a.second) { // first = adjacent node, second = weigth
				distances[a.first] = d[node] + a.second;
				origin[a.first] = node;
			}
		}
	}

	doWay(origin, destiny, origins);
}

int extractMin(int* distances, int size) {
	int posSmaller = 0;
	for (int i = 1; i < size; i++) {
		if (distances[i] < distances[posSmaller])
			posSmaller = i;
	}

	return posSmaller;
}

void doWay (int origin, int destiny, int* origins) {

}