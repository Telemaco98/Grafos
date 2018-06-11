/**
 * @file 	Main.cpp
 * @brief 	The principal archive that manage the system. The goal of
 * 			this system is to do the empirical analysis about the 
 * 			Dijkstra's algorithm, that is an algorithm for finding the
 * 			shortest paths between nodes in a graph.
 * 			
 * @author 	Shirley Ohara (shirleyohara@ufrn.edu.br)
 * @since	06/06/2017
 * @data 	10/10/2017
 */
#include <iostream>
using std::cout;
using std::endl;

#include "ManageArchive.h"
#include "Calculates.h"
#include "Graph.h"

#include <cstdlib>
#include "Dijkstra.h"

/**
 * @return 0 
 */
int main () {
	cleanOutputArchives ();
	Graph* graph = extractArchive ("../data/input/USA-road-d.NY.gr");

	srand(time(NULL));
	int origin  = rand () % (graph->getNodesAmount());
	int destiny = rand () % (graph->getNodesAmount());

	cout << " # | (ii)   | Calculando caminha mais curto com Dijkstra ..." << endl;
	cout << " # +--------+-------------------------------------- " << endl;
	cout << " # | " << origin+1 << " e " << destiny+1 << endl;
	int time = dijkstra(origin, destiny, graph);
	cout << "Tempo de resulta entre " << origin+1 << " e " << destiny+1 << ", foi " << time << endl;

	cout << " # | (4)   | Deleting the graph ..." << endl;
	cout << " # ================================================" << endl;

	delete graph;

	// calculate();
	return 0;
}