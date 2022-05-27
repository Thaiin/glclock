#include "prototype.h"

void themeInit(){
    glClearColor(0.9, 0.9, 0.9, 0);

    circle.colormode = WHITETHEME;
    circle.r = WHITERGB;
    circle.g = WHITERGB;
    circle.b = WHITERGB;
    hand.colormode = WHITETHEME;
    hand.r = BLACKRGB;
    hand.g = BLACKRGB;
    hand.b = BLACKRGB;
}

void themeChange(){
    if(circle.colormode != BLACKTHEME){
        // printf("circle: black, hand & points: white\n");
        glClearColor(0.1, 0.1, 0.1, 0);

        circle.colormode = BLACKTHEME;
        circle.r = BLACKRGB;
        circle.g = BLACKRGB;
        circle.b = BLACKRGB;
        hand.colormode = BLACKTHEME;
        hand.r = WHITERGB;
        hand.g = WHITERGB;
        hand.b = WHITERGB;
    } else {
        // printf("circle: white, hand & points: black\n");
        glClearColor(0.9, 0.9, 0.9, 0);

        circle.colormode = WHITETHEME;
        circle.r = WHITERGB;
        circle.g = WHITERGB;
        circle.b = WHITERGB;
        hand.colormode = WHITETHEME;
        hand.r = BLACKRGB;
        hand.g = BLACKRGB;
        hand.b = BLACKRGB;
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