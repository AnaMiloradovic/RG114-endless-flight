#include "include/obstacles.h"

Obstacle_row obst_buff[OBST_BUFF_SIZE];

//All possible valid obstacle rows
int all_rows[7][3] =    {{0,0,0}, //all_rows[0]
                        {1,0,0},  //all_rows[1]
                        {0,1,0},  //all_rows[2]
                        {0,0,1},  //all_rows[3]
                        {1,1,0},  //all_rows[4]
                        {1,0,1},  //all_rows[5]
                        {0,1,1}}; //all_rows[6]


Obstacle_row new_obstacle_row()
{
    if (err_indicator == 1)
        exit(EXIT_FAILURE);

    Obstacle_row new;

    int i;
    int random_indx = rand() % 7;
    for (i = 0; i < 3; i++)
    {
        new.obst[i] = all_rows[random_indx][i];
    }
    new.obst_zpos = -10.0;

    return new;
}

/* -------------------------------- */
/* --- QUEUE FUNCTIONS BEGINING --- */
/*
 * File   : queue.c
 * Author : zentut.com
 * Purpose: stack header file
 */

/*
    initialize queue pointers
*/
void init(int *head, int *tail)
{
    *head = *tail = 0;
}
 
/*
   enqueue an element
   precondition: the queue is not full
*/
void enqueue(Obstacle_row *q,int *tail, Obstacle_row element)
{
    // Copying int array elements to new queue element
    for (int i = 0; i < 3; i++)
    {
        q[(*tail)].obst[i] = element.obst[i];
    }
    
    q[(*tail)].obst_zpos = element.obst_zpos;
    (*tail)++;
}
 
/*
    dequeue an element
    precondition: queue is not empty
*/
Obstacle_row dequeue(Obstacle_row *q,int *head)
{
    return q[(*head)++];
}
 
/*
    return 1 if queue is full, otherwise return 0
*/
int full(int tail,const int size)
{
    return tail == size;
}
 
/*
  return 1 if the queue is empty, otherwise return 0
*/
int empty(int head, int tail)
{
    return tail == head;
}
 
/*
  display queue content
*/
void display(Obstacle_row *q,int head,int tail)
{
    int i = tail - 1;
    while(i >= head){
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",q[i].obst[j]);
        }        
        printf(" | zpos -> %f ",q[i--].obst_zpos);
        printf("\n");
    }        
    printf("\n");
}

/* --- QUEUE FUNCTIONS END --- */
/* -------------------------------- */

void init_obstacles(){
    init(&obst_buff_head, &obst_buff_tail);

    // Adding OBST_BUFF_SIZE of elements to the queue
    for (int i = 0; i < OBST_BUFF_SIZE; i++){
        n_obst_row = new_obstacle_row();
        
        enqueue(obst_buff, &obst_buff_tail, n_obst_row);
        
        // Setting zpos to current row
        obst_buff[i].obst_zpos = - FAR_CLIP_PLANE - 6*i;

        // Randomly choosing type of obstacles in current row
        obst_buff[i].tree_type = rand() % 2;
    }  
}

bool collided(float player_z, float obst_z, int player_x, int obst_x){
    if (player_z == nearbyint(obst_z) && player_x == obst_x)
        return true;
        
    return false;
}

void process_collision(){ 
    // Stopping the game
    animation_active = 0;

    // Signaling that current game is over
    // That happens ONLY if collision happened
    gameover = true;

    // Displaying notification text for gameover screen
    strcpy(notification_text, "GAME OVER | Press R to Restart game | Press Q to Quit");
    print_notification_text(notification_text);
}
