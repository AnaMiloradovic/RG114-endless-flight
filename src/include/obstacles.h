#ifndef _H_OBSTACLES_H_
#define _H_OBSTACLES_H_

#include "indicators.h"
#include "init.h"
#include "queue.h"

typedef struct _row {
    //pointer to a valid obstacle row
    int positions[3];
    float zpos;
} Obstacle_row;

extern Obstacle_row *prepreke[100];

// extern Obstacle_row *obstacles_list;

Obstacle_row *new_obstacle_row(void);

void pop_front_row(void);

void add_new_row(Obstacle_row new_row);


#endif