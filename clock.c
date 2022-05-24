#include "wintime.h"

void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(500, Timer, 0);
}

// void weekdayreturn(DAYTIME *wd){
// 	switch(wd->weekdaynum){
// 		case 0:
// 			strcpy(wd->weekday, "Sun");
// 			break;
// 		case 1:
// 			strcpy(wd->weekday, "Mon");
// 			break;
// 		case 2:
// 			strcpy(wd->weekday, "Tue");
// 			break;
// 		case 3:
// 			strcpy(wd->weekday, "Wed");
// 			break;
// 		case 4:
// 			strcpy(wd->weekday, "Thu");
// 			break;
// 		case 5:
// 			strcpy(wd->weekday, "Fri");
// 			break;
// 		case 6:
// 			strcpy(wd->weekday, "Sat");
// 			break;
// 		default:
// 			strcpy(wd->weekday, "ERR");
// 	}
// }

void clocktime(){
	tt = time(NULL);	// time(&tt);
	ts = localtime(&tt);

	// wd.weekdaynum = ts->tm_wday;
	// weekdayreturn(&wd);
	
	if(ts->tm_hour > 11){
		wd.hour12 = ts->tm_hour - 12;
	} else {
		wd.hour12 = ts->tm_hour;
	}
	// printf("%d:%02d:%02d\n", wd.hour12, ts->tm_min, ts->tm_sec);
}