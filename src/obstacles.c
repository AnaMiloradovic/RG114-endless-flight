#include "include/obstacles.h"

// Obstacle_row *prepreke = NULL;

Obstacle_row *new_obstacle_row(){

    if (err_indicator == 1)
        exit(EXIT_FAILURE);

    Obstacle_row *new = (Obstacle_row*)malloc(sizeof(Obstacle_row));

    if (new == NULL){
        err_indicator = 1;
        exit(EXIT_FAILURE);
    }
    int i;
    int random_indx = rand()%7;
    for (i=0; i<3; i++){
        new->positions[i] = all_rows[random_indx][i];
    }
    new->zpos = -10; 

    return new;
}

