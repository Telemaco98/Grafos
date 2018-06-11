/**
 * @file 	ManageArchive.h
 * @brief 	This archive is responsible by the manage the archives, like 
 *         	get data, put data or clean it in an archive.
 * 			
 * @author 	Shirley Ohara (shirleyohara@ufrn.edu.br)
 * @since	06/06/2017
 * @data 	10/10/2017
 */

#ifndef _MANAGEARCHIVE_H_
#define _MANAGEARCHIVE_H_ value

#include <iostream>
using std::endl;
using std::cout;
using std::atoi;
using std::atof;

#include <cstring>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

/**
 * @brief This function clean the output archive 
 */
void cleanOutputArchives ();

/**
 * This function will returns a matrix of a input archive
 * @param  pathArchive The path with the archive name
 * @return matriz      The archive matrix extracted 
 */
int** extractArchive (string pathArchive);

/**
 * This function will initialize a matrix with the input argument
 * @param  size 	The size of the Matrix
 * @return matrix 	The matrix initialized
 */
int** inicializeMatrix (int size);

/**
 * This function receive a matrix and free the memory
 * @param matrix The martix
 * @param size   The martix size 
 */
void releaseMemory (int** matrix, int size);

#endif