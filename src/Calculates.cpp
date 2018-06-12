#include "Calculates.h"

extern const string CALCULATING = " # | (ii)   | Calculating the path shortest with ";

void calculates () {
	cleanOutputArchives();
	int amountInputs = 11; //12
	
	for (int i = 0; i < amountInputs; i++) {
		string iString = to_string(i);
		string inputPath = "./data/input/USA-road-" + iString + ".gr";
		Graph* graph = extractArchive (inputPath);

		int origin  = rand () % (graph->getNodesAmount());
		int destiny = rand () % (graph->getNodesAmount());

		// Calculate shortest path with Dijkstra
		cout << CALCULATING + "Dijkstra ..." << endl;
		int time = dijkstra(origin, destiny, graph);
		cout << " # | TEMPO COM DIJKSTRA: " << time << endl;

		// Calculate shortest path with Belmanford
		// cout << CALCULATING + "Belmanford ..." << endl;
		// time = bellmanFord (origin, destiny, graph);
		// cout << " # | TEMPO COM BELLMANFORD: " << time << endl;

		// Calculate shortest path with Ford & Fulkerson
		// cout << CALCULATING + "Ford & Fulkerson ..." << endl;

		// Calculate shortest path with Floyd
		// cout << CALCULATING + "Floyd ..." << endl;

		delete graph; // freeing memory
	}
}