//
// Created by anze on 25.10.2018.
//
#include <iostream>
#include "Renderer.h"


bool Renderer::init() {
    //Initialization flag
    bool success = true;

    this->gRenderer = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        this->gWindow = SDL_CreateWindow("CircutRunners", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                         SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (this->gWindow == nullptr) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Create renderer for window
            this->gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (this->gRenderer == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else { //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}

bool Renderer::render(std::vector<GameObject*> gameObjects) {
    //Clear screen
    SDL_RenderClear( gRenderer );
    //std::cout << "starting to render" << std::endl;
    for (auto &gameObject : gameObjects) {               //Initialize renderer color
        SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        this->gWindow = NULL;
        SDL_Rect dstRect, * srcRect;
        dstRect.x = int(gameObject->getPosX());
        dstRect.y = int(gameObject->getPosY());
        dstRect.h = gameObject->getPart()->h;
        dstRect.w = gameObject->getPart()->w;
        srcRect = gameObject->getPart();
        //std::printf("%d %d %d %d\n", srcRect->x, srcRect->y, srcRect->w, srcRect->h);
        SDL_RenderCopy( gRenderer, gameObject->getTexture(), srcRect, &dstRect );

        //Update screen

    }
    SDL_RenderPresent( gRenderer );
    return true;
}



void Renderer::close() {
    //Destroy window
    SDL_DestroyRenderer( this->gRenderer );
    SDL_DestroyWindow( this->gWindow );
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

}

SDL_Renderer *Renderer::getRenderer() {
    return this->gRenderer;
}