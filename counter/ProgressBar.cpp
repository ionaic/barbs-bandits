#include "ProgressBar.h"

/*!Constructor with starting values.  Sets Elements x and y coords, width, height, and the bar's default value. */
ProgressBar::ProgressBar(int x, int y, int width,
        int height, int value) : BoundedCounter(x, y, width, height, value) {
    Pixel p(255, 0 ,0 , 255);
    Image i(width, height, p);
    _imageE = new ImageElement(0, 0, width, height, i);
    addChild(_imageE);
    _update();
}

/*!Constructor with starting values.  Sets Elements x and y coords, width, height, and the bar's default value. */
ProgressBar::ProgressBar(int x, int y, int width,
        int height, int value, const char* file) : BoundedCounter(x, y, width, height, value) {
    _imageE = new ImageElement(0, 0, file);
    addChild(_imageE);
    _update();
}

/*!sets the value and checks to ensure it's < max value */
bool ProgressBar::setValue(int value) {
    if ( _max < value) {
        cout << "invalid set value: (value, max) " << value
                << ", " << _max << endl;
    }
    else {
        _value = value;
        _update();
        return true;
    }
    return false;
}

/*!++ operator to increment the counter */
ProgressBar &ProgressBar::operator++(int) {
    if ( ! (_value + 1 > _max ) ) {
        _value++;
        _update();
    }
    return *this;
}

/*-- operator to decrement the counter */
ProgressBar &ProgressBar::operator--(int) {
    if (_value > 0) {
        _value--;
        _update();
    }
    return *this;
}

//forces the bar to update
void ProgressBar::_update() {
    float i = ((float) _value) / ((float) _max) * _width;
    _imageE->_img->set(0, 0, i, _height, 255);
    _imageE->_img->set(i, 0, _width - i, _height, 0);
    _imageE->setDirty(true);
}
