#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>



typedef struct
{

SDL_Rect  position_element;
SDL_Surface * image_element;
SDL_Rect positionmax_element;
SDL_Rect positionmin_element;


}element;



void initialiser(element *E);
int position_aleatoire(int positionmax_element,int positionmin_element);
void deplacement_aleatoire(element  E,SDL_Surface*screen);



















































#endif /* FONCTIONS_H_ */
