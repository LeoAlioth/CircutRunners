//
// Created by anze on 28.10.2018.
//

#ifndef CIRCUTRUNNERS_SCENE_H
#define CIRCUTRUNNERS_SCENE_H


#include "GameObject.h"
#include "Renderer.h"

class Scene {
private:
    std::vector<GameObject*> gameObjects;
public:
    bool updateScene();

    bool addObject(GameObject *GO);

    bool removeObject();

    Scene();

    bool init();
    bool close();

    std::vector<GameObject*> getVisibleObjects();



};


#endif //CIRCUTRUNNERS_SCENE_H
