#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Asset.h"


namespace trading {
    class Portfolio {

    public:
        void addAsset(std::unique_ptr<Asset> asset);
        bool removeAsset(const std::string& symbol);
        double getTotalValue() const;
        double getAverageRisk() const;

        const Asset* getRiskiestAsset() const;
        const Asset* getSafestAsset() const;
        void displayAll() const;
        void displayByType(const std::string& type) const;
        void sortByValue() const;
        void displaySummary() const;
        const Asset* findAsset(const std::string& symbol) const;
        size_t getAssetCount() const;


    private:
        std::vector<std::unique_ptr<Asset>> assets_;
    };
}


