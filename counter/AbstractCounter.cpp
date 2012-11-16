
#include "AbstractCounter.h"

/*!simple constructor for x, y, width, height*/
AbstractCounter::AbstractCounter(int x, int y, int width,
        int height, int value) : Element(x, y, width, height){
	_value = value;
}

/*!Update the value stored and re-render it.  Takes an integer as its argument*/
bool AbstractCounter::setValue(int value) {
    _value = value;
    return true;
}

/*!returns the value stored */
int AbstractCounter::getValue() {
    return _value;
}

/*!++ operator to increment the counter */
AbstractCounter &AbstractCounter::operator++(int) {
    _value++;
    return *this;
}

/*!-- operator to decrement the counter */
AbstractCounter &AbstractCounter::operator--(int) {
    _value--;
    return *this;
}
