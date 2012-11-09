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
    if (value <= _max && value >= 0) {
        _value = value;
        return true;
    }
    else {
        return false;
    }
}

BoundedCounter &BoundedCounter::operator++() {
    if ( ! (_value + 1 > _max ) ) {
        _value++;
	   setDirty(1);
    }
    return *this;
}

BoundedCounter &BoundedCounter::operator--() {
    if (_value > 1 ) {
        _value--;
	   setDirty(1);
    }
    return *this;
}
