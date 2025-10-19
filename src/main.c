#include "main.h"
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>


int main(int argc,char *argv[]){
    if (argc != 4||strcmp(argv[1],"-f")!=0)
    {
        //printf("%sUtilisation : ./bin/tsp -f test/FICHIER -c\n%s",RED,NORMAL); 
        return 1;
    }
    char * file_name = argv[2];

    Graphe * g = read_TSPLIB(file_name);

    Tournee * t = createTourne(g);
    char * chRead = argv[3];
    if (strcmp(chRead,"-c")==0)
    {
        double resCanonicalTurn = calcul_poids_tournee(t,calc_dist_att);
        char * turnString = toStringArray(*t);
        printf("Tour %s %s %f %f %s\n", g->nom, "canonical", 0.0, resCanonicalTurn, turnString);
        free(turnString);
    }else if(strcmp(chRead,"-bf")==0){ 
        printf("TODO\n");
    }else{ 
        detruireTournee(t);
        free_graphe(g);
        return 1; 
    }
    
    detruireTournee(t);
    free_graphe(g);
    return 0;
}