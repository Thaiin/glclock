#include "clocktime.h"

void glClockCircle(int w, int h){
	int cenw = w / 2;
	int cenh = h / 2;
    int cir;

    if(w <= h){
        cir = w / 5 * 2;
    } else {
        cir = h / 5 * 2;
    }

    glBegin(GL_POLYGON);    //時計の内側の色
    glColor3ub(circle.r, circle.g, circle.b);
    for(int i = 0; i < SQ; i++){
        glVertex2i(cenw + cir * sin((2 * M_PI * i) / SQ), cenh - cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();

    glBegin(GL_LINE_LOOP);  //時計の外側の線
    glColor3ub(circle.r, circle.g, circle.b);
    for(int i = 0; i < SQ; i++){
        glVertex2i(cenw + cir * sin((2 * M_PI * i) / SQ), cenh - cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();
}

void glClockPoints(int w, int h){
	int cenw = w / 2;
	int cenh = h / 2;
    int cirdots;

    if(w <= h){
        cirdots = w / 3;
    } else {
        cirdots = h / 3;
    }

    for(int i = 0; i < 60; i++){
        glPointSize(2.0);
        glBegin(GL_POINTS);      //時計を60分割
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(cenw + cirdots * sin((2 * M_PI * i) / 60), cenh - cirdots * cos((2 * M_PI * i) / 60));
    }
    glEnd();

    for(int i = 0; i < 12; i++){
        glPointSize(6.0);
        glBegin(GL_POINTS);      //時計を12分割
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(cenw + cirdots * sin((2 * M_PI * i) / 12), cenh - cirdots * cos((2 * M_PI * i) / 12));
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

    glLineWidth(2);
	glBegin(GL_LINES);      //sec
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(cenw + sec_hand * sin((2 * M_PI * ts->tm_sec) / 60), cenh - sec_hand * cos((2 * M_PI * ts->tm_sec) / 60));
    glVertex2i(cenw, cenh);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);      //min
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(cenw + longmin_hand * sin((2 * M_PI * (60 * ts->tm_min + ts->tm_sec)) / 3600), cenh - longmin_hand * cos((2 * M_PI * (60 * ts->tm_min + ts->tm_sec)) / 3600));
    glVertex2i(cenw, cenh);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);      //hour
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(cenw + shorthour_hand * sin((2 * M_PI * (3600 * wd.hour12 + 60 * ts->tm_min + ts->tm_sec)) / 43200), cenh - shorthour_hand * cos((2 * M_PI * (3600 * wd.hour12 + 60 * ts->tm_min + ts->tm_sec)) / 43200));
    glVertex2i(cenw, cenh);
    glEnd();

    glLineWidth(1);
}
