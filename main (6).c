#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "math.h"
#include "personnage.h"
#include "background.h"

int main(int argc,char** argv)
{
    SDL_Surface* screen;
background b;
    int numkeys;
    Uint8 * keys;
    player S;
    Uint32 timer,elapsed;

    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(600,320,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
initialiserback(&b);
 initialiser_perso(&S);
    do
    {
        timer = SDL_GetTicks();
        SDL_FillRect(screen,NULL,0);
        SDL_PumpEvents();
        keys = SDL_GetKeyState(&numkeys);
        Evolue(&S,keys);

afficherback(b,screen);
afficherperso(S,screen);
//        Render(&S,screen);
        SDL_Flip(screen);
        elapsed = SDL_GetTicks() - timer;
        if (elapsed<20)
            SDL_Delay(20-elapsed);
    } while (!keys[SDLK_ESCAPE]);
    SDL_Quit();
    return 0;
}



