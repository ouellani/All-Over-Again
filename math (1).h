#ifndef math_H
#define math_H
//#ifdef WIN32
//#pragma comment(lib,"sdl.lib")
//#pragma comment(lib,"sdlmain.lib")

#define STAT_SOL 0
#define STAT_AIR 1

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personnage.h"
/*typedef struct
{
    int status;
    float x,y;
    float vx,vy;
} Sprite;
void InitSprite(Sprite* Sp);
void Render(Sprite* Sp,SDL_Surface* screen);*/
void Saute(player* Sp,float impulsion);
void ControleSol(player* Sp);
void Gravite(player* Sp,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(player* Sp,Uint8* keys);

#endif

