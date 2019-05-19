#ifndef _H_CALLBACKS_H_
#define _H_CALLBACKS_H_

#include "obstacles.h"
#include "init.h"

void on_display(void);
void on_reshape(int width, int height);
void special_input(int key, int x, int y);
void on_keyboard(unsigned char key, int x, int y);
void on_timer(int value);

#endif