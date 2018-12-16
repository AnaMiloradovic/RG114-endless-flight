#include "include/init.h"

int err_indicator = 0;

int player_x = 3;
int player_z = 0;

int animation_active = 0;
float animation_parameter = 0;

float obstacles_x[MAX_OBSTACLES];
float obstacles_z[MAX_OBSTACLES];

//All possible valid obstacle rows
int all_rows[7][3] =    {{0,0,0}, //all_rows[0]
                        {1,0,0},  //all_rows[1]
                        {0,1,0},  //all_rows[2]
                        {0,0,1},  //all_rows[3]
                        {1,1,0},  //all_rows[4]
                        {1,0,1},  //all_rows[5]
                        {0,1,1}}; //all_rows[6]


void glut_init(int *argc, char **argv){
    /*GLUT init*/
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    /*creating window*/
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Endless Flight");
    glutSetIconTitle("Endless Flight");

    obstacles_init();

    glClearColor(0.9, 0.9, 0.9, 1);
	glEnable(GL_DEPTH_TEST);
}

void callbacks_init(){
    glutDisplayFunc(&on_display);
    glutReshapeFunc(&on_reshape);
    glutKeyboardFunc(&on_keyboard);
}
