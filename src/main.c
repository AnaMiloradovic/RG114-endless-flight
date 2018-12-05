#include <stdlib.h>
#include <GL/glut.h>
#include "include/init.h"
#include "include/indicators.h"

int main(int argc, char **argv) {

  /*Glut init and creating window*/
  glut_init(&argc, argv);

  /*callback function init*/
  callbacks_init();
  
  /*enter main loop*/
  glutMainLoop();

  return 0;
}

