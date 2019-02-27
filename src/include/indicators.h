#ifndef _H_INDICATORS_H_
#define _H_INDICATORS_H_

#include "obstacles.h"


#define MAX_OBSTACLES 30

extern int player_x;
extern int player_z;

extern int animation_active;
//Time elapsed since animation start
extern float animation_parameter;

extern float obstacles_x[MAX_OBSTACLES];
extern float obstacles_z[MAX_OBSTACLES];

extern int err_indicator;

//All possible valid obstacle rows
extern int all_rows[7][3];

// Circular double linked lists library indicators
//--BEGIN--

//--END--

#endif