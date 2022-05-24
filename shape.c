#include "wintime.h"

void glClockCircle(int w, int h){
	int cenw = w / 2;
	int cenh = h / 2;
    int cir, cirdots;

    if(w <= h){
        cir = w / 5 * 2;
        cirdots = w / 3;
    } else {
        cir = h / 5 * 2;
        cirdots = h / 3;
    }

    glBegin(GL_POLYGON);
    glColor3ub(50, 50, 50);
    for(int i = 0; i < SQ; i++){
        glVertex2i(cenw + cir * sin((2 * M_PI * i) / SQ), cenh - cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    for(int i = 0; i < SQ; i++){
        glVertex2i(cenw + cir * sin((2 * M_PI * i) / SQ), cenh - cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();

    for(int j = 0; j < 60; j++){
        glPointSize(1.5);
        glBegin(GL_POINTS);      //時計を60分割
        glColor3ub(255, 255, 255);
        glVertex2i(cenw + cirdots * sin((2 * M_PI * j) / 60), cenh - cirdots * cos((2 * M_PI * j) /60));
    }
    glEnd();

    for(int j = 0; j < 12; j++){
        glPointSize(3.0);
        glBegin(GL_POINTS);      //時計を12分割
        glColor3ub(255, 255, 255);
        glVertex2i(cenw + cirdots * sin((2 * M_PI * j) / 12), cenh - cirdots * cos((2 * M_PI * j) / 12));
    }
    glEnd();
}

void glClockHands(int w, int h){
	int cenw = w / 2;
	int cenh = h / 2;
    int sec_hand, longmin_hand, shorthour_hand;

    if(w <= h){
        sec_hand = w / 3;
	    longmin_hand = w / 4;
    	shorthour_hand = w / 5;
    } else {
        sec_hand = h / 3;
	    longmin_hand = h / 4;
    	shorthour_hand = h / 5;
    }

	glBegin(GL_LINES);      //sec
    glColor3ub(255, 255, 255);
    // glColor3ub(0, 0, 0);
    glVertex2i(cenw + sec_hand * sin((2 * M_PI * ts->tm_sec) / 60), cenh - sec_hand * cos((2 * M_PI * ts->tm_sec) / 60));
    glVertex2i(cenw, cenh);
    glEnd();

    glBegin(GL_LINES);      //min
    glColor3ub(255, 255, 255);
    // glColor3ub(0, 0, 0);
    glVertex2i(cenw + longmin_hand * sin((2 * M_PI * (60 * ts->tm_min + ts->tm_sec)) / 3600), cenh - longmin_hand * cos((2 * M_PI * (60 * ts->tm_min + ts->tm_sec)) / 3600));
    glVertex2i(cenw, cenh);
    glEnd();

    glBegin(GL_LINES);      //hour
    glColor3ub(255, 255, 255);
    // glColor3ub(0, 0, 0);
    glVertex2i(cenw + shorthour_hand * sin((2 * M_PI * (3600 * wd.hour12 + 60 * ts->tm_min + ts->tm_sec)) / 43200), cenh - shorthour_hand * cos((2 * M_PI * (3600 * wd.hour12 + 60 * ts->tm_min + ts->tm_sec)) / 43200));
    glVertex2i(cenw, cenh);
    glEnd();
}