#pragma once
#include "figure.h"
template <typename TypeVal>
class Minor : public figure {
private:
    TypeVal val;
public:
    Minor(TypeVal v) : val(v) {};
    int calculateScore(const std::vector<int>& diceValues) const {
        int count = std::count(diceValues.begin(), diceValues.end(), val);
        return count * val;
    }

    bool isFig(const std::vector<int>& diceValues) const {
        int count = std::count(diceValues.begin(), diceValues.end(), val);
        return count > 0;
    }

    void setVal(int v)  { };

    bool hasSetVal() const { return false; };

    std::string getName() const {
        return "Mineure de " + std::to_string(val);
    }
};


