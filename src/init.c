#include "include/init.h"

int player_x = 3;
int player_z = 0;

void glut_init(int *argc, char **argv){
    /*GLUT init*/
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    /*creating window*/
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Endless Flight");
    glutSetIconTitle("Endless Flight");

    glClearColor(0.9, 0.9, 0.9, 1);
	glEnable(GL_DEPTH_TEST);
}

void callbacks_init(){
    glutDisplayFunc(&on_display);
    glutReshapeFunc(&on_reshape);
    glutKeyboardFunc(&on_keyboard);
}
