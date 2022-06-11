#include "prototype.h"

SET_WH displayScreenSize(){
    SET_WH wh;

    wh.w = glutGet(GLUT_WINDOW_WIDTH);
    wh.h = glutGet(GLUT_WINDOW_HEIGHT);
    wh.cenw = wh.w / 2;
    wh.cenh = wh.h / 2;

    if(wh.w <= wh.h){
        wh.mssize = wh.w;
    } else {
        wh.mssize = wh.h;
    }
    return wh;
}

SET_POSITION locate(SET_WH wh){
    SET_POSITION sp;

    sp.cir = wh.mssize / 5 * 2;
    sp.cirdots = wh.mssize / 3;
    sp.sec_hand = wh.mssize / 3;
    sp.min_hand = wh.mssize / 4;
    sp.hour_hand = wh.mssize / 5;

    if(OPERATING_STATUS == MODE3) {
        sp.smallcir = sp.cir / 3.5;
        sp.smallcirdots = sp.cir / 4.5;
    } else {
        sp.smallcir = sp.cir / 5;
        sp.smallcirdots = sp.cir / 6;
    }
    return sp;
}

MINI_CIRCLECENTER miniCenter(SET_WH wh, SET_POSITION sp){
    MINI_CIRCLECENTER mc;

    if (OPERATING_STATUS == MODE2){
        mc.sec_minicenw = miniCirCenW(wh.cenw, (sp.cirdots * 7 / 8), MINICIRCLE_POS_SEC);
        mc.sec_minicenh = miniCirCenH(wh.cenh, (sp.cirdots * 7 / 8), MINICIRCLE_POS_SEC);
        mc.day_minicenw = miniCirCenW(wh.cenw, (sp.cirdots * 7 / 8), MINICIRCLE_POS_DAY);
        mc.day_minicenh = miniCirCenH(wh.cenh, (sp.cirdots * 7 / 8), MINICIRCLE_POS_DAY);
    }
    else if(OPERATING_STATUS == MODE3) {
        mc.sec_minicenw = miniCirCenW(wh.cenw, (sp.cir * 7 / 3), MINICIRCLE_AROUNDPOS_SEC);
        mc.sec_minicenh = miniCirCenH(wh.cenh, (sp.cir * 7 / 3), MINICIRCLE_AROUNDPOS_SEC);
        mc.day_minicenw = miniCirCenW(wh.cenw, (sp.cir * 7 / 3), MINICIRCLE_AROUNDPOS_DAY);
        mc.day_minicenh = miniCirCenH(wh.cenh, (sp.cir * 7 / 3), MINICIRCLE_AROUNDPOS_DAY);
    }
    return mc;
}

DAYTIME nowtime(){
	DAYTIME wd;
	
	time(&wd.tt);
	wd.ts = localtime(&wd.tt);

	if (wd.ts->tm_hour > 11){
		wd.notation12hour = wd.ts->tm_hour - 12;
        wd.ampm = "PM";
	} else {
		wd.notation12hour = wd.ts->tm_hour;
        wd.ampm = "AM";
	}
	return wd;
}


void operatingStatus_Init(){
    OPERATING_STATUS = MODE1;
}

void operatingStatus_Change(int num){
    switch (num){
        case 1:
            OPERATING_STATUS = MODE1;
            break;
        
        case 2:
            OPERATING_STATUS = MODE2;
            break;

        case 3:
            OPERATING_STATUS = MODE3;
            break;
    }
}

void processingBar_Init(){
    PROCESSING_BAR = DISABLE;
}

void processingBar_Change(){
    if (PROCESSING_BAR != DISABLE){
        PROCESSING_BAR = DISABLE;
    }
    else {
        PROCESSING_BAR = ABLE;
    }
}

void timeDisplayChanged_Init(){
    TIME_DISPLAY_CHANGED = HALFDAY;
}

void timeDisplayChanged_Change(){
    if (TIME_DISPLAY_CHANGED != HALFDAY){
        TIME_DISPLAY_CHANGED = HALFDAY;
    }
    else {
        TIME_DISPLAY_CHANGED = ONEDAY;
    }
}

void theme_Init(int hour){
    if (hour < 6 || hour > 18){     //18 ~ 6時まで
        darkTheme();
	} else {
        whiteTheme();
	}
}

void theme_Change(){
    if (circle.colormode != THEME1){
        whiteTheme();
    }
    else {
        darkTheme();
    }
}


void darkTheme(){
    // printf("circle: black, hand & points: white\n");
    glClearColor(0, 0, 0.05, 0);

    circle.colormode = THEME2;
    circle.r = BLACKR;
    circle.g = BLACKG;
    circle.b = BLACKB;
    hand.colormode = THEME2;
    hand.r = WHITER;
    hand.g = WHITEG;
    hand.b = WHITEB;
    sechand.colormode = THEME2;
    sechand.r = SEC_MINIHAND2_R;
    sechand.g = SEC_MINIHAND2_G;
    sechand.b = SEC_MINIHAND2_B;
}

void whiteTheme(){
    // printf("circle: white, hand & points: black\n");
    glClearColor(0.8, 0.8, 0.82, 0);

    circle.colormode = THEME1;
    circle.r = WHITER;
    circle.g = WHITEG;
    circle.b = WHITEB;
    hand.colormode = THEME1;
    hand.r = BLACKR;
    hand.g = BLACKG;
    hand.b = BLACKB;
    sechand.colormode = THEME1;
    sechand.r = SEC_MINIHAND1_R;
    sechand.g = SEC_MINIHAND1_G;
    sechand.b = SEC_MINIHAND1_B;
}

void colorStatus(int color){    // 0, 1, 2
    switch (color){
        case 0:     // 0 ... hand
            glColor3ub(hand.r, hand.g, hand.b);
            break;
        case 1:     // 1 ... MODE2, 3 時のミニ円盤の針
            glColor3ub(sechand.r, sechand.g, sechand.b);
            break;
        case 2:     // 2 ... circle
            glColor3ub(circle.r, circle.g, circle.b);
            break;
    }
}

void createWindowName(){
    srand((unsigned int)time(NULL));
    int num = rand() % 3;

    if(num == 0){
        glutCreateWindow(WINDOW_NAME1);
    }
    else if (num == 1){
        glutCreateWindow(WINDOW_NAME2);
    }
    else if (num == 2){
        glutCreateWindow(WINDOW_NAME3);
    }
}

void reshapewin(int w, int h){
    int wws = WINDOW_WIDTHSIZE - 10;
    int whs = WINDOW_HEIGHTSIZE - 10;

    if(w <= wws && h <= whs){
        glutReshapeWindow(WINDOW_WIDTHSIZE, WINDOW_HEIGHTSIZE);
    } else if(w < wws){
        glutReshapeWindow(WINDOW_WIDTHSIZE, h);
    } else if(h < whs){
        glutReshapeWindow(w, WINDOW_HEIGHTSIZE);
    }
}