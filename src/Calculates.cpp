#include "Calculates.h"

extern const string CALCULATING = " # | (ii)   | Calculating the path shortest with ";
extern const string DIVISOR 	= " # +---------------------------------------------- ";

/**
 * @brief The function responsible by do the Empirical Analysis
 */
void calculates () {
	cleanOutputArchives();
	int amountInputs = 11; //12
	int timesToRepeat = 5;
	
	for (int i = 7; i < amountInputs; i++) {
		string iString = to_string(i);
		string inputPath = "./data/input/USA-road-" + iString + ".gr";
		Graph* graph = extractArchive (inputPath);
		
		int origin  = 0;//rand () % (graph->getNodesAmount());
		int destiny = (graph->getNodesAmount()) - 1;//rand () % (graph->getNodesAmount());
		
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
	int algorithmsQuantity = 1; // 3
	int* vectorTimeDijkstra = new int[times];
	// int* vectorTimeBellmanFord[times] = new int[times];

	for (int i = 0; i < times; i++) {
		// Calculate shortest path with Dijkstra
		cout << CALCULATING + "Dijkstra ..." << endl;
		vectorTimeDijkstra[i] = dijkstra(origin, destiny, graph);

		// Calculate shortest path with Belmanford
		// cout << CALCULATING + "Belmanford ..." << endl;
		// vectorTimeBellmanFord[i] = bellmanFord (origin, destiny, graph);
	}

	float* vectorTimeMedia = new float[algorithmsQuantity];
 
	vectorTimeMedia[0] = calculateTimeMedia (vectorTimeDijkstra, times);
	cout << " # | TEMPO MEDIO COM DIJKSTRA: " << vectorTimeMedia[0] << endl;

	// vectorTimeMedia[1] = calculateTimeMedia (vectorTimeBellmanFord, times);
	// cout << " # | TEMPO MEDIO COM BELLMAN-FORD: " << vectorTimeMedia[0] << endl;

	loadDataInArchive(graph->getNodesAmount(), vectorTimeMedia, algorithmsQuantity);

	cout << DIVISOR << endl;
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