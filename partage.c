#include "partage.h"


void afficher_background(backgr *bg)
{
bg->pos.x=0;
bg->pos.y=0;
image=IMG_Load("nature.png");
SDL_BlitSurface(image,NULL,ecran,&bg->pos);
}

void afficher_background1(backgr *bg1)
{
bg1->pos.x=0;
bg1->pos.y=250;
image=IMG_Load("nature.png");
SDL_BlitSurface(image,NULL,ecran,&bg1->pos);
}

int main(int argc, char *argv[])
{
SDL_Init(SDL_INIT_EVERYTHING);
ecran=SDL_SetVideoMode(700,500,32,SDL_HWSURFACE|SDL_RESIZABLE);
backgr bg;
backgr bg1;
afficher_background(&bg);
afficher_background1(&bg1);
SDL_Flip(ecran);
pause();
}

