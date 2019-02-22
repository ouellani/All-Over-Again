#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

int main()
{SDL_Surface *screen=NULL;
SDL_Surface *image;
/*declaration des surfaces screen pour l ecran et image pour le caractere*/
SDL_Rect positionecran;
/*declaration de variable de type structure contenant la difference position de l image parrapport au coin fo9ani aal ysar*/ 
SDL_Event event;
/*declaration d une variable de type evenement*/
char pause;
int continuer=1;
if(SDL_Init(SDL_INIT_VIDEO)==-1)
printf("eurreur d initialisation:%s\n",SDL_GetError());
/*initialisation de l interfce a ouvrir*/ 
screen=SDL_SetVideoMode(600,400,32,SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
/*ouverture de l interface*/
if(screen==NULL)
{
printf("unable to set 600*400 video : %s",SDL_GetError());
return -1;
}
/*controle l ouverture de la fenetre*/
SDL_WM_SetCaption("ma premiere fenetre",NULL);
/*ajouter un titre a la fenetre*/
SDL_FillRect(screen,background.bmp,SDL_MapRGB(screen->format,255,255,255));
/*ajout du couleur a la fenetre*/
image=SDL_LoadBMP("image.bmp");
/*chargement d une photo a la memoire*/
positionecran.x=0;
positionecran.y=150;
positionecran.h=100;
positionecran.w=80;
/*positionner l image*/
SDL_BlitSurface(image, NULL,screen,&positionecran);
/*emplacer l image sur l ecran*/
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
Mix_Music*music;
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);


SDL_EnableKeyRepeat(40,40);
while (continuer==1)
{
SDL_WaitEvent(&event);
/*lecture d un evenement*/

	switch(event.type)
	{
		case SDL_QUIT :
		/*si c est un evenement de type quitter */
		{
			continuer=0;
		/*COUPER LA BOUCLE WHILE*/
		}break;
		case SDL_KEYDOWN:
		/*au cas du pression d un boutton du clavier*/
		{switch(event.key.keysym.sym)
			{
				case SDLK_UP :
				{positionecran.y-=30;}break;
				case SDLK_RIGHT :
				{
				positionecran.x+=5;}break;
				case SDLK_LEFT :
				positionecran.x-=5;break;
			}
		}break;
	case SDL_MOUSEBUTTONUP:
			{positionecran.y=event.button.y;
			positionecran.x=event.button.x;
			}
	}
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);
switch(event.type)
{case SDL_KEYUP:
positionecran.y=150;break;

}
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);
/*refraichir l ecran*/

   
}

Mix_FreeMusic(music);
Mix_CloseAudio();
   return EXIT_SUCCESS;
SDL_FreeSurface(image);
SDL_Quit();

}
