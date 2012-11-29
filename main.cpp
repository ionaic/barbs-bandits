//http://web.engr.oregonstate.edu/~mjb/cs553/Handouts/Texture/texture.pdf
//TODO: includes from library
#include <GL/glfw.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "element/Element.h"
#include "text/TextElement.h"
#include "text/TextEdit.h"
#include "image/ImageElement.h"
#include "togglebutton/ToggleButton.h"
#include "counter/AbstractCounter.h"
#include "counter/FractionalCounter.h"
#include "counter/NumericCounter.h"
#include "counter/ProgressBar.h"
#include "button/Button.h"
#include "checkbox/CheckBox.h"
#include "checkbox/RadioButton.h"
#include "counter/SliderBar.h"
#include "dropdown/DropDown.h"
#include "helper/OGHelper.h"

using namespace std;
//global variables so that we can directly access certain elements of the GUI
static string textureFile = "resources/white.bmp";
static ToggleButton* TB;
static ToggleButton* TB2;
static NumericCounter* N;
static FractionalCounter* F;
static ProgressBar* PB;
static TextEdit* TE;
static Element * e;
static DropDown* DD;

/*
 * here is a sample user based callback.
 * This callback is registered to the button in the lower left.
 * When clicked, the button will execute the callback, resetting the ProgressBar.
 */
void buttonClicked(Element* e, int, int) {
    PB->setValue(0);
}

void checkClicked1(Element* e, int, int) {
    cout << "You clicked button 1" << endl;
}

void checkClicked2(Element* e, int, int) {
    cout << "You clicked button 2" << endl;
}
void checkClicked3(Element* e, int, int) {
    cout << "You clicked button 3" << endl;
}

void addGuiElements() {
    //create a new Numeric counter and add it to the GUI at 50, 0 with size 50, 25 and value of 1
    N = new NumericCounter(50, 0, 50, 25, 1);
    e->addChild(N);
    //text edit box at 0, 50, with size 200, 25 and default text of "Hello"
    TE = new TextEdit(0,50,200,25,"Hello");
    e->addChild(TE);
    //drop down menu at 0, 75, with size 50 , 100 and 4 options.
    vector <string> menuList;
    menuList.push_back("DD_1");
    menuList.push_back("DD_2");
    menuList.push_back("DD_3");
    menuList.push_back("DD_4");
    DD = new DropDown(0, 75, 50, 100, menuList, "resources/dd.bmp", "resources/dd2.bmp");
    e->addChild(DD);
    //Fractional counter at 206, 100 with size 50,20, default value of 1 and max value of 100
    F = new FractionalCounter(206, 100, 50, 20, 1 ,100);
    e->addChild(F);
    //progressbar at 0, 231, with size 155, 25 and default value of 0
    PB = new ProgressBar(0, 231, 155, 25, 0, "resources/pb.bmp");
    e->addChild(PB);
    //sliderbar at 0,205, with size 155, 25, with default value of 50
    SliderBar* SB = new SliderBar(0, 205, 155, 25, 50, "resources/sb.bmp" );
    e->addChild(SB);
    //add button at 0,0 with size 50,20 and label "Button"
    Button* B = new Button(0, 0, 50, 25, "resources/b_up.bmp", "resources/b_down.bmp", "Button");
    //register our custom callback to the click event of "Button"
    B->registerMouseDownCallback( buttonClicked );
    e->addChild(B);
    //toggle button at 206, 0, with size 50, 20, labeled "Increase"
    TB = new ToggleButton(206, 0, 50, 25, "resources/b_up.bmp", "resources/b_down.bmp", "Increase");
    e->addChild(TB);
    //toggle button at 206, 50, with size 50, 20, labeled "Decrease"
    TB2 = new ToggleButton(206, 50, 50, 25, "resources/b_up.bmp", "resources/b_down.bmp", "Decrease");
    e->addChild(TB2);
    //CheckBox array at 206, 156, with size 50, 100 with 5 buttons.
    vector <string> buttonList;  //list of strings to be passed to the CheckBox constructor
    buttonList.push_back("    CB 1");
    buttonList.push_back("    CB 2");
    buttonList.push_back("    CB 3");
    buttonList.push_back("    CB 4");
    buttonList.push_back("    CB 5");
    CheckBox* CB = new CheckBox(206, 156, 50, 100, buttonList, "resources/c_1.bmp", "resources/c_2.bmp");
    CB->registerMouseDownCallback(0, checkClicked1);
    CB->registerMouseDownCallback(1, checkClicked2);
    CB->registerMouseDownCallback(2, checkClicked3);
    e->addChild(CB);
    //RadioButton array at 156, 156, with size 50, 100 with 6 buttons.
    vector <string> buttonList2; //list of strings to be passed to the RadioButton constructor
    buttonList2.push_back("     RB 1");
    buttonList2.push_back("     RB 2");
    buttonList2.push_back("     RB 3");
    buttonList2.push_back("     RB 4");
    buttonList2.push_back("     RB 5");
    buttonList2.push_back("     RB 6");
    RadioButton* RB = new RadioButton(156, 156, 50, 100, buttonList2, "resources/r_1.bmp", "resources/r_2.bmp");
    e->addChild(RB);
    //create new resized image at the bottom
    ImageElement* RS = new ImageElement(100, 0, 50, 50, "resources/resize.bmp");
    e->addChild(RS);
}


void animate(void) {
    //if increase is pressed, increase the numeric and fractional counters as well as the progress bar
    if ( TB->isDown() ) { (*N)++; (*F)++; (*PB)++; }
    //if decrease is pressed, decrease the numeric and fractional counters as well as the progress bar
    if ( TB2->isDown() ) { (*N)--; (*F)--; (*PB)--; }
}

int main() {
    //start up the helper class and run some demo OpenGL setup code
    e = OG_init(512, 512, "OpenGUI Demo", textureFile.c_str());
    //run our init function to add elements to the GUI
    addGuiElements();
    //register our animation function so that the progress bar and counters will update in the event loop
    OG_registerAnimation(animate);
    //start up the openGL event loop
    OG_run();

}

