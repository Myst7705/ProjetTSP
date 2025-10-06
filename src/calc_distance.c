#include "calc_distance.h"

int calcul_poids_tournee(Tournee* tournee, int (*calc_dist)(Point, Point)){
    int distance_totale = 0;
    
    for (int i = 0; i < (tournee->size) - 1; i++){
        distance_totale += (*calc_dist)(tournee->ord_point_vis[i], tournee->ord_point_vis[i+1]);
    }
    return distance_totale;
}