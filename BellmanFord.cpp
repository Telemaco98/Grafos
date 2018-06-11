#include "BellmanFord.h"

#define INFINITO 100000000

int BellmanFord( int origin, int destiny, Graph* graph )
{
	int size = graph->getNodesAmount();
	
	int* distances = new int[ size ];
	int* origins   = new int[ size ];
	set<Pair> nodesWithoutCoust;

	for ( int i = 0; i < size; i++ ) {
		origins[ i ]   = -1;
		distances[ i ] = INFINITO;
		if ( i != origin ) {	
			Pair pair = new Pair ( INFINITO, i );
			nodesWithoutCoust.insert( pair );
		}
	}

	pair<int, int> pair ( 0, origin );
	nodesWithoutCoust.insert( pair );
	distances[ origin ] = 0;

	auto start_time = high_resolution_clock::now();
	bool calculateBellmanFord ( origin, destiny, graph, distances, origins, nodesWithoutCoust );
	auto end_time = high_resolution_clock::now();

	int tempo = duration_cast<microseconds>( end_time - start_time ).count();

	doWay ( origin, destiny, origins );

	return tempo;
}


bool calculateBellmanFord ( int origin, int destiny, Graph* graph, int* distances, int* origins, set<Pair> nodesWithoutCoust )
{
	set<Pair> allNodes;	
	while ( !nodesWithoutCoust.empty() ) 
	{
		auto it = nodesWithoutCoust.begin();
		Pair pair = *it;
		allNodes.insert( pair ); // set used to verify the negative cicles
		nodesWithoutCoust.erase(it);
		int node = pair.getValue; // Node in the set with the smallest weigth

		list<pair<int, int>> adjacents = graph->neighborhood(node);

		for (a : adjacents) 
		{
			if (distances[a.first] > distances[node] + a.second) // first = adjacent node, second = weigth
			{ 
				distances[a.first] = distances[node] + a.second;
				origins[a.first] = node;
			}
		} 
	}

	while( !allNodes.empty() )
	{
		auto it = allNodes.begin();
		Pair pair = *it;
		allNodes.erase( it );
		int node = pair.getValue;

		list<pair<int, int>> adjacents = graph->neighborhood(node);

		for (a : adjacents) 
		{
			if (distances[a.first] > distances[node] + a.second) // first = adjacent node, second = weigth
			{ 
				cout << "Ciclo negativo encontrado!!" << endl;
				return false;
			}
		} 

	}

	return true;
}