#define STAT_SOL 0
#define STAT_AIR 1

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "personnage.h"

void initialiser_perso(player* Sp)
{
  Sp->personnage = IMG_Load("hero2.bmp");
SDL_SetColorKey(Sp->image, SDL_SRCCOLORKEY, SDL_MapRGB(Sp->image->format, 255, 255, 255));

    Sp->x = 150.0f;
    Sp->y = 250.0f;
    Sp->compteur = STAT_SOL;
    Sp->vx = Sp->vy = 0.0f;




}

void afficherperso(player Sp, SDL_Surface *screen)
{
  Sp.pos.x = (Sint16)Sp.x;
     Sp.pos.y = (Sint16)Sp.y;
     Sp.pos.w = 20;
     Sp.pos.h = 40;

SDL_BlitSurface(Sp.image,NULL,screen,&Sp.pos);
}
