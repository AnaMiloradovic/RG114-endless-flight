#ifndef _H_INDICATORS_H_
#define _H_INDICATORS_H_

#include <stdlib.h>
#include "indicators.h"
#include "init.h"

extern Obstacle_row *obstacles_list;

typedef struct _row{

    //pointer to a valid obstacle row
    int (*positions)[3];
    float zpos;
    // int *front;
    // int *back;
    // int *next;
    // int *prev;

} Obstacle_row;

Obstacle_row *new_obstacle_row(void);

void pop_front_row(void);

void add_new_row(Obstacle_row new_row);


#endif