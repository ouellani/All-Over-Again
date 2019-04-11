#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "objet.h"
#include <SDL/SDL_image.h>

int main(void){

SDL_Surface *screen;
SDL_Surface *image;

objet o1;
objet o2;
char pause;
SDL_Rect positionscreen;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(900,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


image =IMG_Load("bg.png");

positionscreen.x=0;
positionscreen.y=0;



init_objet (&o1,0,100,"o1.png");
init_objet (&o2,320,100,"o2.png");


int done =1 ;
while (done)
{

SDL_BlitSurface(image,NULL,screen,&positionscreen);




afficher_objet(o1,screen);
afficher_objet(o2,screen);





while(SDL_PollEvent(&event))
{


switch(event.type)
{
case SDL_QUIT:
done= 0;
break;
}

SDL_Flip(screen);
}





SDL_Flip(screen);

}

SDL_FreeSurface(image);


SDL_Quit();

return EXIT_SUCCESS;
pause= getchar();
return 0;
}


