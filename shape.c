#include "include.h"

void glClockCircle(SET_POSITION sp){
    glBegin(GL_POLYGON);    //時計の内側の色
    glColor3ub(circle.r, circle.g, circle.b);
    for(int i = 0; i < SQ; i++){
        glVertex2i(sp.cenw + sp.cir * sin((2 * M_PI * i) / SQ), sp.cenh - sp.cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();

    glBegin(GL_LINE_LOOP);  //時計の外側の線
    glColor3ub(hand.r, hand.g, hand.b);
    for(int i = 0; i < SQ; i++){
        glVertex2i(sp.cenw + sp.cir * sin((2 * M_PI * i) / SQ), sp.cenh - sp.cir * cos((2 * M_PI * i) / SQ));
    }
    glEnd();
}

void glClockSmallCircle(SET_POSITION sp){
    int smallcir = 120;
    glLineWidth(SECPOINT);
    glBegin(GL_LINE_LOOP);  //時計の外側の線
    glColor3ub(hand.r, hand.g, hand.b);
    for(int i = 0; i < smallcir; i++){
        glVertex2i(sp.sec_minicenw + sp.smallcir * sin((2 * M_PI * i) / smallcir), sp.sec_minicenh - sp.smallcir * cos((2 * M_PI * i) / smallcir));
    }
    glEnd();
}


void glClockPoints(SET_POSITION sp){
    for(int i = 0; i < 60; i++){
        glPointSize(2.0);
        glBegin(GL_POINTS);      //時計を60分割
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(sp.cenw + sp.cirdots * sin((2 * M_PI * i) / 60), sp.cenh - sp.cirdots * cos((2 * M_PI * i) / 60));
    }
    glEnd();

    for(int i = 0; i < 12; i++){
        glPointSize(6.0);
        glBegin(GL_POINTS);      //時計を12分割
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(sp.cenw + sp.cirdots * sin((2 * M_PI * i) / 12), sp.cenh - sp.cirdots * cos((2 * M_PI * i) / 12));
    }
    glEnd();
}

void glClockSmallPoints(SET_POSITION sp){
    int smalldot = 5;

    for(int i = 0; i < 6; i++){
        glPointSize(3);
        glBegin(GL_POINTS);
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(sp.sec_minicenw + (sp.smallcir - smalldot) * sin((2 * M_PI * i) / 6), sp.sec_minicenh - (sp.smallcir - smalldot) * cos((2 * M_PI * i) / 6));
    }
    glEnd();
}


void glClockHands(SET_POSITION sp, DAYTIME wd){
    secHandDrawing(sp.cenw, sp.cenh, sp.sec_hand, wd);
    minHandDrawing(sp.cenw, sp.cenh, sp.min_hand, wd);
    hourHandDrawing(sp.cenw, sp.cenh, sp.hour_hand, wd);

    secPointDrawing(sp.cenw, sp.cenh, sp.sec_hand, wd);
    minPointDrawing(sp.cenw, sp.cenh, sp.min_hand, wd);
    hourPointDrawing(sp.cenw, sp.cenh, sp.hour_hand, wd);

    centerPointDrawing(sp.cenw, sp.cenh);
}

void glClockSmallHands(SET_POSITION sp, DAYTIME wd){
    secHandDrawing(sp.sec_minicenw, sp.sec_minicenh, sp.smallcir, wd);
    centerPointDrawing(sp.sec_minicenw, sp.sec_minicenh);

    minHandDrawing(sp.cenw, sp.cenh, sp.min_hand, wd);
    hourHandDrawing(sp.cenw, sp.cenh, sp.hour_hand, wd);

    minPointDrawing(sp.cenw, sp.cenh, sp.min_hand, wd);
    hourPointDrawing(sp.cenw, sp.cenh, sp.hour_hand, wd);

    centerPointDrawing(sp.cenw, sp.cenh);
}


void secHandDrawing(int cenw, int cenh, int sec_hand, DAYTIME wd){
    glLineWidth(SECPOINT);
	glBegin(GL_LINES);      //sec
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_sec(cenw, sec_hand, wd.ts->tm_sec), y_sec(cenh, sec_hand, wd.ts->tm_sec));
    glVertex2i(cenw, cenh);
    glEnd();
}

void minHandDrawing(int cenw, int cenh, int min_hand, DAYTIME wd){
    glLineWidth(MINPOINT);
    glBegin(GL_LINES);      //min
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_min(cenw, min_hand, wd.ts->tm_sec, wd.ts->tm_min), y_min(cenh, min_hand, wd.ts->tm_sec, wd.ts->tm_min));
    glVertex2i(cenw, cenh);
    glEnd();
}

void hourHandDrawing(int cenw, int cenh, int hour_hand, DAYTIME wd){
    glLineWidth(HOURPOINT);
    glBegin(GL_LINES);      //hour
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_hour(cenw, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour), y_hour(cenh, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour));
    glVertex2i(cenw, cenh);
    glEnd();
}

void secPointDrawing(int cenw, int cenh, int sec_hand, DAYTIME wd){
    glPointSize(SECPOINT);
    glBegin(GL_POINTS);      //secpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_sec(cenw, sec_hand, wd.ts->tm_sec), y_sec(cenh, sec_hand, wd.ts->tm_sec));
    glEnd();
}

void minPointDrawing(int cenw, int cenh, int min_hand, DAYTIME wd){
    glPointSize(MINPOINT);
    glBegin(GL_POINTS);      //minpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_min(cenw, min_hand, wd.ts->tm_sec, wd.ts->tm_min), y_min(cenh, min_hand, wd.ts->tm_sec, wd.ts->tm_min));
    glEnd();
}

void hourPointDrawing(int cenw, int cenh, int hour_hand, DAYTIME wd){
    glPointSize(HOURPOINT);
    glBegin(GL_POINTS);      //hourpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(x_hour(cenw, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour), y_hour(cenh, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour));
    glEnd();
}

void centerPointDrawing(int cenw, int cenh){
    glPointSize(CENTERPOINT);
    glBegin(GL_POINTS);      //centerpoint
    glColor3ub(hand.r, hand.g, hand.b);
    glVertex2i(cenw, cenh);
    glEnd();
}