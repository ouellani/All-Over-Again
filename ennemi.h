#ifndef ENNEMI_H_INCLUDED

#define ENNEMI_H_INCLUDED


#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

 typedef struct ennemi
 
 {
     SDL_Surface *tab[8];
     SDL_Rect posEnnemi;
  }ennemi;


 
void initEnnemi(ennemi *e);
 
void afficherEnnemi(ennemi enm,SDL_Surface *screen,int i);
 

#endif

