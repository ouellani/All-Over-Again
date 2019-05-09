#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#define TIME_BETWEEN_2_FRAMES 20

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 200
//#define PLAYER_SPEED 8    // ici on a enlevé cette constante et la mettre dans la structure de l'hero pour faire l'acceleration


#define YSAUT 8
#define GRAVITY 2

#define Collision_droite 20
#define Collision_gauche 30
#define Collision_top 40
#define Collision_bas 50

enum{WALK_RIGHT, WALK_LEFT, IMMOBILE, JUMP};

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define RIGHT 1
#define LEFT 2

#define MAX_FRAMES 6 
#define SPRITE_W 76
#define SPRITE_H 80
#define SPEED 5
#define PLAYER_ACCELERATION 10




#define ENEMY_Height 80
#define ENEMY_Width 76

#define Backg_W 8000
#define Backg_H 600

#define MAXF 3
#define MAXF_ENEMY 6

#define NON 0
#define OUI 1

#define LIFE_BAR_WIDTH 272
#define LIFE_BAR_HEIGHT 86



/*_________   structure numero 1  ____________ */



typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  SDL_Surface* backg_collision;
  SDL_Surface* backg;
  SDL_Rect camera;

};



/*_________   structure numero 2  ____________ */

typedef struct Boutons Boutons ;
struct Boutons 
{
	  SDL_Surface *b1 ;
    SDL_Surface *b2 ;
    SDL_Surface *b3 ;
    SDL_Surface *b4 ;
    SDL_Surface *b5 ;

    SDL_Rect posB1;
    SDL_Rect posB2;
    SDL_Rect posB3;
    SDL_Rect posB4;
    SDL_Rect posB5;
};

/*_________   structure de l hero  ____________ */

typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
Sint16 x , y ;
Sint16 Ysaut;

/* Variables utiles pour l'animation */
int frame_timer, frame_number;
int etat  , direction ; 

float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12 , x13 , x14 , x15 , x16 ;  //points de verification de collision parfaite 
float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12 , y13 , y14 , y15 , y16 ;  // points de verification de collision parfaite 

int jump, ground;
int PLAYER_SPEED ;
int vies ; 

SDL_Surface *life_bar ;
int x_life_bar , y_life_bar , w_life_bar , h_life_bar ;

};



typedef struct Enemy Enemy ;
struct Enemy 
{

SDL_Surface *sprite , *sprite2  , *sprite3 , *sprite4 ;
int direction2;
/* Coordonnées de l'enemy */
int x , y , x2 , y2  , x3 , y3 , x4 , y4,x5,y5   ;
int attacking;
SDL_Rect posattack;
SDL_Surface *attack;

/* Variables utiles pour l'animation */
int frame_timer, frame_number;
int etat  , direction ; 

SDL_Rect frame;
//SDL_Rect dst;

};





/* prototypes */
void initialisation(Acteurs* acteurs);

void initializeHero(Hero* hero) ;

void drawHero(Hero hero , Acteurs *acteurs) ;

void updatePlayer(Hero* hero , Acteurs* acteurs) ;

void centerScrollingOnPlayer(Hero *hero, Acteurs* acteurs);

void animationhero(Hero* hero, Acteurs acteurs);

SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) ;

void update_points_de_collision(Hero* hero);

void initializeEnemy(Enemy* enemy) ;

void drawEnemy(Enemy enemy , Acteurs *acteurs) ;

void drawEnemy2(Enemy enemy , Acteurs *acteurs);

void animationEnemy(Enemy* enemy, Acteurs acteurs) ;

int verification_collision_player_map_droite(Acteurs* acteurs , Hero* hero);

int verification_collision_player_map_gauche(Acteurs* acteurs , Hero* hero);

int verification_collision_player_map_top(Acteurs* acteurs , Hero* hero);

int verification_collision_player_map_bas(Acteurs* acteurs , Hero* hero);

void herojump(Hero* hero);

void intelligence_artificielle(Enemy* enemy, Acteurs acteurs, Hero* hero);

void drawEnemy3(Enemy enemy , Acteurs *acteurs);

void drawEnemy4(Enemy enemy , Acteurs *acteurs);
void drawEnemy5(Enemy enemy , Acteurs *acteurs);

int collision_player_enemy1(Hero *hero , Enemy *enemy);

int collision_player_enemy2(Hero *hero , Enemy *enemy);

int collision_player_enemy3(Hero *hero , Enemy *enemy);

int collision_player_enemy4(Hero *hero , Enemy *enemy);
int collision_player_enemy5(Hero *hero , Enemy *enemy);

void draw_life_bar(Hero *hero  , Acteurs *acteurs);

#endif /* FONCTIONS_H_ */
