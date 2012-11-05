#include "ProgressBar.h"


ProgressBar::ProgressBar(int x, int y, int width,
        int height, int value) : BoundedCounter(x, y, width, height, value) {
    _imageE = new ImageElement(0, 0, width, height);
    addChild(_imageE);
}

bool ProgressBar::setValue(int value) {
    if ( _max < value) {
        cout << "invalid set value: (value, max) " << value << ", " << _max << endl;
    }
    else {
        _value = value;
        _update();
        return true;
    }
}

void ProgressBar::_update() {
    float i = ((float) _value) / ((float) _max) * _width;
    _imageE->_img->set(0, 0, i, _height, Pixel(255, 0, 0, 255));
    _imageE->_img->set(i, 0, _width - i, _height, Pixel(0, 0, 0, 0));
    _imageE->setDirty(true);
}

ProgressBar &ProgressBar::operator++(int) {
    if ( ! (_value + 1 > _max ) ) {
        _value++;
        _update();
    }
    return *this;
}

