#ifndef MATRICE_H
#define MATRICE_H

#include "struct.h"

typedef struct sMatrice* Matrice;

typedef double (*DistanceFun)(Point p1, Point p2);

Matrice createNewMat();

Matrice addPointToMatrice(Matrice mat,Point p,Graphe g,DistanceFun);

Matrice createMatriceFromGraphe(Graphe g,DistanceFun);

void freeMatrice(Matrice Matrice);

double getDistance(Matrice mat, Point p1, Point p2);

void printMatrice(const Matrice mat);

void freeMatrice(Matrice mat);

void mapMatrice();

#endif