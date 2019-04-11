#include"fonction.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>


void initialiser(element* E)
{
    E->position_element.x = 0;
    E->position_element.y = 0;
    E->image_element = IMG_Load("personnage4.png");//SDL_LoadBMP("fish.bmp");
    SDL_SetColorKey(E->image_element, SDL_SRCCOLORKEY, SDL_MapRGB(E->image_element->format, 0, 0, 255));
     E->positionmin_element.x=0;
  E->positionmax_element.x=0;

}






int position_aleatoire(int positionmax,int positionmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;


return pos;
}





void deplacement_aleatoire(element E,SDL_Surface *screen)
{
SDL_Event event;

int continuer = 1;
int tempsPrecedent = 0, tempsActuel = 0;

int pos;
static int k=0;
    
char temps[20];


E.positionmax_element.x=screen->w / 2 ;//- E.image_element->w / 2;

pos=position_aleatoire(E.positionmax_element.x,E.positionmin_element.x);



    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();



        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
           
               if(k==0)

                   {
                     if(E.position_element.x<pos)/*positionmax)*/
                          {
                            E.position_element.x++;

                          }
                     else k=1;

                   }
              if(k==1)
                  {
                    if(E.position_element.x>E.positionmin_element.x)
                            E.position_element.x--;
                    else
                         k=0;
                  }             
                                    /* On bouge l'ennemi */
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }




        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(E.image_element, NULL, screen, &E.position_element);
        SDL_Flip(screen);
    }

   
   

}
