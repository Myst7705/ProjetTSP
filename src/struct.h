
#ifndef STRUCTURE_H
#define STRUCTURE_H

/**  
* @struct Point
* @brief Representation d'un point dans un espace 2D
*/
typedef struct{
    int id; 
    double x,y;
}Point;

/**  
* @struct Graphe
* @brief Representation de la structure qui est manipule pour les calculs du TSP
*/
typedef struct
{
    char nom[32]; /**< Nom du fichier  */ 
    char type_edge[32]; /**< Pour savoir si on est en ATT/GEO/EUC_2D*/ 
    int dimension;  /**< Nombre de points dans le fichier*/
    Point* point; /**< Tableau de point*/
    int est_matrice; /**< Partie 1 mentionne que on peut avoir des coords ou des matrices dans les fichiers de jeux de test */ 
    double** matrice_du_test; /**< Matrice donne par le fichier test -> null si est_matrice = 0 else  contient les valeurs donnes par fichier_test */ 
}Graphe;

/**  
* @struct Tournes
* @brief Representation d'une tournee de visite de chaque point
*/
typedef struct 
{
    int* ord_point_vis;
    int size; 
}Tournes;

#endif