#include "matrice.h"
#include "struct.h"


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    double* list;
    struct Node* next;
}Node;

typedef struct sMatrice
{
    int size;
    Node* head;
}sMatrice;

Matrice createNewMat() {
    Matrice newMat = (Matrice)malloc(sizeof(sMatrice));
    if (!newMat) {
        printf("Erreur d'allocation mémoire pour le noeud.\n");
        exit(1);
    }
    newMat->size = 1;

    newMat->head = (Node*)malloc(sizeof(Node))
    if (newMat->head == NULL)
    {
        printf("Erreur d'allocation mémoire pour le noeud.\n");
        exit(1);
    }
    
    newMat->head->list = (double*)malloc(sizeof(double));
    if (newMat->head->list == NULL)
    {
        printf("Erreur d'allocation mémoire pour le noeud.\n");
        exit(1);
    }

    newMat->head->list[0] = 0;
    newMat->head->next = NULL;


    return newMat;
}

Matrice addPointToMatrice(Matrice mat,Point p,Graphe g,DistanceFun) {

    if (mat==NULL)
    {
        return createNewMat();
    }
    

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire pour le node.\n");
        exit(1);
    }

    // Allouer de la mémoire pour la liste dans ce node
    newNode->list = (double*)malloc((mat->size+1) * sizeof(double));

    if (newNode->list == NULL) {
        printf("Erreur d'allocation mémoire pour la liste.\n");
        exit(1);
    }

    // Calculer la ligne avec la fonction de distance donnee
    for (int i = 0; i < size; i++) {
        newNode->list[i] = Distancefun(p,g->point[i]);  // Exemple de valeur
    }

    newNode->next = NULL;   // Le node suivant est NULL
    Node* current = mat->head;
    while (current->next != NULL) {
        current = current->next;  // Trouver le dernier nœud
    }
    current->next = newNode;  // Ajouter le nouveau nœud à la fin

    mat->size += 1;

    return mat;
    
}


Matrice createMatriceFromGraphe(Graphe g,DistanceFun) {
    Point* Listpoint = g->point;
    Matrice mat = NULL;
    for (int i = 0; i < g->dimension; i++)
    {
        mat = addPointToMatrice(mat,Listpoint[i],g,DistanceFun);
    }
    
    return mat;

}




void freeMatrice(Matrice Matrice) {
    Node* current = Matrice->head;
    while (current != NULL) {
        Node* temp = current;
        free(current->list);  // Libérer le tableau
        current = current->next;
        free(temp);  // Libérer le nœud
    }
}

int getDistance(Matrice Matrice ,Point p1 ,Point p2){
    int i = p1->id - 1;
    int j = p2->id - 1;

    Node* currentNode = Matrice->head;   
    for (int k = 0; k < i; k++)
    {
        currentNode = currentNode->next;
    }
    double* List = currentNode->List;
    return List[j];
}

