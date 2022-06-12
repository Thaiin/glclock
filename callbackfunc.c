#include "prototype.h"

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    DAYTIME wd = nowtime();
    SET_WH wh = displayScreenSize();
    SET_POSITION sp = locate(wh);
    MINI_CIRCLECENTER mc;

    inputTimeNumber(wd, PRINTTIME_W, PRINTTIME_H, TIME_DISPLAY_CHANGED);
    
    if(PROCESSING_BAR == ABLE){
        timeTextLine(wd, PRINTTIME_W, PRINTTIME_H);
    }

    if (OPERATING_STATUS == MODE2){
        mc = miniCenter(wh, sp);
        printClockMode2(wh, sp, mc, wd);
    }else if(OPERATING_STATUS == MODE3){
        mc = miniCenter(wh, sp);
        printClockMode3(wh, sp, mc, wd);
    } else {
        printClockMode1(wh, sp, wd);
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
        exit(0);
    }
    else if(key == 't'){
        theme_Change();
    }
    else if(key == 'T'){
        timeDisplayChanged_Change();
    }
    else if(key == '1'){
        operatingStatus_Change(MODE1);
    }
    else if(key == '2'){
        operatingStatus_Change(MODE2);
    }
    else if(key == '3'){
        operatingStatus_Change(MODE3);
    }
    else if(key == 'p'){
        processingBar_Change();
    }
}