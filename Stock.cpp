#include "Stock.h"

#include <iomanip>
#include <iostream>

trading::Stock::Stock(const std::string& symbol, double quantity,
                      double currentPrice, double entryPrice)
    : symbol_(symbol), quantity_(quantity), currentPrice_(currentPrice), entryPrice_(entryPrice) {}

double trading::Stock::calculateValue() const {
    return quantity_ * currentPrice_;
}

double trading::Stock::calculateRiskScore() const {
    return currentPrice_ < entryPrice_ * 0.9 ? 60 : 30;
}

std::string trading::Stock::getAssetType() const {
    return "STOCK";
}

void trading::Stock::display() const {
    std::cout << std::fixed << std::setprecision(2)
              << getAssetType() << ": " << getSymbol()
              << " | Qty: " << getQuantity()
              << " | Price: $" << getCurrentPrice()
              << " | Value: $" << calculateValue()
              << " | Risk: " << calculateRiskScore() << "/100\n";
}

const std::string& trading::Stock::getSymbol() const {
    return symbol_;
}

double trading::Stock::getQuantity() const {
    return quantity_;
}

double trading::Stock::getCurrentPrice() const {
    return currentPrice_;
}

double trading::Stock::getEntryPrice() const {
    return entryPrice_;
}
