#include "clocktime.h"

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500,  400);
    glutCreateWindow("clock");

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(RENEWALTIME, Timer, 0);
    
    themeInit();
    
    glutMainLoop();

    return 0;
}