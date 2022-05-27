#include "clocktime.h"

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
	    sp.longmin_hand = sp.w / 4;
    	sp.shorthour_hand = sp.w / 5;
    } else {
        sp.cir = sp.h / 5 * 2;
        sp.cirdots = sp.h / 3;
        sp.sec_hand = sp.h / 3;
        sp.longmin_hand = sp.h / 4;
        sp.shorthour_hand = sp.h / 5;
    }
    return sp;
}

DAYTIME nowtime(){
	DAYTIME wd;
	
	time(&wd.tt);
	wd.ts = localtime(&wd.tt);
	wd.weekdaynum = wd.ts->tm_wday;

	if (wd.ts->tm_hour > 11){
		wd.notation12hour = wd.ts->tm_hour - 12;
	} else {
		wd.notation12hour = wd.ts->tm_hour;
	}
	return wd;
}