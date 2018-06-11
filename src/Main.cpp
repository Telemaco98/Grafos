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
	int origin  = 0;//rand () % (graph->getNodesAmount());
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
	return 0
}
	/*Graph* graph = new Graph(11);

	graph->addArrest(0, 1, 1000);
	graph->addArrest(0, 2, 800);
	graph->addArrest(1, 2, 608);
	graph->addArrest(2, 0, 107);
	graph->addArrest(2, 5, 780);
	graph->addArrest(2, 6, 600);
	graph->addArrest(6, 7, 330);
	graph->addArrest(6, 9, 500);
	graph->addArrest(7, 1, 3000);
	graph->addArrest(7, 10, 3000);
	graph->addArrest(8, 5, 600);
	graph->addArrest(8, 10, 600);
	graph->addArrest(8, 0, 4000);
	graph->addArrest(8, 9, 100);
	graph->addArrest(9, 10, 600);
	graph->addArrest(10, 1, 30);
	graph->addArrest(10, 4, 120);
	graph->addArrest(10, 2, 1901);

	graph->print();*/