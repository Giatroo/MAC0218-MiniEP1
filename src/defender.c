// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"
#include "aux.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void) (x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(position_t defender_position,
                                      Spy attacker_spy) {
    static position_t previous_position = INVALID_POSITION;
    UNUSED(previous_position);
    static position_t attacker_position = INVALID_POSITION;
    static int turn = 0;
    direction_t chosen_direction = (direction_t) DIR_LEFT;

    static int TURN_TO_CHECK_ATTACKER_POS = 3;

    if (turn == TURN_TO_CHECK_ATTACKER_POS)
        attacker_position = get_spy_position(attacker_spy);

    if (turn < TURN_TO_CHECK_ATTACKER_POS) {
        chosen_direction =
            turn % 2 == 0 ? (direction_t) DIR_UP : (direction_t) DIR_DOWN;
    } else {
        direction_t dir = get_direction_between_positions(defender_position,
                                                          attacker_position);
        chosen_direction = dir;
    }

    previous_position = defender_position;
    turn++;
    return chosen_direction;
}

/*----------------------------------------------------------------------------*/
