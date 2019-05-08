#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct background
{
SDL_Surface *back;
SDL_Rect posback;
}background;



void initialiserback(background *b);
void afficherback(background b, SDL_Surface *screen);

#endif // BACKGROUND_H_INCLUDED

