#include "Bond.h"

#include <iomanip>
#include <iostream>

trading::Bond::Bond(const std::string& symbol, double quantity,
                    double currentPrice, double couponRate)
    : symbol_(symbol), quantity_(quantity), currentPrice_(currentPrice), couponRate_(couponRate) {}

double trading::Bond::calculateValue() const {
    return quantity_ * currentPrice_ * 0.95;
}

double trading::Bond::calculateRiskScore() const {
    return 10.0;
}

std::string trading::Bond::getAssetType() const {
    return "BOND";
}

void trading::Bond::display() const {
    std::cout << std::fixed << std::setprecision(2)
              << getAssetType() << ": " << getSymbol()
              << " | Qty: " << getQuantity()
              << " | Price: $" << getCurrentPrice()
              << " | Value: $" << calculateValue()
              << " | Risk: " << calculateRiskScore() << "/100\n";
}

const std::string& trading::Bond::getSymbol() const {
    return symbol_;
}

double trading::Bond::getQuantity() const {
    return quantity_;
}

double trading::Bond::getCurrentPrice() const {
    return currentPrice_;
}

double trading::Bond::getCouponRate() const {
    return couponRate_;
}
