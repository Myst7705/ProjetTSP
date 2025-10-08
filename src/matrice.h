#ifndef MATRICE_H
#define MATRICE_H

typedef struct sMatrice* Matrice;

typedef double (*DistanceFun)(Point p1, Point p2);

Matrice creerMatrice(int);

void printMatrice(Matrice Matrice,int size);

void freeMatrice(Matrice* pointeurMatrice);

int getLongueur(Matrice Matrice ,Point p1 ,Point p2);

void mapMatrice();