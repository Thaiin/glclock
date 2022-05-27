#include "prototype.h"

void glClockCircle(SET_POSITION ps){
    glBegin(GL_POLYGON);    //時計の内側の色
    glColor3ub(circle.r, circle.g, circle.b);
    for(int i = 0; i < SQ; i++){
        glVertex2i(ps.cenw + ps.cir * sin((2 * M_PI * i) / SQ), ps.cenh - ps.cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();

    glBegin(GL_LINE_LOOP);  //時計の外側の線
    glColor3ub(hand.r, hand.g, hand.b);
    for(int i = 0; i < SQ; i++){
        glVertex2i(ps.cenw + ps.cir * sin((2 * M_PI * i) / SQ), ps.cenh - ps.cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();
}

void glClockPoints(SET_POSITION ps){
    for(int i = 0; i < 60; i++){
        glPointSize(2.0);
        glBegin(GL_POINTS);      //時計を60分割
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(ps.cenw + ps.cirdots * sin((2 * M_PI * i) / 60), ps.cenh - ps.cirdots * cos((2 * M_PI * i) / 60));
    }
    glEnd();

    for(int i = 0; i < 12; i++){
        glPointSize(6.0);
        glBegin(GL_POINTS);      //時計を12分割
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(ps.cenw + ps.cirdots * sin((2 * M_PI * i) / 12), ps.cenh - ps.cirdots * cos((2 * M_PI * i) / 12));
    }
    glEnd();

    glPointSize(6.0);
    glBegin(GL_POINTS);      //時計を12分割
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();
}

void glClockHands(SET_POSITION ps, DAYTIME wd){
    glLineWidth(SECPOINT);
	glBegin(GL_LINES);      //sec
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_sec(ps.cenw, ps.sec_hand, wd.ts->tm_sec), y_sec(ps.cenh, ps.sec_hand, wd.ts->tm_sec));
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();

    glLineWidth(MINPOINT);
    glBegin(GL_LINES);      //min
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_min(ps.cenw, ps.longmin_hand, wd.ts->tm_sec, wd.ts->tm_min), y_min(ps.cenh, ps.longmin_hand, wd.ts->tm_sec, wd.ts->tm_min));
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();

    glLineWidth(HOURPOINT);
    glBegin(GL_LINES);      //hour
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_hour(ps.cenw, ps.shorthour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour), y_hour(ps.cenh, ps.shorthour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour));
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();


    glPointSize(SECPOINT);
    glBegin(GL_POINTS);      //secpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_sec(ps.cenw, ps.sec_hand, wd.ts->tm_sec), y_sec(ps.cenh, ps.sec_hand, wd.ts->tm_sec));
    glEnd();

    glPointSize(MINPOINT);
    glBegin(GL_POINTS);      //minpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_min(ps.cenw, ps.longmin_hand, wd.ts->tm_sec, wd.ts->tm_min), y_min(ps.cenh, ps.longmin_hand, wd.ts->tm_sec, wd.ts->tm_min));
    glEnd();

    glPointSize(HOURPOINT);
    glBegin(GL_POINTS);      //hourpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_hour(ps.cenw, ps.shorthour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour), y_hour(ps.cenh, ps.shorthour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour));
    glEnd();

    glPointSize(8);
    glBegin(GL_POINTS);      //centerpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();
}