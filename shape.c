#include "clocktime.h"
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
    glVertex2i(ps.cenw + ps.sec_hand * sin((2 * M_PI * wd.ts->tm_sec) / 60), ps.cenh - ps.sec_hand * cos((2 * M_PI * wd.ts->tm_sec) / 60));
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();

    glLineWidth(MINPOINT);
    glBegin(GL_LINES);      //min
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw + ps.longmin_hand * sin((2 * M_PI * (60 * wd.ts->tm_min + wd.ts->tm_sec)) / 3600), ps.cenh - ps.longmin_hand * cos((2 * M_PI * (60 * wd.ts->tm_min + wd.ts->tm_sec)) / 3600));
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();

    glLineWidth(HOURPOINT);
    glBegin(GL_LINES);      //hour
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw + ps.shorthour_hand * sin((2 * M_PI * (3600 * wd.notation12hour + 60 * wd.ts->tm_min + wd.ts->tm_sec)) / 43200), ps.cenh - ps.shorthour_hand * cos((2 * M_PI * (3600 * wd.notation12hour + 60 * wd.ts->tm_min + wd.ts->tm_sec)) / 43200));
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();


    glPointSize(SECPOINT);
    glBegin(GL_POINTS);      //secpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw + ps.sec_hand * sin((2 * M_PI * wd.ts->tm_sec) / 60), ps.cenh - ps.sec_hand * cos((2 * M_PI * wd.ts->tm_sec) / 60));
    glEnd();

    glPointSize(MINPOINT);
    glBegin(GL_POINTS);      //minpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw + ps.longmin_hand * sin((2 * M_PI * (60 * wd.ts->tm_min + wd.ts->tm_sec)) / 3600), ps.cenh - ps.longmin_hand * cos((2 * M_PI * (60 * wd.ts->tm_min + wd.ts->tm_sec)) / 3600));
    glEnd();

    glPointSize(HOURPOINT);
    glBegin(GL_POINTS);      //hourpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw + ps.shorthour_hand * sin((2 * M_PI * (3600 * wd.notation12hour + 60 * wd.ts->tm_min + wd.ts->tm_sec)) / 43200), ps.cenh - ps.shorthour_hand * cos((2 * M_PI * (3600 * wd.notation12hour + 60 * wd.ts->tm_min + wd.ts->tm_sec)) / 43200));
    glEnd();

    glPointSize(8);
    glBegin(GL_POINTS);      //centerpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(ps.cenw, ps.cenh);
    glEnd();
}