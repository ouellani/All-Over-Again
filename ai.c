#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "ai.h"
#include"fonctions.h"



Enemy gestion_ai(Hero hero,Enemy enemy)
 {
int d;

d=enemy.x5-hero.x;

if(d<=250 && d>=0)
enemy.x5-=5;




else if(enemy.x5<4600 && enemy.direction2==1)
enemy.x5+=3;
else if(enemy.x5>4400 && enemy.direction2==0)
enemy.x5-=3;

else if(enemy.x5==4400)
enemy.direction2=1;

else if(enemy.x5==4600)
enemy.direction2=0;

if(d<0 && d>=-250)
enemy.x5+=5;
printf("d=%d         \n",d);

if(d<-250)
{enemy.posattack.x+=10;
enemy.attacking=1;
}



return enemy;

}

void affichageattack(Enemy *enemy,SDL_Surface *screen)
 {
if (enemy->attacking==1)
SDL_BlitSurface(enemy->attack,NULL,screen,&enemy->posattack);
}












