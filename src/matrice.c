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
};



Matrice createNewMat() {
    Matrice newMat = (Matrice)malloc(sizeof(sMatrice));
    if (!newMat) {
        printf("Erreur d'allocation mémoire pour le noeud.\n");
        exit(1);
    }
    newMat->size = 1;

    newMat->head = (Node*)malloc(sizeof(Node));
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

Matrice addPointToMatrice(Matrice mat,Point p,Graphe g,DistanceFun dist) {

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
        newNode->list[i] = dist(p,g->point[i]);  // Exemple de valeur
    }

    newNode->next = NULL;   // Le node suivant est NULL
    Node* current = mat->head;
    while (current->next != NULL) {
        current = current->next;  // Trouver le dernier nœud
    }
    current->next = newNode;  // Ajouter le nouveau nœud à la fin

    mat->size++;

    return mat;
    
}


Matrice createMatriceFromGraphe(Graphe g,DistanceFun dist) {
    Point* Listpoint = g->point;
    Matrice mat = NULL;
    for (int i = 0; i < g->dimension; i++)
    {
        mat = addPointToMatrice(mat,Listpoint[i],g,dist);
    }
    
    return mat;

}




void freeMatrice(Matrice Matrice) {

    if (!Matrice) return;

    Node* current = Matrice->head;
    while (current != NULL) {
        Node* temp = current;
        free(current->list);  // Libérer le tableau
        current = current->next;
        free(temp);  // Libérer le nœud
    }
    free(Matrice);
}

double getDistance(Matrice Matrice ,Point p1 ,Point p2){
    if (!Matrice || m->size <= 0) return 0.0;

    int i = p1->id - 1;
    int j = p2->id - 1;

    if (i < 0 || j < 0 || i >= Matrice->size || j >= Matrice->size) {
        fprintf(stderr, "getDistance: index out of bounds (i=%d, j=%d, size=%d)\n", i, j, m->size);
        return 0.0;
    }

    int r = (i > j) ? i : j;
    int c = (i > j) ? j : i;

    Node* currentNode = Matrice->head;   
    for (int k = 0; k < i; k++)
    {
        currentNode = currentNode->next;
    }
    double* List = currentNode->List;
    return List[j];
}



void printMatrice(const Matrice mat) {
    if (!m) { printf("(null)\n"); return; }

    Node* currentNode = mat->head;

    for (int i = 0; i < m->size; ++i,currentNode=currentNode->next) {
        for (int j = 0; j < m->size; ++j) {
            printf(" %f ",currentNode->list[j]);
        }
        printf("\n");
    }
}
