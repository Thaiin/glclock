#include "clocktime.h"

void themeInit(){
    circle.colormode = BLACKTHEME;
    circle.r = 0;
    circle.g = 0;
    circle.b = 0;
    hand.colormode = BLACKTHEME;
    hand.r = 255;
    hand.g = 255;
    hand.b = 255;
}

void themeChange(){
    if(circle.colormode != BLACKTHEME){
        // printf("circle: black, hand & points: white\n");
        glClearColor(1, 1, 1, 0);

        circle.colormode = BLACKTHEME;
        circle.r = 0;
        circle.g = 0;
        circle.b = 0;
        hand.colormode = BLACKTHEME;
        hand.r = 255;
        hand.g = 255;
        hand.b = 255;
    } else {
        // printf("circle: white, hand & points: black\n");
        glClearColor(0, 0, 0, 0);

        circle.colormode = DEFAULTTHEME;
        circle.r = 255;
        circle.g = 255;
        circle.b = 255;
        hand.colormode = DEFAULTTHEME;
        hand.r = 0;
        hand.g = 0;
        hand.b = 0;
    }
}

void reshapewin(int w, int h){
    if(w <= 490 && h <= 390){
        glutReshapeWindow(500, 400);
    } else if(w < 490){
        glutReshapeWindow(500, h);
    } else if(h < 390){
        glutReshapeWindow(w, 400);
    }
}