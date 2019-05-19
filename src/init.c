#include "include/init.h"

int err_indicator = 0;

int player_x = 3;
int player_z = 0;

int animation_active = 0;
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
    // glutFullScreen();

    /* Parametri svetla i podrazumevanog materijala */
    // GLfloat light_position[] = {1, 3, 1, 0};
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1};
    // GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

    GLfloat ambient_coeffs[] = { 0.3, 0.7, 0.3, 1 };
    GLfloat diffuse_coeffs[] = { 0.2, 1, 0.2, 1 };
    // GLfloat specular_coeffs[] = { 1, 1, 1, 1 };
    // GLfloat shininess = 30;

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0, 0.5, 1, 1);
    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_NORMALIZE);

    // glEnable(GL_LIGHTING);

    /* Postavljaju se svojstva prvog svetla */
    glEnable(GL_LIGHT0);

    // glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    // glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    /* Postavljaju se svojstva materijala */
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);
    // glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    // glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    // glEnable(GL_COLOR_MATERIAL);
}

void callbacks_init()
{
    glutDisplayFunc(&on_display);
    glutReshapeFunc(&on_reshape);
    glutSpecialFunc(special_input);
    glutKeyboardFunc(&on_keyboard);
}
