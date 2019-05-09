#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
#include"ai.h"

int main(int argc, char const *argv[])
{
  
  Uint32 start ;
  const int FPS= 60;


  Acteurs acteurs;
  Boutons boutons;
  Hero hero ;
  Enemy enemy ;
  

   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

 SDL_ShowCursor(SDL_DISABLE);
  
/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "THE MYSTERIOUS ISLAND", NULL );

    initializeHero(&hero);
    initializeEnemy(&enemy);
    initialisation(&acteurs);
    update_points_de_collision(&hero);


    drawHero(hero, &acteurs);
    drawEnemy(enemy , &acteurs);
    draw_life_bar(&hero  , &acteurs);



int carryon = 1;
while(carryon)
{		


	    start=SDL_GetTicks();
				

	    if (hero.vies == 0)
	    {

	    carryon=0 ;

	    }

		intelligence_artificielle(&enemy,acteurs ,&hero);

		SDL_PollEvent(&acteurs.event);

		animationhero(&hero, acteurs);
		updatePlayer(&hero , &acteurs) ;

		centerScrollingOnPlayer(&hero, &acteurs);


		drawHero(hero , &acteurs) ;

		drawEnemy(enemy , &acteurs) ;

		drawEnemy2(enemy , &acteurs) ;

		drawEnemy3(enemy , &acteurs) ;

		drawEnemy4( enemy ,  &acteurs) ;

				drawEnemy5( enemy ,  &acteurs) ;

enemy=gestion_ai(hero,enemy);
affichageattack(&enemy,acteurs.screen);
//printf("BUG \n");
        draw_life_bar(&hero  , &acteurs);

		SDL_Flip(acteurs.screen);

//printf("camera=%d \n",acteurs.camera.x);


	switch(acteurs.event.type)
	{
		case SDL_QUIT:
             carryon = 0;
    	case SDL_KEYDOWN:
			if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
				{
					carryon= 0;
				}
			break;

	}

if ( 1000/FPS > SDL_GetTicks()-start )
		{
			SDL_Delay( 1000/FPS - (SDL_GetTicks()-start)) ;
		}

}




    //LIB
	SDL_Quit();
	return 0 ;

}






