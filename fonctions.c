#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"



/*________________________________________________________________________________________*/



void initialisation(Acteurs* acteurs)
{
	SDL_Surface* tmp1, *tmp2;
	tmp1 = SDL_LoadBMP("stage1_collision.bmp");
	acteurs->backg_collision = SDL_DisplayFormat(tmp1);
	SDL_FreeSurface(tmp1);

	tmp2 = SDL_LoadBMP("stage1.bmp");
	acteurs->backg = SDL_DisplayFormat(tmp2);
	SDL_FreeSurface(tmp2);
	acteurs->camera.x = 4000;
	acteurs->camera.y = 0;
	acteurs->camera.w = SCREEN_WIDTH;
	acteurs->camera.h = SCREEN_HEIGHT;
}



/*________________________________________________________________________________________*/



/*---fonction d initialisation de l hero---*/

void initializeHero(Hero* hero)
{
	SDL_Surface* tmp  , *tmp1  ;

	tmp = SDL_LoadBMP("sprite_hero_right.bmp");
	hero->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));



	tmp1 = SDL_LoadBMP("v.bmp");
	hero->life_bar = SDL_DisplayFormat(tmp1);
	SDL_FreeSurface(tmp1);
	SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));


	//Indique l'état et la direction de notre héros
	hero->direction = RIGHT;
	hero->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	hero->frame_timer = TIME_BETWEEN_2_FRAMES;
	hero->frame_number = 0;

	/* Coordonnées de démarrage de notre héros */
	hero->x = 4200 ;
	hero->y = 0 ;

	hero->x_life_bar = 14 ;
	hero->y_life_bar = 9 ;
	hero->w_life_bar = LIFE_BAR_WIDTH ;
	hero->h_life_bar = LIFE_BAR_HEIGHT ;

	hero->Ysaut = 5;

	hero->jump = NON;
	hero->ground = NON;
	hero->vies = 3 ;

}



/*________________________________________________________________________________________*/



/*---fontion pour afficher l'hero ---*//////////////////////////

void drawHero(Hero hero , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero.x - acteurs->camera.x;
dest.y = hero.y ;


/*SDL_Rect dest_life_bar ;
dest_life_bar.x = hero.x_life_bar - acteurs->camera.x;
dest_life_bar.y = hero.y_life_bar ;
dest_life_bar.w = LIFE_BAR_WIDTH ;
dest_life_bar.h = LIFE_BAR_HEIGHT  ;*/



SDL_Rect frame;
frame.x = hero.frame_number*PLAYER_WIDTH;
frame.y = 0;
frame.w = PLAYER_WIDTH;
frame.h = PLAYER_HEIGHT;


/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs->backg, &acteurs->camera, acteurs->screen, NULL);
SDL_BlitSurface(hero.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(hero.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero.sprite->format, 255, 255, 255));


/*SDL_BlitSurface(hero.life_bar , &frame , acteurs->screen , &dest_life_bar) ;
SDL_SetColorKey(hero.life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero.life_bar->format, 255, 255, 255));*/



}


/*________________________________________________________________________________________*/



/*---fonction de deplacement de l hero---*/

