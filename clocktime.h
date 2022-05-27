#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/glpng.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SQ 360
#define RENEWALTIME 100

#define WHITETHEME 0
#define BLACKTHEME 1
#define DEFAULTTHEME 2

#define SECPOINT 2
#define MINPOINT 3
#define HOURPOINT 4

typedef struct daytime{
	time_t tt;
	struct tm *ts;
	int notation12hour;
	int weekdaynum;
} DAYTIME;

typedef struct displaysetting{	//color: hands & points & circle
	int r;
	int g;
	int b;
	int colormode;
} DISPLAYSETTING;

typedef struct set_position{
	int w;
	int h;
	int cir;
	int cirdots;
	int cenw;
	int cenh;
	int sec_hand;
	int longmin_hand;
	int shorthour_hand;
} SET_POSITION;