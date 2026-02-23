#ifndef YAMS_VIEW_H
#define YAMS_VIEW_H

#include <vector>
#include <string>
#include "../core/joueur.h"
#include "../core/figure.h"

class YamsView {
public:
    void afficherEnteteJoueur(const joueur& j) const;
    void afficherDes(const std::vector<int>& platDice) const;
    void afficherListeFigures(const std::vector<figure*>& figs, const joueur& j) const;
    void afficherMessage(const std::string& msg) const;
    
    bool demanderSiRelance() const;
    std::vector<int> demanderIndexesRelance() const;
    int demanderChoixFigure(int max) const;
};

#endif