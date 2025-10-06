#ifndef CALC_DISTANCE_H
#define CALC_DISTANCE_H

#include "struct.h"


/**
 * @param Pointeur sur une tournee
 * @param Pointeur sur une fonction de calcul de distance
 * @brief Calcul la distance totale d'une tournee
 */
int calcul_poids_tournee(Tournee* tournee, int (*calc_dist)(Point, Point));


/**
 * @param Point a
 * @param Point b
 * @brief Callcul la distance euclidienne en 2D entre points
 */
int calc_dist_eucl2d(Point a, Point b);

/**
 * @param Point a
 * @param Point b
 * @brief Callcul la distance geographique entre points
 */
int calc_dist_geo(Point a, Point b);

/**
 * @param Point a
 * @param Point b
 * @brief Callcul la distance ATT entre points
 */
int calc_dist_att(Point a, Point b);


#endif