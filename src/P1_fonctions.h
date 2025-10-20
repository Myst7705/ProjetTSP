#ifndef P1_FONCTIONS_H
#define P1_FONCTIONS_H

#include <stdbool.h>
#include "struct.h"
#include "P1_fonctions.h"
#include "matrice.h"

#define WITH_MATRICE 1
#define WITHOUT_MATRICE 0

int tsp_bruteforce(const Graphe* g, DistanceFun f, bool faire_matrice_distance,
                    Tournee* outBest, double* outBestLen, Tournee* outWorst, double* outWorstLen);


typedef double (*DistanceCalc)(const Graphe* g, DistanceFun f, int i, int j, Matrice m);


#endif