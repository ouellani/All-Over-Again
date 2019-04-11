#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "objet.h"
#include <SDL/SDL_image.h>


void init_objet (objet *o,int x,int y,char* objetname)
{
o->position.x=x;
o->position.y=y;
o->image= IMG_Load(objetname);

}




void afficher_objet(objet o,SDL_Surface *screen)
{
SDL_BlitSurface(o.image,NULL,screen,&o.position);
}
