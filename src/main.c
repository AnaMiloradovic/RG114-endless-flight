#include "include/init.h"

int main(int argc, char **argv){

  // Seed for random numbers
  srand(time(NULL));

  init_obstacles();
  
  // Glut init and creating window
  glut_init(&argc, argv);

  // Callback function init
  callbacks_init();

  init_texture();
  
  // Enter main loop
  glutMainLoop();

  return 0;
}

