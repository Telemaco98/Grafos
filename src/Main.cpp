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

/**
 * @return
 */
int main () {
	cleanOutputArchives ();
	extractArchive ("../data/input/16x16.txt");

	// calculate();
 	
	return 0;
}