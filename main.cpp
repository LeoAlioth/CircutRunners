/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>
#include <SDL_events.h>
#include <iostream>
#include "Renderer.h"
#include "GameObject.h"
#include "Physics.h"
#include "Scene.h"
#include <math.h>

int level[10][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void handleEvent(SDL_Event *e, GameObject *edi) {

    if (e->type == SDL_MOUSEBUTTONDOWN || SDL_MOUSEMOTION) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (edi->getPosX() < x)
            edi->setPosition(edi->getPosX() + 1, edi->getPosY());
        if (edi->getPosX() > x)
            edi->setPosition(edi->getPosX() - 1, edi->getPosY());
    }

}


int main(int argc, char *args[]) {
    Renderer MainRenderer;
    Physics MainPhysics;
    //Start up SDL and create window
    if (!MainRenderer.init()) {
        printf("Failed to initialize!\n");
    } else {

        //Main loop flag
        bool quit = false;
        Scene mainScene;
        //Event handler
        SDL_Event e;
        std::cout << "creating" << std::endl;
        GameObject Edi("assets/Edison/EdisonWalking.png", MainRenderer.getRenderer(), 64, 64);
        std::cout << "moving" << std::endl;
        Edi.setPosition(192, 32);
        //Edi.setVelocity(5, 0);
        std::cout << "adding" << std::endl;
        mainScene.addObject(&Edi);

        GameObject grounds[10][16];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 16; ++j) {
                if (level[i][j] == 1) {
                    grounds[i][j].create("assets/PCB 1-side/PCB 1-side.png", MainRenderer.getRenderer(), 32, 32);
                    grounds[i][j].setPosition((j * 32), i * 32);
                    grounds[i][j].setStatic();
                    mainScene.addObject(&grounds[i][j]);
                }
            }
        }




        //While application is running
        while (!quit) {

            //Handle events on queue
            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                //std::cout << e.type  << std::endl;
                //handleEvent(&e, &Edi);
                if (e.type == SDL_QUIT) {
                    quit = true;
                }

            }
            /*if (Edi.getPosX() < 0) {
                Edi.setVelocity(5, Edi.getVelocity()[1]);
            }
            if (Edi.getPosX() > 512 - 64) {
                Edi.setVelocity(-5, Edi.getVelocity()[1]);
            }*/
            //printf("X: %f, Y: %f\n", Edi.getPosX(), Edi.getPosY());

            MainPhysics.update(mainScene.getVisibleObjects());
            MainPhysics.collisions(mainScene.getVisibleObjects());
            MainRenderer.render(mainScene.getVisibleObjects());

        }

    }

    //Free resources and close SDL
    MainRenderer.close();

    return 0;
}