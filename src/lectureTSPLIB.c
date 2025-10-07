#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "struct.h"
#include "lectureTSPLIB.h"

#define LINE_LEN 256

Graphe* read_TSPLIB (const char *fichier) {
    //Ouverture du fichier 
    FILE* f = fopen(fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier\n");
        return NULL;
    }

    //Allocation mémoire du graphe
    Graphe* g = malloc(sizeof(Graphe));
    if (!g) {
        perror("Erreur allocation Graphe");
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
    bool fin_lecture_point = false; // true lorsque tous les points ont été lus

    //Lecture du fichier
    while (fgets(ligne, LINE_LEN, f)) {

        //Lecture du nom
        if (strncmp(ligne, "NAME", 4) == 0) {
            sscanf(ligne, "NAME : %31s", g->nom);
        }

        //Lecture de la dimension
        else if (strncmp(ligne, "DIMENSION", 9) == 0) {
            sscanf(ligne, "DIMENSION : %d", &g->dimension);
        } 

        //Lecture du type
        else if (strncmp(ligne, "EDGE_WEIGHT_TYPE", 16) == 0) {
            sscanf(ligne, "EDGE_WEIGHT_TYPE : %31s", g->type_edge);
        } 

        //Cas matrice
        else if (strncmp(ligne, "EDGE_WEIGHT_SECTION", 19) == 0) {
            //Partie 0 pas encore besoin de regarder le cas matrice
            fprintf(stderr,"Error: case matrix not implemented yet\n");
            return NULL;
        } 

        //Cas coordonnées
        else if (strncmp(ligne, "NODE_COORD_SECTION", 18) == 0) {
            g->point = malloc(g->dimension * sizeof(Point));
            continue;
        }

        //Fin du fichier
        else if (strncmp(ligne, "EOF", 3) == 0) {
            break;
        }
        // Lecture des coordonnées
        else if (!fin_lecture_point) {
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
        }

    }
    
    //Fermeture du fichier
    fclose(f);

    return g;
}

void free_graphe(Graphe* g) {
    //si g = null alors rien à faire
    if (!g) return;
    
    // libère les points
    if (g->point)
        free(g->point);

    if (g->matrice_du_test) {
        //Partie 0 pas encore besoin de regarder le cas matrice
        fprintf(stderr,"Error: case matrix not implemented yet\n");
        exit(EXIT_FAILURE)L;
    }
    // libère la structure elle-même
    free(g);
}


int main() {
    Graphe* g = read_TSPLIB("jeudedonnees/berlin52.tsp");
    if (!g) return 1;

    printf("Nom: %s\n", g->nom);
    printf("Type: %s\n", g->type_edge);
    printf("Dimension: %d\n", g->dimension);

    for (int i = 0; i < g->dimension; i++) {
        printf("%d: (%lf, %lf)\n", g->point[i].id, g->point[i].x, g->point[i].y);
    }

    free_graphe(g);
    return 0;
}
