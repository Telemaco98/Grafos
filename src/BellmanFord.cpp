#include "BellmanFord.h"

#define INFINITO 100000000

int bellmanFord (int origin, int destiny, Graph* graph) {
	int size = graph->getNodesAmount();
	
	int* weigths = new int[ size ];
	int* origins = new int[ size ];
	set<Pair> nodesWithoutCoust;

	for ( int i = 0; i < size; i++ ) {
		origins[ i ]   = -1;
		weigths[ i ] = INFINITO;
		if ( i != origin ) {	
			Pair* pair = new Pair ( INFINITO, i );
			nodesWithoutCoust.insert(*pair);
		}
	}

	Pair* pair = new Pair (0, origin);
	nodesWithoutCoust.insert(*pair);
	weigths[origin] = 0;

	auto start_time = high_resolution_clock::now();
	calculateBellmanFord ( origin, destiny, graph, weigths, origins, nodesWithoutCoust );
	auto end_time = high_resolution_clock::now();

	int tempo = duration_cast<microseconds>( end_time - start_time ).count();

	doPathBellmanFord ( origin, destiny, origins );

	return tempo;
}


bool calculateBellmanFord (int origin, int destiny, Graph* graph, int* weigths, int* origins, set<Pair> nodesWithoutCoust) {
	set<Pair> allNodes;	
	while ( !nodesWithoutCoust.empty() ) {
		auto it = nodesWithoutCoust.begin();
		Pair pair = *it;
		allNodes.insert( pair ); // set used to verify the negative cicles
		nodesWithoutCoust.erase(it);
		int node = pair.getKey(); // Node in the set with the smallest weigths

		auto adjacents = graph->neighborhood(node);

		for (auto a : adjacents) {
			if (weigths[a.first] > weigths[node] + a.second) {// first = adjacent node, second = weigths
				weigths[a.first] = weigths[node] + a.second;
				origins[a.first] = node;
			}
		}
	}

	while( !allNodes.empty() ) {
		auto it = allNodes.begin();
		Pair pair = *it;
		allNodes.erase( it );
		int node = pair.getKey();

		auto adjacents = graph->neighborhood(node);

		for (auto a : adjacents)  {
			if (weigths[a.first] > weigths[node] + a.second) {// first = adjacent node, second = weigths
				cout << "Ciclo negativo encontrado!!" << endl;
				return false;
			}
		} 

	}
	return true;
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