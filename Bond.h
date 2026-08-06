#pragma once

#include <string>
#include "Asset.h"

namespace trading {

class Bond : public Asset {
public:
    Bond(const std::string& symbol, double quantity,
         double currentPrice, double couponRate);

    double calculateValue() const override;
    double calculateRiskScore() const override;
    std::string getAssetType() const override;
    void display() const override;

    const std::string& getSymbol() const override;
    double getQuantity() const override;
    double getCurrentPrice() const override;

    double getCouponRate() const;

private:
    std::string symbol_;
    double quantity_;
    double currentPrice_;
    double couponRate_;
};

} // namespace trading
