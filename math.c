#include "prototype.h"

double centerToArc_x(int w, int x, int y, int z){   // Center to arc_x
    return (w + x * sin(2 * M_PI * y / z));
}

double centerToArc_y(int w, int x, int y, int z){   // Center to arc_y
    return (w - x * cos(2 * M_PI * y / z));
}


double miniCirCenW(int cenw, double cc, int arcpos){
    return ((cenw + centerToArc_x(cenw, cc, arcpos, SQ)) / 2);
}

double miniCirCenH(int cenh, double cc, int arcpos){
    return ((cenh + centerToArc_y(cenh, cc, arcpos, SQ)) / 2);
}


double x_sec(int w, int hand, int sec){
    return centerToArc_x(w, hand, sec, 60);
}

double y_sec(int h, int hand, int sec){
    return centerToArc_y(h, hand, sec, 60);
}

double x_min(int w, int hand, int sec, int min){
    return centerToArc_x(w, hand, (60 * min + sec), 3600);
}

double y_min(int h, int hand, int sec, int min){
    return centerToArc_y(h, hand, (60 * min + sec), 3600);
}

double x_hour(int w, int hand, int sec, int min, int hour){
    return centerToArc_x(w, hand, (3600 * hour + 60 * min + sec), 43200);
}

double y_hour(int h, int hand, int sec, int min, int hour){
    return centerToArc_y(h, hand, (3600 * hour + 60 * min + sec), 43200);
}

double x_day(int w, int hand, int sec, int min, int hour){
    return centerToArc_x(w, hand, (3600 * hour + 60 * min + sec), 86400);
}

double y_day(int h, int hand, int sec, int min, int hour){
    return centerToArc_y(h, hand, (3600 * hour + 60 * min + sec), 86400);
}