#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
void attack(SDL_Rect p,SDL_Rect p1,int *i)
{if (p.x<(p1.x+p1.w+50)&&((*i)==2))
	{(*i)=3;
	}
}
int main()
{SDL_Surface *screen=NULL;
SDL_Surface *image=NULL;
SDL_Surface *din[4]={NULL,NULL,NULL,NULL};
SDL_Rect positionecran={600,500,150,100},posdin={0,500,450,300};
SDL_Event event;
int continuer=1,t_actuel=0,t_precedent=0,att=0,i=1;
if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
printf("eurreur d initialisation:%s\n",SDL_GetError());
screen=SDL_SetVideoMode(1200,800,32,SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("unable to set 600*400 video : %s",SDL_GetError());
return -1;
}
image=SDL_LoadBMP("image.bmp");
din[1]=SDL_LoadBMP("din.bmp");
din[0]=SDL_LoadBMP("din_up.bmp");
din[2]=SDL_LoadBMP("din_down.bmp");
din[3]=SDL_LoadBMP("din_att.bmp");
SDL_EnableKeyRepeat(50,50);
while (continuer==1)
{t_actuel=SDL_GetTicks();
if(((t_actuel-t_precedent)>2570)&&(i!=3))
	{if(i==2)
	i=0;
	else i++;
	t_precedent=t_actuel;
	}
attack(positionecran,posdin,&i);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_BlitSurface(din[i],NULL,screen,&posdin);
SDL_Flip(screen);
SDL_PollEvent(&event);
switch(event.type)
{
		case SDL_QUIT :
		{
			continuer=0;
		}break;
		case SDL_KEYDOWN:
		{switch(event.key.keysym.sym)
			{
				case SDLK_UP :
				{positionecran.y=400;
				}break;
				case SDLK_RIGHT :
				{
				positionecran.x++;}break;
				case SDLK_LEFT :{
				positionecran.x--;}break;
			}
		}break;
		case SDL_KEYUP:
		if(event.key.keysym.sym==SDLK_UP)
		{
		 positionecran.y=450;
		}
		

}
}
}
