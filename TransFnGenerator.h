#include <common.h>

class TransFnGenerator {
public:
    TransFnIterator& begin();
    TransFnIterator& end();
};

class TransFnIterator {
private:
    // The transition function maps from ((Q \ F) x Gamma) to (Q x Gamma x {L, R, N}).
    // Concretely, if there are 4 non-final states and 2 input letters (0, 1), then
    // we can have 8 possible inputs.
    // So to model the transition function, we need to store 8 triples from the output space.
    // We'll say the first triple corresponds to inputs (state 1, 0), second corresponds to
    // (state 1, 1), third corresponds to (state 2, 0), and so on.
    //
    // How we represent these triples in a 64-bit integer:
    // 7       |6       |5       |4       |3       |2       |1       |0
    // 00000000|00000000|00000000|00000000|00000000|00000000|00000000|00000000
    // - Bytes 0-2 are used to store the 8 new states. They have 5 possible values, so they take 3 bits each = 24 bits total
    // - Byte 3 is used to store the 8 output letters. They have 2 possible values, so 1 bit each = 8 bits total
    // - Bytes 4-5 are used to store the output directions. They have 3 possible values, so 2 bits each = 16 bits total

    uint32_t new_states;
    uint8_t outputs;
    uint16_t directions;

public:
    void operator++();
    TransFn operator*();
    bool operator==(TransFnIterator other);
    bool operator!=(TransFnIterator other);
};
