#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "include/init.h"
#include "include/indicators.h"
#include "include/obstacles.h"

int main(int argc, char **argv) {

  int i, j;
  Obstacle_row red;
      printf("Test");
  for (i=0; i<25; i++){
    red = new_obstacle_row();
    int poz[3];

    for (j=0; j<3; j++)
      printf("%ls ", red.positions[j]);
    printf("\n");   
  }

  /*Glut init and creating window*/
  glut_init(&argc, argv);

  /*callback function init*/
  callbacks_init();
  
  /*enter main loop*/
  glutMainLoop();


  return 0;
}

