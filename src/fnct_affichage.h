#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "struct.h"
#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN  "\x1B[32m"

/**
 * @brief Fonction d'affichage d'aide pour l'utilisation du programme
 * @return void
 */
void affichage_help();

/**
 * @brief Fonction d'affichage d'aide lorsqu'il y a une erreur d'utilisation du programme
 * @return void
 */
void affichage_erreur();

/**
 * @brief Fonction d'affichage des resultats
 * @return void
 */
void affichageResultat(Graphe * g,char * tourneString,double resultat_calc,double temps,char * methode_calc);

#endif



