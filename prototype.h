#include "define.h"
#include "struct.h"

// 色を決める構造体の宣言
DISPLAYSETTING circle;
DISPLAYSETTING hand;
DISPLAYSETTING sechand;
DISPLAYSETTING cal;

// 表示を変更するための引数
int OPERATING_STATUS;
int PROCESSING_BAR;
int TIME_DISPLAY_CHANGED;

// callbackfunc.c
void Display(void);
void Reshape(int, int);
void Timer(int);
void Keyboard(unsigned char, int, int);

// printtime.c
void printText(int, int, char*);
void inputTimeNumber(DAYTIME, int, int, int);
void timeTextLine(DAYTIME, int, int);

// generic_func.c
void linesDrawing(double, double, double, double, int, int);
void pointDrawing(double, double, int, int);
void lineLoopDrawing(double, double, double, int, int, int);
void polygonDrawing(double, double, double, int, int);

// printclock.c
void printClockMode1(SET_WH, SET_POSITION, DAYTIME);
void printClockMode2(SET_WH, SET_POSITION, MINI_CIRCLECENTER, DAYTIME);
void printClockMode3(SET_WH, SET_POSITION, MINI_CIRCLECENTER, DAYTIME);

void glClockCircle(SET_WH, SET_POSITION);
void glClockHands(SET_WH, SET_POSITION, DAYTIME);
void glClockPoints(SET_WH, SET_POSITION);

void glClockSmallCircle(double, double, int);
void glClockSmallPoints(double, double, int, int);
void glClockHands_MiniHands(SET_WH, SET_POSITION, MINI_CIRCLECENTER, DAYTIME);

void reverseHandDrawing(int, int, int, DAYTIME);
void secHandDrawing(int, int, int, DAYTIME);
void minHandDrawing(int, int, int, DAYTIME);
void hourHandDrawing(int, int, int, DAYTIME);
void dayHandDrawing(int, int, int, DAYTIME);

// setting.c
DAYTIME nowtime();
SET_WH displayScreenSize();
SET_POSITION locate();
MINI_CIRCLECENTER miniCenter(SET_WH, SET_POSITION);

void operatingStatus_Init();
void operatingStatus_Change(int);
void processingBar_Init();
void processingBar_Change();
void timeDisplayChanged_Init();
void timeDisplayChanged_Change();
void theme_Init(int);
void theme_Change();

void darkTheme();
void whiteTheme();
void colorStatus(int);
void createWindowName();
void reshapewin(int, int);

// mathmat.c
double centerToArc_x(int, int, int, int);
double centerToArc_y(int, int, int, int);

double miniCirCenW(int, double, int);
double miniCirCenH(int, double, int);
double x_sec(int, int, int);
double y_sec(int, int, int);
double x_min(int, int, int, int);
double y_min(int, int, int, int);
double x_hour(int, int, int, int, int);
double y_hour(int, int, int, int, int);
double x_day(int, int, int, int, int);
double y_day(int, int, int, int, int);