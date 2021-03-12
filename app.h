#pragma once

#include <SDL2/SDL.h>
#include <iostream>

class App
{
public:
    App(std::string caption, int w, int h);
    ~App();
    void draw();
    void update();
private:
    SDL_Window *window;
    SDL_Surface *w_surface;
    SDL_Surface *stick_man;
    SDL_Texture *texture;
    SDL_Renderer *renderTarget;
    SDL_Event ev;
};

