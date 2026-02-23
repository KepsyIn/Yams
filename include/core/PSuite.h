#pragma once
#include "figure.h"
#include <algorithm>
class PSuite : public figure {
public:
    int calculateScore(const std::vector<int>& diceValues) const {
        return(isFig(diceValues)) ? 30 : 0;
    }

    bool isFig(const std::vector<int>& diceValues) const {
        std::vector<int> sortedDice = diceValues;
        std::sort(sortedDice.begin(), sortedDice.end());
        int count = 0;
        for (size_t i = 0; i < sortedDice.size() - 1; ++i) {
            if (sortedDice[i] + 1 != sortedDice[i + 1]) {
                count = 0;
            }
            else {
                count++;
                if (count >= 3) {
                    return true; 
                }
            }
        }
        return false;
    }

    void setVal(int v) { };

    bool hasSetVal() const { return false; };

    std::string getName() const {
        return "Petite Suite";
    }
};