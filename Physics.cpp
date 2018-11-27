//
// Created by anze on 27.11.2018.
//

#include "Physics.h"

Physics::Physics() {
    this->prev_time = std::chrono::high_resolution_clock::now();
    this->curr_time = std::chrono::high_resolution_clock::now();
    this->pixUnit = 32;
    this->gravityConst = 1;
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
        if (gameObject->isMovable()) {
            //std::cout << "rendering" << std::endl;
            //Render texture to screen
            std::vector<double> vel = gameObject->getVelocity();
            vel[1] += this->gravityConst * elapsed;
            gameObject->setVelocity(vel[0], vel[1]);
            //std::printf("vel: %f\n", vel[1]);

            double px = gameObject->getPosX();
            double py = gameObject->getPosY();
            double cx = this->pixUnit * vel[0] * elapsed;
            double cy = this->pixUnit * vel[1] * elapsed;
            gameObject->setPosition(px + cx, py + cy);
        }
    }
    return true;
}

bool Physics::collisions(std::vector<GameObject *> gameObjects) {
    bool colided;
    double px1;
    double py1;
    int sx1;
    int sy1;

    double px2;
    double py2;
    int sx2;
    int sy2;

    double xmin, xmax, ymin, ymax;

    for (auto &gameObject1 : gameObjects) {
        for (auto &gameObject2 : gameObjects) {
            if ((gameObject1->isMovable() == 1 || gameObject2->isMovable() == 1) && gameObject1 != gameObject2) {
                //std::printf("movable\n");
                //std::cout << "rendering" << std::endl;
                //Render texture to screen
                px1 = gameObject1->getPosX();
                py1 = gameObject1->getPosY();
                sx1 = gameObject1->getSizeX();
                sy1 = gameObject1->getSizeY();

                px2 = gameObject2->getPosX();
                py2 = gameObject2->getPosY();
                sx2 = gameObject2->getSizeX();
                sy2 = gameObject2->getSizeY();

                xmin = px2-sx1;
                ymin = py2-sy1;
                xmax = px2+sx2+sx1;
                ymax = py2+sy2+sy1;




                colided = false;
                if (xmin <= px1 && px1 <= xmax && ymin <= py1 && py1 <= ymax) {
                    colided = true;
                }

                if (colided) {
                    resolveCollision(gameObject1, gameObject2);
                }
            }
        }
    }
    return true;
}

bool Physics::resolveCollision(GameObject *go1, GameObject *go2) {
    if(go1->isMovable() && go2->isMovable()){
        return true;
    } else {

    }
    return false;
}


