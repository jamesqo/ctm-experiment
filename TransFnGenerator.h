#include <common.h>
#include <TransFn.h>

class TransFnGenerator {

public:
    TransFnIterator& begin() const {
        return TransFnIterator(TransFn(0, 0, 0));
    }
    TransFnIterator& end() const {
        return TransFnIterator(TransFn(-1, -1, -1));
    }

};

class TransFnIterator {

private:
    TransFn current_;

public:
    TransFnIterator(TransFn start) : current_(start) {}
    void operator++();
    TransFn operator*() const { return current_; }
    bool operator==(TransFnIterator other) const {
        return current_.out_states == other.current_.out_states &&
            current_.out_letters == other.current_.out_letters &&
            current_.out_directions == other.current_.out_directions;
    }
    bool operator!=(TransFnIterator other) const { return !(*this == other); }

};
