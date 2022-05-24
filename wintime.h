#include <gL/glut.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DAYSIZE 3 + 1
#define SQ 1440
#define RENEWALTIME 50

typedef struct daytime{
	int hour12;
	int weekdaynum;
} DAYTIME;

time_t tt;
struct tm *ts;
DAYTIME wd;

void clocktime();
void glClockCircle(int, int, int, int, int);
void glClockHandsLines(int, int, int, int, int);
void glClockHands(int, int, int, int, int);
void themeChange();

void Display(void);
void Reshape(int, int);
void Timer(int);
void Keyboard(unsigned char, int, int);