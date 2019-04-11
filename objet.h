#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <SDL/SDL_image.h>


typedef struct objet
{
SDL_Rect position;
SDL_Surface *image;
}objet;



void init_objet (objet *o,int x,int y,char *objetname);
void afficher_objet(objet o,SDL_Surface *screen);



#endif
