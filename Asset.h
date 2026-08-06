#pragma once

#include <string>

namespace trading {

class Asset {
public:
    virtual ~Asset() = default;

    virtual double calculateValue() const = 0;
    virtual double calculateRiskScore() const = 0;
    virtual std::string getAssetType() const = 0;
    virtual void display() const = 0;

    virtual const std::string& getSymbol() const = 0;
    virtual double getQuantity() const = 0;
    virtual double getCurrentPrice() const = 0;
};

} // namespace trading
