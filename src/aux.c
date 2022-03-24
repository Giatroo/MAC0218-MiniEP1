// Standard headers
#include <stdio.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"

// Main header
#include "aux.h"

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

int distance_between_positions(position_t p1, position_t p2) {
    int i_dist = abs((int) (p1.i - p2.i));
    int j_dist = abs((int) (p1.j - p2.j));
    return i_dist + j_dist;
}

direction_t get_direction_between_positions(position_t p1, position_t p2) {
    int dir_i = p2.i - p1.i;
    int dir_j = p2.j - p1.j;

    if (dir_i > 0)
        dir_i = 1;
    else if (dir_i < 0)
        dir_i = -1;

    if (dir_j > 0)
        dir_j = 1;
    else if (dir_j < 0)
        dir_j = -1;

    return (direction_t) { dir_i, dir_j };
}

direction_t get_oposite_direction(direction_t dir) {
    direction_t op_dir = (direction_t) { -dir.i, -dir.j };
    return op_dir;
}

int is_in_range(int value, int lower_value, int upper_value) {
    return lower_value <= value && value <= upper_value;
}