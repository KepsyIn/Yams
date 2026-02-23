#pragma once
#include <vector>
#include <string>

class figure
{
public:
	virtual int calculateScore(const std::vector<int>& diceValues) const = 0;
	virtual std::string getName() const = 0;
	virtual bool isFig(const std::vector<int>& diceValues) const = 0;
	virtual bool hasSetVal() const = 0;
	virtual void setVal(int) = 0;;
};

