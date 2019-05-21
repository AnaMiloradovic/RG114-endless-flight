#include "include/init.h"

int err_indicator = 0;

float player_x = 3.0;
int player_x_desired = 3;
int player_z = 0;
float y_param = 0;

int animation_active = 0;
int animation_active_left = 0;
int animation_active_right = 0;
float animation_parameter = 0;
int score = 0;

void glut_init(int *argc, char **argv)
{
    // GLUT init
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // Creating window
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Endless Flight");
    glutSetIconTitle("Endless Flight");

    // Start game in full screen mode
    glutFullScreen();

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0, 0.35, 1, 1);
    glEnable(GL_DEPTH_TEST);

    /* Ukljucujemo normalizaciju vektora normala */
    glEnable(GL_NORMALIZE);
}

void callbacks_init()
{
    glutDisplayFunc(&on_display);
    glutReshapeFunc(&on_reshape);
    glutSpecialFunc(special_input);
    glutKeyboardFunc(&on_keyboard);
}
