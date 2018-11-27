#include <utility>

//
// Created by anze on 25.10.2018.
//

#include <SDL_image.h>
#include "GameObject.h"
#include "Renderer.h"
#include <nlohmann/json.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>

GameObject::GameObject() {
    this->movable = 1;
    this->posX = 0;
    this->posY = 0;
    this->rotation = 0;
    this->velocity.resize(2);
    this->velocity[0] = 0;
    this->velocity[1] = 0;
    this->bouncyness = 1;
    this->sizeX = 0;
    this->sizeY = 0;
};

GameObject::GameObject(std::string path, SDL_Renderer *renderer, int sizeX, int sizeY) {
    //std::cout << "getting textures" << std::endl;
    this->loadTextures(std::move(path), renderer, sizeX, sizeY);
    //std::cout << "moving to 0" << std::endl;
    this->movable = 1;
    this->posX = 0;
    this->posY = 0;
    this->rotation = 0;
    this->velocity.resize(2);
    this->velocity[0] = 0;
    this->velocity[1] = 0;
    this->bouncyness = 1;

}

bool GameObject::loadTextures(std::string path, SDL_Renderer *renderer, int sizeX, int sizeY) {
    this->part.x = 0;
    this->part.y = 0;
    this->part.w = sizeX;
    this->part.h = sizeY;

    /*if (boost::filesystem::is_directory(path)) {
        std::cout << path << " is a directory containing:\n";

        for (auto &entry : boost::make_iterator_range(boost::filesystem::directory_iterator(path), {}))
            std::cout << entry << "\n";
    }*/

    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return false;
    } else {
        //Create texture from surface pixels
        this->objectTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (this->objectTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            return false;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return true;
}

bool GameObject::setPosition(double x, double y) {
    this->posX = x;
    this->posY = y;
    return true;
}

bool GameObject::setRotation(double rotation) {
    this->rotation = rotation;
    return true;
}

bool GameObject::setRotation(double rotation, double rotationalSpeed) {
    this->rotation = rotation;
    this->rotationalSpeed = rotationalSpeed;
    return true;
}

bool GameObject::setVelocity(double vx, double vy) {
    this->velocity[0] = vx;
    this->velocity[1] = vy;
    return true;
}

double GameObject::getPosX() {
    return this->posX;
}

double GameObject::getPosY() {
    return this->posY;
}

double GameObject::getRotation() {
    return this->rotation;
}

double GameObject::getRotationalSpeed() {
    return this->rotationalSpeed;
}

std::vector<double> GameObject::getVelocity() {
    return this->velocity;
}


SDL_Texture *GameObject::getTexture() {
    return this->objectTexture;
}

SDL_Rect *GameObject::getPart() {
    return &this->part;
}

bool GameObject::create(std::string path, SDL_Renderer *renderer, int sizeX, int sizeY) {
    //std::cout << "getting textures" << std::endl;
    this->loadTextures(std::move(path), renderer, sizeX, sizeY);
    //std::cout << "moving to 0" << std::endl;
    this->movable = 1;
    this->posX = 0;
    this->posY = 0;
    this->rotation = 0;
    this->velocity.resize(2);
    this->velocity[0] = 0;
    this->velocity[1] = 0;
    return true;
}

bool GameObject::setBouncyness(double bnc) {
    this->bouncyness = bnc;
    return true;
}

double GameObject::getBouncyness() {
    return this->bouncyness;
}

bool GameObject::setSize(int x, int y) {
    this->sizeX = x;
    this->sizeY = y;
    return false;
}

int GameObject::getSizeX() {
    return this->sizeX;
}

int GameObject::getSizeY() {
    return this->sizeY;
}

bool GameObject::setMovable() {
    this->movable = 1;
    return true;
}

bool GameObject::setStatic() {
    this->movable = 0;
    return true;
}

int GameObject::isMovable() {
    return this->movable;
}



