#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "include/init.h"
#include "include/indicators.h"
#include "include/obstacles.h"

int main(int argc, char **argv) {

  /*Glut init and creating window*/
  glut_init(&argc, argv);

  /*callback function init*/
  callbacks_init();
  
  /*enter main loop*/
  glutMainLoop();

  int i, j;
  Obstacle_row red;
  for (i=0; i<25; i++){
    red = new_obstacle_row();
    // for (j=0; j<3; j++)
      printf("%g", red->positions);
    printf("\n");   
  }

  return 0;
}

