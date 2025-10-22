#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "struct.h"
#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN  "\x1B[32m"


void affichage_help();

void affichage_erreur();

void affichageResultat(Graphe * g,char * tourneString,double resultat_calc,double temps,char * methode_calc);

#endif



