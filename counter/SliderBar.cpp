#include "SliderBar.h"

/*!Constructor with starting values.  Sets x,y coords, width, height, and internal value */
SliderBar::SliderBar(int x, int y, int width,
        int height, int value) : BoundedCounter(x,y,width,height,value) {
    Pixel p(0, 255 ,0 , 255);
    Image i(width, height, p);
    _imageE = new ImageElement(0, 0, width, height, i);
    addChild(_imageE);
    _down = false;
    _update();
}

/*!Constructor with starting values.  Sets x,y coords, width, height, and internal value */
SliderBar::SliderBar(int x, int y, int width,
        int height, int value, const char* file) : BoundedCounter(x,y,width,height,value) {
    _imageE = new ImageElement(0, 0, width, height, file);
    addChild(_imageE);
    _down = false;
    _update();
}

/*!Override BoundedCounter's setValue. Takes an integer as an argument that must be less than max*/
bool SliderBar::setValue(int value) {
    if ( _max < value || value < 0) {
        cout << "invalid set value: (value, max) "
                << value << ", " << _max << endl;
    }
    else {
        _value = value;
        _update();
        return true;
    }
    return false;
}

//force the element to update
void SliderBar::_update() {
    float i = ((float) _value) / ((float) _max) * _width;
    _imageE->_img->set(0, 0, i, _height, 255);
    _imageE->_img->set(i, 0, _width - i, _height, 0);
    _imageE->setDirty(true);
}

/*!Override elements mouseDown */
void SliderBar::mouseDown(int x, int y) {
    bool inside = (this->_width >= x && this->_height >= y);
    if (inside) { //if inside button
        _down = true;
        int newValue = (int) ((float) x * ((float)_max / (float) _width));
        if ( 0 > newValue || _max < newValue) return;
            setValue(newValue);
        if (0 != _mouseCallback ) //if element has a callback
            this->_mouseCallback(this,x,y);
        return;
    }
}

/*!Override elements mouseUp */
void SliderBar::mouseUp(int x, int y) {
    bool inside = (this->_width >= x && this->_height >= y);
    if (_down) //if inside button
        _down = false;
    if (inside) {
        if (0 != _mouseCallback ) //if element has a callback
            this->_mouseCallback(this,x,y);
        return;
    }
}

/*! Override elements mouseMove */
void SliderBar::mouseMove(int x, int y, int dx, int dy) {
    if (_down) {
        int newValue = (int) ((float) x * ((float)_max / (float) _width));
        if ( 0 > newValue || _max < newValue) return;
        setValue(newValue);
    }

}
