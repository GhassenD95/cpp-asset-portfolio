#include <iostream>
#include <memory>

#include "Asset.h"
#include "Bond.h"
#include "Crypto.h"
#include "Option.h"
#include "Portfolio.h"
#include "Stock.h"

int main() {
    trading::Portfolio portfolio;
    portfolio.addAsset(std::make_unique<trading::Stock>("AAPL", 10, 150, 140));
    portfolio.addAsset(std::make_unique<trading::Bond>("US10Y", 100, 95, 0.05));
    portfolio.addAsset(std::make_unique<trading::Option>("AAPL150C", 5, 155, 150));

    std::cout << "Count: " << portfolio.getAssetCount() << "\n";
    std::cout << "Total value: " << portfolio.getTotalValue() << "\n";      // expect 10550
    std::cout << "Average risk: " << portfolio.getAverageRisk() << "\n"; // expect 41.67

    const trading::Asset* riskiest = portfolio.getRiskiestAsset();
    const trading::Asset* safest = portfolio.getSafestAsset();
    std::cout << "Riskiest: " << riskiest->getSymbol() << "\n";  // expect AAPL150C
    std::cout << "Safest: " << safest->getSymbol() << "\n";      // expect US10Y

    std::cout << "--- displayAll ---\n";
    portfolio.displayAll();

    std::cout << "--- findAsset(BTC) ---\n";
    std::cout << (portfolio.findAsset("BTC") ? "found" : "not found") << "\n";  // expect not found

    std::cout << "--- removeAsset(AAPL) ---\n";
    std::cout << (portfolio.removeAsset("AAPL") ? "removed" : "missing") << "\n";
    std::cout << "Count now: " << portfolio.getAssetCount() << "\n";  // expect 2

    return 0;
}
