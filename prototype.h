#include "clocktime.h"


DISPLAYSETTING circle;
DISPLAYSETTING hand;

GLuint img1, img2, img3, img4;
pngInfo info1, info2, info3, info4;

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