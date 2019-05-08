#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface *ecran=NULL,*image;
typedef struct backgr
{
    SDL_Surface *image;
    SDL_Rect pos;
    int stage;
}backgr;

backgr init_background(backgr bg);
backgr init_background(backgr bg1);
void afficher_baackground(backgr bg);
void afficher_baackground(backgr bg1);
#endif // MAIN_H_INCLUDED

