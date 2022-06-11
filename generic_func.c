#include "prototype.h"

void linesDrawing(double w1, double h1, double w2, double h2, int size, int color){
    glLineWidth(size);
    glBegin(GL_LINES);
    colorStatus(color);
    glVertex2i(w1, h1);
    glVertex2i(w2, h2);
    glEnd();
}

void pointDrawing(double w, double h, int size, int color){
    glPointSize(size);
    glBegin(GL_POINTS);
    colorStatus(color);
    glVertex2i(w, h);
    glEnd();
}

void lineLoopDrawing(double w, double h, double len, int size, int num, int color){
    glLineWidth(size);
    glBegin(GL_LINE_LOOP);
    colorStatus(color);
    for(int i = 0; i < num; i++){
        glVertex2i(centerToArc_x(w, len, i, num), centerToArc_y(h, len, i, num));
    }
    glEnd();
}

void polygonDrawing(double w, double h, double len, int num, int color){
    glBegin(GL_POLYGON);
    colorStatus(color);
    for(int i = 0; i < num; i++){
        glVertex2i(centerToArc_x(w, len, i, num), centerToArc_y(h, len, i, num));
    }
    glEnd();
}

void printText(int w, int h, char *s){
    glRasterPos2i(w, h);

    for(int i = 0; i < strlen(s); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }
}