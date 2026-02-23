#pragma once
#include "figure.h"
template <typename TypeVal>
class Brelan : public figure {
private:
    TypeVal val;
public:
    Brelan() {};

    int calculateScore(const std::vector<int>& diceValues) const {
        return (isFig(diceValues)) ? 3 * val : 0;
    }

    bool isFig(const std::vector<int>& diceValues) const {
        int count = std::count(diceValues.begin(), diceValues.end(), val);
        return count == 3;
    }

    void setVal(TypeVal v) { val = v; };

    bool hasSetVal() const { return true; };
    
    std::string getName() const {
        return "Brelan";
    }
};