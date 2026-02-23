#include "core/lancer.h"

int lancer::lance()
{
    //std::srand((unsigned)time(NULL));
    int randomNum = std::rand() % this->nbFace + 1;
    return randomNum;
}


