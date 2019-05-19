#ifndef _H_DRAW_H_
#define _H_DRAW_H_

#include "init.h"

#define EPSILON 0.01

// Function used to draw game track
void draw_track();

// Function used to draw paper plane
void draw_plane();

void set_normal_and_vertex_cylinder(float u, float v);

// Function used to draw obstacles
void draw_tree();


#endif