#ifndef CTRL_C
#define CTRL_C

#include "struct.h"

// Declaration de tout ce qu'on devra free en cas de fin de programme avec ctrl-C
extern char* permActuelle;
extern char* bestPermString;

extern int returnHandler;

extern double bestLen ;
extern double worstLen;

/**
 * @brief Gere le signal du controle-C
 * @param sig est le numero du signal associe
 * @return void
 */
void  INThandler(int sig);

#endif