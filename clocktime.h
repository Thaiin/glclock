#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/glpng.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

DISPLAYSETTING circle;
DISPLAYSETTING hand;

// display.c
void themeInit();
void themeChange();
void reshapewin(int, int);
void inputNumber();

// setting.c
SET_POSITION locate();
DAYTIME nowtime();


// shape.c
void glClockCircle(SET_POSITION);
void glClockPoints(SET_POSITION);
void glClockHands(SET_POSITION, DAYTIME);

// callbackfunc.c
void Display(void);
void Reshape(int, int);
void Timer(int);
void Keyboard(unsigned char, int, int);