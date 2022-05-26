#include "clocktime.h"

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    nowtime();

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    glClockCircle(w, h);
    glClockHands(w, h);
    glClockPoints(w, h);
    glFlush();
    glutSwapBuffers();
}

void Reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScaled(1, -1, 1);
    glTranslated(0, -h, 0);

    reshapewin(w, h);
}

void Timer(int value){
    glutPostRedisplay();
	glutTimerFunc(RENEWALTIME, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y){
    if((key == 'q') || key == 27){
        printf("stop\n");
        exit(0);
    } else if(key == 't'){
        printf("change theme\n");
        themeChange();
    }
}