void updatePlayer(Hero* hero , Acteurs* acteurs)
{	
	int resultat_de_collision_droite = 0,
	resultat_de_collision_gauche =0 ,
	resultat_de_collision_bas =0 ;

	hero->PLAYER_SPEED=12 ;




	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE)
		{



			if (acteurs->event.key.keysym.sym == SDLK_SPACE )
			{

			hero->PLAYER_SPEED += PLAYER_ACCELERATION ;

			}	


			if(hero->etat == IMMOBILE || hero->etat == WALK_LEFT)
			{
				hero->etat = WALK_RIGHT;
			}
			if(hero->direction == LEFT)
				{
					hero->direction = RIGHT ;
				}
			hero->sprite = SDL_LoadBMP("sprite_hero_right.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			

			hero->x += hero->PLAYER_SPEED;
			//hero->x_life_bar += hero->PLAYER_SPEED; 




			update_points_de_collision(hero) ;

			resultat_de_collision_droite = verification_collision_player_map_droite( acteurs , hero) ;

			if(resultat_de_collision_droite== Collision_droite)
			{

			hero->x -= hero->PLAYER_SPEED ;

			update_points_de_collision(hero) ;

			}

			if (hero->x + PLAYER_WIDTH >= Backg_W)
				{
					hero->x = Backg_W - PLAYER_WIDTH ;
				}

			

			
		}


		else if(acteurs->event.key.keysym.sym == SDLK_LEFT )
		{   
			
			if(hero->etat == IMMOBILE || hero->etat == WALK_RIGHT)
			{
				hero->etat = WALK_LEFT;
			}
			if(hero->direction == RIGHT)
				{
					hero->direction = LEFT ;
				}
			hero->sprite = SDL_LoadBMP("sprite_hero_left.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x -= hero->PLAYER_SPEED ;

			update_points_de_collision(hero) ;

			resultat_de_collision_gauche = verification_collision_player_map_gauche( acteurs , hero) ;

			if(resultat_de_collision_gauche==Collision_gauche)
			{

			hero->x += hero->PLAYER_SPEED ;
			update_points_de_collision(hero) ;

			}


            if (hero->x < 0)
				{
					hero->x = 0 ;
				}
		}
	} 

    if(acteurs->event.key.keysym.sym == SDLK_UP)
	{
		herojump(hero);
	}  
    if(acteurs->event.type == SDL_KEYUP)
	{
		if(hero->etat != IMMOBILE)
		{
			hero->etat = IMMOBILE;
		}
	}

	resultat_de_collision_bas = verification_collision_player_map_bas(acteurs , hero);
	update_points_de_collision(hero);
	//printf("Collision = %s\n", (resultat_de_collision == 1) ? "Detecté" : "Pas de collision");
	if(resultat_de_collision_bas == Collision_bas)
	{
		hero->ground = OUI;
		hero->Ysaut = 0;
	}
	//printf("Ground = %s\n", (hero->ground == NON) ? "OFF" : "ON");
	if(resultat_de_collision_bas != Collision_bas && hero->jump == NON)
		hero->Ysaut = YSAUT;
	//printf("Ysaut = %d\n", hero->Ysaut);
	//printf("Y = %d\n", hero->y);
	if(hero->jump == OUI && hero->Ysaut < 0)
		hero->Ysaut += GRAVITY;
	else
		hero->jump = NON;
		

	hero->y += hero->Ysaut ;
}

void herojump(Hero* hero)
{
	if(hero->jump == NON && hero->ground == OUI)
	{
		hero->jump = OUI;
		hero->ground = NON;
		hero->Ysaut = -28;
		hero->y -= 5;
	}
}


/*________________________________________________________________________________________*/


//fonction pour annimer l'hero

void animationhero(Hero* hero, Acteurs acteurs)
{
	if(acteurs.event.type == SDL_KEYDOWN)
	{
		if(acteurs.event.key.keysym.sym == SDLK_LEFT || acteurs.event.key.keysym.sym == SDLK_RIGHT || acteurs.event.key.keysym.sym == SDLK_SPACE)
		{
			if(hero->frame_timer <= 0)
			{
				hero->frame_number++;
				SDL_Delay(15);
			if(hero->frame_number > MAXF-1)
				hero->frame_number = 0;
			}
		else
		hero->frame_timer--;
		SDL_Delay(15);

		}
	}
	
	if(acteurs.event.type == SDL_KEYUP)
	{
		if(hero->direction == RIGHT)
		{
			hero->frame_number = 0;
		}
		else if(hero->direction == LEFT)
		{
			hero->frame_number = MAXF-1;
		}
	}
}



/*________________________________________________________________________________________*/




/*---fonction pour faire le scrolling---*/

