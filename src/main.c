#include "include/init.h"

int main(int argc, char **argv) {

  init_obstacles();
  display(obst_buff, obst_buff_head,obst_buff_tail);
  /*Glut init and creating window*/
  glut_init(&argc, argv);

  /*callback function init*/
  callbacks_init();
  
  /*enter main loop*/
  glutMainLoop();


  return 0;
}

