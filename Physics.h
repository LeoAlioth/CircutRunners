//
// Created by anze on 27.11.2018.
//

#ifndef CIRCUTRUNNERS_PHISYCS_H
#define CIRCUTRUNNERS_PHISYCS_H

#include <chrono>
#include "GameObject.h"

class Physics {
private:
    int pixUnit;
    float gravityConst;
    std::chrono::_V2::system_clock::time_point prev_time;
    std::chrono::_V2::system_clock::time_point curr_time;
    long elapsed_time();
public:
    Physics();
    bool update(std::vector<GameObject*> gameObjects);
    bool collisions(std::vector<GameObject*> gameObjects);
    bool resolveCollision(GameObject * go1, GameObject * go2);

};


#endif //CIRCUTRUNNERS_PHISYCS_H