void centerScrollingOnPlayer(Hero *hero, Acteurs* acteurs)
{
	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE )
	{
		if((hero->x + PLAYER_WIDTH/2) > SCREEN_WIDTH/2)
			{
				hero->x_life_bar += hero->PLAYER_SPEED; ////*****
				acteurs->camera.x += hero->PLAYER_SPEED;
			}
		if(acteurs->camera.x > Backg_W - SCREEN_WIDTH)
			{
				hero->x_life_bar = Backg_W - SCREEN_WIDTH; ////*****
				acteurs->camera.x = Backg_W - SCREEN_WIDTH;
			}
	}
	else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
	{
				hero->x_life_bar -= hero->PLAYER_SPEED; ////*****
				acteurs->camera.x -= hero->PLAYER_SPEED;

		if((hero->x + PLAYER_WIDTH/2) > (Backg_W - SCREEN_WIDTH/2))
		{
			hero->x_life_bar = Backg_W - SCREEN_WIDTH; ////*****
			acteurs->camera.x = Backg_W - SCREEN_WIDTH;
		}
			
		if(acteurs->camera.x < 0)
			{
				acteurs->camera.x = 0;
			}
	}
	}
}



/*________________________________________________________________________________________*/


SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) 
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;

}

/*________________________________________________________________________________________*/


//pour mettre a jour les points de collision ! on 12 points de collision !!!


void update_points_de_collision(Hero* hero)
{				

  //points a droite de l'hero 

	hero->x1=hero->x + PLAYER_WIDTH ;
	hero->y1=hero->y ;												

	hero->x2=  hero->x + PLAYER_WIDTH;
	hero->y2= hero->y + 100  ;


	hero->x3=hero->x + PLAYER_WIDTH ;
	hero->y3= hero->y + PLAYER_HEIGHT - 25 ;


	hero->x4=hero->x + PLAYER_WIDTH ;
	hero->y4= hero->y + 50  ;


	hero->x5=hero->x + PLAYER_WIDTH ;
	hero->y5= hero->y + 150  ;

	//points a gauche de l'hero 

	hero->x6=  hero->x ;
	hero->y6=  hero->y ;

	hero->x7=  hero->x ;
	hero->y7=  hero->y + 100 ;

	hero->x8= hero->x  ;
	hero->y8=  hero->y + PLAYER_HEIGHT - 25;

	hero->x9=  hero->x ;
	hero->y9=  hero->y + 50 ;

	hero->x10=  hero->x ;
	hero->y10=  hero->y + 150 ;

	//points au milieu de l'hero 

	hero->x11=  hero->x + 50 ;
	hero->y11=  hero->y ;

	hero->x12=  hero->x + 50 ;
	hero->y12=  hero->y + PLAYER_HEIGHT ;


}


/*________________________________________________________________________________________*/

//fonction de verification de collision entre le bachground du premier stage et l'hero ! cette fonction retourne 1 en cas de collision sinon 0


int verification_collision_player_map_droite(Acteurs* acteurs , Hero* hero)
{

SDL_Color color1 , color2 , color3 , color4 , color5 ;

int coll = 0;

color1=GetPixel (acteurs->backg_collision , hero->x1 , hero->y1) ; 
color2=GetPixel (acteurs->backg_collision , hero->x2 , hero->y2) ; 
color3=GetPixel (acteurs->backg_collision , hero->x3 , hero->y3) ;
color4=GetPixel (acteurs->backg_collision , hero->x4 , hero->y4) ;     
color5=GetPixel (acteurs->backg_collision , hero->x5 , hero->y5) ;

  
if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255)) 
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) || ((color4.r==255)  &&  (color4.g==255)  &&  (color4.b==255)) 
	|| ((color5.r==255)  &&  (color5.g==255)  &&  (color5.b==255) ))  
{
	coll = Collision_droite;
}

return coll;
}

