#ifndef CALC_DISTANCE_H
#define CALC_DISTANCE_H

#include "struct.h"

#define PI 3.141592
#define RT 6378.388 // Rayon Terre


/**
 * @param Pointeur sur une tournee
 * @param Pointeur sur une fonction de calcul de distance
 * @brief Calcul la distance totale d'une tournee
 */
double calcul_poids_tournee(Tournee* tournee, double (*calc_dist)(Point, Point));


/**
 * @param Point a
 * @param Point b
 * @brief Calcul la distance euclidienne en 2D entre points
 */
double calc_dist_eucl2d(Point a, Point b);

/**
 * @param Point a
 * @param Point b
 * @brief Calcul la distance geographique entre points
 */
double calc_dist_geo(Point a, Point b);

/**
 * @param Point a
 * @param Point b
 * @brief Calcul la distance ATT entre points
 */
double calc_dist_att(Point a, Point b);


#endif