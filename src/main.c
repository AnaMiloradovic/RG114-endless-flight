#include "include/init.h"

int main(int argc, char **argv) {

  obstacles_init();

  /*Glut init and creating window*/
  glut_init(&argc, argv);

  /*callback function init*/
  callbacks_init();
  
  /*enter main loop*/
  glutMainLoop();


  return 0;
}

