#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SQ 360
#define RENEWALTIME 100

#define MODE1 1
#define MODE2 2
#define MODE3 3

#define WINDOW_WIDTHSIZE 500
#define WINDOW_HEIGHTSIZE 400

#define SECPOINT 2
#define MINPOINT 3
#define HOURPOINT 4
#define CENTERPOINT 8
#define MINI_CENTERPOINT 4

#define THEME1 0    // white
#define THEME2 1    // black
#define WHITERGB 240    // white
#define BLACKRGB 20     // black

// theme1 で white がメイン時のカラー
#define SEC_MINIHAND1_R 66
#define SEC_MINIHAND1_G 114
#define SEC_MINIHAND1_B 222

// theme2 で black がメイン時のカラー
#define SEC_MINIHAND2_R 222
#define SEC_MINIHAND2_G 174
#define SEC_MINIHAND2_B 66

typedef struct daytime{
	time_t tt;
	struct tm *ts;
	int notation12hour;
	char *ampm;
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
	int cenw;
	int cenh;
	int cir;
	int smallcir;
	int sec_minicenw;
	int sec_minicenh;
	int cirdots;
	int sec_hand;
	int min_hand;
	int hour_hand;
} SET_POSITION;

// 色を決める構造体の宣言
DISPLAYSETTING circle;
DISPLAYSETTING hand;
DISPLAYSETTING minihand;
DISPLAYSETTING cal;

// 時計の表示を変更するための引数
int OPERATING_STATUS;

// callbackfunc.c
void Display(void);
void Reshape(int, int);
void Timer(int);
void Keyboard(unsigned char, int, int);

// display.c
void reshapewin(int, int);
void printText(int, int, char*);
void inputTimeNumber(DAYTIME);
void printClockMode1(SET_POSITION, DAYTIME);
void printClockMode2(SET_POSITION, DAYTIME);

// shape.c
void glClockCircle(SET_POSITION);
void glClockHands(SET_POSITION, DAYTIME);
void glClockPoints(SET_POSITION);

void glClockSmallCircle(SET_POSITION);
void glClockSmallHands(SET_POSITION, DAYTIME);
void glClockSmallPoints(SET_POSITION);

void secHandDrawing(int, int, int, DAYTIME);
void minHandDrawing(int, int, int, DAYTIME);
void hourHandDrawing(int, int, int, DAYTIME);
void secPointDrawing(int, int, int, DAYTIME);
void minPointDrawing(int, int, int, DAYTIME);
void hourPointDrawing(int, int, int, DAYTIME);
void centerPointDrawing(int, int, int);

// setting.c
SET_POSITION locate();
DAYTIME nowtime();

void themeInit();
void themeChange();

void operatingStatusInit();
void operatingStatusChange(int);

double x_sec(int, int, int);
double y_sec(int, int, int);
double x_min(int, int, int, int);
double y_min(int, int, int, int);
double x_hour(int, int, int, int, int);
double y_hour(int, int, int, int, int);