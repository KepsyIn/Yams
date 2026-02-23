#pragma once
#include <vector>

#include <iostream>
#include <cstdlib>
#include <ctime>

class lancer
{
	int nbFace;
public:
	lancer() : nbFace(6) {
		std::srand((unsigned)time(NULL));
	};
	lancer(int nbF) : nbFace(nbF) {};
	int lance();
};

