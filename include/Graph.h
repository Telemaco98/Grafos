/**
 * @file 	Graph.h
 * @brief 	This archive is responsible by create the class Graph. 
 * 			
 * @author 	Shirley Ohara (shirleyohara@ufrn.edu.br)
 * @since	09/06/2017
 * @data 	10/10/2017
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_ value

#include <iostream>
using std::pair;
using std::endl;
using std::cout;

#include <list>
using std::list;
using std::iterator;

/**
 * @class Graph
 * @brief A graph class has like fields the nodes amount and pointer for 
 * a adjancecy list of pair <int, int> that represents the arrivel 
 * node and the weight of the arrest. 
 */
class Graph {
	private:
		int nodesAmount;			/** < The nodes amount */
		list<pair<int, int>> *adj; 	/** < The list that has the adjacency list */

	public:
		/** The constructor */
		Graph(int nodesAmount);

		/** Destroyer */
		~Graph();

		/** Returns the nodesAmount value */
		int getNodesAmount();

		/** Add a arrest in the graph */
		void addArrest (int originNode, int arrivalNode, int weight);

		/** Returns if a node has */
		bool hasNeighbor (int node, int node2);

		/** Returns the degree of a node  */
		int nodeDegree (int node);

		/** Return all the nodes that are adjacenct to a node */
		list<pair<int, int>> neighborhood (int node);

		/** Prints the graph like a adjacency list */
		void print(); 
};

#endif