#ifndef TSP_INTERFACE_H
#define TSP_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "struct.h"

// Fonctions utilisables dans le code de la GUI
Graphe* tspInit(const char* fichierTSP);
Tournee* tspBruteForce(Graphe* graphe);
int tspGetNbPoints(Tournee* tournee);
Point* tspGetPoints(Tournee* tournee);
void tspFreeGraphe(Graphe* graphe);
void tspFreeTournee(Tournee* tournee);

#ifdef __cplusplus
}
#endif

#endif