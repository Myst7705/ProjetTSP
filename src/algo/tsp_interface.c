#include "tsp_interface.h"
#include "lectureTSPLIB.h"
#include "calc_distance.h"
#include "P1_fonctions.h"
#include "calc_distance.h"
#include "struct.h"
#include <stdlib.h>

static Graphe* graphe = NULL;
static Tournee* bestTournee = NULL;
static Tournee* worstTournee = NULL;
static double bestLen = 0;
static double worstLen = 0;
// TODO: pouvoir choisir la fonction de calcul que l'on veut utiliser dans la GUI
double (*f)(Point a, Point b) = calc_dist_eucl2d;

Graphe* tspInit(const char* fichierTSP){
    graphe = read_TSPLIB(fichierTSP);
    return graphe;
}

int tspGetNbPoints(Tournee* tournee){
    return tournee->size;
}

Point* tspGetPoints(Tournee* tournee){
    return tournee->ord_point_vis;
}

void tspFreeGraphe(Graphe* graphe){
    free_graphe(graphe);
}

void tspFreeTournee(Tournee* tournee){
    detruireTournee(tournee);
}

Tournee* tspBruteForce(Graphe* graphe){
    tsp_bruteforce(graphe, f, false, bestTournee, &bestLen, worstTournee, &worstLen);
    return bestTournee;
}
