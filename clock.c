#include "wintime.h"

void Timer(int value){
	glutPostRedisplay();	//どこに入れてあげればいいんだろう...
	clocktime();
	glutTimerFunc(500, Timer, 0);
}

void weekdayreturn(WEEKDAY *wd){
	switch(wd->weekdaynum){
		case 0:
			strcpy(wd->weekday, "Sun");
			break;
		case 1:
			strcpy(wd->weekday, "Mon");
			break;
		case 2:
			strcpy(wd->weekday, "Tue");
			break;
		case 3:
			strcpy(wd->weekday, "Wed");
			break;
		case 4:
			strcpy(wd->weekday, "Thu");
			break;
		case 5:
			strcpy(wd->weekday, "Fri");
			break;
		case 6:
			strcpy(wd->weekday, "Sat");
			break;
		default:
			strcpy(wd->weekday, "ERR");
	}
}

void clocktime(){
	tt = time(NULL);	// time(&tt);
	ts = localtime(&tt);

	wd.weekdaynum = ts->tm_wday;
	weekdayreturn(&wd);
	
	if(ts->tm_hour > 11){
		wd.hour12 = ts->tm_hour - 12;
		printf("%d:%02d:%02d(PM)\n", wd.hour12, ts->tm_min, ts->tm_sec);
	} else {
		wd.hour12 = ts->tm_hour;
		printf("%d:%02d:%02d(AM)\n", wd.hour12, ts->tm_min, ts->tm_sec);
	}
}

void glClockHands(int w, int h){
	int cenw = w / 2;
	int cenh = h / 2;
	int sec_hand = (cenw + cenh) / 3;
	int longmin_hand = (cenw + cenh) / 4;
	int shorthour_hand = (cenw + cenh) / 5;

	glBegin(GL_LINES);      //sec(blue)
    glColor3ub(0, 0, 255);
    glVertex2i(cenw + sec_hand * sin((2 * M_PI * ts->tm_sec) / 60), cenh - sec_hand * cos((2 * M_PI * ts->tm_sec) / 60));
    glVertex2i(cenw, cenh);

	glEnd();

    glBegin(GL_LINES);      //min(red)
    glColor3ub(255, 0, 0);
    glVertex2i(cenw + longmin_hand * sin((2 * M_PI * (60 * ts->tm_min + ts->tm_sec)) / 3600), cenh - longmin_hand * cos((2 * M_PI * (60 * ts->tm_min + ts->tm_sec)) / 3600));
    glVertex2i(cenw, cenh);

	glEnd();

    glBegin(GL_LINES);      //hour(green)
    glColor3ub(0, 255, 0);
    glVertex2i(cenw + shorthour_hand * sin((2 * M_PI * (3600 * wd.hour12 + 60 * ts->tm_min + ts->tm_sec)) / 43200), cenh - shorthour_hand * cos((2 * M_PI * (3600 * wd.hour12 + 60 * ts->tm_min + ts->tm_sec)) / 43200));
    glVertex2i(cenw, cenh);

    glEnd();
}