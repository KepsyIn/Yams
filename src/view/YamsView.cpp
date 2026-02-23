#include "../../include/view/YamsView.h"
#include <iostream>
#include <sstream>

void YamsView::afficherEnteteJoueur(const joueur& j) const {
    std::cout << "\n=================================================" << std::endl;
    std::cout << "      " << j.getName() << " | Score : " << j.getScore() << std::endl;
    std::cout << "=================================================" << std::endl;
}

void YamsView::afficherDes(const std::vector<int>& platDice) const {
    std::cout << "\nIndex: ";
    for (int i = 0; i < (int)platDice.size(); i++) std::cout << "  " << i << "   ";
    std::cout << "\n       ";
    for (int i = 0; i < (int)platDice.size(); i++) std::cout << "----- ";
    std::cout << "\nDés:   ";
    for (int v : platDice) std::cout << "| " << v << " | ";
    std::cout << "\n       ";
    for (int i = 0; i < (int)platDice.size(); i++) std::cout << "----- ";
    std::cout << std::endl;
}

void YamsView::afficherListeFigures(const std::vector<figure*>& figs, const joueur& j) const {
    if (figs.empty()) {
        std::cout << "Aucune figure possible ! " << std::endl;
        return;
    }
    for (int i = 0; i < (int)figs.size(); i++) {
        bool done = j.isDone(figs[i]);
        std::cout << i << " - " << (done ? "\033[9m" : "") << figs[i]->getName() 
                  << (done ? "\033[0m" : "") << std::endl;
    }
}

bool YamsView::demanderSiRelance() const {
    std::string input;
    std::cout << "Voulez vous relancer les des ? [ y / n ] ";
    std::getline(std::cin, input);
    return (input == "y");
}

std::vector<int> YamsView::demanderIndexesRelance() const {
    std::cout << "Donnez les index des Des a relance : ";
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> indices;
    std::istringstream iss(line);
    int val;
    while (iss >> val) indices.push_back(val);
    return indices;
}

int YamsView::demanderChoixFigure(int max) const {
    int choix = -1;
    while (choix < 0 || choix >= max) {
        std::cout << "Choisissez l'index de la figure : ";
        std::string input;
        std::getline(std::cin, input);
        try { choix = std::stoi(input); } catch (...) { choix = -1; }
    }
    return choix;
}

void YamsView::afficherMessage(const std::string& msg) const {
    std::cout << msg << std::endl;
}