#include "wintime.h"

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500,  400);
    glutCreateWindow("clock");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(500, Timer, 0);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}