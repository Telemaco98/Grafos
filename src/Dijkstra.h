#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_ value

void dijkstra (int origin, int destiny, float** matrix);

void calculateWeight (int origin, int destiny, float** matrix);

void doWay (int origin, int destiny, float** matrix);

void printWay (int way);

#endif