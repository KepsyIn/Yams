#pragma once
#include <algorithm>
#include "figure.h"
class Full : public figure {
public:
    int calculateScore(const std::vector<int>& diceValues) const {
        return (isFig(diceValues)) ? 25 : 0;
    }

    bool isFig(const std::vector<int>& diceValues) const {
        std::vector<int> sortedDice = diceValues;
        std::sort(sortedDice.begin(), sortedDice.end());
        return((sortedDice[0] == sortedDice[2] && sortedDice[3] == sortedDice[4] && sortedDice[2] != sortedDice[3]) ||
            (sortedDice[0] == sortedDice[1] && sortedDice[2] == sortedDice[4] && sortedDice[1] != sortedDice[3]));
    }

    void setVal(int v){};

    bool hasSetVal() const { return false; };

    std::string getName() const {
        return "Full";
    }
};

