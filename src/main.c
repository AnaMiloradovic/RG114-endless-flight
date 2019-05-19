#include "include/init.h"

int main(int argc, char **argv) {

  // Seed for random numbers
  srand(time(NULL));

  init_obstacles();
  display(obst_buff, obst_buff_head,obst_buff_tail);
  
  // Glut init and creating window
  glut_init(&argc, argv);

  // Callback function init
  callbacks_init();
  
  // Enter main loop
  glutMainLoop();


  return 0;
}

