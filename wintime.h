#include <gL/glut.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DAYSIZE 3 + 1
#define SQ 12

typedef struct daytime{
	int hour12;
	int weekdaynum;
	char weekday[DAYSIZE];
} DAYTIME;

time_t tt;
struct tm *ts;
DAYTIME wd;

void weekdayreturn(DAYTIME *);
void clocktime();
void glClockHands(int, int);
void glClockCircle(int, int);

void Display(void);
void Reshape(int, int);
void Timer(int);
void Keyboard(unsigned char, int, int);