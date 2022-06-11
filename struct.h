#include "includefile.h"

typedef struct daytime{
	time_t tt;
	struct tm *ts;
	int notation12hour;
	char *ampm;
} DAYTIME;

typedef struct displaysetting{
	int r;
	int g;
	int b;
	int colormode;
} DISPLAYSETTING;

typedef struct set_wh{
	int w;
	int h;
	int cenw;
	int cenh;
	int mssize;	// minscreensize
} SET_WH;

typedef struct set_position{
	int cir;
	int cirdots;
	int smallcir;
	int smallcirdots;
	int sec_hand;
	int min_hand;
	int hour_hand;
} SET_POSITION;

typedef struct minicen{
	double sec_minicenw;
	double sec_minicenh;
	double day_minicenw;
	double day_minicenh;
}MINI_CIRCLECENTER;