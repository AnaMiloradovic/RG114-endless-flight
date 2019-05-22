#ifndef _H_INIT_H_
#define _H_INIT_H_

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h> 

#include "draw.h"
#include "callbacks.h"
#include "indicators.h"
#include "image.h"

#define WINDOW_HEIGTH 450
#define WINDOW_WIDTH 800

#define FAR_CLIP_PLANE 20.0

void glut_init(int *argc, char **argv);

void callbacks_init(void);

void obstacles_init(void);

void init_texture(void);

void indicators_reset(void);


#endif