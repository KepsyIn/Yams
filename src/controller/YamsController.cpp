#include "../../include/controller/YamsController.h"

YamsController::YamsController(YamsModel& m, YamsView& v) : model(m), view(v) {}

void YamsController::lancerPartie() {
    view.afficherMessage("\n        - PARTIE MINEUR : \n");
    for (int t = 0; t < 6; t++) {
        for (joueur& j : model.getJoueurs()) jouerTour(j, false);
    }

    view.afficherMessage("\n        - PARTIE MAJEUR : \n");
    for (int t = 0; t < 7; t++) {
        for (joueur& j : model.getJoueurs()) jouerTour(j, true);
    }

    joueur& winner = model.getWinner();
    view.afficherMessage("\nBRAVO ! " + winner.getName() + " GAGNE avec " + std::to_string(winner.getScore()) + " pts!");
}

void YamsController::jouerTour(joueur& j, bool estMaj) {
    view.afficherEnteteJoueur(j);
    model.lancerTousLesDes();
    
    int relances = 0;
    while (relances < 2) {
        view.afficherDes(model.getPlatDice());
        if (!view.demanderSiRelance()) break;
        
        model.relancerSelection(view.demanderIndexesRelance());
        relances++;
    }

    view.afficherDes(model.getPlatDice());
    auto possibles = model.getFiguresPossibles(j, estMaj);

    if (possibles.empty()) {
        view.afficherMessage("Pas de figure disponible, choisissez pour barrer :");
        auto& complete = estMaj ? model.getFiguresMaj() : model.getFiguresMin();
        view.afficherListeFigures(complete, j);
        int choix = view.demanderChoixFigure(complete.size());
        j.addFigure(complete[choix]);
    } else {
        view.afficherListeFigures(possibles, j);
        int choix = view.demanderChoixFigure(possibles.size());
        j.addFigure(possibles[choix]);
        j.updateScore(possibles[choix]->calculateScore(model.getPlatDice()));
    }
}