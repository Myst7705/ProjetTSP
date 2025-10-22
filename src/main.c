#include "main.h"
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include <signal.h>
#include "ctrl_c.h"
#include "P1_fonctions.h"


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

void affichage(Graphe * g,char * tourneString,double resultat_calc,double temps,char * methode_calc){
    printf("Instance ; Méthode ; Temps CPU (sec) ; Longueur ; Tour\n");
    printf("%s ; %s ; %f ; %f ; %s\n", g->nom, methode_calc, 0.0, resultat_calc, tourneString); 
}

int main(int argc,char *argv[]){
    if (argc ==2)
    {
        if (strcmp(argv[1],"-h")==0)
        {  
            affichage_help();
            return 0;
        }else{
            affichage_erreur();
            return 1; 
        }
    }else if (argc == 4 && strcmp(argv[3],"-c")!=0)
    {
        affichage_erreur();
        return 1;
    }else if(argc == 5 && strcmp(argv[4],"bf")!=0){
        affichage_erreur();
        return 1;
    }
     

    char * file_name = argv[2];

    //CREATION DE L'INSTANCE LUE
    Graphe* gr = read_TSPLIB(file_name);
    if (!gr){
        return 2;
    }
    
    Tournee * t = createTourneCanonique(gr);
    
    // INIT CALCUL DE FONCTION DE CALCUL DE BASE 
    DistanceFun calc_dist = calc_dist_att;
    if (strcmp(gr->type_edge,"GEO")==0)
    {
        calc_dist = calc_dist_geo;
    }else if(strcmp(gr->type_edge,"EUC_2D")==0){ 
        calc_dist = calc_dist_eucl2d;
    }
    
    char * chRead;
    if(argc==4){ chRead = argv[3];}
    else{ chRead = argv[4];}
    
    if (strcmp(chRead,"-c")==0) //TOURNEE CANNONIQUE
    {
        double resCanonicalTurn = calcul_poids_tournee(t,calc_dist);
        char * turnString = toStringArray(*t);
        printf("Tour %s %s %f %f %s\n", gr->nom, "canonical", 0.0, resCanonicalTurn, turnString);
        //affichage(g,turnString,resCanonicalTurn,0.0,chRead);
        free(turnString);
        detruireTournee(t);
    }else if(strcmp(chRead,"bf")==0){ //BRUTE FORCE
        Tournee* best = createTourneCanonique(gr);
        Tournee* worst = createTourneCanonique(gr);
        double bestL;
        double worstL;

        // Allocation memoire de la chaine de caractere permActuelle et bestPermString affichee dans ctrl_c
        bestPermString = malloc(512);
        permActuelle = malloc(512);
        
        void (*oldINT)(int) = signal(SIGINT, INThandler);

        if (oldINT == SIG_ERR){
            perror("Erreur assignement signal SIGINT\n");
            return 3;
        }
        clock_t begin = clock();
        int returnBruteForce = tsp_bruteforce(gr,calc_dist,WITHOUT_MATRICE,best,&bestL,worst,&worstL);
        clock_t end = clock();
        if (returnBruteForce == -1){
            free_graphe(gr);
            detruireTournee(best);
            detruireTournee(worst);
            free(permActuelle);
            free(bestPermString);
            detruireTournee(t); // Test
            exit(0);
        }
        signal(SIGINT, oldINT);

        

        
        free(permActuelle);
        free(bestPermString);
        detruireTournee(t); // Test


        int timeCPU = (int)(end-begin);
        char * bestString = toStringArray(*best);
        char * worstString = toStringArray(*worst);
        printf("Tour %s %s %d %f %s\n", gr->nom, "bf", timeCPU, bestL, bestString);
        printf("Tour %s %s %d %f %s\n", gr->nom, "bf", timeCPU, worstL, worstString);

        free(bestString);
        free(worstString);
        detruireTournee(best);
        detruireTournee(worst);
    }else{
        return 1;
    }

    free_graphe(gr);
    
    
    return 0;
}