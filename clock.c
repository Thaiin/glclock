#include "clocktime.h"

void nowtime(){
	tt = time(NULL);	// time(&tt);
	ts = localtime(&tt);
	wd.weekdaynum = ts->tm_wday;
	
	if(ts->tm_hour > 11){
		wd.hour12 = ts->tm_hour - 12;
	} else {
		wd.hour12 = ts->tm_hour;
	}
}