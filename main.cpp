#include <cstdint>
#include <iostream>
#include <string>

#include <common.h>
#include <TransFnGenerator.h>
#include <TuringMachine.h>

void add_to_db(TransFn trans_fn, TMString output_str) {
    // TODO
}

int main() {
    TMString input_str;

    TransFnGenerator trans_fns;
    for (TransFn trans_fn : trans_fns) {
        TuringMachine machine(trans_fn);
        bool halted;
        TMString output_str = machine.run(input_str, halted); // Non-halting machines can be detected w/ Busy Beaver
        if (!halted) continue;
        add_to_db(trans_fn, output_str);
    }

    /*
    // Calculate the algo probs / complexities using the stored info
    for (entry : db) {
        algo_prob = entry.count / db.count;
        algo_complexity = -log_2(algo_prob);
    }
    */

    return 0;
}
