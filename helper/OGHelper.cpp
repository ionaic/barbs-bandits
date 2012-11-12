#include "Element.h"
#include "../image/ImageElement.h"
#include <GL/glfw.h>
#include "OGHelper.h"

static bool _running;
static string _title;
static int _windowWidth;
static int _windowHeight;
static int OG_textureWidth;
static int OG_textureHeight;
static bool _initialized;
static Element* e;
static bool _quit;
static int _vsync;
static void (* _animation)(void);
static GLuint texture;

void _init();
void _draw();
void GLFWCALL windowResize( int width, int height );
void GLFWCALL mouseClicked(int mButton, int clicked);
void GLFWCALL mouseMoved(int x, int y);
void GLFWCALL keyPressed(int key, int action);
void GLFWCALL printableKeyPressed(int key, int action);
int shutDown(int returnCode);
int closeWindow(void);


Element * OG_init(int width, int height, string title, string baseTexture) {
    _windowWidth = width;
    _windowHeight = height;
    _title = title;
    OG_textureWidth = 0;
    OG_textureHeight = 0;
    _quit = 0;
    _vsync = 1;
    _running = true;
    _init();
    e = new ImageElement(0, 0, baseTexture.c_str());
    OG_textureWidth = e->width();
    OG_textureHeight = e->height();
    return (Element *) e;
}

void _init(void) {
    /** Initializes a glfw window for use in the demo
     */

    if ( GL_TRUE != glfwInit()) {
        cout << "glfw could not be initialized." << endl;
        shutDown(1);
    }

    if ( GL_TRUE != glfwOpenWindow(_windowWidth, _windowHeight, 8, 8, 8,
                         8, 8, 0, GLFW_WINDOW) ) {
        shutDown(1);
    }

    //glfw stuff
    glfwSetWindowTitle("OpenGUI Demo");
    glfwSetWindowCloseCallback( closeWindow );
    glfwSetWindowSizeCallback( windowResize );
    glfwSetMouseButtonCallback( mouseClicked );
    glfwSetMousePosCallback( mouseMoved );
    glfwSetKeyCallback( keyPressed );
    glfwSetCharCallback( printableKeyPressed );
    //vsync
    glfwSwapInterval(_vsync);

    //set clear color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //set the matrices
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(.5, -.5, -.5, .5, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);

    //now bind the texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    //set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //set texture clamping
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    //set lighting properties (ignore lighting for gui)
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
    _initialized = true;
}

void OG_addChild(Element * child){
    e->addChild(child);
}

void OG_run(void) {
    /** the main event loop for the demo
     */
    cout << "running" << endl;
    double oldTime = glfwGetTime();
    while(_running) {
        double currentTime = glfwGetTime();
        if (_quit)
            break;
        if ( currentTime > oldTime + 0.02 )
        {
            _draw();
            if (_animation) {
                _animation();
            }
            glfwSwapBuffers();
            oldTime = currentTime;
        }
        else
            usleep(10);
    }
    shutDown(0);
}

void _draw(void)
{
    static clock_t last = 0;
    static int loops = 0;
    if (last == 0) last = clock();
    loops++;
    if (loops>60) {
        clock_t nclock = clock();
        float diff = nclock-last;
        last = nclock;
        diff = diff/ CLOCKS_PER_SEC;
        diff = diff/60;
        diff = 1./diff;
        cout << diff << endl;
        loops = 0;
    }
    // draw GUI box
    //enable texturing

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, OG_textureWidth, OG_textureHeight,
                0, GL_RGBA, GL_UNSIGNED_BYTE, e->render()->getPixels());

    glEnable( GL_TEXTURE_2D );
    glLoadIdentity();
    glBegin(GL_QUADS);
    {

        glTexCoord2f( 0.0f, 0.0f);
        glVertex2i(-1, -1);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2i(-1, 1);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2i(1, 1);
        glTexCoord2f( 1.0f, 0.0f);
        glVertex2i(1, -1);
    }
    glEnd();
    glDisable( GL_TEXTURE_2D );
}

// Callback for when the window is resized
void GLFWCALL windowResize( int width, int height ) {
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    _windowWidth = width;
    _windowHeight = height;

}

void GLFWCALL mouseClicked(int mButton, int clicked)
{
    int x, y;
    glfwGetMousePos( &x, &y );
    float I = ((float)x)/((float)_windowWidth);
    float J = ((float)(_windowHeight-y))/((float)_windowHeight);
    if (mButton == 0 && clicked == 1) {
        e->mouseDown(OG_textureWidth*I, OG_textureHeight*J);
    }
    if (mButton == 0 && clicked == 0) {
        e->mouseUp(OG_textureWidth*I, OG_textureHeight*J);
    }
}

void GLFWCALL mouseMoved(int x, int y) {
    static int oldx = 0;
    static int oldy = 0;
    static bool first = true;
    y = (_windowHeight-y);
    float I = ((float)x)/((float)_windowWidth);
    float J = ((float)(_windowHeight-y))/((float)_windowHeight);
    if (first) {
        first = false;
        oldx = x;
        oldy = y;
    } else {
        e->mouseMove(OG_textureWidth * I, OG_textureHeight * J,x-oldx,y-oldy);
        oldx = x;
        oldy = y;
    }
}

void GLFWCALL printableKeyPressed(int key, int action) {
            e->keyDown(key);
}

void GLFWCALL keyPressed(int key, int action) {
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_ESC)
                _quit = 1;
        else if (key == GLFW_KEY_BACKSPACE)
            e->keyDown(-1);
    }
}

int shutDown(int returnCode) {
    if (_initialized)
        glfwTerminate();
    cout << "exiting" << endl;
    exit(returnCode);
}

int closeWindow(void) {
    shutDown(EXIT_SUCCESS);
    return GL_TRUE;
}

void OG_registerAnimation(AnimCallback_t func) {
    _animation = func;
}

