#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



void initposition(SDL_Rect *posback1,SDL_Rect *posback2,SDL_Rect *posplayer1,SDL_Rect *posplayer2);
//void initimage(SDL_Surface *back1,SDL_Surface *back2 ,SDL_Surface *player1,SDL_Surface *player2);
void movementplayer(int *directionSDL1,int *directionSDL2,SDL_Rect *posplayer1,SDL_Rect *posplayer2);
#endif // FILE_H_INCLUDED

