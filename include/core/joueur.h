#pragma once
#include <string>
#include "figure.h"
#include <vector>

class joueur
{
	std::vector<figure*> figureDoned; // figure effectué par le joueur
	std::string userName; // nom du joueur
	int score; // score du joueur
public:
	joueur() : userName(""), score(0) {};
	joueur(const std::string& name) : userName(name), score(0) {};
	bool isDone(const figure*) const;
	void addFigure(figure*);
	void updateScore(const int& score);
	std::string getName() const;
	int getScore() const;

	const bool operator< (const joueur& j) const {
		return this->getScore() < j.getScore();
	}
	const bool operator<= (const joueur& j) const {
		return this->getScore() <= j.getScore();
	}
	const bool operator>= (const joueur& j) const {
		return this->getScore() >= j.getScore();
	}
	const bool operator> (const joueur& j) const {
		return this->getScore() > j.getScore();
	}

};

