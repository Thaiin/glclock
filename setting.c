#include "include.h"

SET_POSITION locate(){
    SET_POSITION sp;

    sp.w = glutGet(GLUT_WINDOW_WIDTH);
    sp.h = glutGet(GLUT_WINDOW_HEIGHT);

    sp.cenw = sp.w / 2;
    sp.cenh = sp.h / 2;
    
    if(sp.w <= sp.h){
        sp.cir = sp.w / 5 * 2;
        sp.cirdots = sp.w / 3;
        sp.sec_hand = sp.w / 3;
	    sp.min_hand = sp.w / 4;
    	sp.hour_hand = sp.w / 5;
    } else {
        sp.cir = sp.h / 5 * 2;
        sp.cirdots = sp.h / 3;
        sp.sec_hand = sp.h / 3;
        sp.min_hand = sp.h / 4;
        sp.hour_hand = sp.h / 5;
    }

    sp.smallcir = sp.cir / 5;
    sp.sec_minicenw = (sp.cenw + (sp.cenw + (sp.cirdots * 5 / 6) * sin((2 * M_PI * 130) / SQ))) / 2;
    sp.sec_minicenh = (sp.cenh + (sp.cenh + (sp.cirdots * 5 / 6) * cos((2 * M_PI * 130) / SQ))) / 2;

    return sp;
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


void themeInit(){
    glClearColor(0.9, 0.9, 0.9, 0);

    circle.colormode = THEME1;
    circle.r = WHITERGB;
    circle.g = WHITERGB;
    circle.b = WHITERGB;
    hand.colormode = THEME1;
    hand.r = BLACKRGB;
    hand.g = BLACKRGB;
    hand.b = BLACKRGB;
    minihand.colormode = THEME1;
    minihand.r = SEC_MINIHAND1_R;
    minihand.g = SEC_MINIHAND1_G;
    minihand.b = SEC_MINIHAND1_B;
}

void themeChange(){
    if (circle.colormode != THEME1){
        // printf("circle: white, hand & points: black\n");
        glClearColor(0.9, 0.9, 0.9, 0);

        circle.colormode = THEME1;
        circle.r = WHITERGB;
        circle.g = WHITERGB;
        circle.b = WHITERGB;
        hand.colormode = THEME1;
        hand.r = BLACKRGB;
        hand.g = BLACKRGB;
        hand.b = BLACKRGB;
        minihand.colormode = THEME1;
        minihand.r = SEC_MINIHAND1_R;
        minihand.g = SEC_MINIHAND1_G;
        minihand.b = SEC_MINIHAND1_B;
    }
    else {
        // printf("circle: black, hand & points: white\n");
        glClearColor(0.1, 0.1, 0.1, 0);

        circle.colormode = THEME2;
        circle.r = BLACKRGB;
        circle.g = BLACKRGB;
        circle.b = BLACKRGB;
        hand.colormode = THEME2;
        hand.r = WHITERGB;
        hand.g = WHITERGB;
        hand.b = WHITERGB;
        minihand.colormode = THEME2;
        minihand.r = SEC_MINIHAND2_R;
        minihand.g = SEC_MINIHAND2_G;
        minihand.b = SEC_MINIHAND2_B;
    }
}

void operatingStatusInit(){
    OPERATING_STATUS = MODE1;
}

void operatingStatusChange(int num){
    if(num == 2){
        OPERATING_STATUS = MODE2;
    } else {
        OPERATING_STATUS = MODE1;
    }
}


double x_sec(int w, int hand, int sec){
    return (w + hand * sin((2 * M_PI * sec / 60)));
}

double y_sec(int h, int hand, int sec){
    return h - hand * cos((2 * M_PI * sec) / 60);
}

double x_min(int w, int hand, int sec, int min){
    return w + hand * sin((2 * M_PI * (60 * min + sec)) / 3600);
}

double y_min(int h, int hand, int sec, int min){
    return h - hand * cos((2 * M_PI * (60 * min + sec)) / 3600);
}

double x_hour(int w, int hand, int sec, int min, int hour){
    return w + hand * sin((2 * M_PI * (3600 * hour + 60 * min + sec)) / 43200);
}

double y_hour(int h, int hand, int sec, int min, int hour){
    return h - hand * cos((2 * M_PI * (3600 * hour + 60 * min + sec)) / 43200);
}