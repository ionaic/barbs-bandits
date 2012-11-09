#include <string>
#include <vector>
#include "Element.h"

class Dropdown : public ToggleButton {
    public:
        //Dropdown();
        //Dropdown(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        Dropdown(unsigned int x, unsigned int y, unsigned int width, unsigned int height, std::vector<std::string> &children);
        void dd_click(std::string label);
        
        void update();
        
    private:
        Button* unclicked;
        //Image *_unclickedResult;
        bool _clicked;
};
