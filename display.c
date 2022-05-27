#include "clocktime.h"
#include "prototype.h"

void themeInit(){
    glClearColor(0.9, 0.9, 0.9, 0);

    circle.colormode = WHITETHEME;
    circle.r = 255;
    circle.g = 255;
    circle.b = 255;
    hand.colormode = WHITETHEME;
    hand.r = 20;
    hand.g = 20;
    hand.b = 20;
}

void themeChange(){
    if(circle.colormode != BLACKTHEME){
        // printf("circle: black, hand & points: white\n");
        glClearColor(0.1, 0.1, 0.1, 0);

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
        glClearColor(0.9, 0.9, 0.9, 0);

        circle.colormode = WHITETHEME;
        circle.r = 255;
        circle.g = 255;
        circle.b = 255;
        hand.colormode = WHITETHEME;
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

// void inputNumber(){
//     glColor3ub(hand.r, hand.g, hand.b);
//     glRasterPos2i(100, 100);
//     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
//     glColor3ub(hand.r, hand.g, hand.b);
//     glRasterPos2i(108, 100);
//     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
// }