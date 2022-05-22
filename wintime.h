#include <gL/glut.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DAYSIZE 3 + 1

typedef struct weekday{
	int hour12;
	int weekdaynum;
	char weekday[DAYSIZE];
} WEEKDAY;

time_t tt;
struct tm *ts;
WEEKDAY wd;

void weekdayreturn(WEEKDAY *);
void clocktime();
void glClockHands(int, int);

void Display(void);
void Reshape(int, int);
void Timer(int);