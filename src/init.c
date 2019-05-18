#include "include/init.h"

int err_indicator = 0;

int player_x = 3;
int player_z = 0;

int animation_active = 0;
float animation_parameter = 0;

void glut_init(int *argc, char **argv){
    // GLUT init 
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // Creating window 
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Endless Flight");
    glutSetIconTitle("Endless Flight");

    // Start game in full screen mode 
    // glutFullScreen();

    glClearColor(0.9, 0.9, 0.9, 1);
	glEnable(GL_DEPTH_TEST);
}

void callbacks_init(){
    glutDisplayFunc(&on_display);
    glutReshapeFunc(&on_reshape);
    glutKeyboardFunc(&on_keyboard);
}


