#include "Calculates.h"

extern const string CALCULATING = " # | (ii)   | Calculating the path shortest with ";
extern const string ARCHIVES_OUT_PATH = "./data/output/times.dat";

/**
 * @brief The function responsible by do the Empirical Analysis
 */
void calculates () {
	cleanOutputArchives();
	int amountInputs = 11; //12
	int timesToRepeat = 10;
	
	for (int i = 0; i < amountInputs; i++) {
		string iString = to_string(i);
		string inputPath = "./data/input/USA-road-" + iString + ".gr";
		Graph* graph = extractArchive (inputPath);

		int origin  = rand () % (graph->getNodesAmount());
		int destiny = rand () % (graph->getNodesAmount());
		
		repeatCalculus(timesToRepeat, graph, origin, destiny);

		delete graph; // freeing memory
	}
}

/**
 * @brief This function does a repetition of the shortest path algorithms
 * @param times 	The time repeat quantity
 * @param graph 	The graph
 * @param origin 	The origin node
 * @param destiny 	The destiny node
 */
void repeatCalculus (int times, Graph* graph, int origin, int destiny) {
	int algorithmsQuantity = 1; // 4
	int* vectorTimeDijkstra = new int[times];
	// int vectorTimeBellmanFord[times];
	// int vectorTimeFF[times];
	// int vectorTimeFloyd[times];

	for (int i = 0; i < times; i++) {
		// Calculate shortest path with Dijkstra
		cout << CALCULATING + "Dijkstra ..." << endl;
		vectorTimeDijkstra[i] = dijkstra(origin, destiny, graph);
		// cout << " # | TEMPO COM DIJKSTRA: " << vectorTimeDijkstra[i] << endl;

		// Calculate shortest path with Belmanford
		// cout << CALCULATING + "Belmanford ..." << endl;
		// time = bellmanFord (origin, destiny, graph);
		// cout << " # | TEMPO COM BELLMANFORD: " << time << endl;

		// Calculate shortest path with Ford & Fulkerson
		// cout << CALCULATING + "Ford & Fulkerson ..." << endl;

		// Calculate shortest path with Floyd
		// cout << CALCULATING + "Floyd ..." << endl;
	}

	float* vectorTimeMedia = new float[algorithmsQuantity];
 
	vectorTimeMedia[0] = calculateTimeMedia (vectorTimeDijkstra, times);
	// vectorTimeMedia[1] = calculateTimeMedia (vectorTimeBellmanFord, times);
	// vectorTimeMedia[2] = calculateTimeMedia (vectorTimeFF, times);
	// vectorTimeMedia[3] = calculateTimeMedia (vectorTimeFloyd, times);

	// loadData(ARCHIVES_OUT_PATH, vectorTimeMedia, graph->getNodesAmount());

	delete [] vectorTimeMedia;
}

/**
 * @brief 	This function calculates the standard deviation of the time values
 * @param 	vTimes  Vector with the times of the calculus
 * @param 	size 	The size of the vector
 * @return 	result 	The result of the media calculus
 */
float calculateTimeMedia (int* vTimes, int size) {
	float media = 0, sum = 0;
	for (int i = 0; i < size; i++)
		media += vTimes[i];
	
	media = media/size;

	for (int i = 0; i < size; i++) {
		sum += pow (vTimes[i] - media, 2);
	}

	float result = sum / ((float)size - 1);
	result = sqrt (result);

	delete [] vTimes;
	return result;
}