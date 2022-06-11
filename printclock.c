#include "prototype.h"

void printClockMode1(SET_WH wh, SET_POSITION sp, DAYTIME wd){
    glClockCircle(wh, sp);
    glClockPoints(wh, sp);
    glClockHands(wh, sp, wd);
}

void printClockMode2(SET_WH wh, SET_POSITION sp, MINI_CIRCLECENTER mc, DAYTIME wd){   
    glClockCircle(wh, sp);
    glClockPoints(wh, sp);
    
    // sec
    glClockSmallCircle(mc.sec_minicenw, mc.sec_minicenh, sp.smallcir);
    glClockSmallPoints(mc.sec_minicenw, mc.sec_minicenh, sp.smallcirdots, 6);

    // day
    glClockSmallCircle(mc.day_minicenw, mc.day_minicenh, sp.smallcir);
    glClockSmallPoints(mc.day_minicenw, mc.day_minicenh, sp.smallcirdots, 4);

    glClockHands_MiniHands(wh, sp, mc, wd);
}

void printClockMode3(SET_WH wh, SET_POSITION sp, MINI_CIRCLECENTER mc, DAYTIME wd){   
    glClockCircle(wh, sp);
    glClockPoints(wh, sp);
    // sec
    glClockSmallCircle(mc.sec_minicenw, mc.sec_minicenh, sp.smallcir);
    glClockSmallPoints(mc.sec_minicenw, mc.sec_minicenh, sp.smallcirdots, 6);

    // day
    glClockSmallCircle(mc.day_minicenw, mc.day_minicenh, sp.smallcir);
    glClockSmallPoints(mc.day_minicenw, mc.day_minicenh, sp.smallcirdots, 4);

    glClockHands_MiniHands(wh, sp, mc, wd);
}


void glClockCircle(SET_WH wh, SET_POSITION sp){
    polygonDrawing(wh.cenw, wh.cenh, sp.cir, SQ, 2);
    lineLoopDrawing(wh.cenw, wh.cenh, sp.cir, 5, SQ, 0);
}

void glClockSmallCircle(double cenw, double cenh, int scir){
    polygonDrawing(cenw, cenh, scir, SSQ, 2);
    lineLoopDrawing(cenw, cenh, scir, 3, SSQ, 0);
}


void glClockPoints(SET_WH wh, SET_POSITION sp){
    int size;

    for(int i = 0; i < 60; i++){
        if(i % 5 == 0){         //時計の1時間の境目を見やすくするために12分し大きな点にする
            size = 6;
        } else {
            size = 2;
        }
        pointDrawing(centerToArc_x(wh.cenw, sp.cirdots, i, 60), centerToArc_y(wh.cenh, sp.cirdots, i, 60), size, 0);
    }
}

void glClockSmallPoints(double cenw, double cenh, int scdots, int dotsnum){
    for(int i = 0; i < dotsnum; i++){
        glPointSize(4);
        glBegin(GL_POINTS);
        glColor3ub(hand.r, hand.g, hand.b);
        glVertex2i(centerToArc_x(cenw, scdots, i, dotsnum), centerToArc_y(cenh, scdots, i, dotsnum));
    }
    glEnd();
}


void glClockHands(SET_WH wh, SET_POSITION sp, DAYTIME wd){  // MODE1
    minHandDrawing(wh.cenw, wh.cenh, sp.min_hand, wd);
    hourHandDrawing(wh.cenw, wh.cenh, sp.hour_hand, wd);
    secHandDrawing(wh.cenw, wh.cenh, sp.sec_hand, wd);
    reverseHandDrawing(wh.cenw, wh.cenh, sp.sec_hand, wd);

    pointDrawing(wh.cenw, wh.cenh, CENTERPOINT, 1);
    pointDrawing(wh.cenw, wh.cenh, CENTERPOINT / 2, 0);
}

void glClockHands_MiniHands(SET_WH wh, SET_POSITION sp, MINI_CIRCLECENTER mc, DAYTIME wd){    // MODE2 & 3
    secHandDrawing(mc.sec_minicenw, mc.sec_minicenh, sp.smallcirdots, wd);
    pointDrawing(mc.sec_minicenw, mc.sec_minicenh, MINI_CENTERPOINT, 1);

    dayHandDrawing(mc.day_minicenw, mc.day_minicenh, sp.smallcirdots, wd);
    pointDrawing(mc.day_minicenw, mc.day_minicenh, MINI_CENTERPOINT, 0);

    // minをsec_handの長さ, hourをmin_handの長さにする
    minHandDrawing(wh.cenw, wh.cenh, sp.sec_hand, wd);
    hourHandDrawing(wh.cenw, wh.cenh, sp.min_hand, wd);

    pointDrawing(wh.cenw, wh.cenh, CENTERPOINT, 0);
}

void secHandDrawing(int cenw, int cenh, int sec_hand, DAYTIME wd){
    int x = x_sec(cenw, sec_hand, wd.ts->tm_sec);
    int y = y_sec(cenh, sec_hand, wd.ts->tm_sec);

    linesDrawing(x, y, cenw, cenh, SECPOINT, 1);
    pointDrawing(x, y, SECPOINT, 1);
}

void minHandDrawing(int cenw, int cenh, int min_hand, DAYTIME wd){
    int x = x_min(cenw, min_hand, wd.ts->tm_sec, wd.ts->tm_min);
    int y = y_min(cenh, min_hand, wd.ts->tm_sec, wd.ts->tm_min);

    linesDrawing(x, y, cenw, cenh, MINPOINT, 0);
    pointDrawing(x, y, MINPOINT, 0);
}

void hourHandDrawing(int cenw, int cenh, int hour_hand, DAYTIME wd){
    int x = x_hour(cenw, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour);
    int y = y_hour(cenh, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.notation12hour);

    linesDrawing(x, y, cenw, cenh, HOURPOINT, 0);
    pointDrawing(x, y, HOURPOINT, 0);
}

void dayHandDrawing(int cenw, int cenh, int hour_hand, DAYTIME wd){
    int x = x_day(cenw, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.ts->tm_hour);
    int y = y_day(cenh, hour_hand, wd.ts->tm_sec, wd.ts->tm_min, wd.ts->tm_hour);

    linesDrawing(x, y, cenw, cenh, SECPOINT, 0);    //secの針の大きさに合わせる
    pointDrawing(x, y, SECPOINT, 0);               //hour..24
}

void reverseHandDrawing(int cenw, int cenh, int hand, DAYTIME wd){
    int smax = 60;
    int sc = wd.ts->tm_sec + smax / 2;

    // if(sc > 60){
    //     sc -= smax;
    // }
    int x = centerToArc_x(cenw, hand / 5, sc, smax);
    int y = centerToArc_y(cenh, hand / 5, sc, smax);

    linesDrawing(x, y, cenw, cenh, SECPOINT, 1);
    pointDrawing(x, y, SECPOINT, 1);
    
}