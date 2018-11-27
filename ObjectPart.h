//
// Created by anze on 29.10.2018.
//

#ifndef CIRCUTRUNNERS_OBJECTPART_H
#define CIRCUTRUNNERS_OBJECTPART_H


#include <SDL_system.h>
#include <vector>

class ObjectPart {
private:
    SDL_Texture * objectTexture;
    std::vector<SDL_Rect> texturePartVector;
};


#endif //CIRCUTRUNNERS_OBJECTPART_H
