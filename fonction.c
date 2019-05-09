#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>

void initposition(SDL_Rect *posback1,SDL_Rect *posback2,SDL_Rect *posplayer1,SDL_Rect *posplayer2)
{ posback1->x=0;
  posback1->y=0;
  posback2->x=0;
  posback2->y=250;
posplayer1->x=10;
posplayer1->y=170;
posplayer2->x=10;
posplayer2->y=380;

}



void movementplayer(int *directionSDL1,int *directionSDL2,SDL_Rect *posplayer1,SDL_Rect *posplayer2)
{
if(*directionSDL1==1)
posplayer1->x+=10;
if(*directionSDL1==2)
posplayer1->x-=10;
if(*directionSDL2==1)
posplayer2->x+=10;
if(*directionSDL2==2)
posplayer2->x-=10;

if (posplayer1->x>1100)
posplayer1->x-=10;
if (posplayer2->x>1100)
posplayer2->x-=10;
}

