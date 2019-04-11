#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "aide.h"
void init_aide(help *h)
{h->image=IMG_Load("monkey.png");
h->h_p.x=0;
h->h_p.y=250;

}
void afficher_help(SDL_Surface **screen,help h)
{SDL_BlitSurface(h.image,NULL,*screen,&h.h_p);
}
void help_mvt(help *h)
{SDL_Event event;
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:
	{switch(event.key.keysym.sym)
		{
			case SDLK_RIGHT : h->h_p.x+=3;break;
			case SDLK_LEFT : h->h_p.x=h->h_p.x-3;break;
		}
	}break;


}
}


























