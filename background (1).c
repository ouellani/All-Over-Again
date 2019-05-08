#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "background.h"



void initialiserback(background *b)
{
b->posback.x = 0;
b->posback.y = 0;
b->back = SDL_LoadBMP("forest.bmp");
}

void afficherback(background b, SDL_Surface *screen)
{
SDL_BlitSurface(b.back,NULL,screen,&b.posback);

}

