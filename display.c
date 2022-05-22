#include "wintime.h"

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    clocktime();
    glClockHands(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    glFlush();
}

void Reshape(int w, int h){
    printf("window: width*height = %d x %d\n", w, h);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScaled(1, -1, 1);
    glTranslated(0, -h, 0);
}