/* element.h
 * render : renders the element to the screen
 *
 */

#include <vector>
#pragma once

using namespace std;


static int currentId = 0;


class Element{
public:
    Element();
    Element(int x, int y, int xs, int ys);
    void render();
    void mouseInput(int x, int y);

private:
    int xCoord;
    int yCoord;
    int xSize;
    int ySize;
    bool dirty;
    vector <Element *> children;
    Element * parent;
    int id;
};
