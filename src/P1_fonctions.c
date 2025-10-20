#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "struct.h"
#include "P1_fonctions.h"
#include "matrice.h"

typedef double (*DistanceCalc)(const Graphe* g, DistanceFun f, int i, int j, Matrice m);


/* 
 * Next lexicographical permutation algorithm (C)
 * by Project Nayuki, 2017. Public domain.
 * https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
 */
/* 
 * Computes the next lexicographical permutation of the specified array of integers in place,
 * returning a Boolean to indicate whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)
 */
bool next_permutation(int array[], size_t length) {
	// Find non-increasing suffix
	if (length == 0)
		return false;
	size_t i = length - 1;
	while (i > 0 && array[i - 1] >= array[i])
		i--;
	if (i == 0)
		return false;
	
	// Find successor to pivot
	size_t j = length - 1;
	while (array[j] <= array[i - 1])
		j--;
	int temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;
	
	// Reverse suffix
	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	return true;
}



double dist_ij(const Graphe* g, DistanceFun f, int i, int j, Matrice m) {
    if (i == j) return 0.0;

    return f(g->point[i], g->point[j]);
}

double dist_ij_mat(const Graphe* g, DistanceFun f, int i, int j, Matrice mat) {
    if (i == j) return 0.0;

    return getDistance(mat, g->point[i], g->point[j]);
}

/* perm = indices de points, len = nombre de points (N) */
double tour_length_from_perm(const Graphe* g, DistanceFun f, const int* perm, int len, DistanceCalc dist, Matrice mat) {
    double sum = 0.0;
    for (int k = 0; k < len - 1; ++k) {
        sum += dist(g, f, perm[k], perm[k+1], mat);
    }
    /* fermer la boucle */
    sum += dist(g, f, perm[len-1], perm[0], mat);
    return sum;
}

int fill_tournee_from_perm(const Graphe* g, const int* perm, int n, Tournee* out) {
    if (!out) return -1;

    out->size = n;
    Point tabPoints[n];
        for (int i = 0; i < n; ++i) {
            int idx = perm[i];
            tabPoints[i] = g->point[idx]; /* copie */
        }
    out->ord_point_vis = tabPoints;

    return 0;
}



int tsp_bruteforce(const Graphe* g, DistanceFun f, bool faire_matrice_distance , Tournee* outBest, double* outBestLen, Tournee* outWorst,double* outWorstLen) {
    if (!g || g->dimension <= 0 || !outBest || !outBestLen) return -1;
    const int N = g->dimension;

    

    /* initialisation */
    int perm[N];
    int bestPerm[N];
    int worstPerm[N];

    for (int i = 0; i < N; ++i) perm[i] = i;

    DistanceCalc dist = dist_ij;
    Matrice mat = NULL;

    if (faire_matrice_distance)
    {
        mat = createMatriceFromGraphe( (*g) , f );
        dist = dist_ij_mat;

    }
    
    

    double bestLen ;
    double worstLen;
    
    /* évalue la permutation initiale (déjà triée) */
    
        double L0 = tour_length_from_perm(g, f, perm, N, dist, mat);
        bestLen = L0;
        worstLen = L0;
        memcpy(bestPerm, perm, (size_t)N * sizeof(int));
        memcpy(worstPerm, perm, (size_t)N * sizeof(int));
    

    /* boucle d'exploration des permutations */
    while (next_permutation(perm, N)) {
        double L = tour_length_from_perm(g, f, perm, N, dist, mat);
        if (L < bestLen) {
            bestLen = L;
            memcpy(bestPerm, perm, (size_t)N * sizeof(int));
        }
        if (L > worstLen) {
            worstLen = L;
            memcpy(worstPerm, perm, (size_t)N * sizeof(int));
        }
    }


    /* Remplir outBest (allocation unique faite ici) */
    fill_tournee_from_perm(g, bestPerm, N, outBest);
    *outBestLen = bestLen;

    /* Remplir outBest (allocation unique faite ici) */
    fill_tournee_from_perm(g, worstPerm, N, outWorst);
    *outWorstLen = worstLen;
    return 0;
}