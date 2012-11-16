#include "BoundedCounter.h"

/*! Constructor with starting value. Sets maximum to 100. */
BoundedCounter::BoundedCounter(int x, int y, int width,
        int height, int value) : AbstractCounter(x, y, width, height, value) {
    _max = 100;
}

/*!Constructor with starting value and maximum value*/
BoundedCounter::BoundedCounter(int x, int y, int width, int height,
        int value, int max) : AbstractCounter(x, y, width, height, value) {
    _max = max;
}

/*!Set maximum value of the counter.  Takes an integer as the argument */
void BoundedCounter::setMax(int max) {
    _max = max;
}

/*!Set value of the counter. Takes an integer that must be less than maximum */
bool BoundedCounter::setValue(int value) {
    if (value <= _max && value >= 0) {
        _value = value;
        return true;
    }
    else {
        return false;
    }
}

/*!++ operator to increment the counter */
BoundedCounter &BoundedCounter::operator++() {
    if ( ! (_value + 1 > _max ) ) {
        _value++;
	   setDirty(1);
    }
    return *this;
}

/*!-- operator to decrement the counter */
BoundedCounter &BoundedCounter::operator--() {
    if (_value > 1 ) {
        _value--;
	   setDirty(1);
    }
    return *this;
}
