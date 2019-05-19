#include "include/callbacks.h"

void on_display(void)
{
  /* Pozicija svetla (u pitanju je beskonacno daleko svetlo). */
  // GLfloat light_position[] = {1, 10, 1, 0};

  /* Brise se prethodni sadrzaj prozora. */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* Podesava se vidna tacka. */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3.0, 2.5, 1.5, 3.0, 0.0, -1.0, 0.0, 1.0, 0.0);

  /* Kreira se objekat. */
  draw_plane();

  draw_track();

  //Iscrtaj prepreke
  int i;
  for (i = 0; i < OBST_BUFF_SIZE; i++)
  {
    if (obst_buff[i].obst_zpos < 10)
    {
      for(int j=0; j<3; j++)
      {          
        if (obst_buff[i].obst[j] == 1)
        {
          int obst_x = 1+2*j;

          glPushMatrix();

            glColor3f(1, 0, 1);

            // static GLfloat material_ambient[] = { 0.9, 0.9, 0.9, 1 };
            // static GLfloat material_diffuse[] = { 1, 1, 1, 1 };

            // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
            // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);

            glTranslatef(obst_x, 0, obst_buff[i].obst_zpos);
            glutSolidSphere(0.3, 40, 40);

          glPopMatrix();

          // check_collision();
          if ((obst_buff[i].obst_zpos > (player_z-0.2))&&(obst_buff[i].obst_zpos < (player_z+0.2)) && obst_x == player_x)
          {
            printf("-------------\n");
            printf("--GAME OVER--\n");
            printf("-------------\n");
            printf("SCORE: %d\n", score);
            printf("-------------\n");
            exit(EXIT_FAILURE);
          }
        }            
      }       
    }
  }
  

  glShadeModel(GL_SMOOTH);

  // glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  /* Nova slika se salje na ekran. */
  glutSwapBuffers();
}

void on_reshape(int width, int height)
{
  /* Podesava se viewport. */
  glViewport(0, 0, width, height);

  /* Podesava se projekcija. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80, (float) width / height, 1, FAR_CLIP_PLANE);
  // glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, FAR_CLIP_PLANE);
  glMatrixMode(GL_MODELVIEW);
}

void special_input(int key, int x, int y) {
  switch(key) 
  {
    case GLUT_KEY_LEFT:
      if (player_x > 1)
        player_x -= 2.0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_RIGHT:
      if (player_x < 5)
        player_x += 2.0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_UP:
      if (player_z > -2)
        player_z -= 2.0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_DOWN:
      if (player_z < 0)
        player_z += 2.0;
      glutPostRedisplay();
      break;
      
  }
}

void on_keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27:
    case 'q':
    case 'Q':
      /* Zavrsava se program. */
      exit(0);
      break;

    case 'a':
    case 'A':
      if (player_x > 1)
        player_x -= 2.0;
      glutPostRedisplay();
      break;

    case 'd':
    case 'D':
      if (player_x < 5)
        player_x += 2.0;
      glutPostRedisplay();
      break;

    case 'w':
    case 'W':
      if (player_z > -2)
        player_z -= 2.0;
      glutPostRedisplay();
      break;

    case 's':
    case 'S':
      if (player_z < 0)
        player_z += 2.0;
      glutPostRedisplay();
      break;

    case 'n':
    case 'N':
      if (!animation_active)
      {
        glutTimerFunc(50, on_timer, 0);
        animation_active = 1;
      }
      else
      {
        animation_active = 0;
      }
      break;
    }
}

void on_timer(int value)
{
  if (value != 0)
    return;

  animation_parameter += .01;

  //TODO
  //Pomeranje prepreka
  {
    int i;
    for (i = 0; i < OBST_BUFF_SIZE; i++)
      if (obst_buff[i].obst_zpos < 1)
      {
        obst_buff[i].obst_zpos += animation_parameter * .1;
      } 
      else
      {
        for(int j = 0; j < 3; j++){
          if (obst_buff[i].obst[j] == 1)
            score++;
        }
        // dequeue(obst_buff, &obst_buff_head);
        // Obstacle_row new = new_obstacle_row();
        obst_buff[i].obst_zpos = -758.0;
        // enqueue(obst_buff, &obst_buff_tail, new);
      }
      
  }

  // printf("zpos: %f\n", obst_buff[0].obst_zpos);

  glutPostRedisplay();

  //Po potrebi se ponovo postavlja timer
  if (animation_active)
    glutTimerFunc(50, on_timer, 0);
}