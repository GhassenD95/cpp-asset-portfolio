#include <iostream>
#include <memory>
#include <string>

#include "Asset.h"
#include "Bond.h"
#include "Crypto.h"
#include "Option.h"
#include "Portfolio.h"
#include "Stock.h"

int main() {
    trading::Portfolio portfolio;
    int choice = 0;

    do {
        std::cout << "\n=== Asset Portfolio Manager ===\n"
                  << "1. Add Stock\n"
                  << "2. Add Bond\n"
                  << "3. Add Option\n"
                  << "4. Add Crypto\n"
                  << "5. Remove Asset (by symbol)\n"
                  << "6. Display All Assets\n"
                  << "7. Display by Type\n"
                  << "8. View Portfolio Summary\n"
                  << "9. Sort by Value (display only)\n"
                  << "10. Find Asset\n"
                  << "11. Exit\n"
                  << "Choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string symbol;
                double quantity, currentPrice, entryPrice;
                std::cout << "Symbol: ";
                std::cin >> symbol;
                std::cout << "Quantity: ";
                std::cin >> quantity;
                std::cout << "Current Price: ";
                std::cin >> currentPrice;
                std::cout << "Entry Price: ";
                std::cin >> entryPrice;
                portfolio.addAsset(std::make_unique<trading::Stock>(symbol, quantity, currentPrice, entryPrice));
                std::cout << "Stock added.\n";
                break;
            }
            case 2: {
                std::string symbol;
                double quantity, currentPrice, couponRate;
                std::cout << "Symbol: ";
                std::cin >> symbol;
                std::cout << "Quantity: ";
                std::cin >> quantity;
                std::cout << "Current Price: ";
                std::cin >> currentPrice;
                std::cout << "Coupon Rate: ";
                std::cin >> couponRate;
                portfolio.addAsset(std::make_unique<trading::Bond>(symbol, quantity, currentPrice, couponRate));
                std::cout << "Bond added.\n";
                break;
            }
            case 3: {
                std::string symbol;
                double quantity, currentPrice, strikePrice;
                std::cout << "Symbol: ";
                std::cin >> symbol;
                std::cout << "Quantity: ";
                std::cin >> quantity;
                std::cout << "Current Price: ";
                std::cin >> currentPrice;
                std::cout << "Strike Price: ";
                std::cin >> strikePrice;
                portfolio.addAsset(std::make_unique<trading::Option>(symbol, quantity, currentPrice, strikePrice));
                std::cout << "Option added.\n";
                break;
            }
            case 4: {
                std::string symbol;
                double quantity, currentPrice;
                std::cout << "Symbol: ";
                std::cin >> symbol;
                std::cout << "Quantity: ";
                std::cin >> quantity;
                std::cout << "Current Price: ";
                std::cin >> currentPrice;
                portfolio.addAsset(std::make_unique<trading::Crypto>(symbol, quantity, currentPrice));
                std::cout << "Crypto added.\n";
                break;
            }
            case 5: {
                std::string symbol;
                std::cout << "Symbol to remove: ";
                std::cin >> symbol;
                std::cout << (portfolio.removeAsset(symbol) ? "Asset removed.\n" : "Asset not found.\n");
                break;
            }
            case 6:
                portfolio.displayAll();
                break;
            case 7: {
                std::string type;
                std::cout << "Asset type: ";
                std::cin >> type;
                portfolio.displayByType(type);
                break;
            }
            case 8:
                portfolio.displaySummary();
                break;
            case 9:
                portfolio.sortByValue();
                break;
            case 10: {
                std::string symbol;
                std::cout << "Symbol: ";
                std::cin >> symbol;
                const trading::Asset* found = portfolio.findAsset(symbol);
                if (found != nullptr) {
                    found->display();
                } else {
                    std::cout << "Asset not found.\n";
                }
                break;
            }
            case 11:
                std::cout << "Goodbye.\n";
                break;
            default:
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 11);

    return 0;
}
