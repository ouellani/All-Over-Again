#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"fonction.h"
int main() {


SDL_Surface *screen=NULL,*player1,*player2,*background1,*background2;
SDL_Rect posback1,posback2,posplayer1,posplayer2;
SDL_Event event;
  int game =1,directionSDL1,directionSDL2;
  background1=IMG_Load("background1.png");
  background2=IMG_Load("background2.png");
  player1=IMG_Load("player1.png");
  player2=IMG_Load("player2.png");
  SDL_Init( SDL_INIT_EVERYTHING );
  screen = SDL_SetVideoMode(700, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
initposition(&posback1,&posback2,&posplayer1,&posplayer2);
//initimage(background1,background2 ,player1,player2);
SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

while (game)
{
  //input from SDL
  while(SDL_PollEvent(&event)){
        switch (event.type)
        {
        // exit if the window is closed
        case SDL_QUIT:
            game = 0;
            break;
        case SDL_KEYDOWN:
        {

            if (event.key.keysym.sym == SDLK_w)//perso 1
              directionSDL1 = 1;

            if (event.key.keysym.sym == SDLK_e)//perso 1
              directionSDL1 = 2;
          if (event.key.keysym.sym == SDLK_o)//perso 2
          directionSDL2 = 1;
          if (event.key.keysym.sym == SDLK_p)//perso 2
          directionSDL2 = 2;
        }break;
        break;
        case SDL_KEYUP:
          directionSDL1=0;
          directionSDL2=0;
        break;

      }}
movementplayer(&directionSDL1,&directionSDL2,&posplayer1,&posplayer2);


SDL_BlitSurface(background1,NULL,screen,&posback1);
SDL_BlitSurface(background2,NULL,screen,&posback2);
SDL_BlitSurface(player1,NULL,screen,&posplayer1);
SDL_BlitSurface(player2,NULL,screen,&posplayer2);
SDL_Flip(screen);
}





SDL_FreeSurface(background1);
SDL_FreeSurface(background2);
SDL_FreeSurface(player1);
SDL_FreeSurface(player2);


}

