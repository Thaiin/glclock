#include "wintime.h"

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500,  400);
    glutCreateWindow("clock");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(RENEWALTIME, Timer, 0);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glClearColor(1, 1, 1, 1);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

    glutMainLoop();

    return 0;
}