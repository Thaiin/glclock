#include "include.h"

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    DAYTIME wd = nowtime();
    SET_POSITION sp = locate();

    inputTimeNumber(wd);

    if (OPERATING_STATUS == MODE2){
        printClockMode2(sp, wd);
    } else {
        printClockMode1(sp, wd);
    }
    
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
        // printf("stop\n");
        exit(0);
    }
    else if(key == 't'){
        themeChange();
    }
    else if(key == '1'){
        // printf("mode1\n");
        operatingStatusChange(MODE1);
    }
    else if(key == '2'){
        // printf("mode2\n");
        operatingStatusChange(MODE2);
    }
    else if(key == '3'){
        // printf("mode3\n");
        operatingStatusChange(MODE3);
    }
}