int verification_collision_player_map_gauche(Acteurs* acteurs , Hero* hero)
{

SDL_Color color6 , color7 , color8 , color9 , color10 ;

int coll = 0;

color6=GetPixel (acteurs->backg_collision , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->backg_collision , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->backg_collision , hero->x8 , hero->y8) ;
color9=GetPixel (acteurs->backg_collision , hero->x9 , hero->y9) ;
color10=GetPixel (acteurs->backg_collision , hero->x10 , hero->y10) ;
  
if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) ) 
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) ) || ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) )
	 || ((color9.r==255)  &&  (color9.g==255)  &&  (color9.b==255) ) || ((color10.r==255)  &&  (color10.g==255)  &&  (color10.b==255)))
{
	coll = Collision_gauche;
}

return coll;
}

int verification_collision_player_map_top(Acteurs* acteurs , Hero* hero)
{

SDL_Color  color11  ;

int coll = 0;

color11=GetPixel (acteurs->backg_collision , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ))
{
	coll = Collision_top;
}

return coll;
}

int verification_collision_player_map_bas(Acteurs* acteurs , Hero* hero)
{

SDL_Color  color12 ;

int coll = 0;


color12=GetPixel (acteurs->backg_collision , hero->x12 , hero->y12) ;

if(((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
	coll = Collision_bas;
}

return coll;
}


/*________________________________________________________________________________________*/


/*---fonction d initialisation de l enemy---*/

void initializeEnemy(Enemy* enemy)
{
	SDL_Surface* tmp , *tmp2 , *tmp3  , *tmp4  ;
enemy->direction2=0;
enemy->attacking=0;
enemy->posattack.y=450;
enemy->posattack.x=enemy->x5;
enemy->attack=IMG_Load("1.png");

	tmp = SDL_LoadBMP("e1.bmp");
	enemy->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(enemy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite->format, 255, 255, 255));


	tmp2 = SDL_LoadBMP("e2.bmp");
	enemy->sprite2 = SDL_DisplayFormat(tmp2);
	SDL_FreeSurface(tmp2);
	SDL_SetColorKey(enemy->sprite2 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite2->format, 255, 255, 255));



	tmp3 = SDL_LoadBMP("e3.bmp");
	enemy->sprite3 = SDL_DisplayFormat(tmp3);
	SDL_FreeSurface(tmp3);
	SDL_SetColorKey(enemy->sprite3 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite3->format, 255, 255, 255));


    tmp4 = SDL_LoadBMP("e4.bmp");
	enemy->sprite4 = SDL_DisplayFormat(tmp4);
	SDL_FreeSurface(tmp4);
	SDL_SetColorKey(enemy->sprite4 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite4->format, 255, 255, 255));


	


	//Indique l'état et la direction de notre enemy
	enemy->direction = RIGHT;
	enemy->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	enemy->frame_timer = TIME_BETWEEN_2_FRAMES;
	enemy->frame_number = 0;

	/* Coordonnées de démarrage de notre enemies */
	enemy->x = 1572 ;
	enemy->y = 422 ;

	enemy->x2 = 2361 ;
	enemy->y2 = 181 ;

	enemy->x3 = 3083 ;
	enemy->y3 = 422 ;
    
    enemy->x4 = 7463 ;
	enemy->y4 = 422 ;
	

    enemy->x5 = 4500 ;
	enemy->y5 = 422 ;
}


/*________________________________________________________________________________________*/



/*---fontion pour afficher l'enemy ---*//////////////////////////

void drawEnemy(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x - acteurs->camera.x;
dest.y = enemy.y ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite->format, 255, 255, 255));
SDL_Delay(15);
	
}


/*________________________________________________________________________________________*/


void drawEnemy2(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x2 - acteurs->camera.x;
dest.y = enemy.y2 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite2 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite2 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite2->format, 255, 255, 255));
SDL_Delay(15);
	
}


/*________________________________________________________________________________________*/


