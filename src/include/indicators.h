#ifndef _H_INDICATORS_H_
#define _H_INDICATORS_H_

// #include "init.h"
#define TIMER_ID 0
#define TIME 50

extern float player_x;
extern int player_x_desired;
extern int player_z;
extern float y_param;

extern int animation_active;
extern int animation_active_left;
extern int animation_active_right;

//Time elapsed since animation start
extern float animation_parameter;

extern int speed;

extern float score;

extern int err_indicator;

extern bool gameover;

extern char notification_text[255];

#endif