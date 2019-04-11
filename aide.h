#ifndef DEFS_H_
#define DEFS_H_
typedef struct help
{SDL_Surface *image;
SDL_Rect h_p;
SDL_Surface *gadget;
SDL_Rect g_p;
}help;
void init_aide(help *h);
void afficher_help(SDL_Surface **screen,help h);
void help_mvt(help *h);
#endif
