#include "Crypto.h"

#include <iomanip>
#include <iostream>

trading::Crypto::Crypto(const std::string& symbol, double quantity, double currentPrice)
    : symbol_(symbol), quantity_(quantity), currentPrice_(currentPrice) {}

double trading::Crypto::calculateValue() const {
    return quantity_ * currentPrice_;
}

double trading::Crypto::calculateRiskScore() const {
    return quantity_ > 100 ? 90 : 70;
}

std::string trading::Crypto::getAssetType() const {
    return "CRYPTO";
}

void trading::Crypto::display() const {
    std::cout << std::fixed << std::setprecision(2)
              << getAssetType() << ": " << getSymbol()
              << " | Qty: " << getQuantity()
              << " | Price: $" << getCurrentPrice()
              << " | Value: $" << calculateValue()
              << " | Risk: " << calculateRiskScore() << "/100\n";
}

const std::string& trading::Crypto::getSymbol() const {
    return symbol_;
}

double trading::Crypto::getQuantity() const {
    return quantity_;
}

double trading::Crypto::getCurrentPrice() const {
    return currentPrice_;
}
