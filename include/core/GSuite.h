#pragma once
#include "figure.h"
#include <algorithm>
class GSuite : public figure {
public:
    int calculateScore(const std::vector<int>& diceValues) const {
        return (isFig(diceValues)) ? 40 : 0;
    }

    bool isFig(const std::vector<int>& diceValues) const {
        std::vector<int> sortedDice = diceValues;
        std::sort(sortedDice.begin(), sortedDice.end());
        for (int i = 0; i < 4; i++) {
            if (sortedDice[i] + 1 != sortedDice[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void setVal(int v) { };

    bool hasSetVal() const { return false; };

    std::string getName() const {
        return "Grande Suite";
    }
};