#include "ctrl_c.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "lectureTSPLIB.h"

int returnHandler = 0;

void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);

     printf("Vous avez appuye sur la touche Ctrl-C\n");
     printf("Meilleure tournee: %s\n", bestPermString);
     printf("Longueur de la meilleure tournee: %f \n", bestLen);
     printf("Permutation actuelle: %s \n", permActuelle);

     printf("Voulez vous vraiment quitter? [y or n]\n");
     
     c = getchar();
     if (c == 'y' || c == 'Y'){
       // actions
       returnHandler = -1;
       return;
     }
     else{
          signal(SIGINT, INThandler);
     }

     int tmp;
     while ((tmp = getchar()) != EOF && tmp != '\n') { fflush(stdout); }
}
