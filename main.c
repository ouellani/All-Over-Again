#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "aide.h"
#include "affichervie.h"
int main(void){
SDL_Surface *vie[5];
   
    SDL_Event event;
    SDL_Rect positionvie1,positionvie2,positionvie3,positionvie4,positionvie5,positionback;

help h;
SDL_Surface *screen=NULL,*bg=NULL;
SDL_Rect pos={0,0},positionvie={10,10};
int continuer=1;
if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set 600x400 video: %s\n",SDL_GetError());
return 1;

}
bg=SDL_LoadBMP("background.bmp");
init_aide(&h);
printf("%d\n",h.h_p.x);
while(continuer==1)
{SDL_BlitSurface(bg,NULL,screen,&pos);
affichervie(vie,&screen,positionvie);
afficher_help(&screen,h);
help_mvt(&h);

SDL_Flip(screen);

}

SDL_Quit();

return EXIT_SUCCESS;

return 0;
}
