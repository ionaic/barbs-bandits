
#include "AbstractCounter.h"

AbstractCounter::AbstractCounter(int x, int y, int width,
        int height, int value) : Element(x, y, width, height){
	_value = value;
}

bool AbstractCounter::setValue(int value) {
    _value = value;
    return true;
}

int AbstractCounter::getValue() {
    return _value;
}

AbstractCounter &AbstractCounter::operator++() {
    _value++;
    cout << _value << endl;
    setDirty(true);
    return *this;
}
