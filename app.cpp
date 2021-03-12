#include "app.h"

App::App(std::string caption, int w, int h)
{
    //Start SDL Video
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed To Init Video." << std::endl << SDL_GetError() << std::endl;
        return;
    }

    //Check if window was created.
    window = SDL_CreateWindow(caption.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    if(!window)
    {
        std::cout << "Cannot Create SDL Window." << std::endl << SDL_GetError() << std::endl;
        return;
    }
    else
    {
        w_surface = SDL_GetWindowSurface(window);
        if(!w_surface)
        {
            std::cout << "Cannot Create Window Surface." << std::endl << SDL_GetError() << std::endl;
            return;
        }
    }
}

App::~App()
{
    //Clear up things.
    SDL_DestroyWindow(window);
    SDL_FreeSurface(w_surface);
    SDL_FreeSurface(stick_man);
    SDL_DestroyRenderer(renderTarget);
    SDL_DestroyTexture(texture);
    //Free pointers
    w_surface = stick_man = nullptr;
    texture = nullptr;
    SDL_Quit();
}

void App::draw()
{
    SDL_Rect rc{0,0,75,129};

    //Image of stick man to load.
    stick_man = SDL_LoadBMP("stickman.bmp");

    //Check if bitmap was loaded.
    if(stick_man == NULL)
    {
        std::cout << "Cannot Load Image." << std::endl;
    }
    //Create render target
    renderTarget = SDL_CreateRenderer(window,-1,0);
    //Create an texture surface from the stic kman image.
    texture = SDL_CreateTextureFromSurface(renderTarget,stick_man);
    //Set the window background color
    SDL_SetRenderDrawColor(renderTarget,255,255,255,255);
    //Render the stick man to the screen.
    SDL_RenderClear(renderTarget);
    SDL_RenderCopy(renderTarget,texture,NULL,&rc);
    SDL_RenderPresent(renderTarget);

}

void App::update()
{
    bool IsRunning = true;

    while(IsRunning)
    {
        while(SDL_PollEvent(&ev) > 0)
        {
            //Check if event message was button X been pressed.
            if(ev.type == SDL_QUIT)
            {
                //Stop the running of main loop
                IsRunning = false;
            }
        }
        //Do all the drawing.
        draw();
    }
}
