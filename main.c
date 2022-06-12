#include "prototype.h"

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500,  400);
    createWindowName();

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(RENEWALTIME, Timer, 0);

    DAYTIME nt = nowtime();
    theme_Init(nt.ts->tm_hour);
    operatingStatus_Init();
    processingBar_Init();
    timeDisplayChanged_Init();

    glutMainLoop();

    return 0;
}