//
// Created by ghassen on 6‏/8‏/2026.
//

#include "Option.h"

#include <iomanip>
#include <iostream>

trading::Option::Option(const std::string &symbol, double quantity, double currentPrice, double strikePrice) : symbol_(symbol), quantity_(quantity), currentPrice_(currentPrice), strikePrice_(strikePrice) {
}

double trading::Option::calculateValue() const {
    return currentPrice_ > strikePrice_ ? (currentPrice_ - strikePrice_) * quantity_ : 0;
}

double trading::Option::calculateRiskScore() const {
    return 85.0;
}

std::string trading::Option::getAssetType() const {
    return "OPTION";
}

void trading::Option::display() const {
    std::cout << std::fixed << std::setprecision(2)
          << getAssetType() << ": " << getSymbol()
          << " | Qty: " << getQuantity()
          << " | Price: $" << getCurrentPrice()
          << " | Value: $" << calculateValue()
          << " | Risk: " << calculateRiskScore() << "/100\n";

}

const std::string & trading::Option::getSymbol() const {
    return symbol_;
}

double trading::Option::getQuantity() const {
    return quantity_;
}

double trading::Option::getCurrentPrice() const {
    return currentPrice_;
}

double trading::Option::getStrikePrice() const {
    return strikePrice_;
}
