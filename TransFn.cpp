#include <TransFn.h>

#include <cmath>

#include <common.h>

bool TransFn::is_valid() {
    for (uint32_t i = 0; i < 8; i++) {
        uint8_t out_state = (out_states / (uint32_t)std::pow(NUM_STATES, i)) % NUM_STATES;
        uint8_t out_letter = (out_letters / (uint32_t)std::pow(NUM_LETTERS, i)) % NUM_LETTERS;
        uint8_t out_direction = (out_directions / (uint32_t)std::pow(NUM_DIRECTIONS, i)) % NUM_DIRECTIONS;

        bool is_final_state = (out_state == STATE_FINAL);
        bool is_none_direction = (out_direction == DIRECTION_NONE);

        // Either both must be true or neither must be
        if ((is_final_state && !is_none_direction) || (!is_final_state && is_none_direction)) {
            return false;
        }
    }

    return true;
}
