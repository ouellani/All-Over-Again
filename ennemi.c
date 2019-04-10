
#include "ennemi.h"


  void initEnnemi(ennemi *e)
  
  {

      
      e->posEnnemi.x= 0 ;
      e->posEnnemi.y= 0 ;
      e->tab[0]=IMG_Load("personnage0.png");
    
  e->tab[1]=IMG_Load("din1.png");
  
    e->tab[2]=IMG_Load("din2.png");
    
  e->tab[3]=IMG_Load("din3.png");
      e->tab[4]=IMG_Load("din4.png");
   
   e->tab[5]=IMG_Load("din5.png");
      e->tab[6]=IMG_Load("din6.png");
   
   e->tab[7]=IMG_Load("din7.png");
     
        
    }

  


  void afficherEnnemi(ennemi enm, SDL_Surface *screen,int i)
   
 {
      
     SDL_BlitSurface (enm.tab[i],NULL,screen,&enm.posEnnemi);
     SDL_Flip (screen);
    
    }

