//
// Created by anze on 28.10.2018.
//

#include "Scene.h"
#include "GameObject.h"
#include "Renderer.h"

bool Scene::updateScene() {
    GameObject * tmpGO;
    for (int i = 0; i < this->gameObjects.size(); i++) {
        tmpGO = gameObjects[i];
        tmpGO->setPosition(tmpGO->getPosX(), tmpGO->getPosY());
    }
    return true;
}

bool Scene::addObject(GameObject * GO) {
    this->gameObjects.push_back(GO);
    return true;
}

Scene::Scene() {
}

bool Scene::init() {
    return true;
}

std::vector<GameObject*> Scene::getVisibleObjects() {
    return this->gameObjects;
}

