#include "ctrl_c.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "struct.h"
#include "P1_fonctions.h"
#include "lectureTSPLIB.h"

void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     printf("Vous avez appuye sur la touche Ctrl-C\n");
     printf("Meilleure tournee:\n %s", bestPermString);
     printf("Longueur de la meilleure tournee: %f\n", bestLen);
     printf("Permutation actuelle: %s\n", permActuelle);



     printf("Voulez vous vraiment quitter? [y or n]\n");
     
     c = getchar();
     if (c == 'y' || c == 'Y'){
       // actions
       exit(0);
     }
     else{
          signal(SIGINT, INThandler);
     }

     getchar(); // Get new line character
}
