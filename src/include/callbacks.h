#ifndef _H_CALLBACKS_H_
#define _H_CALLBACKS_H_

#include <stdlib.h>
#include <GL/glut.h>
#include "init.h"
#include "indicators.h"

void on_display(void);
void on_reshape(int width, int height);
void on_keyboard(unsigned char key, int x, int y);

#endif