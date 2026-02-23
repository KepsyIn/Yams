#ifndef YAMS_MODEL_H
#define YAMS_MODEL_H

#include <vector>
#include <string>
#include <algorithm>
#include "../core/joueur.h"
#include "../core/figure.h"
#include "../core/lancer.h"
#include "../core/Minor.h"
#include "../core/Brelan.h"
#include "../core/Carre.h"
#include "../core/Full.h"
#include "../core/PSuite.h"
#include "../core/GSuite.h"
#include "../core/YamsFig.h"
#include "../core/Chance.h"

class YamsModel {
private:
    std::vector<int> platDice;
    std::vector<joueur> joueurs;
    std::vector<figure*> figuresMin;
    std::vector<figure*> figuresMaj;
    lancer myLancer;

public:
    YamsModel(int nbJoueur, unsigned int faceDes);
    ~YamsModel(); // Pour libérer les pointeurs de figures

    void initFigures();
    void lancerTousLesDes();
    void relancerSelection(const std::vector<int>& indexes);
    
    std::vector<figure*> getFiguresPossibles(const joueur& j, bool maj);
    
    // Getters
    std::vector<int>& getPlatDice() { return platDice; }
    std::vector<joueur>& getJoueurs() { return joueurs; }
    const std::vector<figure*>& getFiguresMin() const { return figuresMin; }
    const std::vector<figure*>& getFiguresMaj() const { return figuresMaj; }
    joueur& getWinner();
};

#endif