#include "Graph.h"

/** 
 * The constructor
 * @param nodesAmount The quantity of nodes
 */
Graph::Graph(int nodesAmount) {
	this->nodesAmount = nodesAmount;
	adj = new list<pair<int, int>>[nodesAmount];
}

/** Destroyer */
Graph::~Graph() {
	delete [] adj;
}

/** 
 * Returns the nodesAmount value
 * @return nodesAmount
 */
int Graph::getNodesAmount() {
	return nodesAmount;
}

/**
 * Adding a arrest in the list of origin node with a weight
 * @param originNode  The origin node 
 * @param arrivalNode The arrival node
 * @param weight      The arrest weight 
 */
void Graph::addArrest (int originNode, int arrivalNode, int weight) {
	pair<int, int> pair (arrivalNode, weight);
	adj[originNode].push_back(pair);
}

/**
 * Verify if a node has a neightbor
 * @param  node 			The node searcher
 * @param  neightborNode	The neighbor node
 * @return true if the node has neighbor and false in otherwise
 */
bool Graph::hasNeighbor (int node, int neightborNode) {
	for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
		pair<int, int> pair (*it);
		if (pair.first == neightborNode)
			return true;
	}

	return false;
}

/**
 * Returns the degree of a node
 * @param  node The node searched
 * @return      The size list of the node
 */
int Graph::nodeDegree (int node) {
	return adj[node].size();
}

/** 
 * Prints the graph like a adjacency list
 */
void Graph::print() {
	cout << "+===========================+" << endl;
	cout << "|           Graph           |" << endl;
	cout << "+===========================+" << endl;
	cout << "  Origin | Arrival | Weight  " << endl;
	cout << "+---------------------------+" << endl;

	for (int i = 0; i < nodesAmount; i++) {
		for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
			pair<int, int> pair (*it);
			cout << " " << (i + 1);
			cout << " - " << (pair.first + 1);
			cout << " - " << pair.second << endl;
		}
	}
	cout << "+===========================+" << endl;
}

int main () {
	Graph* graph = new Graph(3);

	graph->addArrest(0, 1, 1000);
	graph->addArrest(0, 2, 800);
	graph->addArrest(1, 2, 100);
	graph->addArrest(2, 0, 4000);
	graph->addArrest(2, 1, 3000);

	cout << graph->hasNeighbor(2, 1) << endl;
	graph->print();

	delete graph;

	return 0;
}