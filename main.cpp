#include <iostream>
#include <memory>
#include <vector>

#include "Asset.h"
#include "Bond.h"
#include "Crypto.h"
#include "Option.h"
#include "Stock.h"

int main() {
    std::vector<std::unique_ptr<trading::Asset>> testAssets;
    testAssets.push_back(std::make_unique<trading::Stock>("AAPL", 10, 150, 140));
    testAssets.push_back(std::make_unique<trading::Bond>("US10Y", 100, 95, 0.05));
    testAssets.push_back(std::make_unique<trading::Option>("AAPL150C", 5, 155, 150));
    testAssets.push_back(std::make_unique<trading::Crypto>("BTC", 0.5, 30000));

    for (const auto& asset : testAssets) {
        std::cout << asset->getAssetType() << ": " << asset->calculateValue() << "\n";
    }

    return 0;
}
