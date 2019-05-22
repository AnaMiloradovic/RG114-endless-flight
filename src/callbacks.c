#include "include/callbacks.h"

void on_display(void)
{
  // Default light parameters
  GLfloat light_position[] = {0, 10, 10, 1};
  GLfloat light_ambient[] = {0, 0, 0, 1};
  GLfloat light_diffuse[] = {1, 1, 1, 1};
  GLfloat ambient_coeffs[] = {0.3, 1, 0, 1};
  GLfloat diffuse_coeffs[] = {0, 1, 0, 1};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Viewpoint setup
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3.0, 2.55, 1.5, 3.0, 0.0, -0.9, 0.0, 1.0, 0.0);

  // Turning lighting on and setting default light
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

  // Default material
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);

  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);

  glShadeModel(GL_SMOOTH);

  draw_plane();

  draw_track();

  // Drawing obstacles loop
  for (int i = 0; i < OBST_BUFF_SIZE; i++){

    if (obst_buff[i].obst_zpos < 1){

      for (int j = 0; j < 3; j++){

        if (obst_buff[i].obst[j] == 1){

          int obst_x = 1 + 2 * j;

          // Drawing obstacles
          glPushMatrix();
            glTranslatef(obst_x, 0, obst_buff[i].obst_zpos);

            // Randomly picking type of obstacle to be drawn
            (obst_buff[i].tree_type == 0) ? draw_tree_1() : draw_tree_2();
          glPopMatrix();

          // Checking for collisons
          if (collided(player_z, obst_buff[i].obst_zpos, player_x, obst_x))
            process_collision();
        }
      }
    }
  }

  // Displaying current score
  display_score();

  // Printing text to the middle of the screen
  print_notification_text(notification_text);

  // Sending new frame to a screen
  glutSwapBuffers();
}

void on_reshape(int width, int height)
{
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80, (float)width / height, 1, FAR_CLIP_PLANE);
  glMatrixMode(GL_MODELVIEW);
}


// Enabling arrow keys to be used for plane movement
void special_input(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_LEFT:
    // Moving plane to the left if game is running
    if (animation_active == 1)
    {
      animation_active_right = 0;
      if (animation_active_left == 0 && player_x_desired > 1)
      {
        player_x_desired -= 2;
        animation_active_left = 1;
        glutTimerFunc(TIME, move_left, TIMER_ID);
      }
    }
    break;

  case GLUT_KEY_RIGHT:
    // Moving plane to the right if game is running
    if (animation_active == 1)
    {
      animation_active_left = 0;
      if (animation_active_right == 0 && player_x_desired < 5)
      {
        player_x_desired += 2;
        animation_active_right = 1;
        glutTimerFunc(TIME, move_right, TIMER_ID);
      }
    }
    break;

  case GLUT_KEY_UP:
    // Speeding plane up
    if (speed < 4 && animation_active == 1)
      speed += 3;
    glutPostRedisplay();
    break;

  case GLUT_KEY_DOWN:
    // Slowing plane down
    if (speed > 0 && animation_active == 1)
      speed -= 3;
    glutPostRedisplay();
    break;
  }
}

void on_keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    // Quitting the game
    case   27:
    case 'q':
    case 'Q':
      exit(0);
      break;

    case 'a':
    case 'A':
      // Moving plane to the left if game is running
      if (animation_active == 1)
      {
        animation_active_right = 0;
        if (animation_active_left == 0 && player_x_desired > 1)
        {
          player_x_desired -= 2;
          animation_active_left = 1;
          glutTimerFunc(TIME, move_left, TIMER_ID);
        }
      }
      break;

    case 'd':
    case 'D':
      // Moving plane to the right if game is running
      if (animation_active == 1)
      {
        animation_active_left = 0;
        if (animation_active_right == 0 && player_x_desired < 5)
        {
          player_x_desired += 2;
          animation_active_right = 1;
          glutTimerFunc(TIME, move_right, TIMER_ID);
        }
      }
      break;

    case 'w':
    case 'W':
      // Speeding plane up
      if (speed < 4 && animation_active == 1)
        speed += 3;
      glutPostRedisplay();
      break;

    case 's':
    case 'S':
      // Slowing plane down
      if (speed > 0 && animation_active == 1)
        speed -= 3;
      glutPostRedisplay();
      break;

    case ' ':
      // Starting or resuming the game
      if (!animation_active && !gameover)
      {
        animation_active = 1;
        strcpy(notification_text, "");
        glutTimerFunc(TIME, on_timer, TIMER_ID);
      } else { 
      // Pausing the game
        animation_active = 0;
        strcpy(notification_text, "Press Space to Start/Resume Game | Press Q to quit");
      }
      break;

    case 'r':
    case 'R':
    // Restarting the game 
      if (!animation_active)
        restart_game();
      glutPostRedisplay();
      break;
    }
}

void on_timer(int value)
{
  if (value != TIMER_ID)
    return;

  animation_parameter += (.01 * speed);
  y_param += 0.2;

  // Updating obstacle positions
  for (int i = 0; i < OBST_BUFF_SIZE; i++){
    if (obst_buff[i].obst_zpos < 1){
      score += .0001 * speed;
      obst_buff[i].obst_zpos += animation_parameter * .1;
    } else {
      for (int j = 0; j < 3; j++){
        if (obst_buff[i].obst[j] == 1)
          score += 8 * speed;
      }
      obst_buff[i].obst_zpos = -758.0;
    }
  }

  glutPostRedisplay();

  // Reseting timer if needed
  if (animation_active)
    glutTimerFunc(TIME, on_timer, TIMER_ID);
}

// Airplane moving to the right
void move_right(int value){
  if (value != TIMER_ID)
    return;

  player_x += 0.5;

  if (player_x == player_x_desired)
    animation_active_right = 0;

  if (animation_active_right)
    glutTimerFunc(TIME, move_right, TIMER_ID);

  glutPostRedisplay();
}

// Airplane moving to the left
void move_left(int value){
  if (value != TIMER_ID)
    return;

  player_x -= 0.5;

  if (player_x == player_x_desired)
    animation_active_left = 0;

  if (animation_active_left)
    glutTimerFunc(TIME, move_left, TIMER_ID);

  glutPostRedisplay();
}

// Function used for displaying score counter in upper right corner
void display_score(){
  int current_width = glutGet(GLUT_WINDOW_WIDTH);
  int current_height = glutGet(GLUT_WINDOW_HEIGHT);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();

    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    gluOrtho2D(0.0, current_width, 0.0, current_height);
    char score_string[20];
    int words = sprintf(score_string, "%s %.1f", "YOUR SCORE: ", score);
    if (words < 0)
      exit(1);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(current_width - 160, current_height - 45.0);
    int len = (int)strlen(score_string);

    for (int i = 0; i < len; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, score_string[i]);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);

    glPopMatrix();

  glPopMatrix();
  glutPostRedisplay();
}

// Function used for printing text notification before game is started
// on pause and when game is over
void print_notification_text(char *text){
  int len = (int)strlen(text);
  int current_width = glutGet(GLUT_WINDOW_WIDTH);
  int current_height = glutGet(GLUT_WINDOW_HEIGHT);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    glLoadIdentity();
    glDisable(GL_LIGHTING);
    glOrtho(0, current_width, 0, current_height, -1, 1);
  
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(current_width/2 - 5*len, current_height*.95);

    for (int i = 0; i < len; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glMatrixMode(GL_MODELVIEW);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);

  glPopMatrix();
  glutPostRedisplay();
}

void restart_game(){
  indicators_reset();
  init_obstacles();
}