#include "../../include/model/YamsModel.h"

YamsModel::YamsModel(int nbJoueur, unsigned int faceDes) : myLancer(faceDes) {
    for (int i = 0; i < 5; i++) platDice.push_back(0);
    for (int i = 1; i <= nbJoueur; i++) {
        joueurs.push_back(joueur("Joueur " + std::to_string(i)));
    }
    initFigures();
}

YamsModel::~YamsModel() {
    for (figure* f : figuresMin) delete f;
    for (figure* f : figuresMaj) delete f;
}

void YamsModel::initFigures() {
    for (int i = 1; i <= 6; i++) figuresMin.push_back(new Minor<int>(i));
    figuresMaj.push_back(new Brelan<int>());
    figuresMaj.push_back(new Carre<int>());
    figuresMaj.push_back(new Full());
    figuresMaj.push_back(new PSuite());
    figuresMaj.push_back(new GSuite());
    figuresMaj.push_back(new YamsFig<int>());
    figuresMaj.push_back(new Chance());
}

void YamsModel::lancerTousLesDes() {
    for (int& d : platDice) d = myLancer.lance();
    std::sort(platDice.begin(), platDice.end());
}

void YamsModel::relancerSelection(const std::vector<int>& indexes) {
    for (int ind : indexes) {
        if (ind >= 0 && ind < (int)platDice.size()) {
            platDice[ind] = myLancer.lance();
        }
    }
    std::sort(platDice.begin(), platDice.end());
}

std::vector<figure*> YamsModel::getFiguresPossibles(const joueur& j, bool maj) {
    std::vector<figure*> dispo;
    auto& listeRef = maj ? figuresMaj : figuresMin;
    
    for (auto* f : listeRef) {
        if (f->isFig(platDice)) {
            dispo.push_back(f);
        } else if (f->hasSetVal()) {
            for (int i = 1; i <= 6; i++) {
                f->setVal(i);
                if (f->isFig(platDice)) { 
                    dispo.push_back(f); 
                    break; 
                }
            }
        }
    }
    return dispo;
}

joueur& YamsModel::getWinner() {
    int maxIdx = 0;
    for(int i = 1; i < joueurs.size(); i++) {
        if (joueurs[maxIdx] <= joueurs[i]) maxIdx = i;
    }
    return joueurs[maxIdx];
}