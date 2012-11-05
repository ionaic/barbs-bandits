#include "BoundedCounter.h"

BoundedCounter::BoundedCounter() {
    BoundedCounter(0,0,0,0,0);
}

BoundedCounter::BoundedCounter(int x, int y, int width, int height, int value) {
    BoundedCounter(x, y, width, height, value, 100);
}

BoundedCounter::BoundedCounter(int x, int y, int width, int height,
        int value, int max) : AbstractCounter(x, y, width, height, value) {
    _max = max;
}

void BoundedCounter::setMax(int max) {
    _max = max;
}

bool BoundedCounter::setValue(int value) {
    if (value < _max) {
        _value = value;
        return true;
    }
    else {
        return false;
    }
}
