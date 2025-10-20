#ifndef LECTURETSP_H
#define LECTURETSP_H

#include "struct.h"

/**
 * @brief Libère un graphe allouée dynamiquement
 * @param g Pointeur vers un graphe allouée dynamiquement
 * @return Void
 */
void free_graphe(Graphe* g);

/**
 * @brief Lit un fichier TSPLIB et crée un Graphe
 * @param fichier Chemin ou nom du fichier TSPLIB à lire
 * @return Pointeur vers le Graphe allouée dynamiquement, ou NULL en cas d'erreur
 */
Graphe* read_TSPLIB (const char *fichier);

Tournee * createTourneCanonique(Graphe *g);

char * toStringArray(Tournee T);

void detruireTournee(Tournee * t);
#endif