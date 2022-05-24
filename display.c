#include "wintime.h"

void Display(void){
    int r, g, b;
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    clocktime();
    glClear(GL_COLOR_BUFFER_BIT);
    glClockCircle(w, h, r, g, b);
    glClockHands(w, h, r, g, b);
    glClockHandsLines(w, h, r, g, b);
    glFlush();
    glutSwapBuffers();
}

void Reshape(int w, int h){
    printf("window: width*height = %d x %d\n", w, h);
    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScaled(1, -1, 1);
    glTranslated(0, -h, 0);

    if(w <= 490 && h <= 390){
        glutReshapeWindow(500, 400);
    } else if(w < 490){
        glutReshapeWindow(500, h);
    } else if(h < 390){
        glutReshapeWindow(w, 400);
    }
}

void Keyboard(unsigned char key, int x, int y){
    if((key == 'q') || key == 27){
        printf("終了\n");
        exit(0);
    } else if(key == 't'){
        printf("テーマ変更\n");
        themeChange();
    }
}