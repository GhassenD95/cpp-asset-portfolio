#pragma once

#include <string>
#include "Asset.h"

namespace trading {

class Stock : public Asset {
public:
    Stock(const std::string& symbol, double quantity,
          double currentPrice, double entryPrice);

    double calculateValue() const override;
    double calculateRiskScore() const override;
    std::string getAssetType() const override;
    void display() const override;

    const std::string& getSymbol() const override;
    double getQuantity() const override;
    double getCurrentPrice() const override;

    double getEntryPrice() const;

private:
    std::string symbol_;
    double quantity_;
    double currentPrice_;
    double entryPrice_;
};

} // namespace trading
