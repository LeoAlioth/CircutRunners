//
// Created by anze on 25.10.2018.
//

#ifndef CIRCUTRUNNERS_GAMEOBJECT_H
#define CIRCUTRUNNERS_GAMEOBJECT_H


#include <vector>
#include <SDL_rect.h>
#include <SDL_system.h>
#include <string>
#include "ObjectPart.h"

class GameObject {
private:
    int movable;
    double posX;
    double posY;
    double rotation;
    double rotationalSpeed;
    double bouncyness;
    int sizeX, sizeY;
    std::vector<double>velocity;
    SDL_Rect part;
    SDL_Texture * objectTexture;
    std::vector<ObjectPart> objectParts;

    bool loadTextures(std::string path, SDL_Renderer * renderer, int sizeX, int sizeY);

public:
    GameObject();

    GameObject(std::string path, SDL_Renderer * renderer, int sizeX, int sizeY);

    bool create(std::string path, SDL_Renderer * renderer, int sizeX, int sizeY);

    bool setPosition(double x, double y);

    bool setRotation(double rotation);

    bool setRotation(double rotation, double rotationalSpeed);

    bool setVelocity(double velx, double vely);

    double getPosX();

    double getPosY();

    double getRotation();

    double getRotationalSpeed();

    bool setBouncyness(double bnc);

    double getBouncyness();

    bool setSize(int x, int y);

    int getSizeX();

    int getSizeY();

    bool setMovable();

    bool setStatic();

    int isMovable();

    std::vector<double> getVelocity();

    SDL_Texture * getTexture();

    SDL_Rect * getPart();


};

#endif //CIRCUTRUNNERS_GAMEOBJECT_H
