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

/**
 * @return 0 
 */
int main () {
	cleanOutputArchives ();
	Graph* graph = extractArchive ("../data/input/USA-road-d.NY.gr");
	// graph->print();

	cout << " # | (ii)   | Deleting the graph ..." << endl;
	cout << " # ================================================" << endl;
	delete graph;

	// calculate();
	return 0;
}