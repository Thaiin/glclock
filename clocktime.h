#include <GL/glut.h>
#include <GL/glpng.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DAYSIZE 3 + 1
#define SQ 1440
#define RENEWALTIME 50
#define DEFAULTTHEME 0
#define BLACKTHEME 1

typedef struct daytime{
	int hour12;
	int weekdaynum;
} DAYTIME;

typedef struct displaysetting{	//defaultの時の針の色
	int r;
	int g;
	int b;
	int colormode;
} DISPLAYSETTING;

time_t tt;
struct tm *ts;

DAYTIME wd;
DISPLAYSETTING circle;
DISPLAYSETTING hand;

// display.c
void themeInit();
void themeChange();
void reshapewin(int, int);

// clock.c
void nowtime();

// shape.c
void glClockCircle(int, int);
void glClockPoints(int, int);
void glClockHands(int, int);

// callbackfunc.c
void Display(void);
void Reshape(int, int);
void Timer(int);
void Keyboard(unsigned char, int, int);