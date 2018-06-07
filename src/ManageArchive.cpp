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
	cout << " # Cleaning the output archives..." << endl;
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
float** extractArchive (string pathArchive) {
	ifstream input(pathArchive.c_str());
	float** matrix = NULL;

	if (!input) {
		cout << " # ERROR: Can not read the input archive, it doesn't exists!" << endl;
	} else {
		cout << " # Initializing the matrix ..." << endl;
		
		string matrixSizeString;
		getline(input, matrixSizeString); // getting the matrix size
		int matrixSize = atoi(matrixSizeString.c_str());

		float **matrix = inicializeMatrix (matrixSize);

		cout << " # Extracting the matrix of " + pathArchive << endl;

		for ( int i = 0; i < matrixSize; i++ ) {
			for ( int j = 0; j < matrixSize; j++ ) {
				string valueString;
				input >> valueString;
				// cout << valueString + " " ;
				matrix[i][j] = atof(valueString.c_str());
			}
			// cout << endl;
		}
	}
	return matrix;
}

/**
 * This function will initialize a matrix with the input argument
 * @param  size 	The size of the Matrix
 * @return matrix 	The matrix initialized
 */
float ** inicializeMatrix (int size) {
	float** matrix = new float*[size];
	for ( int i = 0; i < size; i++ )
		matrix[i] = new float[size];

	return matrix;
}