void drawEnemy3(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x3 - acteurs->camera.x;
dest.y = enemy.y3 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite3 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite3 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite3->format, 255, 255, 255));
SDL_Delay(15);
	
}


/*________________________________________________________________________________________*/


void drawEnemy4(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x4 - acteurs->camera.x;
dest.y = enemy.y4 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite4 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite4 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite4->format, 255, 255, 255));
SDL_Delay(15);
	
}



void drawEnemy5(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x5 - acteurs->camera.x;
dest.y = enemy.y5 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite4 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite4 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite4->format, 255, 255, 255));
SDL_Delay(15);
	
}


/*________________________________________________________________________________________*/




void animationEnemy(Enemy* enemy, Acteurs acteurs)
{		
			if(enemy->frame_timer <= 0)
			{
				enemy->frame_number++;
				SDL_Delay(15);
			if(enemy->frame_number > MAXF_ENEMY-1)
				enemy->frame_number = 0;
			}
		else
		enemy->frame_timer--;
		SDL_Delay(15);	
	
}



/*________________________________________________________________________________________*/



void intelligence_artificielle(Enemy *enemy, Acteurs acteurs , Hero* hero)
{

int d, d2 , d3 , d4 , d5 , resultat_collision_enemy1 , resultat_collision_enemy2 , resultat_collision_enemy3 , resultat_collision_enemy4,resultat_collision_enemy5 ;  
SDL_Surface *tmp1 ;





  		d = enemy->x - hero->x - PLAYER_WIDTH;
  		d2 = enemy->x2 - hero->x - PLAYER_WIDTH;
		d3 = enemy->x3 - hero->x - PLAYER_WIDTH;
		d4 = enemy->x4 - hero->x - PLAYER_WIDTH;
				d5 = enemy->x5 - hero->x - PLAYER_WIDTH;


  		resultat_collision_enemy1 = collision_player_enemy1(hero , enemy);
  		resultat_collision_enemy2 = collision_player_enemy2(hero , enemy);
  		resultat_collision_enemy3 = collision_player_enemy3(hero , enemy);
  		resultat_collision_enemy4 = collision_player_enemy4(hero , enemy);
		  		resultat_collision_enemy5 = collision_player_enemy5(hero , enemy);
		
 

		if(d<500 && d>0)
		{
				
			enemy->x -= 3 ;	
			animationEnemy(enemy,  acteurs);

		}
		else if( resultat_collision_enemy1==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy(*enemy , &acteurs) ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}





		if(d2<500 && d2>0)
		{
				
			enemy->x2 -= 3 ;	
			animationEnemy(enemy,  acteurs);

				
		}
		else if( resultat_collision_enemy2==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy2(*enemy , &acteurs) ;


			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}



		}





		if(d3<500 && d3>0)
		{		
			enemy->x3 -= 3 ;	
			animationEnemy(enemy,  acteurs);
		}
		else if( resultat_collision_enemy3==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy3(*enemy , &acteurs) ;


			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}



		}





		if(d4<500 && d4>0)
		{
				
			enemy->x4 -= 3 ;	
			animationEnemy(enemy,  acteurs);

				
		}
		else if( resultat_collision_enemy4==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy4(*enemy , &acteurs) ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}

		
}


/*________________________________________________________________________________________*/
              

int collision_player_enemy1(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


int collision_player_enemy2(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y2 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x2 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y2)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x2)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/

int collision_player_enemy3(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y3 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x3 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y3)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x3)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/

int collision_player_enemy4(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y4 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x4 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y4)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x4)
                return 0;
        return 1;
}

int collision_player_enemy5(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y5 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x5 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y5)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x5)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


void draw_life_bar(Hero *hero  , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero->x_life_bar - acteurs->camera.x;
dest.y = hero->y_life_bar ;


/*SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;*/

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(hero->life_bar , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));
SDL_Delay(15);
	
}


/*________________________________________________________________________________________*/


