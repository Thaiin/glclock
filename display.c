#include "wintime.h"

void Display(void){
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    clocktime();

    glClear(GL_COLOR_BUFFER_BIT);
    glClockCircle(w, h);
    glClockHands(w, h);
    glFlush();
    // glutSwapBuffers();
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