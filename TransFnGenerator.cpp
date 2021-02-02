#include <TransFnGenerator.h>

void TransFnIterator::operator++() {
    do {
        if (current_.out_states < MAX_OUT_STATES) {
            current_.out_states++;
        } else if (current_.out_letters < MAX_OUT_LETTERS) {
            current_.out_states = 0;
            current_.out_letters++;
        } else if (current_.out_directions < MAX_OUT_DIRECTIONS) {
            current_.out_states = 0;
            current_.out_letters = 0;
            current_.out_directions++;
        } else {
            // We've finished iteration
            *this = TransFnGenerator().end();
            break;
        }
    } while (!current_.is_valid());
}
