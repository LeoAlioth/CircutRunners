//
// Created by anze on 27.11.2018.
//

#include "Physics.h"

Physics::Physics() {
    this->prev_time = std::chrono::high_resolution_clock::now();
    this->curr_time = std::chrono::high_resolution_clock::now();
    this->pixUnit = 32;
    this->gravityConst = 0.1;
};

long Physics::elapsed_time() {
    this->curr_time = std::chrono::high_resolution_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(this->curr_time - this->prev_time).count();
    this->prev_time = this->curr_time;
    return elapsed;
}

bool Physics::update(std::vector<GameObject *> gameObjects) {
    double elapsed = (double) elapsed_time() / 1000000;
    for (auto &gameObject : gameObjects) {
        if(gameObject->isMovable()) {
            //std::cout << "rendering" << std::endl;
            //Render texture to screen
            std::vector<double> vel = gameObject->getVelocity();
            vel[1] += this->gravityConst * pixUnit * elapsed;
            gameObject->setVelocity(vel[0], vel[1]);
            std::printf("vel: %f\n", vel[1]);

            double px = gameObject->getPosX();
            double py = gameObject->getPosY();
            double cx = this->pixUnit * vel[0] * elapsed;
            double cy = this->pixUnit * vel[1] * elapsed;
            gameObject->setPosition(px + cx, py + cy);
        }
    }
    return true;
}

bool Physics::checkCollisions(std::vector<GameObject *> gameObjects) {
    for (auto &gameObject1 : gameObjects) {
        for (auto &gameObject2 : gameObjects) {
            //std::cout << "rendering" << std::endl;
            //Render texture to screen
            double px1 = gameObject1->getPosX();
            double py1 = gameObject1->getPosY();
            int sx1 = gameObject1->getSizeX();
            int sy1 = gameObject1->getSizeY();

            double px2 = gameObject2->getPosX();
            double py2 = gameObject2->getPosY();
            int sx2 = gameObject2->getSizeX();
            int sy2 = gameObject2->getSizeY();


        }
    }
    return true;
}


