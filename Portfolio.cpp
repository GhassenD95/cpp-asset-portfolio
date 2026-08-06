//
// Created by ghassen on 6‏/8‏/2026.
//

#include "Portfolio.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>

void trading::Portfolio::addAsset(std::unique_ptr<Asset> asset) {

    assets_.push_back(std::move(asset));
}

bool trading::Portfolio::removeAsset(const std::string &symbol) {
    auto it = std::find_if(assets_.begin(), assets_.end(),
                           [&symbol](const std::unique_ptr<Asset>& asset) {
                               return asset->getSymbol() == symbol;
                           });
    if (it == assets_.end()) {
        return false;
    }
    assets_.erase(it);
    return true;
}

double trading::Portfolio::getTotalValue() const {
    return std::accumulate(
        assets_.begin(),
        assets_.end(),
        0.0,
        [](double total, const std::unique_ptr<Asset>& asset) {
            return total + asset->calculateValue();
        });
}

double trading::Portfolio::getAverageRisk() const {
    if (assets_.empty()) {
        return 0.0;
    }

    auto totalRisk = std::accumulate(
        assets_.begin(),
        assets_.end(),
        0.0,
        [](double total, const auto& asset) {
            return total + asset->calculateRiskScore();
        });
    return totalRisk / assets_.size();
}

const trading::Asset* trading::Portfolio::getRiskiestAsset() const {
    auto it =  std::max_element(
        assets_.begin(),
        assets_.end(),
        [](const auto& a, const auto& b) {
            return a->calculateRiskScore() < b->calculateRiskScore();
        }
    );

    return it == assets_.end() ? nullptr : it->get();
}

const trading::Asset * trading::Portfolio::getSafestAsset() const {
    auto it = std::min_element(
        assets_.begin(),
        assets_.end(),
        [](const auto& a, const auto& b) {
            return a->calculateRiskScore() < b->calculateRiskScore();
        }
        );
    return it == assets_.end() ? nullptr : it->get();
}

void trading::Portfolio::displayAll() const {
    for (const auto& asset : assets_) {
        asset->display();
    }
}

void trading::Portfolio::displayByType(const std::string &type) const {
    std::vector<const Asset*> matches;
    matches.reserve(assets_.size());
    std::for_each(assets_.begin(), assets_.end(),
                  [&type, &matches](const std::unique_ptr<Asset>& asset) {
                      if (asset->getAssetType() == type) {
                          matches.push_back(asset.get());
                      }
                  });
    for (const Asset* asset : matches) {
        asset->display();
    }
}

void trading::Portfolio::sortByValue() const {
    std::vector<const Asset*> sorted;
    sorted.reserve(assets_.size());
    std::transform(assets_.begin(), assets_.end(), std::back_inserter(sorted),
                   [](const std::unique_ptr<Asset>& asset) { return asset.get(); });
    std::sort(sorted.begin(), sorted.end(),
              [](const Asset* a, const Asset* b) {
                  return a->calculateValue() > b->calculateValue();
              });
    for (const Asset* asset : sorted) {
        asset->display();
    }
}

const trading::Asset * trading::Portfolio::findAsset(const std::string &symbol) const {
    auto it =  std::find_if(assets_.begin(), assets_.end(),
                 [&symbol](const std::unique_ptr<Asset>& asset) {
                     return asset->getSymbol() == symbol;
                 });
    return it == assets_.end() ? nullptr : it->get();
}

size_t trading::Portfolio::getAssetCount() const {
    return assets_.size();
}

void trading::Portfolio::displaySummary() const {
    std::cout << "=== Portfolio Summary ===\n";
    std::cout << "Total Assets: " << getAssetCount() << "\n";
    std::cout << std::fixed << std::setprecision(2)
              << "Total Value: $" << getTotalValue() << "\n";
    std::cout << std::fixed << std::setprecision(1)
              << "Average Risk Score: " << getAverageRisk() << "/100\n";

    const trading::Asset* riskiest = getRiskiestAsset();
    if (riskiest != nullptr) {
        std::cout << "Riskiest Asset: " << riskiest->getSymbol()
                  << " (" << riskiest->getAssetType() << ")"
                  << " - Risk: " << riskiest->calculateRiskScore() << "\n";
    }

    const trading::Asset* safest = getSafestAsset();
    if (safest != nullptr) {
        std::cout << "Safest Asset: " << safest->getSymbol()
                  << " (" << safest->getAssetType() << ")"
                  << " - Risk: " << safest->calculateRiskScore() << "\n";
    }
}
