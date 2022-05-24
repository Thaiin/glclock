#include "wintime.h"

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(340,  340);
    glutCreateWindow("clock");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(500, Timer, 0);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}