#include "include/obstacles.h"

Obstacle_row *obstacles_list = NULL;

Obstacle_row new_obstacle_row(){

    if (err_indicator == 1)
        return;

    Obstacle_row *new = (Obstacle_row*)malloc(sizeof(Obstacle_row));

    if (new == NULL){
        err_indicator = 1;
        return;
    }

    new->positions = &all_rows[rand()%7];
    // new.positions = {0,0,0}
    new->zpos = -20;

}

