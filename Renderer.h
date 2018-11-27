//
// Created by anze on 25.10.2018.
//



#ifndef CIRCUTRUNNERS_Renderer_H
#define CIRCUTRUNNERS_Renderer_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <string>
#include <vector>
#include "GameObject.h"
#include <chrono>
#include <math.h>


class Renderer {
private:

//The window we'll be rendering to
    SDL_Window * gWindow = nullptr;

//The surface contained by the window
    SDL_Surface * gScreenSurface = nullptr;

//Current displayed PNG image
    SDL_Surface * gPNGSurface = nullptr;

    SDL_Renderer * gRenderer = nullptr;

//Screen dimension constants
    const int SCREEN_WIDTH = 512;
    const int SCREEN_HEIGHT = 320;
public:
    bool init();
    bool render(std::vector<GameObject*> gameObjects);
    void close();
    SDL_Renderer * getRenderer();
};


#endif //CIRCUTRUNNERS_Renderer_H
