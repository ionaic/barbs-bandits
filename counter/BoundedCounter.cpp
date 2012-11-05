#include "BoundedCounter.h"

BoundedCounter::BoundedCounter(int x, int y, int width,
        int height, int value) : AbstractCounter(x, y, width, height, value) {
    _max = 100;
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

BoundedCounter &BoundedCounter::operator++(int) {
    if ( ! (_value + 1 > _max ) )
        _value++;
    return *this;
}

BoundedCounter &BoundedCounter::operator--(int) {
    if (_value > 1 )
        _value--;
    return *this;
}
