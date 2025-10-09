#include "main.h"
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>


int main(int argc,char *argv[]){

    //./bin/tsp -f fichier -c
    if (argc != 4||strcmp(argv[1],"-f")!=0||strcmp(argv[3],"-c")!=0)
    {
        // printf("%sUtilisation : ./bin/tsp -f test/FICHIER -c\n%s",RED,NORMAL); 
        return 1;
    }
    char * file_name = argv[2];

    Graphe * g = read_TSPLIB(file_name);

    // printf("Printing value that's was read: \n");
    // for (int i = 0; i < g->dimension; i++)
    // {
    //     Point p = g->point[i];
    //     printf("[%d] value read -> x : %f y : %f\n",p.id,p.x,p.y);
    // }
    // printf("\n");
    Tournee * t = createTourne(g);
    // printf("Printing value that's in a turn: \n");
    // for (int i = 0; i < g->dimension; i++)
    // {
    //     Point p1 = t->ord_point_vis[i];
    //     printf("[%d] value read -> x : %f y : %f\n",p1.id,p1.x,p1.y);
    // }

    double resCanonicalTurn = calcul_poids_tournee(t,calc_dist_att);
    char * turnString = toStringArray(*t);
    printf("Instance ; Méthode ; Temps CPU (sec) ; Longueur ; Tour\n");
    printf("%s ; canonical ; 0.0 ; %f; %s\n",g->nom,resCanonicalTurn,turnString);
    return 0;
}