//http://web.engr.oregonstate.edu/~mjb/cs553/Handouts/Texture/texture.pdf
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
#include "helper/OGHelper.h"

using namespace std;

static string textureFile = "texture.bmp";
static ToggleButton* TB;
static ToggleButton* TB2;
static NumericCounter* N;
static FractionalCounter* F;
static ProgressBar* PB;
static TextEdit* TE;

void buttonClicked(Element* e, int, int) {
    Element* element = e;
}

void buttonClicked2(Element* e, int, int) {
    Element* element = e;
    PB->setValue(0);
}


OGHelper * init() {
    OGHelper* helper = new OGHelper(512, 512, "OpenGUI Demonstration");
    helper->OG_init(textureFile.c_str());
    N = new NumericCounter(50, 0, 50, 25, 1);
    helper->addChild(N);
    //text edit box
    TE = new TextEdit(2,50,200,25,"Hello");
    helper->addChild(TE);
    //Fractional counter in bottom right above increse
    F = new FractionalCounter(206, 100, 50, 20, 1 ,100);
    helper->addChild(F);
    //progressbar in the upper left
    PB = new ProgressBar(0, 231, 155, 25, 0);
    helper->addChild(PB);
    //sliderbar below progress bar
    SliderBar* SB = new SliderBar(0, 205, 155, 25, 0 );
    helper->addChild(SB);
    //lower left button
    Button* B = new Button(0, 0, 50, 20, "Button");
    B->registerMouseDownCallback( buttonClicked2 );
    helper->addChild(B);
    //toggle button on the right
    TB = new ToggleButton(206, 0, 50, 20, "Increase");
    TB->registerMouseDownCallback( buttonClicked );
    helper->addChild(TB);
    //another toggle button on the right
    TB2 = new ToggleButton(206, 50, 50, 20, "Decrease");
    TB2->registerMouseDownCallback( buttonClicked );
    helper->addChild(TB2);
    //CheckBox array
    vector <string> buttonList;
    buttonList.push_back("CB 1");
    buttonList.push_back("CB 2");
    buttonList.push_back("CB 3");
    buttonList.push_back("CB 4");
    buttonList.push_back("CB 5");
    CheckBox* CB = new CheckBox(206, 156, 50, 100, buttonList);
    helper->addChild(CB);
    //RadioButton array
    vector <string> buttonList2;
    buttonList2.push_back("RB 1");
    buttonList2.push_back("RB 2");
    buttonList2.push_back("RB 3");
    buttonList2.push_back("RB 4");
    buttonList2.push_back("RB 5");
    buttonList2.push_back("RB 6");
    buttonList2.push_back("RB 7");
    buttonList2.push_back("RB 8");
    RadioButton* RB = new RadioButton(156, 156, 50, 100, buttonList2);
    helper->addChild(RB);

    return helper;
}



int main() {
    //start up the helper class
    OGHelper* helper = init();
    helper->run();

}







