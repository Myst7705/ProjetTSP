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

/**
 * @brief Creer dynamiquement et renvoie la tournee canonique tu graphe passe en parametre
 * @param g Graphe dont on veut la tournee canonique
 * @return Tournee*
 */
Tournee * createTourneCanonique(Graphe *g);

/**
 * @brief Convertit une tournee passee en parametre en chaine de caracteres formatee
 * @param T Tournee dont on veut une chaine de caracteres formatee
 * @return char*
 */
char * toStringArray(Tournee T);

/**
 * @brief Fonction liberant l'espace memoire de la Tournee donnee en parametre
 * @param t Tournee a detruire
 * @return void
 */
void detruireTournee(Tournee * t);
#endif