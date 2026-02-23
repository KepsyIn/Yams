#include "core/joueur.h"

bool joueur::isDone(const figure* platFig) const
{
    for (const figure* f : this->figureDoned) {
        if (f == platFig) return true;
    }
    return false;
}

void joueur::addFigure(figure* f)
{
    this->figureDoned.push_back(f);
}

void joueur::updateScore(const int& score)
{
    this->score += score;
}

std::string joueur::getName() const
{
    return this->userName;
}

int joueur::getScore() const {
    return this->score;
}
