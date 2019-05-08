#ifndef PER_H_INCLUDED
#define PER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
/*typedef struct
{

SDL_Surface *personnage;

    int status;
    float x,y;
    float vx,vy;
SDL_Rect R;

}
Sprite;*/

typedef struct player
{SDL_Surface *images[7];
int compteur,nbr_vie,score,dist,direction;
SDL_Rect pos;
float x,y;
    float vx,vy;
}player;




void initialiser_perso(player* Sp);
void afficherperso(player Sp , SDL_Surface *screen);

#endif // COLLISION_H_INCLUDED

