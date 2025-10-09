#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"
#include "struct.h"

// Euclidean distance function
double euclideanDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int numPoints = 3;

    // Allocate an array of Points (not pointers)
    Point* points = (Point*)malloc(numPoints * sizeof(Point));
    if (!points) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize points
    for (int i = 0; i < numPoints; i++) {
        points[i].id = i + 1;
        points[i].x = i * 1.0;
        points[i].y = i * 2.0;
    }

    // Create a graph
    Graphe graph;
    graph.dimension = numPoints;
    graph.point = points;
    graph.est_matrice = 0;
    graph.nom[0] = '\0';
    graph.type_edge[0] = '\0';
    graph.matrice_du_test = NULL;

    // Create distance matrix
    Matrice mat = createMatriceFromGraphe(graph, euclideanDistance);

    // Print the distance matrix
    printf("Distance matrix:\n");
    printMatrice(mat);

    // Test getDistance
    printf("\nDistance between point 1 and point 3: %f\n",
           getDistance(mat, points[0], points[2]));

    // Free matrix
    freeMatrice(mat);

    // Free points array
    free(points);

    return 0;
}

