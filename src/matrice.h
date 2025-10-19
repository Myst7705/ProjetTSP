#ifndef MATRICE_H
#define MATRICE_H

#include "struct.h"

typedef struct sMatrice* Matrice;

typedef double (*DistanceFun)(Point p1, Point p2);

/**
 @brief Creation d'une nouvelle sous matrice
 */
Matrice createNewMat();

/**
 * @param mat Matrice ou on rajoute le point
 * @param p Point a rajouter
 * @param DistanceFun fonction de calcule de distance utilise
 * @brief Ajouter un point a une matrice
 */
Matrice addPointToMatrice(Matrice mat,Point p,Graphe g,DistanceFun);

/**
 * @param g Graphe utilise pour creer la matrice
 * @param DistanceFun fonction de calcule de distance utilise
 * @brief Creer une matrice en utilisant une graphe 
 */
Matrice createMatriceFromGraphe(Graphe g,DistanceFun);

/**
 * @param Matrice Matrice a effacer
 * @brief detruie la matrice rentrer en parametre 
 */
void freeMatrice(Matrice Matrice);

/**
 * @brief donne la distance entre 2 points de la matrice 
 */
double getDistance(Matrice mat, Point p1, Point p2);

/**
 * @param Matrice Matrice a afficher
 * @brief afficher la matrice entre en parametre
 */
void printMatrice(const Matrice mat);


#endif