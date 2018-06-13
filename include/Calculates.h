#ifndef _CALCULATES_H_
#define _CALCULATES_H_ value

#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::string;
using std::to_string;

#include<cmath>

#include "ManageArchive.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Graph.h"

/**
 * @brief The function responsible by do the Empirical Analysis
 */
void calculates ();

/**
 * @brief This function does a repetition of the shortest path algorithms
 * @param times 	The time repeat quantity
 * @param graph 	The graph
 * @param origin 	The origin node
 * @param destiny 	The destiny node
 */
void repeatCalculus (int times, Graph* graph, int origin, int destiny);

/**
 * @brief 	This function calculates the standard deviation of the time values
 * @param 	vTimes  Vector with the times of the calculus
 * @param 	size 	The size of the vector
 * @return 	result 	The result of the media calculus
 */
float calculateTimeMedia (int vTimes[], int size);

#endif
