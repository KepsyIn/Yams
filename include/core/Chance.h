#pragma once

#include <algorithm>
#include "figure.h"
class Chance : public figure {
public:
    int calculateScore(const std::vector<int>& diceValues) const {
        int sum = 0;
        for (int d : diceValues) {
            sum += d;
        }
        return sum;
    }

    bool isFig(const std::vector<int>& diceValues) const {
        return true;;
    }

    void setVal(int v) {};

    bool hasSetVal() const { return false; };

    std::string getName() const {
        return "Chance";
    }
};