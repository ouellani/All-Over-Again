#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include "ennemi.h"


int main (void)

{

SDL_Surface *screen=NULL;

ennemi e;
screen= SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Flip(screen);

while(1)
{
initEnnemi(&e);
afficherEnnemi(e,screen,0);
}

SDL_Quit;

return 0;
}

