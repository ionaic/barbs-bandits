#include "ProgressBar.h"

ProgressBar::ProgressBar() {
    ProgressBar(0,0,0,0,0);
}

ProgressBar::ProgressBar(int x, int y, int width,
        int height, int value) : BoundedCounter(x, y, width, height, value) {
    _imageE = new ImageElement(0, 0, width, height);
    addChild(_imageE);
}

bool ProgressBar::setValue(int value) {
    if ( _max < value) return false;
    else {
        _value = value;
        _update();
        return true;
    }
}

void ProgressBar::_update() {
    float i = ((float) _value) / ((float) _max) * _width;
    _imageE->_img->set(0, 0, i, _height, Pixel(255, 0, 0, 255));
    _imageE->setDirty(true);
}


