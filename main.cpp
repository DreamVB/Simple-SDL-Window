//Simple starter SDL Project.
#include <exception>
#include <string>
#include "app.h"
#include "app.cpp"

int main( int argc, char * argv[] )
{
    //init the App class
    App app("SDL Demo Window",640,480);
    //Start up things
    app.update();
    //Return to system
    return 0;
}
