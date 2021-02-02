#include <common.h>

class TuringMachine {
public:
    TuringMachine(TransFn trans_fn);
    TMString run(const TMString& input_str, bool& halted);
};
