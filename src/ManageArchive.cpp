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

/**
 * @brief This function clean the output archive 
 */
void cleanOutputArchives () {
	cout << " # ================================================" << endl;
	cout << " # Cleaning the output archives ..." << endl;
	string pathArchive = "../data/output/output.dat";

	ofstream output;
	output.open (pathArchive.c_str());
	output.clear ();
	output.close ();
}

/**
 * This function will returns a matrix of a input archive
 * @param  pathArchive The path with the archive name
 * @return matriz      The archive matrix extracted 
 */
int** extractArchive (string pathArchive) {
	ifstream input(pathArchive.c_str());
	int** matrix = NULL;

	if (!input) {
		cout << " # ERROR: Can not read the input archive, it doesn't exists!" << endl;
	} else {
		cout << " # Initializing the matrix ..." << endl;
		string archiveHeader;
		getline(input, archiveHeader);
		cout << " # " << archiveHeader << endl; // print the header archive

		string matrixSizeString;
		getline(input, matrixSizeString); // getting the matrix size
		int matrixSize = atoi(matrixSizeString.c_str());

		int **matrix = inicializeMatrix (matrixSize);

		cout << " # Extracting the matrix of " + pathArchive << endl;
		
		while (!input.eof()) {
			string a;
			input >> a;
			int arrestI, arrestJ, distance;
			input >> arrestI >> arrestJ >> distance;

			matrix[arrestI][arrestJ] = distance;
		}
	}
	return matrix;
}

/**
 * This function will initialize a matrix with the input argument
 * @param  size 	The size of the Matrix
 * @return matrix 	The matrix initialized
 */
int ** inicializeMatrix (int size) {
	int** matrix = NULL;
	matrix = new int*[size];
	for ( int i = 0; i < size; i++ )
		matrix[i] = new int[size];

	cout << " # " << endl;
	cout << " # ================================================" << endl;
	cout << " # Setting all matrix positions with zero ..." << endl;
	for ( int i = 0; i < size; i++ ) {
		for ( int j = 0; j < size; j++ ) 
			matrix[i][j] = 0;
	}

	return matrix;
}

/**
 * This function receive a matrix and release the memory occuped by it
 * @param matrix The martix
 * @param size   The martix size 
 */
void releaseMemory (int** matrix, int size) {
	cout << " # " << endl;
	cout << " # Releasing the memory occuped by the matrix " << size << "x" << size << " ..."<< endl;

	for ( int i = 0; i < size; i++)
		delete [] matrix [i];

	delete [] matrix;
}