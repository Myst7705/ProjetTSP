#include "fnct_affichage.h"
#include <stdio.h>
#include <stdlib.h>

void affichage_help(){
    printf("Utilisation :\n");
    printf("> %s./bin/tsp -f test/FICHIER -c||-m [bf] %s: pour faire fonctionner le code\n",GREEN,NORMAL);
    printf("> %s./bin/tsp -h %s: pour savoir comment utiliser le code\n",GREEN,NORMAL);
    printf("> %ssource venv/bin/activate %s: a activer dans le repertoire python, elle va nous permettre de faire fonctionner le sous-environnement python \n",GREEN,NORMAL);
}

void affichage_erreur(){
    printf("Utilisation :\n");
    printf("> %s./bin/tsp -f test/FICHIER -c||-m [bf] %s: pour faire fonctionner le code\n",RED,NORMAL);
    printf("> %s./bin/tsp -h %s: pour savoir comment utiliser le code\n",RED,NORMAL);
}

void affichageResultat(Graphe * g,char * tourneString,double resultat_calc,double temps,char * methode_calc){
    printf("Instance ; Méthode ; Temps CPU (sec) ; Longueur ; Tour\n");
    printf("%s ; %s ; %f ; %f ; %s\n", g->nom, methode_calc, temps, resultat_calc, tourneString); 
}
