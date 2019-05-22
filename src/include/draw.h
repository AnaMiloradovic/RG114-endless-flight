#ifndef _H_DRAW_H_
#define _H_DRAW_H_

#include "init.h"

#define DIRT_TEXTURE "src/img/grass.bmp"

GLuint names[1];

// Function used to draw game track
void draw_track(void);

// Function used to draw paper plane
void draw_plane(void);

// Functions used to draw obstacles
// (two types of trees)
void draw_tree_1(void);
void draw_tree_2(void);


#endif