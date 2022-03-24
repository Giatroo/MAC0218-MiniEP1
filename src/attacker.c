// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"
#include "aux.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void) (x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PRIVATE FUNCTIONS                             */
/*----------------------------------------------------------------------------*/

int check_if_needs_to_try_another_direction(int trying_direction,
                                            position_t attacker_position,
                                            position_t previous_position) {
    // try another direction
    if (equal_positions(attacker_position, previous_position))
        trying_direction++;
    else // reset the direction to try
        trying_direction = 0;

    if (trying_direction >= 8) {
        printf("No possible direction, this shouldn't be printed.");
        trying_direction = 0;
    }

    return trying_direction;
}


/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(position_t attacker_position,
                                      Spy defender_spy) {
    static position_t previous_position = INVALID_POSITION;
    static position_t defender_position = INVALID_POSITION;
    static int trying_direction = 0;
    static int turn = 0;
    const int TURN_TO_CHECK_DEFENDER_POS = 2;

    direction_t direction_order[8] = { DIR_UP_RIGHT,  DIR_RIGHT, DIR_DOWN_RIGHT,
                                       DIR_UP,        DIR_DOWN,  DIR_UP_LEFT,
                                       DIR_DOWN_LEFT, DIR_LEFT };

    if (turn == TURN_TO_CHECK_DEFENDER_POS)
        defender_position = get_spy_position(defender_spy);

    if (is_in_range(turn, TURN_TO_CHECK_DEFENDER_POS,
                    TURN_TO_CHECK_DEFENDER_POS + 5) &&
        distance_between_positions(attacker_position, defender_position) < 5) {
        direction_t dir = get_direction_between_positions(attacker_position,
                                                          defender_position);
        direction_t op_dir = get_oposite_direction(dir);
        /* printf("Attacker: gonna try direction %d %d\n", op_dir.i, op_dir.j);
         */
        previous_position = attacker_position;
        turn++;
        return op_dir;
    }

    trying_direction = check_if_needs_to_try_another_direction(
        trying_direction, attacker_position, previous_position);

    /* printf("Attacker: gonna try direction %d\n", trying_direction); */

    previous_position = attacker_position;
    turn++;

    return direction_order[trying_direction];
}

