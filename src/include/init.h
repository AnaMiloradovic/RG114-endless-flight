#ifndef _H_INIT_H_
#define _H_INIT_H_

#include <GL/glut.h>
#include "callbacks.h"
#include "indicators.h"

#define WINDOW_HEIGTH 450
#define WINDOW_WIDTH 800

void glut_init(int *argc, char **argv);

void callbacks_init(void);

#endif