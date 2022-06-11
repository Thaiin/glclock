#include "prototype.h"

void inputTimeNumber(DAYTIME wd, int w, int h, int day){
    char s[20];

    if(day == HALFDAY){
        sprintf(s, "%2d:%02d:%02d %s", wd.notation12hour, wd.ts->tm_min, wd.ts->tm_sec, wd.ampm);
    } else {
        sprintf(s, "%2d:%02d:%02d", wd.ts->tm_hour, wd.ts->tm_min, wd.ts->tm_sec);
        w += 20;
    }

    glColor3ub(hand.r, hand.g, hand.b);
    printText(w, h, s);
}

void timeTextLine(DAYTIME wd, int w, int h){
    double nowtimesec = 3600 * wd.ts->tm_hour + 60 * wd.ts->tm_min + wd.ts->tm_sec;
    int hpos = h + 12;
    int wpos = w - 4;
    
    int endpoint = 12;
    int linelen = 110;

    int wcen = (wpos + linelen + w) / 2;

    // 白枠
    linesDrawing(wpos, hpos - 4, w + linelen, hpos - 4, 5, 0);
    linesDrawing(wpos, hpos + 4, w + linelen, hpos + 4, 5, 0);
    pointDrawing(wpos, hpos, endpoint, 0);
    pointDrawing(linelen + w, hpos, endpoint, 0);

    // 上から黒で塗りつぶす
    linesDrawing(wpos, hpos, w + linelen, hpos, 7, 2);
    pointDrawing(wpos, hpos, endpoint - 4, 2);
    pointDrawing(linelen + w, hpos, endpoint - 4, 2);

    // 枠内のdot
    pointDrawing(wpos, hpos, endpoint - 6, 1);
    pointDrawing(linelen + w, hpos, endpoint - 6, 1);
    pointDrawing(wcen, hpos, endpoint - 7, 1);

    // 枠内の線
    linesDrawing(wpos, hpos, linelen * nowtimesec / 86400 + w, hpos, 2, 1);
    pointDrawing(linelen * nowtimesec / 86400 + wpos, hpos, 2, 1);
}