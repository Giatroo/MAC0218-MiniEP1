#ifndef AUX_H
#define AUX_H

#include "direction.h"
#include "position.h"

int distance_between_positions(position_t p1, position_t p2);
direction_t get_direction_between_positions(position_t p1, position_t p2); 
direction_t get_oposite_direction(direction_t dir);
int is_in_range(int value, int lower_value, int upper_value);

#endif // !AUX_H