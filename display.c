#include "include.h"

void reshapewin(int w, int h){
    int wws = WINDOW_WIDTHSIZE - 10;
    int whs = WINDOW_HEIGHTSIZE - 10;

    if(w <= wws && h <= whs){
        glutReshapeWindow(WINDOW_WIDTHSIZE, WINDOW_HEIGHTSIZE);
    } else if(w < wws){
        glutReshapeWindow(WINDOW_WIDTHSIZE, h);
    } else if(h < whs){
        glutReshapeWindow(w, WINDOW_HEIGHTSIZE);
    }
}

void printText(int w, int h, char *s){
    glRasterPos2i(w, h);

    for(int i = 0; i < strlen(s); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }
}

void inputTimeNumber(DAYTIME wd){
    char s[20];

    sprintf(s, "%2d:%02d:%02d %s", wd.notation12hour, wd.ts->tm_min, wd.ts->tm_sec, wd.ampm);

    glColor3ub(hand.r, hand.g, hand.b);
    printText(20, 40, s);
}

void printClockMode1(SET_POSITION sp, DAYTIME wd){
    glClockCircle(sp);
    glClockPoints(sp);
    glClockHands(sp, wd);
}

void printClockMode2(SET_POSITION sp, DAYTIME wd){
    glClockCircle(sp);
    glClockPoints(sp);
    glClockSmallCircle(sp);
    glClockSmallPoints(sp);
    glClockSmallHands(sp, wd);
}