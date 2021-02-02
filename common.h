#include <cstdint>
#include <vector>

typedef std::vector<bool> TMString;
typedef uint64_t TransFn;

constexpr uint8_t N = 4; // Number of states in each Turing machine
constexpr uint8_t K = 2; // Number of symbols in each Turing machine's alphabet
