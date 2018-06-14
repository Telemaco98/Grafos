/**
 * @file 	ManageArchive.cpp
 * @brief 	This archive is responsible by declare the funtions for be 
 *          implemented in the ManageArchive.cpp
 * 			
 * @author 	Shirley Ohara (shirleyohara@ufrn.edu.br)
 * @since	06/06/2017
 * @data 	10/10/2017
 */

#include "ManageArchive.h"
extern const string ARCHIVES_OUT_PATH = "./data/output/times.dat";

/**
 * @brief This function clean the output archive 
 */
void cleanOutputArchives () {
	cout << " # ================================================" << endl;
	cout << " # | (1)    | Cleaning the output archives ..." << endl;
	cout << " # +--------+-------------------------------------- " << endl;

	ofstream output;
	output.open (ARCHIVES_OUT_PATH.c_str());
	output.clear ();
	output.close ();
}

/**
 * This function will returns a graph of a input archive
 * @param  pathArchive The path with the archive name
 * @return graph       The archive matrix extracted 
 */
Graph* extractArchive (string pathArchive) {
	ifstream input(pathArchive.c_str());
	Graph* graph = NULL;

	if (!input) {
		cout << " # ERROR: Can not read the input archive, it doesn't exists!" << endl;
	} else {
		cout << " # | (i)    | Opening the archive  ..." << endl;
		cout << " # |--------+-------------------------------------- " << endl;
		string archiveHeader;
		getline(input, archiveHeader);
		cout << " # | Header archive: " << archiveHeader << endl; // print the header archive

		int graphSize;
		input >> graphSize; // getting the graph size

		cout << " # | (i.i)  | Initializing the graph ..." << endl;
		graph = new Graph(graphSize);

		cout << " # | (i.ii) | Extracting the graph of " + pathArchive << endl;
		cout << " # +---------------------------------------------- " << endl;
		
		while (!input.eof()) {
			string a;
			input >> a;
			int arrestI, arrestJ, distance;
			input >> arrestI >> arrestJ >> distance;
			
			graph->addArrest(arrestI-1, arrestJ-1, distance);
		}
	}
	return graph;
}

/**
 * This function put the time data results in the output ar
 * @param sizeGraph The size of the graph calculated
 * @param vTimes 	The vetor with the media of the algoritmhs time result
 * @param sizeV 	The size of the vector
 */
void loadDataInArchive (int sizeGraph, float* vTimes, int sizeV) {
	ofstream output;
	output.open(ARCHIVES_OUT_PATH.c_str(), ios::app);

	output << sizeGraph;
	for (int i = 0; i < sizeV; i++)
		output << " " << vTimes[i];

	output << endl;
	output.close();
}