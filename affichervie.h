#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct viie
{
  SDL_Rect positionback;
  SDL_Surface *vie;
}viie;
void affichervie(SDL_Surface *vie[5],SDL_Surface **screen,SDL_Rect positionvie);

