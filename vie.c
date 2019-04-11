#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "affichervie.h"



void affichervie(SDL_Surface *vie[5],SDL_Surface **screen,SDL_Rect positionvie)  {
    
    SDL_Event event;
    int i=0;
    vie[0] = IMG_Load("vie0.png");
    vie[1] = IMG_Load("vie1.png");
    vie[2] = IMG_Load("vie2.png");
    vie[3] = IMG_Load("vie3.png");
    vie[4] = IMG_Load("vie4.png");

 

    //SDL_EnableKeyRepeat(100,100);
 
        SDL_PollEvent(&event);
        switch(event.type)
        {
          
            
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT:
               { if (i<4)
		i++;
               

  }               
 



                break;

                case SDLK_RIGHT:

             {if (i>0)
i--;



    }                

                break;
                
                /*case SDLK_e:
SDL_BlitSurface(back,NULL, ecran,&positionback); 
                SDL_BlitSurface(vie5,NULL, ecran,&positionvie5);

  SDL_Flip(screen);
    SDL_FreeSurface(screen); 
              

                break;*/
}
SDL_BlitSurface(vie[i],NULL,*screen,&positionvie);
}

    

}
    
    
    
