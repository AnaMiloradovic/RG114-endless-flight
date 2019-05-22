#include "include/init.h"


// Initializing game indicators
int err_indicator = 0;

float player_x = 3.0;
int player_x_desired = 3;
int player_z = 0;
float y_param = 0.0;

int animation_active = 0;
int animation_active_left = 0;
int animation_active_right = 0;
float animation_parameter = 0.0;
float score = 0.0;
int speed = 1;
bool gameover = false;

char notification_text[] = "Press Space to Start/Resume Game | Press Q to quit";

// Used when we need to restart game
void indicators_reset(){
    err_indicator = 0;

    player_x = 3.0;
    player_x_desired = 3;
    player_z = 0;
    y_param = 0;

    animation_active = 0;
    animation_active_left = 0;
    animation_active_right = 0;
    animation_parameter = 0;
    score = 0;
    speed = 1;

    gameover = false;

    strcpy(notification_text, "Press Space to Start/Resume Game | Press Q to quit");
}

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
    glutFullScreen();

    // OpenGL init
    glClearColor(0, 0.35, 1, 1);
    // glClearColor(0.1, 0.8, 0, 1);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_NORMALIZE);
}

void callbacks_init(){
    glutDisplayFunc(&on_display);
    glutReshapeFunc(&on_reshape);
    glutSpecialFunc(special_input);
    glutKeyboardFunc(&on_keyboard);
    
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutSetCursor(GLUT_CURSOR_NONE);
}


void init_texture(){
    /* Objekat koji predstavlja teskturu ucitanu iz fajla */
    Image * image;

    /* Ukljucuju se teksture. */
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    /*
     * Inicijalizuje se objekat koji ce sadrzati teksturu ucitanu iz
     * fajla
     */
    image = image_init(0, 0);

    /* Kreira se tekstura*/
    image_read(image, DIRT_TEXTURE);

    /* Generisu se identifikatori tekstura. */
    glGenTextures(1, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);


    /*Iskljucujemo aktivnu teksturu*/
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Unistava se objekat za citanje tekstura iz fajla. */
    image_done(image);
    // glDisable(GL_TEXTURE_2D);
}
