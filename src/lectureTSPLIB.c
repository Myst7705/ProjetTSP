#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "struct.h"
#include "lectureTSPLIB.h"

#define LINE_LEN 256

void free_graphe(Graphe* g) {
    //si g = null alors rien à faire
    if (!g) return;
    
    // libère les points
    if (g->point)
        free(g->point);
    if (g->matrice_du_test) {
        //Partie 0 pas encore besoin de regarder le cas matrice
        fprintf(stderr,"Erreur: le cas matrice n'est pas encore implémentée\n");
        exit(EXIT_FAILURE);
    }
    // libère la structure elle-même
    free(g);
}

Graphe* read_TSPLIB (const char *fichier) {
    //Ouverture du fichier 
    FILE* f = fopen(fichier, "r");
    if (!f) {
        perror("Erreur: ouverture fichier\n");
        return NULL;
    }

    //Allocation mémoire du graphe
    Graphe* g = malloc(sizeof(Graphe));
    if (!g) {
        perror("Erreur: allocation Graphe\n");
        fclose(f);
        return NULL;
    }
    //Remplis le graphe de 0 en prévision de potentielles erreurs
    memset(g, 0, sizeof(Graphe));

    //Matrices pas encore implémentées
    g->est_matrice = 0;
    g->matrice_du_test= NULL;

    // Variables utilitaires pour la lecture du fichier TSPLIB
    char ligne[LINE_LEN];       // buffer pour lire chaque ligne du fichier
    int idx_point = 0;          // compteur de points lus
    bool fin_lecture_name = false; // true lorsque name a été lu
    bool fin_lecture_dimension = false; // true lorsque dimension a été lu
    bool fin_lecture_type_edge = false; // true lorsque type edge a été lu
    bool fin_lecture_section = false; // true lorsque section a été lu
    bool fin_lecture_point = false; // true lorsque on a finis de lire des points

    //Lecture du fichier
    while (fgets(ligne, LINE_LEN, f)) {
        //Lecture du nom
        if (strncmp(ligne, "NAME", 4) == 0) {
            sscanf(ligne, "NAME : %31s", g->nom);
            fin_lecture_name = true;
        }

        //Lecture de la dimension
        else if (strncmp(ligne, "DIMENSION", 9) == 0 && fin_lecture_name) {
            sscanf(ligne, "DIMENSION : %d", &g->dimension);
            fin_lecture_dimension = true;
        } 

        //Lecture du type
        else if (strncmp(ligne, "EDGE_WEIGHT_TYPE", 16) == 0 && fin_lecture_dimension) {
            sscanf(ligne, "EDGE_WEIGHT_TYPE : %31s", g->type_edge);
            fin_lecture_type_edge = true;
        } 

        //Cas matrice
        else if (strncmp(ligne, "EDGE_WEIGHT_SECTION", 19) == 0 && fin_lecture_type_edge ) {
            //Partie 0 pas encore besoin de regarder le cas matrice
            fprintf(stderr,"Erreur: le cas matrice n'est pas encore implémentée\n");
            free_graphe(g);
            fclose(f);
            return NULL;
        } 

        //Cas coordonnées
        else if (strncmp(ligne, "NODE_COORD_SECTION", 18) == 0 && fin_lecture_type_edge ) {
            g->point = malloc(g->dimension * sizeof(Point));
            fin_lecture_section = true;
        }

        //Fin du fichier
        else if (strncmp(ligne, "EOF", 3) == 0 && fin_lecture_point) {
            break;
        }

        //Fin du fichier
        else if (strncmp(ligne, "TYPE", 4) == 0 || strncmp(ligne, "COMMENT", 4)==0) {
            continue;
        }
        // Lecture des coordonnées
        else if (!fin_lecture_point && fin_lecture_section) {
            int id;
            double x, y;
            if (sscanf(ligne, "%d %lf %lf", &id, &x, &y) == 3) {
                g->point[idx_point].id = id;
                g->point[idx_point].x = x;
                g->point[idx_point].y = y;
                idx_point++;
                if (idx_point >= g->dimension) {
                    fin_lecture_point=true;
                }
            }
            //Cas erreur lecture de quelque chose qui n'est pas une coordonnées
            else {
                fprintf(stderr,"Erreur: Un problème a eu lieu lors de la lecture de coordonnées\n");
                free_graphe(g);
                fclose(f);
                return NULL;
            }
        } 
        
        //Cas Erreur format
        else {
            fprintf(stderr,"Erreur: mauvais format de fichier\n");
            free_graphe(g);
            fclose(f);
            return NULL;
        }

    }
    
    //Fermeture du fichier
    fclose(f);

    return g;
}

Tournee * createTourne(Graphe * g){
    Tournee * t = malloc(sizeof(Tournee));
    if(!t){
        return NULL;
    }
    int size = g->dimension;
    t->size = size;
    t->ord_point_vis = malloc(sizeof(Point)*size);
    for (int i = 0; i < size; i++)
    {
        t->ord_point_vis[i] = g->point[i];
    }
    return t;    
}

char * toStringArray(Tournee T){
    char *str = malloc(512); // allocate on heap
    if (!str) return NULL;   // check malloc success
    str[0] = '\0';
    strcat(str,"[");
    for (int i = 0; i < T.size; i++)
    {
        char tmp[10];
        sprintf(tmp,"%d",T.ord_point_vis[i].id);
        strcat(str,tmp);
        if (i < (T.size-1))
        {
            strcat(str,"," );
        }
    }
    strcat(str,"]");
    return str; 
}

void detruireTournee(Tournee *t){
    if(!t) return;
    free(t->ord_point_vis);
    free(t);
    t = NULL; 
}
