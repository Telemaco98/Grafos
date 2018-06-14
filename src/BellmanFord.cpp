#include "BellmanFord.h"

#define INFINITO 100000000

int bellmanFord (int origin, int destiny, Graph* graph) {
	int size = graph->getNodesAmount();
	
	int* distance = new int[ size ];
	int* origins = new int[ size ];

	for ( int i = 0; i < size; i++ ) {
		distance[i] = INFINITO;
		origins[i] = -1;
	}

	distance[origin] = 0;

	auto start_time = high_resolution_clock::now();
	bool result = calculateBellmanFord ( origin, destiny, graph, distance, origins);
	auto end_time = high_resolution_clock::now();

	int tempo = duration_cast<microseconds>( end_time - start_time ).count();

	if (result) doPathBellmanFord ( origin, destiny, origins );

	return tempo;
}

bool calculateBellmanFord (int origin, int destiny, Graph* graph, int* distance, int* origins) {
	for (int i = 1; i < graph->getNodesAmount(); i++) {
		for (int j = 0; j < graph->getNodesAmount(); j++) {
			auto adjacents = graph->neighborhood(j);
			for (auto a : adjacents) {
				if (distance[a.first] > distance[j] + a.second) { // first = adjacent node, second = weigth
					distance[a.first] = distance[j] + a.second;
					origins[a.first] = j;
				}
			}
		}
	}

	return (!hasNegativeCicle(graph, distance, origins));
}

bool hasNegativeCicle (Graph* graph, int* distance, int* origins) {
	for (int i = 0; i < graph->getNodesAmount(); i++) {
		auto adjacents = (graph->neighborhood(i));
		for (auto a : adjacents) {
			if (distance[a.first] > distance[i] + a.second) {// first = adjacent node, second = distance
				cout << "Ciclo negativo encontrado!!" << endl;
				return true;
			}
		}
	}
	return false;
}

void doPathBellmanFord (int origin, int destiny, int* origins) {
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