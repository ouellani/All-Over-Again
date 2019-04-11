#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "headers.h"
#include "math.h"

int coll_trigo_cir(SDL_Rect rect1,SDL_Rect rect2)
{float x1,y1,x2,y2,r1,r2;
float d1,d2;
x1=rect1.x+rect1.w/2;
y1=rect1.y+rect1.h/2;
x2=rect2.x+rect2.w/2;
y2=rect2.y+rect2.h/2;
r1=sqrt(rect1.w/2*rect1.w/2+rect1.h/2*rect1.h/2);
r2=sqrt(rect2.w/2*rect2.w/2+rect2.h/2*rect2.h/2);
d1=r1+r2;
d2=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
if (d2<=d1)
return 1;
else return 0;
} 
int coll_trigo_ins(SDL_Rect rect1,SDL_Rect rect2)
{float x1,y1,x2,y2,r1,r2;
float d1,d2;
x1=rect1.x+rect1.w/2;
y1=rect1.y+rect1.h/2;
x2=rect2.x+rect2.w/2;
y2=rect2.y+rect2.h/2;
if (rect1.w<rect1.h)
r1=rect1.h/2;
else 
r1=rect1.w/2;
if (rect2.w<rect2.h)
r2=rect2.h/2;
else 
r2=rect2.w/2;
d1=r1+r2;
d2=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
if (d2<=d1)
return 1;
else return 0;
}
