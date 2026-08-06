#pragma once

#include <string>
#include "Asset.h"

namespace trading {

class Crypto : public Asset {
public:
    Crypto(const std::string& symbol, double quantity, double currentPrice);

    double calculateValue() const override;
    double calculateRiskScore() const override;
    std::string getAssetType() const override;
    void display() const override;

    const std::string& getSymbol() const override;
    double getQuantity() const override;
    double getCurrentPrice() const override;

private:
    std::string symbol_;
    double quantity_;
    double currentPrice_;
};

} // namespace trading
